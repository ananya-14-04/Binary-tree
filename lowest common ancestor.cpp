#include<bits/stdc++.h>
using namespace std;

class node {
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

bool getPath(node *root,int key , vector<int> &path)
{
    if(root==nullptr)
    {
        return false;
    }

    path.push_back(root->data);

    if(root->data==key)
    {
        return true;
    }
    if(getPath(root->left,key,path)|| getPath(root->right,key,path))
   {
   return true;

   } 

   path.pop_back();
   return false;
}
   int lowest_ancestor(node *root,int n1,int n2)
   {
       vector<int>path1;
       vector<int>path2;
       if(!getPath(root,n1,path1)|| !getPath(root,n2,path2))
       {
          return -1;
       }
       int pc;
        for(int pc=0;pc<path1.size()&& path2.size();pc++)
        {
            if(path1[pc]!=path2[pc])
            break;
        }

        return path1[pc-1];
   }


   int main()
   {
       node *root= new node(1);
       root->left =new node(2);
       root->right = new node(3);
       root->left->right= new node(4);
       root->right->right = new node(6);
       root->left->left=new node(5);

       cout << "lowest ancestor : " << lowest_ancestor(root,2,5);
   }