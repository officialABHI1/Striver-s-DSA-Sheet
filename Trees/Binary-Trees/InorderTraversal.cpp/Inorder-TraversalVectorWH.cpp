/*
    In this approach we do the Inorder Traversal for tree

            5
        10    20
      11  13

      with the help of helper function & manipulating the samee ans vector with each fun call

      Time Complexity:  O(N)
      Space Complexity: O(depth) == O(N) -in worst Case - Skewed Tree 

 */

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
        ans.push_back(root->val);
        helper(root->right, ans);

        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
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
    vector<int> inorder = s.inorderTraversal(root);

    // Print the inorder traversal
    cout << "Inorder Traversal: ";
    for (int i : inorder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}