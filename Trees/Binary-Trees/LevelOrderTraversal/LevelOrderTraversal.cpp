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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
         
         //int levels = helper(root,0);
    
     // cout<<"levels: "<<levels<<endl;
      
      vector<vector<int>> ans;
      
     // ans.resize(levels);
      
      if(root==NULL){
        return ans;
      }
      
      queue<TreeNode*>q;
      
      q.push(root);
      
      bool parity = false;
      
      int i =0;
      while(!q.empty()){
        
        int sz = q.size();
        
        //ans[i].resize(sz);
         
        vector<int>temp;
         
       // int k=0;
        while(sz--){
            
            TreeNode *curr = q.front();
            
            if(curr->left!=NULL)
            q.push(curr->left);
            
            if(curr->right!=NULL)
            q.push(curr->right);
            
            temp.push_back(curr->val);
            
            q.pop();
            //k++;
           }
           
           if(!parity){
             
             parity = true;
             ans.push_back(temp);
             
           }
           else{
              parity = false;
              //reverse(temp.begin(),temp.end());
              ans.push_back(temp);
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
  
     vector<vector<int>> ans = s.levelOrder(root);

    for(auto i:ans)
      for(auto j:i)  
        cout<<j<<" ";
    //cout << endl;

    return 0;
}