#include<bits/stdc++.h>
class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        map<char, int> mp;
        char ch = 'a';
        int val = 26;
        for(; ch<= 'z'; ch++)
            {
            mp[ch] = val;
                val--;
            }
        for(int i = 0; i< s.size(); i++)
            {
                int pos = i + 1;
                sum += pos * mp[s[i]];
            }
        return sum;
    }
};