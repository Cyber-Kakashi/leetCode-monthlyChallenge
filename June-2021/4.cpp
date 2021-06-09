// Open the Lock
class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    deque<pair<string, int>> memo = {{"0000", 0}};
    unordered_set<string> visited(deadends.begin(), deadends.end());
    if (target == "0000") return 0;
    int k = 3;
    while (memo.size()) {
      if (memo[0].first == target) {
        return memo[0].second;
      } else {
        if (visited.find(memo[0].first) == visited.end()) {
          updateMemo(memo, visited);
        } else {
          memo.pop_front();
        }
      }
    }

    return -1;
  }
  
  void updateMemo(deque<pair<string, int>>& memo, unordered_set<string>& visited) {
    string lock = memo[0].first;
    string temp = lock;
    for (int i = 0; i < 4; i++) {
      temp = lock;
      temp[i] = (char)((((int)(temp[i] - '0') + 1) % 10) + '0');
      if (visited.find(temp) == visited.end()) {
        memo.push_back({temp, memo[0].second + 1});
      }
      temp = lock;
      if (temp[i] == '0') {
        temp[i] = '9';
      } else {
        temp[i] = (char)((((int)(temp[i] - '0')) - 1) + '0');
      }
      
      if (visited.find(temp) == visited.end()) {
        memo.push_back({temp, memo[0].second + 1});
      }
    }
    visited.insert(memo[0].first);
    memo.pop_front();
  }
  
};