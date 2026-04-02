/*

Problem Name   : Serialize and Deserialize Binary Tree
Platform       : LeetCode
Topic          : String, Tree, Depth-First Search, Breadth-First Search, Design, Binary Tree
Problem Link   : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-04-02
Approach       : DFS
Time           : O(N)
Space          : O(N)

*/

using Node = TreeNode;
class Codec {
private:
    void dfsSerialize(Node* node, vector<string>& res) {
        if (!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    Node* dfsDeserialize(vector<string>& val, int& i) {
        if (val[i] == "N") {
            i++;
            return nullptr;
        }
        Node* node = new Node(stoi(val[i]));
        i++;
        node->left = dfsDeserialize(val, i);
        node->right = dfsDeserialize(val, i);
        return node;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> elements;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elements.push_back(item);
        }
        return elements;
    }

    string join(const vector<string>& v, const string& delim) {
        ostringstream s;
        for (const auto& i : v) {
            if (&i != &v[0]) {
                s << delim;
            }
            s << i;
        }
        return s.str();
    }

public:
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");
    }

    TreeNode* deserialize(string data) {
        vector<string> val = split(data, ',');
        int i = 0;
        return dfsDeserialize(val, i);
    }
};
