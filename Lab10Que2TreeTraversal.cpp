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

void Inorder(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
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

void Postorder(Node* root)
{
    if (root==NULL)
    {
        return;
    }

    else
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node* root= NULL;
    root= Insert(root,'G');
    Insert(root,'D'); 
    Insert(root,'L'); 
    Insert(root,'B'); 
    Insert(root,'E'); 
    Insert(root,'S');
    
    cout << "Inorder: ";
    Inorder(root);

    cout << "\nPreorder: ";
    Preorder(root);

    cout << "\nPostorder: ";
    Postorder(root);

    return 0;
}