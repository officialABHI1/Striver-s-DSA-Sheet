#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<int> helper(TreeNode *root,vector<int>&ans){
      
      //vector<int>ans;

      if(root!=NULL){

          helper(root->left,ans);

          ans.push_back(root->val);

          helper(root->right,ans);
      }
       return ans; 
    }

    bool isValidBST(TreeNode* root) {

        vector<int>v;
        
        if(root==NULL)
         return true;

        v = helper(root,v);

        int sz = v.size();

       // v.push_back(INT_MAX+1);

        
        for(int i=0;i<sz-1;i++){

            if(v[i]>=v[i+1]){
               return false;
            }
        }

        return true;

    }
};

int main() {
    // Create nodes for the binary tree
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4, node3, nullptr);
    TreeNode* node5 = new TreeNode(5, node1, node4);
    TreeNode* node6 = new TreeNode(6);

    // Create the binary tree
    TreeNode* root = node5;

    // Create a Solution object
    Solution solution;

    // Call the isValidBST function
    bool is_valid = solution.isValidBST(root);

    // Print the result
    if(is_valid) {
        cout << "The binary tree is a valid BST.";
    } else {
        cout << "The binary tree is not a valid BST.";
    }

    return 0;
}
