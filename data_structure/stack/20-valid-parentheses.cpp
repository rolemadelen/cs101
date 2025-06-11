class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return false;
        if(s.size() & 1 == 1) return false;

        const int SIZE = s.size();
        stack<char> stk;

        for(int i=0; i<SIZE; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) return false;
                else if (s[i] == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (s[i] == ']' && stk.top() == '[') {
                    stk.pop();
                } else if (s[i] == '}' && stk.top() == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};