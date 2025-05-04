//to impliment intacter binary search tree
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>    
using namespace std;
class treeadt
{
    struct node
    {
        int data;
        struct node* left;
        struct node* right;
    }*head;
    public:
    treeadt()
    {
        head=NULL;
    }
    struct node* gethead()
    {
        return head;
    }
    void sethead(struct node* nhead)
    {
        head = nhead;
    }
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    struct node* insert(struct node*, int);
    int search(struct node*, int, int);
};

int main()
{
    int chc;
    treeadt obj;
    do 
    {
        cout<<("enter: \n\t 1. for inserting\n\t 2. inorder\n\t 3. preorder\n\t 4. postorder\n\t 5. search\n\t 6. exit\n");
        cout<<("enter the choice\n");
        cin>>chc;
        switch(chc)
        {
            case 1:
            {
                int val;
                cout<<("enter the integer to be inserted\n");
                cin>>val;
                int ret;
                obj.sethead(obj.insert(obj.gethead(), val));
                break;
            }
            case 2:
            {
                obj.inorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 3:
            {
                obj.preorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 4:
            {
                obj.postorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 5:
            {
                int key;
                cout<<"enter the integer to be searched \n";
                cin>>key;
                int ret = obj. search(obj.gethead(), key, 0);
                if (ret == 0)
                {
                    cout<<"the integer was not found\n";
                }
                else
                {
                    cout<<"the integer was found\n";
                }
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
        }
    }while(1);
}

treeadt::node* treeadt::insert(struct node* root, int data)
{
        
    if (root == NULL) 
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->right = NULL;
        newnode->left = NULL;
        newnode->data = data;
        return newnode;
    }
    else
    {
        if (data<root->data)
        {
            root->left=insert(root->left, data);
        }
        else
        {
            root->right=insert(root->right, data);   
        }
    }
    return root;
}


void treeadt::inorder(struct node* root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}

void treeadt::preorder(struct node* root)
{
    if(root)
    {
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }
}

void treeadt::postorder(struct node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}

int treeadt::search(struct node* root, int key, int flag)
{
    if (root)
    {
        flag=search(root->left, key, flag);
        if (root->data==key)
        {
            flag++;
        }
        flag=search(root->right, key, flag);
    }
    return flag;
}