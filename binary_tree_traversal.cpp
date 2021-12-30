#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void inorder_traversal(node *root)
{
    if(root==nullptr)
    return ;

    inorder_traversal(root->left);
    cout << root->data << " " ;
    inorder_traversal(root->right);
}
void post_ordertraversal(node *root)
{
    if(root==nullptr)
    return ;
    post_ordertraversal(root->left);
    post_ordertraversal(root->right);
    cout << root->data << " ";
}
void preorder_traversal(node *root)
{
    if(root==nullptr)
    return;
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
int search(int inorder[],int start , int end ,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        return i;
    }
    return -1;
}
node* buildtree(int preorder[],int inorder[],int start ,int end)
{
    static int idx=0;
    if(start>end)
    return nullptr;
  
  int curr=preorder[idx];
  idx++;
  node *n1= new node(curr);
  if(start==end)
  return n1;
  int pos=search(inorder,start,end,curr);

  n1->left=buildtree(preorder,inorder,start,pos-1);
  n1->right=buildtree(preorder,inorder,pos+1,end);

  return n1;
}
void inorder_print(node *root)
{
    if(root==nullptr)
     return ;
  inorder_print(root->left);
   cout << root->data << "->";
   inorder_print(root->right);
     

}
node *buildtree(int n)
{
    node *temp=nullptr;
    if(n>)
}
int main()
{
   /* node *root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right = new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);
    cout << "inorder traversal " ;
    inorder_traversal(root);
     cout <<endl;
     cout << "postorder traversal " ;
     post_ordertraversal(root);
     cout <<endl;
     cout << "preorder traversal ";
     preorder_traversal(root);*/
    
    int inorder[]={4, 2, 5, 1, 6, 3, 7};
    int preorder[]={1, 2, 4, 5, 3, 6, 7};
    
    node *n2=buildtree(preorder,inorder,0,6);
   inorder_print(n2);
     

}