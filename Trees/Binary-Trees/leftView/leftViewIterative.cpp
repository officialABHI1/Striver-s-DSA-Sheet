#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> leftView(TreeNode* root) {
      
      vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        bool firstNode = true;

        while (sz--) {
            TreeNode *curr = q.front();
            q.pop();

            if (firstNode) {
                ans.push_back(curr->val);
                firstNode = false;
            }

            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
    }

    return ans;
  }
};

int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    
    // Create a Solution object
    Solution s;
  
    vector<int> ans = s.leftView(root);

    for(auto i: ans)
        cout << i << " ";
    cout << endl;

    return 0;
}
