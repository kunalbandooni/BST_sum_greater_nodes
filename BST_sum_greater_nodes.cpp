#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
typedef struct tree{
    int info;
    struct tree *left;
    struct tree *right; 
}tree_type;
tree_type *create(int n){
    tree_type *temp;
    temp=(tree_type*)malloc(sizeof(tree_type));
    if(temp==NULL)
        cout<<"Not Enough Memory";
    else{
        temp->info=n;
        temp->left=NULL;
        temp->right=NULL;
    }
    return temp;
}
tree_type* insert(tree_type *root,tree_type *temp){
    if(root==NULL)
        return temp;
    if(temp->info<root->info){
        if(root->left==NULL)
            root->left=temp;
        else
            insert(root->left,temp);        
    }
    else{
        if(root->right==NULL)
            root->right=temp;
        else
            insert(root->right,temp);
    }
    return root;
}
void modify(tree_type *root,int &sum){
    if(root==NULL)
        return;
    modify(root->right,sum);
    sum+=(root->info);
    (root->info)=sum;
    modify(root->left,sum);
}
void inorder(tree_type *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<" ->"<<root->info;
    inorder(root->right);
}
int main(){
    tree_type *root=NULL;
    tree_type *temp;
    int n,num,a,sum=0;;
    while(1){
        cout<<"\n1.Insert\n2.Modify BST with sum of Greater Nodes\n3.Exit\nEnter your choice:";
        cin>>n;
        switch (n)
        {
            case 1:
                cout<<"Enter the element:";
                cin>>num;
                temp=create(num);
                root=insert(root,temp);
            break;
            case 2:
                modify(root,sum);
                cout<<"\nInorder looks like this now";
                inorder(root);
            break;
            case 3:
               return 0;
            break;
            default:
                cout<<"Invalid option";
        }
    }
    return 0;
}