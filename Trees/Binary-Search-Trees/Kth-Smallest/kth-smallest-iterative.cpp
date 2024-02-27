#include <bits/stdc++.h>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
        
        if(root!=NULL){

           helper(root->left,ans);
           ans.push_back(root->val);
           helper(root->right,ans);
        }

        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>ans;

        if(root==NULL){
            return 0;
        }

        ans = helper(root,ans);

        //sort(ans.begin(),ans.end());

        return ans[k-1];

    }
};


int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution solution;
    int k = 4; // Find the 2nd smallest element
    int result = solution.kthSmallest(root, k);

    cout << "The " << k << "nd smallest element in the binary search tree is: " << result << endl;

    return 0;
}