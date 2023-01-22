#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* addNode(int item)
{
    Node* addNode= new Node();
    addNode->data= item;
    addNode->left= NULL;
    addNode->right= NULL;
    return addNode;
}

Node* Insert(Node* root, char data)
{
    if (root == NULL) 
    { 
        root = addNode(data); 
    } 
    else if (data < root->data) 
    { 
        root->left = Insert(root->left, data); 
    } 
    else
    { 
        root->right = Insert(root->right, data); 
    } 
    return root; 

}

void Preorder(Node* root)
{
    if (root==NULL)
    {
        return;
    }

    else
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Mirror(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        Node*temp= root->left;
        Mirror(root->left);
        Mirror(root->right);
        root->left= root->right;
        root->right=temp;
    }

}


int main()
{
    struct Node *root = NULL; 
    root = Insert(root,'G'); 
    Insert(root,'D'); 
    Insert(root,'L'); 
    Insert(root,'B'); 
    Insert(root,'E'); 
    Insert(root,'S'); 

    cout<<"Pre-Order Before Mirror"<<" "; 
    Preorder(root); 
    cout<<endl; 
    Mirror(root); 
    cout<<"Pre-Order After Mirror"<<" "; 
    Preorder(root); 
    cout<<endl;
    
    return 0;
}