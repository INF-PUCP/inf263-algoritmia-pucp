class Solution {
public:
  int INF = 1e8;
  int GetCost(int target, const vector<int>& tops, const vector<int>& bottoms) {
    int len = (int) tops.size();
    int cost = 0;
    for (int i = 0; i < len; i++) {
      if (tops[i] == target) continue;
      if (bottoms[i] == target) {
        cost++;
        continue;
      }
      return INF;
    }
    return cost;
  }
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int min_cost = INF;
    min_cost = min(min_cost, GetCost(tops[0], tops, bottoms));
    min_cost = min(min_cost, GetCost(tops[0], bottoms, tops));
    min_cost = min(min_cost, GetCost(bottoms[0], tops, bottoms));
    min_cost = min(min_cost, GetCost(bottoms[0], bottoms, tops));
    if (min_cost == INF) return -1;
    return min_cost;
  }
};