#include<bits/stdc++.h>
using namespace std;

struct Node{

int val;  // store the value of the node
   
Node *left  = NULL; // store the address of left child
Node *right = NULL; // store the address of right child

};

void preOrder(Node * root){

 //if node doesn't exists
 
 if(root == NULL)
  return;

  cout<<root->val<<" ";

 preOrder(root->left); // calling the inorder recursively on left Subtree

 preOrder(root->right); // calling the inorder recursively on right Subtree

}


int main(){

//creation of the nodes 

Node *root  = new Node;
Node *node1 = new Node;
Node *node2 = new Node;
Node *node3 = new Node;
Node *node4 = new Node;


//assign the values in each node
root->val =90;
node1->val =10;
node2->val =20;
node3->val = 11;
node4->val =13;

//assiging the relationship between nodes

root->left=node1;
root->right = node2;
node1->left =node3;
node1->right =node4;

//tree traversals

preOrder(root);
 
}