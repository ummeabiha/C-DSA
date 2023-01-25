#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* addNode(int item)
{
    Node* addNode= new Node();
    addNode-> data= item;
    addNode-> left= NULL;
    addNode-> right= NULL;
    return addNode;
}

//INSERTION
Node* Insert(Node* root, int item)
{
    if (root==NULL)
    {
        root = addNode(item); 
    }

    else if (root->data > item)
    {
        root->left = Insert(root->left, item); 
    }

    else
    {
        root->right = Insert(root->right, item); 
    }

    return root;
}

//SEARCHING
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

    else if (root->data > item)
    {
        return Search(root-> left, item);
    }
    
    else
    {
        return Search(root->right, item);
    }
}

//DELETION
Node* Delete(Node* root, int item)
{
    Node* loc = Search(root, item);

    if (loc==NULL)
    {
        cout << "Item doesnot exist." << endl;
    }

    else if (loc== root->left)
    {
        root->left= NULL;
        cout << "\nNode is deleted from the left." << endl;
    }

    else if (loc== root->right)
    {
        root->right= NULL;
        cout << "\nNode is deleted from the right." << endl;
    }

    else if (loc->data < root->data)
    {
        Delete(root-> left, item);
    }

    else
    {
        Delete(root-> right, item);
    }
}

//MIRROR
void Mirror(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        Node* temp= root->left;
        Mirror(root->left);
        Mirror(root->right);
        root->left= root->right;
        root->right= temp;
    }
}

//TRAVERSING
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


int main()
{
    struct Node *root = NULL; 

    //INSERTION
    root = Insert(root, 15); 
    Insert(root, 10); 
    Insert(root, 20); 
    Insert(root, 25); 
    Insert(root, 8); 
    Insert(root, 12); 

    //SEARCHING
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

    //TRAVERSING
    cout<<"\nInorder: " << " "; Inorder(root);
    cout<<"\nPreorder: "<< " "; Preorder(root);
    cout<<"\nPostorder: " << " "; Postorder(root);

    //DELETION
    Delete(root,8); 
    cout<<"\n\nInorder after deleteing 8: "<<" "; 
    Inorder(root); 

    //MIRROR
    cout<<"\n\nPre-Order Before Mirror"<<" "; 
    Preorder(root);  
    Mirror(root); 
    cout<<"\nPre-Order After Mirror"<<" "; 
    Preorder(root); 
    cout<<endl;

    return 0;
}