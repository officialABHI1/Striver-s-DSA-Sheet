class Solution {
public:
    int maxDepth(TreeNode* root) {

        int hl,hr;

        if(root == NULL)
         return 0;

        hl= maxDepth(root->left);

        hr= maxDepth(root->right);

        return max(hl,hr)+1;
        
    }
};