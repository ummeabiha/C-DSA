#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
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

void Preorder(Node* root)
{
    if (root!=NULL)
    {
        cout << root-> data<< " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(Node* root)
{
    if (root!=NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root-> data<< " ";
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


int main()
{
    struct Node *root = NULL; 
    root = Insert(root, 15); 
    Insert(root, 10); 
    Insert(root, 20); 
    Insert(root, 25); 
    Insert(root, 8); 
    Insert(root, 12); 
    cout<<"Inorder: "; 
    Inorder(root);
    cout<<"\nPreorder: "; 
    Preorder(root);
    cout<<"\nPostorder: "; 
    Postorder(root);

    int item;
    cout << "\nEnter the element you want to search: " << endl;
    cin >> item;
    if (Search(root,item)==NULL)
    {
        cout << "Element is not Found!" << endl;
    }
    else
    {
        cout << item << " is Present in the Tree." << endl;
    }

    return 0;
}