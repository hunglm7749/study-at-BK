#include <iostream>


#include "SLinkedList.h"
#include "CircularLinkedList.h"
#include "QuickSort.h"



std::string toString(int const* arr, int size)
{
    std::ostringstream ss;
    ss << '[';
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
            ss << arr[i] << ", ";
        else
            ss << arr[i];
    }
    ss << ']';
    return ss.str();
}

static int customPivot(int*, int size)
{
    return size > 0 ? 0 : 0;
}


int main()
{
    #pragma region LinkedList

    /*std::cout << "\n";
    std::cout << "==============================================================================================\n";
    std::cout << "SECTION 1:                     SLinkedList                                                    \n";
    std::cout << "==============================================================================================\n";

    // empty list
    //std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;

        std::cout << "\e[38;2;238;230;158m" << "empty list:" << "\e[0m" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // add(item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;

        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data)
        {
            list.add(item);
        }

        std::cout << "\e[38;2;238;230;158m"  << "add(item):" << "\e[0m" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // add(2, item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        list.add(-30);
        list.add(-40);
        list.add(-50);

        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data)
        {
            list.add(2, item);
        }

        std::cout << "\e[38;2;238;230;158m"  << "add(2, item):" << "\e[0m" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // add(0, item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        list.add(-30);
        list.add(-40);
        list.add(-50);

        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data)
        {
            list.add(0, item);
        }

        std::cout << "\e[38;2;238;230;158m"  << "add(0, item):" << "\e[0m" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // add(-1, item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        list.add(-30);
        list.add(-40);
        list.add(-50);

        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

        try
        {
            for (int item: data)
            {
                list.add(-1, item);
            }
        }
        catch (std::out_of_range) {}

        std::cout << "\e[38;2;238;230;158m"  << "add(-1, item):" << "\e[0m" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // add(size(), item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        list.add(-30);
        list.add(-40);
        list.add(-50);

        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data)
        {
            list.add(list.size(), item);
        }

        std::cout << "\e[38;2;238;230;158m"  << "add(size(), item):" << "\e[0m" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // add(size() + 1, item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        list.add(-30);
        list.add(-40);
        list.add(-50);

        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

        try
        {
            for (int item: data)
            {
                list.add(list.size(), item);
            }
        } 
        catch (std::out_of_range) {}

        std::cout << "\e[38;2;238;230;158m"  << "add(size() + 1, item):" << "\e[0m" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // removeAt(index)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140  };
        int removelist[] = { 0, 0, 1, 1, 14 - 5, 14 - 6, 4, 5 };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "removeAt(index):" << "\e[0m" << std::endl;
        std::cout << "list:     " << list.toString() << std::endl;
        for (int index: removelist)
        {
            std::cout << "rm [" << index << "] => ";
            list.removeAt(index);
            std::cout << list.toString() << std::endl;
            std::cout << "size: " << list.size() << std::endl;
        }
    }

    // removeAt(0)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140  };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "removeAt(0):" << "\e[0m" << std::endl;
        std::cout << "list:     " << list.toString() << std::endl;
        while (list.size() > 0)
        {
            std::cout << "rm [0] => ";
            list.removeAt(0);
            std::cout << list.toString() << std::endl;
            std::cout << "size: " << list.size() << std::endl;
        }
    }

    // removeAt(2)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140  };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "removeAt(2):" << "\e[0m" << std::endl;
        std::cout << "list:     " << list.toString() << std::endl;
        while (list.size() > 2)
        {
            std::cout << "rm [2] => ";
            list.removeAt(0);
            std::cout << list.toString() << std::endl;
            std::cout << "size: " << list.size() << std::endl;
        }
    }

    // removeAt(size() - 1)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140  };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "removeAt(size() - 1):" << "\e[0m" << std::endl;
        std::cout << "list:     " << list.toString() << std::endl;
        while (list.size() > 0)
        {
            std::cout << "rm [last_idx] => ";
            list.removeAt(list.size() - 1);
            std::cout << list.toString() << std::endl;
            std::cout << "size: " << list.size() << std::endl;
        }

        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "second round:" << "\e[0m" << std::endl;
        std::cout << "list:     " << list.toString() << std::endl;
        while (list.size() > 0)
        {
            std::cout << "rm [last_idx] => ";
            list.removeAt(list.size() - 1);
            std::cout << list.toString() << std::endl;
            std::cout << "size: " << list.size() << std::endl;
        }
    }

    // remove(80)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 80, 20, 30, 40, 80, 60, 70, 80, 80, 100, 110, 120, 130, 80  };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "remove(80):" << "\e[0m" << std::endl;
        std::cout << "list:     " << list.toString() << std::endl;
        while (true)
        {
            bool success = list.removeItem(80);
            if (!success) break;
            std::cout << "rm '80' => ";
            std::cout << list.toString() << std::endl;
            std::cout << "size: " << list.size() << std::endl;
        }
    }

    // remove(80) (with removeItemData)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 80, 20, 30, 40, 80, 60, 70, 80, 80, 100, 110, 120, 130, 80  };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "remove(80) (with removeItemData):" << "\e[0m" << std::endl;
        std::cout << "list:     " << list.toString() << std::endl;
        while (true)
        {
            bool success = list.removeItem(80,
                [](int a) {
                    std::cout << "\e[38;2;215;119;87mhello world!\e[0m (we just removed: " << a << ") " << std::endl;
                }
            );
            if (!success) break;
            std::cout << "rm '80' => ";
            std::cout << list.toString() << std::endl;
            std::cout << "size: " << list.size() << std::endl;
        }
    }

    // remove(item) success/fail
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 80, 20, 30, 40, 80, 60, 70, 80, 80, 100, 110, 120, 130, 80  };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "remove() success/fail:" << "\e[0m" << std::endl;
        std::cout << "list: " << list.toString() << std::endl;
        std::cout << std::boolalpha << "rm \'-9981\' => " << list.removeItem(-9981) << std::endl;
        std::cout << "list: " << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
        std::cout << std::boolalpha << "rm \'60\'    => " << list.removeItem(60) << std::endl;
        std::cout << "list: " << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // clear()
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 80, 20, 30, 40, 80, 60, 70, 80, 80, 100, 110, 120, 130, 80  };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "clear():" << "\e[0m" << std::endl;
        std::cout << "list:    " << list.toString() << std::endl;
        std::cout << "clear => ";
        list.clear();
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;

        std::cout << "second round\n";
        for (int item: data) { list.add(item); }
        std::cout << "list:    " << list.toString() << std::endl;
        std::cout << "clear => ";
        list.clear();
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // get(index)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 0, 2, 4, 6, 8, 10 };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "get(index):" << "\e[0m" << std::endl;
        std::cout << "list:    " << list.toString() << std::endl;
        for (int i = 0; i < list.size(); i++)
        {
            std::cout << "list[" << i << "] = " << list.get(i) << std::endl;
        }
    }

    // indexOf(item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        SLinkedList<int> list;
        int data[] = { 9, 3, 6, -5 };
        int tofind[] = { 9, 6, 0, 7, -5 };
        for (int item: data) { list.add(item); }

        std::cout << "\e[38;2;238;230;158m"  << "indexOf(item):" << "\e[0m" << std::endl;
        std::cout << "list:    " << list.toString() << std::endl;

        for (int item: tofind)
        {
            std::cout << "where \'" << item << "\' => " << list.indexOf(item) << std::endl;
        }
    }*/

    #pragma region CircularList

    /*std::cout << "\n";
    std::cout << "==============================================================================================\n";
    std::cout << "SECTION 2:                     CircularLinkedList                                             \n";
    std::cout << "==============================================================================================\n";
    
    // empty list
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;

        std::cout << "\e[38;2;238;230;158m" << "empty list:" << "\e[0m\n" << std::endl;
        std::cout << list.toString() << std::endl;
        std::cout << "size: " << list.size() << std::endl;
    }

    // add(item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        std::cout << "\e[38;2;238;230;158m"  << "add(item):" << "\e[0m\n" << std::endl;

        for (int item: data)
        {
            list.add(item);
            std::cout << "add " << item << " => " << list.toString() << std::endl;
            std::cout << "------------\n";
            std::cout << "size: " << list.size() << "\n\n";
        }
    }

    using Node = CircularLinkedList<int>::Node;

    // add(item) circularity
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

        std::cout << "\e[38;2;238;230;158m"  << "add(item) circularity:" << "\e[0m\n" << std::endl;
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";

        std::cout << "list: " << list.toString() << "\n\n";

        for (int item: data)
        {
            list.add(item);
            std::cout << "add " << item << " => " << list.debugString([](int x) { return 3 * x; }) << std::endl;
        }
    }

    // add(2, item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        list.add(-30);
        list.add(-40);
        list.add(-50);
        list.add(-60);
        list.add(-70);

        std::cout << "\e[38;2;238;230;158m"  << "add(2, item):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";

        std::cout << "list: " << list.debugString() << "\n\n";
        
        for (int item: data)
        {
            list.add(2, item);
            std::cout << "add " << item << " at 2 => " << list.debugString([](int x) { return x + 3; }) << std::endl;
        }
    }

    // add(0, item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

        std::cout << "\e[38;2;238;230;158m"  << "add(0, item):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";

        std::cout << "list: " << list.toString() << "\n\n";
        
        for (int item: data)
        {
            list.add(0, item);
            std::cout << "add " << item << " at 0 => " << list.debugString([](int x) { return x + 3; }) << std::endl;
        }
    }

    // add(size(), item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

        std::cout << "\e[38;2;238;230;158m"  << "add(size(), item):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";

        std::cout << "list: " << list.toString() << "\n\n";
        
        for (int item: data)
        {
            list.add(list.size(), item);
            std::cout << "add " << item << " at " << list.size() << " => " << list.debugString([](int x) { return x + 3; }) << std::endl;
        }
    }

    // removeAt(2)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data) list.add(item);

        std::cout << "\e[38;2;238;230;158m"  << "removeAt(2):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";
        std::cout << "list:              " << list.debugString([](int x) { return x + 3; }) << "\n\n";

        while (list.size() > 2)
        {
            int item = list.removeAt(2);
            std::cout << "removed " << item << " at 2 => " << list.debugString([](int x) { return x + 3; }) << std::endl;
        }
    }

    // removeAt(0)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data) list.add(item);

        std::cout << "\e[38;2;238;230;158m"  << "removeAt(0):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";
        std::cout << "list:              " << list.debugString([](int x) { return 3 * x; }) << "\n\n";

        while (list.size() > 0)
        {
            int item = list.removeAt(0);
            std::cout << "removed " << item << " at 0 => " << list.debugString([](int x) { return 3 * x; }) << std::endl;
        }
    }

    // removeAt(size() - 1)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data) list.add(item);

        std::cout << "\e[38;2;238;230;158m"  << "removeAt(size() - 1):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";
        std::cout << "list:              " << list.debugString([](int x) { return 3 * x; }) << "\n\n";

        while (list.size() > 0)
        {
            int item = list.removeAt(list.size() - 1);
            std::cout << "removed " << item << " at 0 => " << list.debugString([](int x) { return 3 * x; }) << std::endl;
        }
    }

    // removeItem(item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 30, 10, 20, 30, 40, 50, 60, 30, 70, 80, 30 };
        for (int item: data) list.add(item);

        std::cout << "\e[38;2;238;230;158m"  << "removeItem(item):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";
        std::cout << "list:         " << list.debugString([](int x) { return x + 3; }) << "\n\n";

        while (true)
        {
            bool res = list.removeItem(30);

            if (res == false)
            {
                std::cerr << "cant find item " << 30 << std::endl;
                break;
            }
            
            std::cout << "removed " << 30 << " => " << list.debugString([](int x) { return x + 3; }) << std::endl;
        }
    }

    // clear()
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 30, 10, 20, 30, 40, 50, 60, 30, 70, 80, 30 };
        for (int item: data) list.add(item);

        std::cout << "\e[38;2;238;230;158m"  << "removeItem(item):" << "\e[0m\n\n";
        std::cout << "orange = head\n";
        std::cout << "blue = tail\n\n";
        std::cout << "list: " << list.debugString([](int x) { return x + 3; }) << "\n\n";

        list.clear();
        std::cout << "clear => " << list.debugString([](int x) { return x + 3; }) << std::endl;
    }

    // get(index)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data) list.add(item);

        std::cout << "\e[38;2;238;230;158m"  << "get(index):" << "\e[0m\n\n";
        std::cout << "list: " << list.debugString([](int x) { return x + 3; }) << "\n\n";

        for (int i = 0; i < list.size(); i++)
        {
            std::cout << "list[" << i << "] = " << list.get(i) << std::endl;
        }
    }

    // indexOf(item)
    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        CircularLinkedList<int> list;
        int data[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
        for (int item: data) list.add(item);

        std::cout << "\e[38;2;238;230;158m"  << "get(index):" << "\e[0m\n\n";
        std::cout << "list: " << list.debugString([](int x) { return x + 3; }) << "\n\n";

        std::cout << "where 70 => " << list.indexOf(70) << std::endl;
        std::cout << "where 90 => " << list.indexOf(90) << std::endl;
        std::cout << "where 75 => " << list.indexOf(75) << std::endl;
        std::cout << "where 80 => " << list.indexOf(80) << std::endl;
        std::cout << "where 0 => " << list.indexOf(0) << std::endl;
        std::cout << "where 10 => " << list.indexOf(10) << std::endl;
    }*/

    #pragma region QuickSort

    /*std::cout << "\n";
    std::cout << "==============================================================================================\n";
    std::cout << "SECTION 3:                            QuickSort                                               \n";
    std::cout << "==============================================================================================\n";


    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {8,3,5,1,7,0,5,2,5};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {10, 5, 8, 9, 3, 6, 15, 12, 16};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {1, 2, 3, 5, 4, 6, 7, 9, 8, 10};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {9999, 1, 2, 3, 4, 5, 6, 7, 8};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {-5, 12, -20, 0, 15, -3, 0, 8, -1};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {9, 7, 5, 3, 1, 2, 4, 6, 8};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {45, 12, 89, 3, 27, 64, 12, 90, 33, 5, 71};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 42 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;   
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 4, 1 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 0, 1, 2, 3, 4, 5,6, 7, 8, 9 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 4, 4, 4, 4, 4, 4,4 ,4 ,4 ,4 ,4 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter;
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n";
    std::cout << "==============================================================================================\n";
    std::cout << "SECTION 4:                       QuickSort (custom pivot)                                     \n";
    std::cout << "==============================================================================================\n";

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {8,3,5,1,7,0,5,2,5};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {10, 5, 8, 9, 3, 6, 15, 12, 16};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {1, 2, 3, 5, 4, 6, 7, 9, 8, 10};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {9999, 1, 2, 3, 4, 5, 6, 7, 8};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {-5, 12, -20, 0, 15, -3, 0, 8, -1};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {9, 7, 5, 3, 1, 2, 4, 6, 8};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = {45, 12, 89, 3, 27, 64, 12, 90, 33, 5, 71};
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 42 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;   
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 4, 1 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 0, 1, 2, 3, 4, 5,6, 7, 8, 9 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        int arr[] = { 4, 4, 4, 4, 4, 4,4 ,4 ,4 ,4 ,4 };
        std::cout << "original: " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;

        QuickSort<int> sorter(customPivot);
        sorter.sort(arr, sizeof(arr) / sizeof(int));
        std::cout << "sorted:   " << toString(arr, sizeof(arr) / sizeof(int)) << std::endl;
    }*/


    #pragma region String Order

    /*std::cout << "\n";
    std::cout << "==============================================================================================\n";
    std::cout << "SECTION 4:                               String Order                                         \n";
    std::cout << "==============================================================================================\n";

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        std::string s1 = "Apple";
        std::string s2 = "apple";
        
        std::cout << "s1 = " << s1 << std::endl;
        std::cout << "s2 = " << s2 << std::endl;
        std::cout << "s1 < s2 => " << std::boolalpha << (s1 < s2) << std::endl;
        std::cout << "s1 = s2 => " << std::boolalpha << (s1 == s2) << std::endl;
        std::cout << "s1 = s2 => " << std::boolalpha << (s1 > s2) << std::endl;
    }

    std::cout << "\n------------------------------------------------------------------------------------\n";
    {
        std::string s1 = "Apple";
        std::string s2 = "Apple pencil";
        
        std::cout << "s1 = " << s1 << std::endl;
        std::cout << "s2 = " << s2 << std::endl;
        std::cout << "s1 < s2 => " << std::boolalpha << (s1 < s2) << std::endl;
        std::cout << "s1 = s2 => " << std::boolalpha << (s1 == s2) << std::endl;
        std::cout << "s1 = s2 => " << std::boolalpha << (s1 > s2) << std::endl;
    }*/


    std::cout << "\n------------------------------------------------------------------------------------\n";
    return 0;
}
