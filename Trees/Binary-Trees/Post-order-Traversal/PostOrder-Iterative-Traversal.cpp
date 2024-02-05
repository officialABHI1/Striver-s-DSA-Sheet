/*
    In this approach we do the Iterative PostOrder Traversal for tree using Two stacks

            5
        10    20
      11  13

      Time Complexity:  O(N)
      Space Complexity: O(depth) == O(2N) ~ O(N) -in worst Case - Skewed Tree & Extra O(N) stack space to print the nodes

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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;

        if(root==nullptr)
        return ans;

        stack<TreeNode*>st1,st2;

       // TreeNode *curr =root;

        st1.push(root);

        while(!st1.empty()){
            TreeNode *curr =st1.top();

            st2.push(curr);

            st1.pop();

            if(curr->left)
            st1.push(curr->left);

            if(curr->right)
            st1.push(curr->right);
        }

        while(!st2.empty()){
            TreeNode* temp =st2.top();

            ans.push_back(temp->val);

            st2.pop();
        }

        return ans;
        
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
  
    vector<int> PostOrder = s.postorderTraversal(root);

  
    cout << "Postorder Traversal: ";
    for (int i : PostOrder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
