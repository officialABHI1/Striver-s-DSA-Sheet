#include <bits/stdc++.h>
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
    
    vector<int> ZigZag(TreeNode* root) {
      
      vector<int>ans;
      
      if(root==NULL){
        return ans;
      }
      
      queue<TreeNode*>q;
      
      q.push(root);
      
      bool parity = false;
      
      while(!q.empty()){
        
        int sz = q.size();
         
        vector<int>temp;
         
        while(sz--){
            
            TreeNode *curr = q.front();
            
            if(curr->left!=NULL)
            q.push(curr->left);
            
            if(curr->right!=NULL)
            q.push(curr->right);
            
            temp.push_back(curr->val);
            
            q.pop();
           }
           
           if(!parity){
             
             parity = true;
             
             int k = temp.size();
             
             for(int i=0;i<k;i++)
              ans.push_back(temp[i]);
             
           }
           else{
             int k = temp.size();
             
             for(int i=k-1;i>=0;i--)
              ans.push_back(temp[i]);
          
             parity = false;
           }
         
      }
      return ans;
    }
};

int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(90);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(13);
    
    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(15);
    
    // Create a Solution object
    Solution s;
  
     vector<int> ans = s.ZigZag(root);

    for(auto i:ans)
    cout<<i<<" ";
    cout << endl;

    return 0;
}
