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

int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        return i;
    }
    return -1;
}
node* build_tree(int postorder[],int inorder[],int start,int end)
{
   if(start>end)
   return nullptr;

    static int idx= end;
    int curr= postorder[idx];
    idx--;
     node  *n1= new node(curr);
     if(start==end)
     return n1;
    
    int pos=search(inorder,start,end,curr);
    n1->right=build_tree(postorder,inorder,pos+1,end);
    n1->left=build_tree(postorder,inorder,0,pos-1);

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
  void level_order_traversal(node *root)  
  {
      if(root==nullptr)
      return ;

      queue<node*>q;
      q.push(root);
      q.push(nullptr);
      while(!q.empty())
      {
         node *front = q.front();
         q.pop();
         if(front!=nullptr)
         {
             cout << front->data << "->";
             if(front->left)
             q.push(front->left);
             if(front->right)
             q.push(front->right);
         }
         else if (!q.empty())
         {
             q.push(nullptr);
         }
      }
  }
//sum at kth level

int sum_at_kth_level(node *root,int k)
{
    if(root==nullptr)
    return -1;
     queue<node*>q;
    q.push(root);
    q.push(nullptr);

    int cnt=0;
    int sum=0;
    while(!q.empty())
    {
        node *front = q.front();
        q.pop();
        if(front!=nullptr)
        {
            if(k==cnt)
              sum+=front->data;

              if(front->left)
              q.push(front->left);
              if(front->right)
              q.push(front->right);
        }
        else if (!q.empty())
        {
            cnt++;
            if(cnt>k)
            break;
            q.push(nullptr);
        }
    }
    return sum;

}
int count_node(node *root)
{
     if(root==nullptr)
     return 0;

     return count_node(root->left) +count_node(root->right)+1;
}
int sum_nodes(node *root)
{
    if(root==nullptr)
     return 0;

    return sum_nodes(root->left)+sum_nodes(root->right)+root->data;
}
int height_tree(node *root)
{
    if(root==nullptr)
       return 0;

    return max(height_tree(root->left),height_tree(root->right))+1;
}
//time complexity is O(n^2);

int calcdiameter(node *root)
{
    if(root==nullptr)
    return 0;


    int lheight = height_tree(root->left);
    int rheight=height_tree(root->right);

    int ldia= calcdiameter(root->left);
    int rdia = calcdiameter(root->right); 

    return max((lheight+rheight+1),max(ldia,rdia));
}

//optimised version of calculating diameter 

int calcDia(node *root , int* height)
{
     if(root==nullptr)
     {
         *height=0;
         return 0;
     }
     int lh=0,rh=0;
     int ldiam= calcDia(root->left,&lh);
     int rdiam=calcDia(root->right,&rh);

     int currD=lh+rh+1;
     *height=max(lh,rh)+1;

     return max(currD,max(ldiam,rdiam));
}
//replace the value of each node with sum of all subtree nodes and itself

 void sum_replace(node *root)
 {
     if(root==nullptr)
     {
         return ;
     }
    
    sum_replace(root->left);
    sum_replace(root->right);
    if(root->left!=nullptr)
    {
        root->data+=root->left->data;

    }
    if(root->right!=nullptr)
    {
        root->data+=root->right->data;
    }
 }

 void preorder_traversal(node *root)
{
    if(root==nullptr)
    return;
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

//checking whether binary tree is balanced or not 
bool isbalanced( node *root,int *height)
{
    if(root==nullptr)
    {
        *height=0;
        return true;
    }
    int lh=0,rh=0;
    if(isbalanced(root->left,&lh)==false)
    {
        return false;
    }
    if(isbalanced(root->right,&rh)==false)
    {
        return false;
    }

    *height=max(lh,rh)+1;

    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
}

//right view of binary tree 
  void right_view(node *root)
  {

      if(root==nullptr)
      {
          return ;
      }
    queue<node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node *curr=q.front();
            q.pop();

            if(i==n-1)
            {
                cout << curr->data << " ";
            }
            if(curr->left!=nullptr)
            {
                q.push(curr->left);
            }
            if(curr->right!=nullptr)
            {
                q.push(curr->right);
            }
        }
    }
  }
 
 //left view of tree

 void left_view(node *root)
 {
    
 }
   
   // lowest common ancestor 

     
  
int main()
{
    /*
        1
       /  \
      2    3
     / \   /
    4   5  6   */
      /* int postorder[]={4 ,5, 2, 6, 7, 3, 1};
    int inorder[]={4 ,2, 5, 1, 6, 3, 7 };

    node *n2=build_tree( postorder,inorder,0,6);*/
    //level order traversal

    node *root= new node(1);
    root->left = new node(2);
    root->right= new node(3);
    root->left->left= new node(4);
    root->left->right= new node (5);
    root->right->left = new node(6);

    //inorder_print(n2);
    level_order_traversal(root);
cout <<endl;
    int sum=sum_at_kth_level(root,1);
    cout << sum <<endl;
    int s1=sum_at_kth_level(root,2);
    cout << s1 <<endl;
//count all nodes in  a tree
   int cnt=count_node(root);
   cout << "node count : " <<cnt <<endl;
   //sum of nodes
   int s2=sum_nodes(root);
   cout << "sum of nodes : " << s2 <<endl;

   //height of binary tree
   int height=height_tree(root);
   cout << "height of tree : " << height <<endl;

   //calculating diameter 
   int diameter = calcdiameter(root);
   cout << "diameter : " << diameter<<endl;

   cout << "optimised version " <<endl;
   int h=0;
   int d=calcDia(root,&h);
   cout << "diameter : " << d <<endl;
     preorder_traversal(root);
     cout <<endl;
      cout << "left view:";
      left_view(root);
     //sum replace 
     cout <<endl;
    sum_replace(root);
    preorder_traversal(root);
     cout << endl;
    right_view(root);
    cout <<endl;
    left_view(root);
   }