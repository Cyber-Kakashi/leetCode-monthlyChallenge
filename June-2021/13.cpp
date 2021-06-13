// Palindrome Pairs

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reverseMemo;
        vector<vector<int>> ans;
        
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            reverse(str.begin(), str.end());
            reverseMemo[str] = i;
        }
        
        if (reverseMemo.find("") != reverseMemo.end()) {
            for (int i = 0; i < words.size(); i++) {
                if (words[i].size() && isPalindrome(words[i])) {
                    ans.push_back({i, reverseMemo[""]});
                    ans.push_back({reverseMemo[""], i});
                }
            }
        }
        
        for (int i = 0; i < words.size(); i++) {
            string left, right;
            for (int j = 0; j < words[i].size(); j++) {
                left.push_back(words[i][j]);
                right = words[i].substr(j+1);
                int lc = reverseMemo.count(left);
                int rc = reverseMemo.count(right);
                if (lc and i != reverseMemo[left] and isPalindrome(right) and left.size()) {
                    ans.push_back({i, reverseMemo[left]});
                }
                if (rc and i != reverseMemo[right] and isPalindrome(left) and right.size()) {
                    ans.push_back({reverseMemo[right], i});
                }
            }
        }
        
        return ans;
    }
    
    bool isPalindrome(string str) {
        for (int i = 0; i < (str.size()/2); i++) {
            if (str[i] != str[str.size() - 1 - i]) return false;
        }
        
        return true;
    }
};