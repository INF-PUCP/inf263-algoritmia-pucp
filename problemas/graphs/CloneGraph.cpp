/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
map<int, Node*> is_visited;

public:
  Node* DFS(Node* node) {
    Node* from = new Node(node->val);
    is_visited[node->val] = from;
    int len = node->neighbors.size();
    for (Node* to : node->neighbors) {
      if (is_visited.count(to->val) == 0) {
        (from->neighbors).push_back(DFS(to));
      } else {
        (from->neighbors).push_back(is_visited[to->val]);
      }
    }
    return from;
  }

  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    is_visited.clear();
    return DFS(node);
  }
};
