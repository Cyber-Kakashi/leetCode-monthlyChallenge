// stone game VII
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>> memo(stones.size() + 1, vector<int>(stones.size() + 1, -1));
        int sum = 0;
        
        for (auto stone: stones) {
            sum += stone;
        }
        
        return compute(0, stones.size() - 1, memo, stones, sum);
    }
    
    int compute (int low, int high, vector<vector<int>>& memo, vector<int>& stones, int sum) {
        if (low == high) return 0;
        
        if (memo[low][high] != -1) {
            return memo[low][high];
        }
        
        return memo[low][high] = max(sum - stones[low] - compute(low + 1, high, memo, stones, sum - stones[low]), 
                                sum - stones[high] - compute(low, high - 1, memo, stones, sum - stones[high]));
    }
};