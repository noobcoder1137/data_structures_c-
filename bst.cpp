// Noobcoder.com
// Source code for tutorial series found here:
// https://www.youtube.com/playlist?list=PLvTjg4siRgU1ahA4wioy9qF3eMcH-Nh-I

#include <iostream>

using namespace std;


class Node{
    public:
        Node *left, *right;
        int data;
        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};


class BST{
    private:
        // keeps track of the root of our tree
        Node *root;
        // inserts node to our BST
        // 1st param is the data we want to insert
        // 2nd param is the pointer of the current root
        void insertPrivate(int data,Node *&root){
            // our BST is empty, set our root to the node we just created
            if(root == NULL)
                root = new Node(data);
            // go left
            else if(data < root->data){
                // if left child is not Null, we can't insert here
                // continue looking for place to insert in the left subtree
                if(root->left != NULL)
                    insertPrivate(data,root->left);
                else
                // insert as the left child node of the current node we're at
                    root->left = new Node(data);
            }
            // go right
            else if(data > root->data){
                // if right child is not Null, we can't insert here
                // continue looking for place to insert in the right subtree
                if(root->right != NULL)
                    insertPrivate(data,root->right);
                else
                // insert as the right child node of the current node we're at
                    root->right = new Node(data);
            }
        }
        // removes node from our BST
        // 1st param is the data of the node we're looking for to delete
        // 2nd param pointer of the node we're currently at
        void removePrivate(int data, Node *&root){
            // empty BST, nothing to remove
            if(root == NULL)
                return;
            // *** Search for the node we want to delete *** //
            // if data is less than data of node we're currently at
            // search left subtree
            else if(data < root->data)
                removePrivate(data, root->left);
            // if data is greater than the data of the node we're currently at
            // search right subtree
            else if (data > root->data)
                removePrivate(data, root->right);

            // *** Found node we want to delete *** //
            else {
                // Case 1:  No child
                if(root->left == NULL && root->right == NULL) {
                    delete root;
                    root = NULL;
                }
                //Case 2: One child
                else if(root->left == NULL) {
                    Node *temp = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->right == NULL) {
                    Node *temp = root;
                    root = root->left;
                    delete temp;
                }
                // case 3: 2 children
                else {
                    // find smallest value within the right subtree
                    // to replace the node we're going to delete
                    Node *temp = findMin(root->right);
                    root->data = temp->data;
                    removePrivate(temp->data,root->right);
                }
            }
            return;
        }
        // helper method. Finds smallest value within a tree
        Node* findMin(Node* root){
            int i = 0;
            while(root->left != NULL){
                root = root->left;
                i++;
            }
            return root;
        }
    public:
        BST(){
            root = NULL;
        }

        void insert(int data){
            insertPrivate(data,root);
        }

        void remove(int data){
            removePrivate(data, root);
        }
};


int main(){
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);
    tree.insert(3);
    tree.remove(5);
}
