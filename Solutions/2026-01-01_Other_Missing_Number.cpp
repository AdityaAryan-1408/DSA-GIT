/*

Problem Name   : Missing Number
Platform       : Other
Topic          : Math
Problem Link   : https://cses.fi/problemset/task/1083
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
    long long sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    long long res = n * (n + 1) / 2;
    cout << res - sum;
}

int main()
{
    fastIO();

    int tc;
    tc = 1;
    while (tc--)
    {
        solve();
    }

    return 0;
}