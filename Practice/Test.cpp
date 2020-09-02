#pragma once
#include <iostream> 
#include <queue> 

using namespace std; 

void showq(queue <int> gq)
{
    queue <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void Test2()
{
    queue <int> gquiz;
    gquiz.push(10);
}