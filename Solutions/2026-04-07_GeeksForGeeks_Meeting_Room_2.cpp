/*

Problem Name   : Meeting Room 2
Platform       : GeeksForGeeks
Topic          : Heap, Greedy, Sorting, Two Pointers, Arrays, Intervals
Problem Link   : https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-07
Time           : O(NlogN)
Space          : O(N)

*/

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        map<int, int> events;
        int n = start.size();
        for(int i= 0; i<n; i++){
            events[start[i]]++;
            events[end[i]]--;
        }
        
        int overlaps = 0;
        int maxOverlaps = 0;
        
        for(auto &it: events){
            overlaps += it.second;
            maxOverlaps = max(maxOverlaps, overlaps);
        }
        return maxOverlaps;
    }
    
};
