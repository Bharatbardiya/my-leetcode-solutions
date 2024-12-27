class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> op = {"+", "-", "/", "*"};
        stack<int> st;
        for (auto s : tokens) {
            if (op.count(s)) {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                int ans = 0;
                if (s == "+") {
                    ans = x2 + x1;
                } else if (s == "-") {
                    ans = x2 - x1;
                } else if (s == "*") {
                    ans = x2 * x1;
                } else {
                    ans = x2 / x1;
                }
                st.push(ans);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};