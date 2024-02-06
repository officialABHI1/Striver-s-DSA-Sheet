
class Solution {
public:

    int helper(TreeNode* root,int count){
      
      if(root==NULL)
      {
        return count;
      }
      
      if(root!=NULL && root->left ==nullptr && root->right==nullptr){
        return count+1;
      } 
      
      int leftCount= helper(root->left,count);
      
      int RightCount= helper(root->right,count);
      
      return leftCount+RightCount;

    }
    
    int leafNodesCount(TreeNode* root) {
      
      int count =0;
      
      if(root==NULL)
      {
        return 0;
      }
      
      return helper(root,count);
      
    }
};