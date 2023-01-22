#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node *addNode(int item)
{
    Node *addNode = new Node();
    addNode->data = item;
    addNode->left = NULL;
    addNode->right = NULL;
    return addNode;
}

Node*Insert(Node* root, int data)
{
    if (root==NULL)
    {
        root= addNode(data);
    }
    else if(data< root->data)
    {
        root->left= Insert(root->left, data);
    }
    else
    {
          root->right= Insert(root->right, data);
    }
    return root;
}

void Inorder(Node* root)
{
    if (root!=NULL)
    {
        Inorder(root->left);
        cout << root-> data<< " ";
        Inorder(root->right);
    }
}

Node* Search(Node* root, int item)
{
    if (root==NULL)
    {
        return root;
    }
    else if (root->data==item)
    {
        return root;
    }
    else if (root->data >item)
    {
        return Search(root->left, item);
    }
    else
    {
        return Search(root->right, item);
    }
}


Node* Deletion(Node* root, int data)
{
    Node* loc= Search(root,data);

    if (loc==NULL)
    {
        cout << "Item doesnot exist." << endl;
    }

    else if (loc==root->left)
    {
        root->left=NULL;
        cout << "Node is deleted from the left." << endl;
    }

    else if (loc==root->right)
    {
        root->right=NULL;
        cout << "\nNode is deleted from the right." << endl;
    }

    else if (loc->data< root->data)
    {
        Deletion(root->left, data);
    }

    else
    {
        Deletion(root->right, data);
    }
}


int main()
{
    struct Node *root = NULL; 
    root = Insert(root, 15); 
    Insert(root, 10); 
    Insert(root, 20); 
    Insert(root, 25); 
    Insert(root, 8); 
    Insert(root, 12); 
    
    cout<<"Inorder"<<" "; 
    Inorder(root); 
    cout<<endl; 
    
    Deletion(root,8); 
    cout<<"Inorder after deleteing 8: "<<" "; 
    Inorder(root); 
    
    Deletion(root,20); 
    cout<<"Inorder after deleting 20: "<<" "; 
    Inorder(root); 
} 
    