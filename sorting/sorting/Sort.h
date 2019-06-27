#pragma once
#include <vector>
#include <queue>
using namespace std;

class Sort {
private:
    static void merge(vector<int>& vec, int left, int middle, int right);
    static void insert(vector<int>& vec, int vecSize, int value, bool increasingOrder);
public :
    Sort() {}
    static void mergeSort(vector<int>& vec, int left, int right);
    static void selectionSort(vector<int>& vec, bool increasingOrder);
    static void bubbleSort(vector<int>& vec, bool increasingOrder);
    static void insertionSort(vector<int>& vec, bool increasingOrder);
};