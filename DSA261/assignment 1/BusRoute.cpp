#include "BusRoute.h"

BusRoute::BusRoute(string routeId)
    : routeId(routeId), outboundCount(0), built(false) {}

string BusRoute::getId() const {
    return routeId;
}

bool BusRoute::isBuilt() const {
    return built;
}

int BusRoute::getStopCount(Direction direction)
{
    // TODO Q3

    if (!built)
        return 0;

    if (direction == Direction::OUTBOUND)
    {
        return outboundCount;
    }
    else
    {
        return stops.size() - outboundCount + 2;
    }
}

int BusRoute::physicalIndex(int index, Direction direction) 
{
    // TODO Q3

    if (direction == Direction::OUTBOUND)
    {
        if (index == outboundCount - 1)
        {
            return 0;
        }
        else
        {
            int outboundOffset = stops.size() - outboundCount + 1;
            return outboundOffset + index;
        }
    }
    else
    {
        return index;
    }
}

BusStop& BusRoute::getStop(int index, Direction direction)
{
    // TODO Q3

    if (index < 0 || index >= getStopCount(direction))
        throw std::out_of_range("Index out of range!");

    return stops.get(physicalIndex(index, direction));
}

void BusRoute::build(SLinkedList<BusStop>& outbound, SLinkedList<BusStop>& inbound) 
{
    // TODO Q3

    // inbound: A -> B -> C -> D -> (E)
    // outbound: E -> F -> C -> B -> (A)

    // step 1 => stops: A -> B -> C -> D (A is head, D is tail)
    // step 2 => stops: A -> B -> C -> D -> E -> F -> C -> B (A is head, B is tail)

    stops.clear();
    int i = 0;
    for (BusStop stop: inbound)
    {
        if (i == inbound.size() - 1) break;
        stops.add(stop);
        i++;
    }

    int j = 0;
    for (BusStop stop: outbound)
    {
        if (j == outbound.size() - 1) break;
        stops.add(stop);
        j++;
    }

    outboundCount = outbound.size();
    built = true;
}

int BusRoute::getHopCount(string fromStopId, string toStopId, Direction direction)
{
    // TODO Q3

    SLinkedList<BusStop> route;
    for (int i = 0; i < getStopCount(direction); i++)
    {
        route.add(getStop(i, direction));
    }

    int first_stop_idx = route.indexOf(BusStop(fromStopId));
    int last_stop_idx = route.indexOf(BusStop(toStopId));

    if (first_stop_idx == -1 || last_stop_idx == -1 || last_stop_idx < first_stop_idx)
        return -1;
    else
        return last_stop_idx - first_stop_idx;
}
