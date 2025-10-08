
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};




class Solution {
    int i = 0;
    unordered_map<int, int> pos; // maps node value → index in postorder

    Node* build(vector<int>& pre, vector<int>& post, int l, int r) {
        if (i >= pre.size() || l > r) return nullptr;

        Node* root = new Node(pre[i++]);
        if (l == r || i >= pre.size()) return root;

        int k = pos[pre[i]]; 
        root->left = build(pre, post, l, k);
        root->right = build(pre, post, k + 1, r - 1);

        return root;
    }

  public:
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        pos.reserve(n);
        for (int j = 0; j < n; j++) pos[post[j]] = j;
        i = 0;
        return build(pre, post, 0, n - 1);
    }
};
