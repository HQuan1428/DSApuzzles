/*
    TOPIC-AVL TREES

    - Type of Violations
        1. An insertion into the left subtree of the left child of X.
        2. An insertion into the right subtree of the left child of X.
        3. An insertion into the left subtree of the right child of X.
        4. An insertion into the right subtree of the right child of X.

    - Single Rotations:
        + Left Left Rotation(case 1): 
            Let us assume node X is not satisfying the AVL tree propety.
            We start at the node inserted and travel up the tree, updating the balance informatinat every node on the path. 
        + Right Right Rotation(case 4):
    
    - Double Rotations: 
        + Left Right Rotation(case 2):
        + Right Left Rotatin(case 3):
*/

#include <bits/stdc++.h>
#define ll long long

struct AVLTreesNode {
    int data;
    AVLTreesNode *left; 
    AVLTreesNode *right;
    int height;
    AVLTreesNode(int value) : data(value), left(NULL), right(NULL), height(0){}
};

// Finding the height of an AVL tree 
int Height(AVLTreesNode *root) {
    if(!root) {
        return -1;
    }
    return root->height;
}

// Rotations 
AVLTreesNode* LLRotation(AVLTreesNode *X) {
    AVLTreesNode *W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = std::max(Height(X->left), Height(X->right)) + 1;
    W->height = std::max(Height(W->left), Height(W->right)) + 1;
    return W; 
}

AVLTreesNode* RRRotation(AVLTreesNode *X) {
    AVLTreesNode *W = X->right;
    X->right = W->left;
    W->left = X;
    X->height = std::max(Height(X->left), Height(X->right)) + 1;
    W->height = std::max(Height(W->left), Height(X->right)) + 1;
    return W;
}

AVLTreesNode* LRRotation(AVLTreesNode *Z) {
    Z->left = RRRotation(Z->left);
    return LLRotation(Z);
}

AVLTreesNode* RLRotation(AVLTreesNode *Z) {
    Z->right = LLRotation(Z->right);
    return RRRotation(Z);
}

// Insert into an AVL tree 
AVLTreesNode* Insert(AVLTreesNode *root, int data) {
    if(!root) {
        root = new AVLTreesNode(data); 
    }
    else if(root->data < data) {
        root->right = Insert(root->right, data); 
        if(std::abs(Height(root->left) - Height(root->right)) == 2) {
            if(data < root->right->data) {
                root = RLRotation(root);
            }
            else {
                root = RRRotation(root);
            }
        }
    }
    else if(root->data > data) {
        root->left = Insert(root->left, data); 
        if(std::abs(Height(root->left) - Height(root->right)) == 2) {
            if(data < root->left->data) {
                root = LLRotation(root);
            }
            else {
                root = LRRotation(root);
            }
        }
    }
    root->height = std::max(Height(root->left), Height(root->right)) + 1;
    return root;
}

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}