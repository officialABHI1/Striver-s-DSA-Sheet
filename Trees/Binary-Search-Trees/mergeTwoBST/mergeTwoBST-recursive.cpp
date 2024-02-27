#include <iostream>

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL){
            return root2;
        }

        if(root2==NULL){
            return root1;
        }

        root1->val+=root2->val;

        root1->left = mergeTrees(root1->left,root2->left);

        root1->right = mergeTrees(root1->right,root2->right);

        return root1;
    } 
};

int main() {
    // Create nodes for the binary trees
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3, node1, nullptr);
    TreeNode* node4 = new TreeNode(4, nullptr, node2);
    TreeNode* node5 = new TreeNode(5, node3, node4);

    // Create the binary trees
    TreeNode* root1 = node5;
    TreeNode* root2 = new TreeNode(1, new TreeNode(3), new TreeNode(2));

    // Create a Solution object
    Solution solution;

    // Call the mergeTrees function
    TreeNode* mergedRoot = solution.mergeTrees(root1, root2);

    // Print the value of the root of the merged tree
    std::cout << "The value of the root of the merged tree is " << mergedRoot->val << ".";

    return 0;
}
