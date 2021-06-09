// Maximum Performance of a Team
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> memo;
        priority_queue<int, vector<int>, greater<int>> maxHeap;
        long sum = 0;
        long maxPerf = 0;
        for (int i = 0; i < speed.size(); i++) {
            memo.push_back({efficiency[i], speed[i]});
        }
        
        sort(memo.rbegin(), memo.rend());
        
        for (auto mem: memo) {
            sum += mem.second;
            maxHeap.push(mem.second);
            if (maxHeap.size() > k) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            
            maxPerf = max((sum*mem.first), maxPerf);
        }
        
        cout << sum;
        
        return maxPerf % (int)(1e9+7);
    }
};