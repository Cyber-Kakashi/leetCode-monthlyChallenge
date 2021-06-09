// Jump Game VI
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> memo;
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1]= nums[n-1];
        memo.push_back(n - 1);
        
        for (int i = n - 2; i >= 0; i--) {
            if (memo.size() && (memo.front()-i > k)) memo.pop_front();
            dp[i] = nums[i] + dp[memo.front()];
            while (memo.size() && (dp[memo.back()] < dp[i])) memo.pop_back();
            memo.push_back(i);
        }
        
        return dp[0];
    }
};