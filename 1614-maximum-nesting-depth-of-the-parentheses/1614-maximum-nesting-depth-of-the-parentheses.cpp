class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = INT_MIN;
        for(char c : s){
            if(c == '('){
                st.push(c);
                maxDepth = max(maxDepth, (int)st.size());
            }else if(c == ')' && !st.empty()) st.pop();
        }
        return maxDepth == INT_MIN? 0 : maxDepth;
    }
};