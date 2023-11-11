/*
    TOPIC-GENERIC TREES: PROBLEM & SOLUTION
*/

#include <bits/stdc++.h>
#define ll long long
#define TN TreeNode

struct TreeNode {
    int data;
    TreeNode *firstChild;
    TreeNode *nextSibling; 
};

//Problem 1: the sum of all the elements of the tree 
int FindSum(TN *root) {
    if(!root)
        return 0;
    return root->data + FindSum(root->firstChild) + FindSum(root->nextSibling); 
}

//Problem 2: find the height with given a parent array. 
int FindDepthInGenericTree(int P[], int n) {
    int maxDepth = -1;
    for (int i = 0; i < n; i++) {
        int currentDepth = 0;
        int j = i;
        /*
            condition true : P[j] not root
        */ 
        while(P[j] != -1){
            currentDepth += 1;
            j = P[j]; // access parent of j
        }
        maxDepth = std::max(maxDepth, currentDepth);
    }
    return maxDepth; 
}

//Problem 3: count the sibling pointer
int CountSibling(TN *root) {
    int count = 0; 
    while(root){
        count += 1;
        root = root->nextSibling;
    }
    return count;
}

// Problem 4: count the number of children
int CountChild(TN *root) {
    int count = 0;
    root = root->firstChild; 
    while(root) {
        count++;
        root = root->nextSibling;
    }
    return count;
}

//Problem 5: isomorphic or not 
bool IsIsomorphic(TN *root1, TN *root2) {
    if(!root2 && !root2)
        return true;
    if((root1 && !root2) || (!root1 && root2))
        return false;
    return IsIsomorphic(root1->firstChild, root2->firstChild) && IsIsomorphic(root1->nextSibling, root2->nextSibling);
}

//Prolem 6: quasi_isomorphic or not
bool IsQuasi_Isomorphic(TN *root1, TN *root2) {
    if(!root2 && !root1) {
        return true;
    }
    if((!root1 && root2) || (root1 && !root2))
        return false;
    return ((IsQuasi_Isomorphic(root1->firstChild, root2->firstChild) && IsQuasi_Isomorphic(root1->nextSibling, root2->nextSibling)) || (IsQuasi_Isomorphic(root1->firstChild, root2->nextSibling) && IsQuasi_Isomorphic(root1->nextSibling, root2->firstChild)));
}



int main(int argc, char const *argv[]){
    int P[] = {-1, 0, 1, 6, 6, 0, 0, 2, 7};
    std::cout << FindDepthInGenericTree(P, 9) << std::endl;
    system("pause");
    return 0;
}