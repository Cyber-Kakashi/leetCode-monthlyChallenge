// Interleaving String

class Solution {
public:
    unordered_map<string, bool> memo;
    bool isInterleave(string s1, string s2, string s3) {
        int ss1 = s1.size();
        int ss2 = s2.size();
        int ss3 = s3.size();
        int p1 = 0, p2 = 0, p3 = 0;
        if (ss1 + ss2 != ss3) return false;
        
        return check(s1,s2,s3, ss1, ss2, ss3, p1, p2, p3);
    }
    
    bool check (string s1, string s2, string s3, int ss1, int ss2, int ss3, int p1, int p2, int p3) {
        if (p3 == ss3) {
            return (p1 == ss1 and p2 == ss2) ? true : false;
        }
        
        string key = to_string(p1) + "/" + to_string(p2) + "/" + to_string(p3);
        
        if (memo.find(key) != memo.end()) return memo[key];
        
        if (p1 == ss1) {
            return memo[key] = s2[p2] == s3[p3] ? check(s1, s2, s3, ss1, ss2, ss3, p1, p2+1, p3+1) : false;
        }
        
        if(p2 == ss2) {
            return memo[key] = s1[p1] == s3[p3] ? check(s1, s2, s3, ss1, ss2, ss3, p1+1, p2, p3+1) : false;
        }
        
        
        bool first = false, second = false;
        
        if (s1[p1] == s3[p3]) {
            first = check(s1, s2, s3, ss1, ss2, ss3, p1+1, p2, p3+1);
        }
        
        if (s2[p2] == s3[p3]) {
            second = check(s1, s2, s3, ss1, ss2, ss3, p1, p2+1, p3+1);
        }
        
        
        return memo[key] = first or second;
    }
};