/*

Problem Name   : Serialize and Deserialize Binary Tree
Platform       : LeetCode
Topic          : String, Tree, Depth-First Search, Breadth-First Search, Design, Binary Tree
Problem Link   : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-04-02
Approach       : BFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "N";
        string res;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (!node) {
                res += "N,";
            } else {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "N")
            return nullptr;
        Node* root = new Node(stoi(val));
        queue<Node*> q;
        q.push(root);
        while (getline(ss, val, ',')) {
            Node* node = q.front();
            q.pop();
            if (val != "N") {
                node->left = new Node(stoi(val));
                q.push(node->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                node->right = new Node(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
