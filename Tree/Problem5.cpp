
/*
    TOPIC: THE PROBLEMS OF AVL TREES
*/

#include <bits/stdc++.h>
#define ll long long

#define AVLTr AVLTreesNode

struct AVLTreesNode {
    int data;
    AVLTreesNode *left;
    AVLTreesNode *right;
    int height;
    AVLTreesNode(int value) : data(value), left(NULL), right(NULL), height(0) {}
};

//Problem 73: Give a height h, give an algorithm for generating the HB(0)
AVLTr* BuildHB0(int h) {
    static int count = 0; 
    if(h == 0) {
        return NULL;
    }
    AVLTr *temp = new AVLTr(0);
    temp->left = BuildHB0(h - 1);
    temp->data = count++;
    temp->right = BuildHB0(h - 1);
    return temp;
}
//Time complexity: O(n), Space complexity: O(logn)

//Problem 74: the orther way solving problem-73, Wa take the range
AVLTr* BuildHB0_P74(int l, int r) {
    if(l > r) {
        return NULL;
    }
    int mid = l + (r - l) / 2;
    AVLTr *temp = new AVLTr(mid);
    temp->left = BuildHB0_P74(l, mid - 1);
    temp->right = BuildHB0_P74(mid + 1, r);
    return temp; // return a subtree.
}
// Time complexity: O(n), Space complexity: O(logn)

//Problem 77: check whether the given binary search is the AVL trees or not.
int IsAVL(AVLTr *root) {
    if(!root){
        return 0;
    }
    int left = IsAVL(root->left); 
    if(left == -1) {
        return left;
    }
    int right = IsAVL(root->right); 
    if(right == -1) {
        return right;
    }
    if(std::abs(left - right) > 1) {
        return -1;
    }
    return std::max(left, right) + 1;
}
//Time complexity: O(n), Space complexity: O(n)


//Problem 78: Give a height h, generate an AVL tree with minimun numbers of nodes
AVLTr* GenerateAVLTree(int h) {
    static int count = 0;
    if(h == 0) {
        return NULL;
    }
    AVLTr *temp = new AVLTr(0);
    temp->left = GenerateAVLTree(h - 1);
    temp->data = count++;
    temp->right = GenerateAVLTree(h - 1);
    temp->height = h;
    return temp;
}

//Problem 79: Count the number of nodes in the range [a, b]
int RangeCount(AVLTr *root, int a, int b) {
    if(!root) {
        return 0;
    }
    if(root->data  > b) {
        return RangeCount(root->left, a, b);
    }
    if(root->data < a) {
        return RangeCount(root->right, a, b); 
    }
    return RangeCount(root->left, a, b) + RangeCount(root->right, a, b) + 1; 
}

//Problem 82: Given a BST and key, find the element in the BST which is cloest the given key.
AVLTr* ClosestInBST(AVLTr *root, int key) {
    int min_value = INT_MAX;
    AVLTr *min_ele = NULL;
    std::queue<AVLTr *> Q;
    if(!root) {
        return 0;
    }
    Q.push(root); 
    while(!Q.empty()) {
        AVLTr *temp = Q.front();
        Q.pop();
        int difference = std::abs(key - temp->data);
        if(min_value > difference) {
            min_value = difference;
            min_ele = temp;
        }
        if(temp->left) {
            Q.push(temp->left);
        }
        if(temp->right) {
            Q.push(temp->right);
        }
    }
    return min_ele;
}
//Time complexity: O(n), Space complexity: O(n)

//Problem 83: Solving problem 82 using the recursive approach
AVLTr* ClosestInBST_P83(AVLTr *root, int key){
    if(!root) {
        return NULL;
    }
    if(root->data == key) {
        return root;
    }
    if(root->data > key) {
        if(!root->right) {
            return root;
        }
        AVLTr *temp = ClosestInBST_P83(root->right, key);
        return (std::abs(temp->data - key)) < (std::abs(root->data - key)) ? temp : root;
    }
    if(root->data < key) {
        if(!root->left) {
            return root;
        }
        AVLTr *temp = ClosestInBST_P83(root->left, key);
        return (std::abs(temp->data - key)) < (std::abs(root->data - key)) ? temp : root;
    }
    return NULL;
}
//Time complexity: O(n) worst case, O(logn) average case.
//Spacc complexity: O(n) worst case, O(logn) average case.

//Problem 85: How do you remove all the hafl nodes(which have only one child)? Node that ew sould not rouch leaves.
AVLTr* removeHalfNodes(AVLTr *root) {
    if(!root) {
        return NULL;
    }
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);
    if(!root->left && !root->right) {
        return root; // This is leaf node.
    }
    if(!root->left) {
        return root->right; // remove root
    }
    if(!root->right) {
        return root->left; // remove root
    }
    return root; // this is parent node
}

// Time complexity: O(n)

//Problem 86: How do you remove its leaves? 
AVLTr* removeLeaves(AVLTr *root) {
    if(!root) {
        return root;
    }
    if(!root->left && !root->right) {
        delete root;
        root = NULL;
    }
    else {
        root->left = removeLeaves(root->left);
        root->right = removeLeaves(root->right);
    }
    return root;
}
// Time complexity: O(n)

//Problem 87: Given A BS and two integers as parameters, how do you remove(prune) elements that are not within that range? 
AVLTr* PruneBST(AVLTr *root, int A, int B) {
    if(!root) {
        return root;
    }
    root->left = PruneBST(root->left, A, B);
    root->right = PruneBST(root->right, A, B);
    if(root->data < A) {
        return root->right;
    }
    if(root->data > B) {
        return root->left;
    }
    return root;
}
//Time complexity: O(n) with worst case, O(logn) with average case.

//Problem 88: Connect all the adjacent nodes at the same level?

//Node 
struct BSTNode {
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode *next;
    BSTNode(int value): data(value), left(NULL), right(NULL), next(NULL) {}
};



void printTree(AVLTr *root) {
    if(!root) {
        return;
    }
    printTree(root->left);
    std::cout << root->data << std::endl;
    printTree(root->right);
}

int main(int argc, char const *argv[]){
    AVLTr *root = new AVLTr(49);
    // left subtree
    root->left = new AVLTr(37);
    root->left->left = new AVLTr(13);
    root->left->left->left = new AVLTr(7);
    root->left->left->right = new AVLTr(19);
    root->left->left->right->right = new AVLTr(25);
    root->left->right = new AVLTr(41);

    //right subtree
    root->right = new AVLTr(89);
    root->right->left = new AVLTr(53);
    root->right->left->right = new AVLTr(71);
    root->right->left->right->left = new AVLTr(60);
    root->right->left->right->right = new AVLTr(82);

    printTree(PruneBST(root, 24, 71)); 

    system("pause");
    return 0;
}