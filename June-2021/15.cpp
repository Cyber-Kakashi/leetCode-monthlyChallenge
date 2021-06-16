// MatchSticks to square

class Solution {
public:
    
    bool makesquare(vector<int>& matchsticks) {
        int target;
        int perimeter = 0;
        vector<int> sides(4, 0);
        
        if (matchsticks.size() < 4) return false;
        
        for (auto match : matchsticks) {
            perimeter += match;
        }
        
        if (!perimeter % 4) return false;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        target = perimeter/4;
        
        return checkSides(sides, matchsticks, target, 0);
        
    }
    
    bool checkSides(vector<int>& sides, vector<int>& m, int target, int index) {
        if (index == m.size()) {
            return sides[0] == sides[1] and sides[1] == sides[2] and sides[2] == sides[3];
        }
        
        for (int i = 0; i < 4; i++) {
            if (sides[i] + m[index] <= target) {
                sides[i] += m[index];
                if (checkSides(sides, m, target, index+1))
                    return true;
                sides[i] -= m[index];
            }
        }
        
        return false;
    }
};