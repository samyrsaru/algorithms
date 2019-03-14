/*

input:
{
    [1, 0, 0, 1, 0],
    [1, 0, 1, 0, 0],
    [0, 0, 1, 0, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 1, 1, 0]
}

Obs:
    0 - land
    1 - river
    nRows, nCols might differ

output : [1, 2, 2, 2, 5]*

*river sizes

*/

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool IsNodeVisited(int i, int j, const set < pair<int, int> >& setVisitedNodes);

bool CanMove(const vector<vector<int> >& matrix, const set < pair<int, int> >& setVisitedNodes, int i, int j);

void GetNodeRiverSize(const vector<vector<int> >& matrix, set < pair<int, int> >& setVisitedNodes, vector<int>& vecSizes, int i, int j, int& nSize);

vector<int> riverSizes(vector<vector<int> > matrix);

int main()
{
    // just 3 tests from algoexpert.io
    // test 1
    {
        vector<vector<int>> matrix =
        {
            {1, 0, 0, 1, 0},
            {1, 0, 1, 0, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 1, 1, 0}
        };
        vector < int > vecOutputExpected = { 1, 2, 2, 2, 5 };
        vector < int > vecOutput = riverSizes(matrix);
        sort(vecOutput.begin(), vecOutput.end());
        cout << "Test #1 : " << ((vecOutputExpected == vecOutput) ? "PASSED" : "FAILED" ) << "\n";
    }

    // test 2
    {
        vector<vector<int>> matrix = { {0} };
        vector< int > vecOutputExpected = {};
        vector < int > vecOutput = riverSizes(matrix);
        sort(vecOutput.begin(), vecOutput.end());
        cout << "Test #2 : " << ((vecOutputExpected == vecOutput) ? "PASSED" : "FAILED") << "\n";
    }

    // test 3
    {
        vector<vector<int>> matrix = { {1} };
        vector < int > vecOutputExpected = { 1 };
        vector < int > vecOutput = riverSizes(matrix);
        sort(vecOutput.begin(), vecOutput.end());
        cout << "Test #3 : " << ((vecOutputExpected == vecOutput) ? "PASSED" : "FAILED") << "\n";
    }

    return 0;
}

bool IsNodeVisited(int i, int j, const set < pair<int, int> >& setVisitedNodes)
{
    return setVisitedNodes.find(make_pair(i, j)) != setVisitedNodes.end();
}

bool CanMove(const vector<vector<int> >& matrix, const set < pair<int, int> >& setVisitedNodes, int i, int j)
{
    int nRows = matrix.size();
    if (i >= nRows || i < 0)
        return false;

    int nCols = matrix[i].size();

    if (j >= nCols || j < 0)
        return false;

    if (!matrix[i][j])
        return false;

    if (IsNodeVisited(i, j, setVisitedNodes))
        return false;

    return true;
}

void GetNodeRiverSize(const vector<vector<int> >& matrix, set < pair<int, int> >& setVisitedNodes, vector<int>& vecSizes, int i, int j, int& nSize)
{
    setVisitedNodes.insert(make_pair(i, j));
    nSize++;

    if (CanMove(matrix, setVisitedNodes, i, j + 1))
    {
        GetNodeRiverSize(matrix, setVisitedNodes, vecSizes, i, j + 1, nSize);
    }
    if (CanMove(matrix, setVisitedNodes, i, j - 1))
    {
        GetNodeRiverSize(matrix, setVisitedNodes, vecSizes, i, j - 1, nSize);
    }
    if (CanMove(matrix, setVisitedNodes, i - 1, j))
    {
        GetNodeRiverSize(matrix, setVisitedNodes, vecSizes, i - 1, j, nSize);
    }
    if (CanMove(matrix, setVisitedNodes, i + 1, j))
    {
        GetNodeRiverSize(matrix, setVisitedNodes, vecSizes, i + 1, j, nSize);
    }
}

vector<int> riverSizes(vector<vector<int> > matrix)
{
    vector<int> vecSizes = {};

    if (matrix.empty())
        return vecSizes;

    if (matrix[0].empty())
        return vecSizes;

    set < pair<int, int> > setVisitedNodes = {};

    int nRows = matrix.size();
    for (int i = 0; i < nRows; ++i)
    {
        int nCols = matrix[i].size();
        for (int j = 0; j < nCols; ++j)
        {
            int node = matrix[i][j];
            if (node)
            {
                if (IsNodeVisited(i, j, setVisitedNodes))
                    continue;

                int nSize = 0;
                GetNodeRiverSize(matrix, setVisitedNodes, vecSizes, i, j, nSize);

                vecSizes.push_back(nSize);
            }
        }
    }

    return vecSizes;
}