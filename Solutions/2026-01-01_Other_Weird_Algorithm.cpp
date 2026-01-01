/*

Problem Name   : Weird Algorithm
Platform       : Other
Topic          : Math
Problem Link   : https://cses.fi/problemset/task/1068
Type           : Practice
Difficulty     : Easy
Date Solved    : 2026-01-01

*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            cout << n << " ";
        }
        else
        {
            n = n * 3 + 1;
            cout << n << " ";
        }
    }
}

int main()
{
    fastIO();

    int tc;
    // cin >> tc;
    tc = 1;
    while (tc--)
    {
        solve();
    }

    return 0;
}