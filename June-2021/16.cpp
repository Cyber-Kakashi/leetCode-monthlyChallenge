// Generate Parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n; 
        int close = n;
        buildSet(open, close, "", ans);
        return ans;
    }
    
    void buildSet(int open, int close, string str, vector<string>& ans) {
        if (open == 0 and close == 0) {
            ans.push_back(str);
        } else {
            if (open > 0) {
                buildSet(open - 1, close, str + "(", ans);
            }
            if (close > 0 and (close - open)) {
                buildSet(open, close-1, str + ")", ans);
            }
        }
    }
};