// Min Cost Climbing Stairs
class Solution {
public:
    map<int, int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        return min(traverseStairs(cost, 0), traverseStairs(cost, 1));
    }
    
    int traverseStairs(vector<int>&cost, int index) {
        if (index < (int)cost.size()) {
            
            if (memo.find(index) != memo.end()) return memo[index];
            
            return memo[index] = cost[index] + min(traverseStairs(cost, index+1), 
                                  traverseStairs(cost, index+2));
             
        }
        
        return 0;
    }
};