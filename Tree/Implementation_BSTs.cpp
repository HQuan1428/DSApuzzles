/*
    TOPIC-BINARY SEARCH TREES     
*/

#include <bits/stdc++.h>
#define ll long long
#define BSTsNode BinarySearchTreesNode

struct BinarySearchTreesNode {
    int data;
    BinarySearchTreesNode *left;
    BinarySearchTreesNode *right;
    BinarySearchTreesNode(int value) : data(value), left(NULL), right(NULL){}
};

// Finding an Element in BSTs
BSTsNode* Find(BSTsNode *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data < data) {
        return Find(root->right, data); 
    }
    if(root->data > data) {
        return Find(root->left, data); 
    }
    return root; // result if exist. 
}

BSTsNode* FindNonrecursive(BSTsNode *root, int data) {
    if(!root) {
        return NULL;
    }
    while(root) {
        if(root->data > data) {
            root = root->left; 
        }
        else if(root->data < data) {
            root = root->right; 
        }
        else {
            return root;
        }
    }
    return NULL;
}

// Finding Minimum Element in BSTs
BSTsNode* FindMin(BSTsNode *root) {
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL) {
        return root; 
    }
    return FindMin(root->left); 
}

BSTsNode* FindMinNonRecursive(BSTsNode *root) {
    if(!root) {
        return NULL; 
    }
    while(root->left) {
        root = root->left;
    }
    return root;
}

// Finding Minimum Element in BSTs
BSTsNode *FindMax(BSTsNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL)
    {
        return root;
    }
    return FindMax(root->right);
}

BSTsNode *FindMaxNonRecursive(BSTsNode *root)
{
    if (!root)
    {
        return NULL;
    }
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

// Inserting an Element from BSTs
BSTsNode* Insert(BSTsNode *root, int data) {
    if(root == NULL) {
        root = new BSTsNode(data);
    }
    else {
        if(data < root->data) {
            root->left = Insert(root->left, data); 
        }
        else if(data > root->data) {
            root->right = Insert(root->right, data); 
        }
    }
    return root;
}

//Deleting an Element from BSTs
BSTsNode* Delete(BSTsNode *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == data) {
        if(root->left && root->right) {
            BSTsNode *temp = FindMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, root->data); 
        }
        else {
            BSTsNode *temp = root; 
            if(!root->left) {
                root = root->right;
            }
            if(!root->right) {
                root = root->left;
            }
            delete temp;
            temp = NULL;
        }
    }
    else if(root->data > data) {
        root->left = Delete(root->left, data);
    }
    else {
        root->right = Delete(root->right, data);
    }
    return root;
}



int main(int argc, char const *argv[]){
    // freopen("data_in.txt", "r", stdin); 
    // freopen("data_out.txt", "w", stdout); 
    

    system("pause");
    return 0;
}