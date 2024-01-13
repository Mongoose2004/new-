#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node
{   public:
    int data;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
    
};
Node *createBBST(vector<int>v,int start,int end)
{ 
    if(start>end)
    return NULL;
    int mid=start+(end-start)/2;
        Node *root=new Node(v[mid]);
     root->left=createBBST(v,start,mid-1);
     root->right=createBBST(v,mid+1,end);
    return root;
    
    
    
    
}
void inorder(Node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
   { 
    int size;
    cin>>size;
    vector<int>v(size);
    for(int i=0;i<size;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    Node *root =createBBST(v,0,size-1);
    inorder(root);
    
}