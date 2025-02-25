#include <iostream>


using namespace std;



class Node
{
    public:
    int data;
    Node * left, * right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }

};



class BST
{
    public:
    Node * root;

    BST()
    {
        root = NULL;
    }
    Node * insert(Node*pNode, int item)
    {
        if(pNode == NULL)
        {
            Node * newNode = new Node(item);
            pNode = newNode;
        }
        else if (item < pNode->data)
        {
            pNode->left = insert(pNode->left, item);
        }
        else if(item>pNode->data)
        {
            pNode->right = insert(pNode->right, item);
        }
        return pNode;
    }
    void insert(int item)
    {
        root = insert(root, item);
    }
    void Preorder(Node * r)
    {
        if(r == NULL) return ;
        cout << r->data << "\t";
        Preorder(r->left);
        Preorder(r->right);
    }

    void inorder(Node * r)
    {
        if(r == NULL) return ;
        inorder(r->left);
        cout << r->data << "\t";
        inorder(r->right);
    }

    void Postorder(Node * r)
    {
        if(r ==NULL) return;
        Postorder(r->left);
        Postorder(r->right);
        cout << r->data << "\t";
    }


    Node * Search(Node * r, int item)
    {
        if(r == NULL)
        {
            return NULL;
        }
        else if (r->data == item)
        {
            return r;
        }
        else if (item < r->data)
        {
            return Search(r->left, item);
        }
        else
        {
            return Search(r->right, item);
        }
          
    }


    Node * Findmin(Node*r)
    {
        if(r == NULL)
        {
            return NULL;
        }
        else if(r->left == NULL)
        {
            return r;
        }
        else 
        {
            return Findmin(r->left);
        }
    }



    Node * Findmax(Node * r)
    {
        if(r == NULL)
        {
            return NULL;
        }
        else if(r->right == NULL)
        {
            return r;
        }
        else 
        {
            return Findmax(r->right);
        }
    }

    bool Search(int item)
    {
        Node * result = Search(root, item);
        return result != NULL;
    }

    Node * Delete(Node*r, int key)
    {

        if(r == NULL) return NULL;
        if(key < r->data)
        {
            r->left = Delete(r->left, key);
        }
        else if(key > r->data)
        {
            r->right = Delete(r->right, key);
        }
        else
        {
            if(r->left == NULL && r->right == NULL)
            {
                r = NULL;
            }
            else if(r->left != NULL && r->right == NULL)
            {
                r->data = r->left->data;
                delete r->left;
                r->left = NULL;
            }
            else if(r->right != NULL && r->left == NULL)
            {
                r->data = r->right->data;
                delete r->right;
                r->right = NULL;
            }
            else
            {
                Node * pre = Findmax(r->left);
                r->data = pre->data;
                Delete(r->left, pre->data);
                
            }
        }
        return r;

    }
};







int main()
{
    BST bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(5);
    bst.insert(110);
    bst.insert(220);
    bst.insert(350);
    bst.insert(55);
    bst.Preorder(bst.root);
    cout << "\n----------------------------\n";
    bst.inorder(bst.root);
    cout << "\nThe item you are looking for is found or not \n" ;
    cout << bst.Search(350) << endl;
    Node * min = bst.Findmin(bst.root);

    cout << "\n" << min->data << endl;

    Node * max = bst.Findmax(bst.root);

    cout << "\n" << max->data << endl;
    Node * result = bst.Delete(bst.root, 350);
    
    
   
    bst.Preorder(result);
   
   cout << "\n\n\t\t";
    result = bst.Delete(bst.root, 5);
    bst.Preorder(result);


    return 0;
}