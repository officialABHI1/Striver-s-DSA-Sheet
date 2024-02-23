#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<int> helper(TreeNode *root, vector<int>&ans){
       
        if(root==NULL)
        {
            ans.push_back(101);
            return ans;
        }
        
        ans.push_back(root->val);
        if(root->left == NULL && root->right != NULL){
            ans.push_back(102); // different value for left null
        }
        helper(root->left,ans);
        if(root->right == NULL && root->left != NULL){
            ans.push_back(103); // different value for right null
        }
        helper(root->right,ans);

        return ans;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
      
        vector<int> tree1,tree2;

        if(p==NULL && q==NULL){
            return true;
        }
        else if(p!=NULL && q==NULL || p==NULL && q!=NULL){
            return false;
        }

        tree1 = helper(p,tree1);
        tree2 = helper(q,tree2);

        if(tree1==tree2){
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main() {
    // Create two binary trees
    TreeNode* p = new TreeNode(1);
    p->left = NULL;
    p->right = new TreeNode(1);

    TreeNode* q = new TreeNode(1);
    q->left = NULL;
    q->right = new TreeNode(1);

    // Check if the trees are identical
    Solution solution;
    bool result = solution.isSameTree(p, q);

    // Print the result
    if (result) {
        cout << "The trees are identical." << endl;
    }
    else {
        cout << "The trees are not identical." << endl;
    }

    // Free memory
    delete p->right;
    delete p;
    delete q->right;
    delete q;

    return 0;
}