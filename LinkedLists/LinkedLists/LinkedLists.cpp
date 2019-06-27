// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> linkedList;
    linkedList.push(2);
    linkedList.push(5);
    linkedList.push(3);

    linkedList.print();

    linkedList.reverse();
    linkedList.add(7, 2);
    linkedList.add(8, 0);

    linkedList.print();
}