// sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "Sort.h"

using namespace std;

int main()
{
    vector<int> vec = {38, 27, 43, 3, 9, 82, 10};

    //Sort::mergeSort(vec, 0, vec.size() - 1);
    //Sort::selectionSort(vec, true);
    //Sort::bubbleSort(vec, true);
    Sort::insertionSort(vec, true);

    for (int el : vec)
        cout << el << " ";
}