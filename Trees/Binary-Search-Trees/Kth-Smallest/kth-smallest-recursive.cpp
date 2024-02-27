#include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        
        if(root == NULL){
            return 0;
        }

        stack<TreeNode*> st;

        st.push(root);

        while(true){

            while(root){
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if(--k == 0){
                return root->val;
            }
         
            root = root->right;
        }
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