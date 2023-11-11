/*
    TOPIC-THREADED BINARY TREE TRAVERSALS
*/

// Tree node 
#include <bits/stdc++.h>
#define ll long long
#define TBT ThreadedBinaryTreeNode

struct ThreadedBinaryTreeNode
{
    ThreadedBinaryTreeNode *left;
    int LTag;
    int data;
    int RTag;
    ThreadedBinaryTreeNode *right;
};

//Finding Inorder Successor in Inorder Threaded Binary Tree 
TBT* InorderSuccessor(TBT *P) {
    if(P->RTag == 0) {
        return P->right;
    }
    TBT *Position = P->right; 
    while(Position->LTag == 1) {
        Position = Position->left;
    }
    return Position;
}

//Inorder Traversal
void InorderTraversal(TBT *root) {
    TBT *P = InorderSuccessor(root); 
    while(P != root) {
        P = InorderSuccessor(P); 
        if(P == root )
            return;
        std::cout << P->data << std::endl;
    }
}

void InorderTraversal2(TBT *root)
{
    TBT *P = root;
    while (1)
    {
        P = InorderSuccessor(P);
        if (P == root)
            return;
        std::cout << P->data << std::endl;
    }
}

// Finding PreOrder Successor
TBT* PreOrderSuccessor(TBT *P) {
    TBT *Position; 
    if(P->LTag == 1) {
        return P->left;
    }
    Position = P->right; 
    while(Position->RTag == 0) {
        Position = Position->right; 
    }
    return Position;
}

// PreOrder Traversal 
void PreOrderTraversal(TBT *root) {
    TBT *P = PreOrderSuccessor(root); 
    while(P != root) {
        P = PreOrderSuccessor(P);
        std::cout << P->data << std::endl;
    }
}

void PreOrderTraversal2(TBT *root)
{
    TBT *P = root;
    while (1)
    {
        P = PreOrderSuccessor(P);
        if(P == root)
            return;
        std::cout << P->data << std::endl;
    }
}


//Insert Right 
void InsertRightInorderTBT(TBT *P, TBT *Q) {
    Q->right = P->right;
    Q->RTag = P->RTag;
    Q->left = P;
    Q->LTag = 0;
    P->right = Q;
    P->RTag = 1; 
    if(Q->RTag == 1) {
        TBT *Temp = Q->right; 
        while(Temp->LTag) {
            Temp = Temp->left; 
        }
        Temp->left = Q; 
    }
}

// Problem 1: Find preorder successor in binary tree
TBT* PreorderSuccessorInBinaryTree(TBT *node) {
    static TBT *P;
    static std::stack<TBT *> S; 
    if(node != NULL) {
        P = node;
    }
    if(P->left != NULL) {
        S.push(P);
        P = P->left;
    }
    else {
        while(P->right == NULL) {
            P = S.top();
            S.pop(); 
        }
        P = P->right;
    }
    return P;
}

// Problem 2: Find the inorder successor in binary tree.
TBT *InorderSuccessorInBinaryTree(TBT *node)
{
    static TBT *P;
    static std::stack<TBT *> S;
    if (node != NULL)
    {
        P = node;
    }
    if (P->right == NULL)
    {
        P = S.top();
        S.pop(); 
    }
    else
    {
        P = P->right;
        while (P->left != NULL)
        {
            S.push(P);
            P = P->left;
        }
    }
    return P;
}

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}
