//binary expression tree

#include "bin_tree_header.h"

treeadt::treeadt()
{
    head=NULL;
}

string postfix();
void consttree(string, treeadt&);
int main()
{
    string post;
    int chc;
    treeadt obj;
    do 
    {
        cout<<("enter: \n\t 1. for entering postfix expression\n\t 2. construction of experssion tree\n\t 3. indorder\n\t 4. preorder\n\t 5. postorder\n\t 6. exit\n");
        cout<<("enter the choice\n");
        cin>>chc;
        switch(chc)
        {
            case 1:
            {
                post=postfix();
                break;
            }
            case 2:
            {
                consttree(post, obj);
                break;
            }
            case 3:
            {
                obj.inorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 4:
            {
                obj.preorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 5:
            {
                obj.postorder(obj.gethead());
                cout<<"\n";
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"invalid input\n";
            }
        }
    }while(1);
}

string postfix()
{
    string post;
    cout<<"enter a valid postfix expression: ";
    cin>>post;
    return post;
}

void consttree(string post, treeadt& obj)
{
    obj.sethead(obj.exptree(post, NULL, '\0'));
}