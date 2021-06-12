// Minimum Number of Refueling Stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        int maxDistanceReachable = startFuel;
        priority_queue<int> refills;
        int stops = 0;
        for (int i = 0; i < stations.size(); i++) {
            while(!refills.empty() and maxDistanceReachable < stations[i][0]) {
                stops++;
                maxDistanceReachable += refills.top();
                refills.pop();
            }
            if (maxDistanceReachable < stations[i][0]) {
                return -1;
            }
            
            refills.push(stations[i][1]);
        }
        
        return stops;
    }
};