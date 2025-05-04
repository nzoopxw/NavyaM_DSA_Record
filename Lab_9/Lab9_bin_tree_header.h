#ifndef HEADER_H
#define HEADER_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>    
#include <stack>
using namespace std;
class treeadt
{
    struct node
    {
        char data;
        struct node* left;
        struct node* right;
    }*head;
    public:
    treeadt();
    struct node* gethead()
    {
        return head;
    }
    void sethead(struct node* root)
    {
        head = root;
    }
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    void insert(char);
    struct node* exptree(string, struct node*, char);
    int search(struct node*, char, int);
};

void treeadt::insert(char data)
{
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->data=data;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        queue<struct node*> que;
        que.push(head);
        while(!que.empty())
        {
            struct node* Node = que.front();
            que.pop();
            if (Node->left != nullptr)
            {
                que.push(Node->left);
            }
            else
            {
                Node->left=newnode;
                return;
            }
            if (Node->right != nullptr)
            {
                que.push(Node->right);
            }
            else
            {
                Node->right=newnode;
                return;
            }
        }
    }
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

int treeadt::search(struct node* root, char key, int flag)
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

treeadt::node* treeadt::exptree(string exp, struct node* root, char data)
{
    int i = 0;
    stack<treeadt::node*> stk;
    while (i < exp.length())
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->right = NULL;
        newnode->left = NULL;
        newnode->data = exp[i];

        if (isalnum(exp[i]))
        {
            stk.push(newnode);
        }
        else
        {
            struct node* o1 = stk.top();
            stk.pop();
            struct node* o2 = stk.top();
            stk.pop();
            newnode->right = o1;
            newnode->left = o2;
            stk.push(newnode);
        }
        i++;
    }
    return stk.top();
}
#endif