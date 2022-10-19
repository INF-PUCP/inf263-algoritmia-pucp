// https://leetcode.com/problems/course-schedule/
class Solution {
public:
    vector<int> done;
    vector<vector<int>> adj;
    bool ok = true;
    void Initialize(int n) {
        done = vector<int>(n, 0);
        adj = vector<vector<int>>(n);
    }
    
    void DFS(int u) {
        done[u] = 1;
        for (int v : adj[u]) {
            if (done[v] == 0) {
                DFS(v);
            } else if (done[v] == 1) {
                ok = false;
            }
        }
        done[u] = 2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n_courses = numCourses;
        Initialize(n_courses);
        int n_prerequisites = (int)prerequisites.size();
        for (int i = 0; i < n_prerequisites; i++) {
            int to = prerequisites[i][0];
            int from = prerequisites[i][1];
            adj[from].push_back(to);
        }
        for (int i = 0; i < n_courses; i++) {
            if (done[i] == 0) {
                DFS(i);
            }
        }
        return ok;
    }
};
