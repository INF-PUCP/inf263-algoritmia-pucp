class Solution {
public:
  vector<vector<int>> nxt;
  vector<vector<bool>> dp, done;
  
  bool DP(int pos, int jump, const vector<int>& a) {
    if (pos == (int) a.size() - 1) return true;
    if (done[pos][jump]) return dp[pos][jump];
    if (nxt[pos][jump] == -1) {
      dp[pos][jump] = false;
    } else {
      dp[pos][jump] = DP(nxt[pos][jump], jump ^ 1, a);
    }
    done[pos][jump] = true;
    return dp[pos][jump];
  }
  
  int FindNext(int target, const map<int, int>& positions) {
    auto it = positions.lower_bound(target);
    if (it == positions.end()) return -1;
    return it->second;
  }
  
  int oddEvenJumps(vector<int>& arr) {
    int len = (int) arr.size();
    int cnt = 0;
    nxt = vector<vector<int>>(len, vector<int>(2, -1));
    dp = vector<vector<bool>>(len, vector<bool>(2, false));
    done = vector<vector<bool>>(len, vector<bool>(2, false));
    map<int, int> positions, negative_positions;
    for (int i = len - 1; i >= 0; i--) {
      nxt[i][1] = FindNext(arr[i], positions);
      nxt[i][0] = FindNext(-arr[i], negative_positions);
      positions[arr[i]] = i;
      negative_positions[-arr[i]] = i;
    }
    for (int i = 0; i < len; i++) {
      if (DP(i, 1, arr)) {
        cnt++;
      }
    }
    return cnt;
  }
};
