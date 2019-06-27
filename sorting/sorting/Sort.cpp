#include"pch.h"
#include "Sort.h"

void Sort::merge(vector<int>& vec, int left, int middle, int right)
{
    queue<int> queueLeft;
    queue<int> queueRight;

    for (int index = left; index <= middle; ++index)
        queueLeft.push(vec[index]);

    for (int index = middle + 1; index <= right; ++index)
        queueRight.push(vec[index]);

    int indexVec = left;
    while (queueLeft.size() || queueRight.size())
    {
        int min = 0;
        if (queueLeft.size() && queueRight.size())
        {
            if (queueLeft.front() < queueRight.front())
            {
                min = queueLeft.front();
                queueLeft.pop();
            }
            else
            {
                min = queueRight.front();
                queueRight.pop();
            }
            vec[indexVec++] = min;
        }
        else if (queueLeft.size())
        {
            vec[indexVec++] = queueLeft.front();
            queueLeft.pop();
        }
        else if (queueRight.size())
        {
            vec[indexVec++] = queueRight.front();
            queueRight.pop();
        }
    }

}

void Sort::mergeSort(vector<int>& vec, int left, int right)
{
    if (left >= right)
        return;

    int middle = (left + right) / 2;

    mergeSort(vec, left, middle);
    mergeSort(vec, middle + 1, right);

    merge(vec, left, middle, right);
}

void Sort::selectionSort(vector<int>& vec, bool increasingOrder)
{
    size_t n = vec.size();
    for (size_t index1 = 0; index1 < n - 1; ++index1)
    {
        for (size_t index2 = index1 + 1; index2 < n; ++index2)
        {
            if (increasingOrder)
            {
                if (vec[index1] > vec[index2])
                    swap(vec[index1], vec[index2]);
            }
            else
            {
                if (vec[index1] < vec[index2])
                    swap(vec[index1], vec[index2]);
            }
        }
    }
}

void Sort::bubbleSort(vector<int>& vec, bool increasingOrder)
{
    size_t n = vec.size();
    for (size_t index1 = 0; index1 < n - 1; ++index1)
    {
        for (size_t index2 = 0; index2 < n - index1 - 1; ++index2)
        {
            if (increasingOrder)
            {
                if (vec[index2] > vec[index2+1])
                    swap(vec[index2], vec[index2 + 1]);
            }
            else
            {
                if (vec[index2] < vec[index2+1])
                    swap(vec[index2], vec[index2 + 1]);
            }
        }
    }
}

void Sort::insert(vector<int>& vec, int vecSize, int value, bool increasingOrder)
{
    int index = 0;
    while ((increasingOrder && index < vecSize && vec[index] < value) || (!increasingOrder && index < vecSize && vec[index] > value))
        index++;

    for (int index2 = vecSize - 1; index2 >= index; index2--)
    {
        vec[index2 + 1] = vec[index2];
    }

    vec[index] = value;
}

void Sort::insertionSort(vector<int>& vec, bool increasingOrder)
{
    size_t n = vec.size();
    for (size_t index = 1; index < n; ++index)
    {
        insert(vec, index, vec[index], increasingOrder);
    }
}