// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MergeSort.h"

int main()
{
    std::vector<int> arr = { 38,27,43,3,9,82,10, 22, 1 ,2, 3,111, 3,124};
    mergeSort(arr, 0, static_cast<int>(arr.size() - 1));
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
