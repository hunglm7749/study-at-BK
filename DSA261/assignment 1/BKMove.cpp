#include "BKMove.h"

void BKMove::addRoute(BusRoute* route) {
    if (route == nullptr) throw invalid_argument("route must not be null");
    routes.push_back(route);
}

int BKMove::getRouteCount() const {
    return static_cast<int>(routes.size());
}

BusRoute* BKMove::getRoute(int index) {
    if (index < 0 || index >= static_cast<int>(routes.size())) {
        throw out_of_range("BKMove route index is out of range");
    }
    return routes[index]; 
}

bool operator<(std::string const& left, std::string const& right)
{
    std::size_t min_lenght = std::min(left.length(), right.length());
    for (std::size_t i = 0; i < min_lenght; i++)
    {
        if (left[i] < right[i]) return true;
        if (left[i] > right[i]) return false;
    }
    
    // ABCD < ABCDxxx 
    return left.length() < right.length();
}

vector<RouteResult> BKMove::findDirectRoutes(string fromStopId, string toStopId)
{
    // TODO Q5.1

    std::vector<RouteResult> result;
    for (BusRoute* route: routes)
    {
        for (Direction direction: { Direction::INBOUND, Direction::OUTBOUND })
        {
            int hopCount = route->getHopCount(fromStopId, toStopId, direction);
            if (hopCount >= 0)
            {
                result.push_back(
                    RouteResult {
                        route->getId(),
                        direction,
                        hopCount
                    }
                );
            }
        }
    }

    QuickSort<RouteResult> sorter;
    sorter.sort(
        result.data(), 
        result.size(), 
        [](RouteResult& r1, RouteResult& r2) {

            // struct RouteResult {
            //     string routeId;        // priority 2  (lexico graphically smaller)
            //     Direction direction;   // priority 3  (OUTBOUND < INBOUND)
            //     int hopCount;          // priority 1  (smaller)
            // };

            // enum Direction {
            //     OUTBOUND = 0,
            //     INBOUND = 1
            // };

            if (r1.hopCount < r2.hopCount)
                return -1;
            else if (r1.hopCount > r2.hopCount)
                return 1;

            if (r1.routeId < r2.routeId)
                return -1;
            else if (r1.routeId > r2.routeId)
                return 1;

            if (r1.direction < r2.direction)
                return -1;
            else if (r1.direction > r2.direction)
                return 1;

            return 0;
        }
    );
    return result;
}

vector<JourneyResult> BKMove::findJourneys(string fromStopId, string toStopId)
{
    // TODO Q5.2

    // find journey A -> F
    // route 0: A -> B -> E -> G -> D
    // route 1: C -> D -> G -> F
    // => journey: | A -> B -> E -> G | G -> F |



    std::vector<JourneyResult> result;

    /// NO TRANSFERS
    {
        for (BusRoute* route: routes)
        {
            for (Direction direction: { Direction::INBOUND, Direction::OUTBOUND })
            {
                int hopCount = route->getHopCount(fromStopId, toStopId, direction);
                if (hopCount >= 0)
                {
                    result.push_back(
                        JourneyResult {
                            route->getId(),
                            direction,
                            hopCount
                        }
                    );
                }
            }
        }
    }

    /// ONE TRANSFER
    {
        for (BusRoute* firstRoute: routes)
        {
            for (BusRoute* secondRoute: routes)
            {
                if (firstRoute->getId() == secondRoute->getId())
                    continue;
                
                for (Direction firstRoute_direction: { Direction::OUTBOUND, Direction::INBOUND })
                {
                    SLinkedList<std::string> transfer_stopIds;
                    int firstRoute_stopCount = firstRoute->getStopCount(firstRoute_direction);
                    for (int i = 0; i < firstRoute_stopCount; i++)
                    {
                        transfer_stopIds.add(firstRoute->getStop(i, firstRoute_direction).getId());
                    }

                    for (Direction secondRoute_direction: { Direction::OUTBOUND, Direction::INBOUND })
                    {
                        for (std::string transer_stopId: transfer_stopIds)
                        {
                            int firstRoute_hopCount = firstRoute->getHopCount(
                                fromStopId, 
                                transer_stopId, 
                                firstRoute_direction
                            );

                            int secondRoute_hopCount = secondRoute->getHopCount(
                                transer_stopId,
                                toStopId,
                                secondRoute_direction
                            );

                            if (firstRoute_hopCount >= 1 && secondRoute_hopCount >= 1)
                            {
                                result.push_back(
                                    JourneyResult {
                                        firstRoute->getId(),
                                        firstRoute_direction,
                                        transer_stopId,
                                        secondRoute->getId(),
                                        secondRoute_direction,
                                        firstRoute_hopCount + secondRoute_hopCount
                                    }
                                );
                            }
                        }
                    }
                }
            }
        }
    }

    QuickSort<JourneyResult> sorter;
    sorter.sort(
        result.data(),
        result.size(),
        [](JourneyResult& j1, JourneyResult& j2)
        {
            if (j1.transfers < j2.transfers)
                return -1;
            else if (j1.transfers > j2.transfers)
                return 1;

            if (j1.totalHops < j2.totalHops)
                return -1;
            else if (j1.totalHops > j2.totalHops)
                return 1;

            if (j1.firstRouteId < j2.firstRouteId)
                return -1;
            else if (j1.firstRouteId > j2.firstRouteId)
                return 1;

            if (j1.firstDirection < j2.firstDirection)
                return -1;
            else if (j1.firstDirection > j2.firstDirection)
                return 1;

            if (j1.transferStopId < j2.transferStopId)
                return -1;
            else if (j1.transferStopId > j2.transferStopId)
                return 1;

            if (j1.secondRouteId < j2.secondRouteId)
                return -1;
            else if (j1.secondRouteId > j2.secondRouteId)
                return 1;

            if (j1.secondDirection < j2.secondDirection)
                return -1;
            else if (j1.secondDirection > j2.secondDirection)
                return 1;

            return 0;
        }
    );

    return result;
}
