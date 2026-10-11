#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "ISort.h"
#include <stdexcept>
using namespace std;



template<class T>
class QuickSort : public ISort<T> {
private:

    int (*pivotSelection)(T* first, int size);

public:

    QuickSort(int (*pivotSelection)(T*, int) = 0): pivotSelection(pivotSelection) {}

    void sort(T array[], int size, int (*comparator)(T&, T&) = 0) override 
    {
        // TODO Q4

        quickSort(array, 0, size - 1, comparator);
    }

private:

    void quickSort(T array[], int left, int right, int (*comparator)(T&, T&) = 0) 
    {
        // TODO Q4

        if ((right - left + 1) <= 1)
            return;

        int mid = partition(array, left, right, comparator);
        quickSort(array, left, mid - 1, comparator);
        quickSort(array, mid + 1, right, comparator);
    }

    void swap(T& a, T& b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    int partition(T array[], int left, int right, int (*comparator)(T&, T&) = 0)
    {
        // TODO Q4

        // ascending:
        // a < b  => -1
        // a == b => 0
        // a > b  => 1

        // descending:
        // a < b  => 1
        // a == b => 0
        // a > b  => -1

        int (*less_than)(T&, T&) = (
            comparator != nullptr        ?
            comparator                   :
            [](T& a, T& b) { return (a < b? -1: (a > b? 1: 0)); }
        );

        int pivot = (
            pivotSelection                                                  ? 
            left + pivotSelection(array, right - left + 1)      :
            right
        );

        swap(array[pivot], array[right]);
        int i = left - 1;
        int j = left;

        while (j < right)
        {
            if (less_than(array[j], array[right]) == -1)
            {
                i++;
                swap(array[j], array[i]);
            }
            j++;
        }

        i++;
        swap(array[i], array[right]);
        return i;
    }
};

template class QuickSort<int>;

#endif
