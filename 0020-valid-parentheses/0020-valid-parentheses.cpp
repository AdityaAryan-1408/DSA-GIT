class Solution {
public:
    bool isValid(string& s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            if (!st.empty() && (curr == ')' && st.top() == '(' ||
                                curr == '}' && st.top() == '{' ||
                                curr == ']' && st.top() == '[')) {
                st.pop();
            } else {
                st.push(curr);
            }
        }
        return st.empty();
    }
};