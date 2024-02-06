
class Solution {
public:

    int leafNodesCount(TreeNode* root) {
      
      int count =0;
      
      if(root==NULL)
      {
        return 0;
      }
      
      if(root!=NULL && root->left ==nullptr && root->right==nullptr){
        return 1;
      } 
      
      int leftCount  =leafNodesCount(root->left)+count;
      int rigthCount =leafNodesCount(root->right)+count;
      
      return leftCount+rigthCount;
      
    }
};