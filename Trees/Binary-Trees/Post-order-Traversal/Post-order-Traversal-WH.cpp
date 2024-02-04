
#include <iostream>
#include <vector>
#include <stack>

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

    vector<int> helper(TreeNode * root, vector<int>&ans){
     
        if(root == NULL)
        {
            return {};
        }

        helper(root->left,ans);
        helper(root->right, ans);
        ans.push_back(root->val);

        return ans;
    }

    vector<int> postOrderTraversal(TreeNode* root) {
        
        vector<int>ans;

        TreeNode *curr = root;

        return helper(curr,ans);
       
    }
};


int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create a Solution object
    Solution s;
    // Get the inorder traversal
    vector<int> postOrder = s.postOrderTraversal(root);

    // Print the inorder traversal
    cout << "Postorder Traversal: ";
    for (int i : postOrder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}