/*
    In this approach we do the Iterative Inorder Traversal for tree

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
    
    vector<int> preorderTraversal(TreeNode* root) {
        

        vector<int>ans;

        if (root == nullptr) {
            return ans;
        }

        //TreeNode* curr = root;
        
        stack<TreeNode*>st;

        st.push(root);

        while(!st.empty()){

            TreeNode *curr = st.top();
            st.pop();

            ans.push_back(curr->val);
 
            if(curr->right!=NULL) 
            st.push(curr->right);

            if(curr->left!=NULL)
            st.push(curr->left);

          // *Note: We first push right child and left child after so that we can get let child first during the removal time
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
