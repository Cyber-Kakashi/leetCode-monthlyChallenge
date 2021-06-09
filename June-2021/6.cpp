// Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (!nums.size()) return 0;
        
        unordered_set<int> memo(nums.begin(), nums.end());
        int maxStreak = 1;
        int currentStreak = 1;
        int temp;
        
        for (auto num : memo) {
            if (memo.find(num - 1) == memo.end()) {
                temp = num + 1;
                while (memo.find(temp++) != memo.end()) {
                    currentStreak++;
                }
                
                maxStreak = max(maxStreak, currentStreak);
                currentStreak = 1;
            }
        }
        
        return maxStreak;
    }
};