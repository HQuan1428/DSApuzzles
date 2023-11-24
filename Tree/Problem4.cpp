/*
    TOPIC-THE PROBLEMS OF BSTs
*/


#include <bits/stdc++.h>
#define ll long long
#define BSTsNode BinarySearchTreesBSTsNode
//Each BSTsNode
struct BinarySearchTreesBSTsNode
{
    int data;
    BinarySearchTreesBSTsNode *left;
    BinarySearchTreesBSTsNode *right;
    BinarySearchTreesBSTsNode(int value) : data(value), left(NULL), right(NULL) {}
};

//Problem 47: Find the lowest common ancestor(LCA)
BSTsNode* FindLCA(BSTsNode *root, BSTsNode *a, BSTsNode *b) {
    int min_value = a->data > b->data ? b->data : a->data;
    while(!root) { 
        if((root->data > a->data && root->data < b->data) || (root->data < a->data && root->data > b->data)){
            return root;
        }
        if(min_value < root->data) {
            root = root->left; 
        }
        else {
            root = root->right;
        }
    }
    return root;
}

BSTsNode* FindNode(BSTsNode *root, int data) {
    if(!root) {
        return NULL; 
    }
    std::queue<BSTsNode *> Q;
    Q.push(root); 
    while(!Q.empty()) {
        BSTsNode *temp = Q.front();
        Q.pop(); 
        if(temp->data == data) {
            return temp; 
        }
        if(temp->left) {
            Q.push(temp->left);
        }
        if(temp->right) {
            Q.push(temp->right);
        }
    }
    return NULL;
}

//Problem 50-52-53: Check whether the given binary tree is a BST or not?
/*
This approach is wrong as this will return tree for binary tree below
          5
        /   \
       /     \
      3       8
     / \     / \
    2   4   7   9
           /
          1
*/
bool isBST(BSTsNode *root) {
    if(!root) {
        return true;
    }
    if(root->left && root->left->data > root->data) {
        return false;
    }
    if(root->right && root->right->data < root->data) {
        return false;
    }
    if(!isBST(root->left) || !isBST(root->right)){
        return false;
    }
    return true;
}

//the correct algorithm 
BSTsNode* FindMax(BSTsNode *root) {
    if(!root) {
        return NULL;
    }
    if(!root->right) {
        return root;
    }
    return FindMax(root->right);
}
BSTsNode* FindMin(BSTsNode *root) {
    if (!root){
        return NULL;
    }
    if(!root->left) {
        return root;
    }
    return FindMin(root->left); 
}

bool IsBST(BSTsNode *root) {
    if(!root) {
        return true;
    }
    if(root->left && FindMax(root->left)->data > root->data) {
        return false;
    }
    if(root->right && FindMin(root->right)->data < root->data) {
        return false;
    }
    if(!IsBST(root->left)|| !IsBST(root->right)) {
        return false;
    }
    return true; 
}
// Time Complexity: O(n^2) - Space Complexity: O(n)

// Improve the complexity of algorithm the problem above

/*
Solution: 
*/
bool isBST_P52(BSTsNode *root, int minkey, int maxkey) {
    if(!root) {
        return true;
    }
    return {root->data > minkey &&
            root->data < maxkey &&
            isBST_P52(root->left, minkey, root->data) &&
            isBST_P52(root->right, root->data, maxkey)};
}

/*
Solution: Intuition says that the in-order traversal for the BST results in a sorted list of nodes. (Problem 53 of the tree refer)
Time Complexity: O(n) - Space Complextity: O(n)
*/
bool isBSTs_P53(BSTsNode *root, int prev_val) {
    if(!root) {
        return true;
    }
    if (!isBSTs_P53(root->left, prev_val)){
        return false;
    }
    if(root->data < prev_val) {
        return false;
    }
    return isBSTs_P53(root->right, root->data); 
}

//Problem 56: Convert a sorted DLL to BSTs
/*
Solution: 
    - Find mid of Linked list
    - Recursive two halves of linked list. 
        + The Prev pointer point the mid left of DLL. 
        + The Next Pointer point the mid right of DLL. 
*/

//Problem 57: Convert a sorted array to BSTs
/*
Solution:
    - The algotithm is similar to the one in problem 56. But there are still differences:
        + We need to creat a node for each element in Linked list. 
*/
// Start My Code
BSTsNode* ConvertArr(int a[], int left, int right) {
    if(left > right) {
        return NULL;
    }
    BSTsNode *newNode = new BSTsNode(0);
    if(left == right) {
        newNode->data = a[left];
    }
    else{
        int mid = (right - left) / 2 + left;
        newNode->data = a[mid]; 
        newNode->left = ConvertArr(a, left, mid - 1);
        newNode->right = ConvertArr(a, mid + 1, right); 
    }
    return newNode;
}

//End My Code

// Problem 60: Finding the Kth smallest element in BST
BSTsNode* KthSmallestInBST(BSTsNode *root, int k, int *count) {
    if(!root) {
        return NULL;
    }
    BSTsNode *left = KthSmallestInBST(root->left, k, count); 
    if(left) {
        return left;
    }
    if(++(*count) == k) {
        return root;
    }
    return KthSmallestInBST(root->right, k, count);
}  

//Problem 61: Floor and ceiling
void FloorInBSTUtil(BSTsNode *, BSTsNode *&, int);
BSTsNode* FloorInBSTs(BSTsNode *root, int data) {
    BSTsNode *prev = NULL;
    FloorInBSTUtil(root, prev, data);
    return prev;
}
void FloorInBSTUtil(BSTsNode*root, BSTsNode *&prev, int data) {
    if(!root) {
        return;
    }
    FloorInBSTUtil(root->left, prev, data);
    if(root->data == data) {
        return;
    }
    if(root->data > data) {
        return;
    }
    prev = root;
    FloorInBSTUtil(root->right, prev, data);
}

void CeilInBSTUtil(BSTsNode *, BSTsNode *&, int);
BSTsNode *CeilInBSTs(BSTsNode *root, int data)
{
    BSTsNode *prev = NULL;
    CeilInBSTUtil(root, prev, data);
    return prev;
}
void CeilInBSTUtil(BSTsNode *root, BSTsNode *&prev, int data)
{
    if (!root)
    {
        return;
    }
    CeilInBSTUtil(root->right, prev, data);
    if (root->data == data)
    {
        return;
    }
    if (root->data < data)
    {
        return;
    }
    prev = root;
    CeilInBSTUtil(root->left, prev, data);
}

//Problem 62-63-64: Finding the union and intersection of BSTs

//Problem 65: print all the element of BST int he range K1 and K2
void RangePrint(BSTsNode *root, int k1, int k2) {
    if(!root) {
        return;
    }
    if(root->data >= k1)
        RangePrint(root->left, k1, k2); 
    if(root->data >= k1 && root->data <= k2) {
        std::cout << root->data << " "; 
    }
    if(root->data <= k2)
        RangePrint(root->right, k1, k2); 
}

//another way solving problem 65
//Solution: Using level traversal, adding the element to queue then check for the range 
void RangePrint_P66(BSTsNode* root, int k1, int k2) {
    if(!root){
        return;
    }
    std::queue<BSTsNode *> Q;
    Q.push(root); 
    while(!Q.empty()) {
        BSTsNode *temp = Q.front();
        Q.pop(); 
        if(temp->data >= k1 && temp->data <= k2) {
            std::cout << temp->data << " "; 
        }
        if (temp->left && temp->left->data <= k2) {
            Q.push(temp->left);
        } 
        if(temp->right && temp->right->data >= k1) {
            Q.push(temp->right); 
        }
    }
}


//Problem 70: check the elements of BSTs the same or not 
bool areTheSameBST (BSTsNode *root1, BSTsNode *root2) {
    if(!root1 && !root2) {
        return true;
    }
    if(!root1 || !root2) {
        return false;
    }
    areTheSameBST(root1->left, root2->left);
    if(root1->data != root2->data) {
        return false;
    }
    return areTheSameBST(root1->right, root2->right); 
}

//Problem 71: How many structurally unique BSTs are possible that store those key values. 
int CountTrees(int n) {
    if (n <= 1){
        return 1;
    }
    int sum = 0;
    int left, right;
    for (int root = 1; root <= n; root++) {
        left = CountTrees(root - 1);
        right = CountTrees(n - root);
        sum += left * right;
    }
    return sum;
}

//Problem 72:
int keyCount = 0; 
void GreaterConstant(BSTsNode *r, int k) {
    if(!r) {
        return;
    }
    if(r->data > k) {
        GreaterConstant(r->left, k);
    }
    if(r->data > k) {
        keyCount += 1; 
    }
    GreaterConstant(r->right, k); 
}

int main(int argc, char const *argv[]) {
    /* Construct the following tree
          5
        /   \
       /     \
      3       8
     / \     / \
    2   4   7   9
           /
          6
    */
    BSTsNode *root = new BSTsNode(5);
    root->left = new BSTsNode(3);
    root->right = new BSTsNode(8);
    root->left->left = new BSTsNode(2);
    root->left->right = new BSTsNode(4);
    root->right->left = new BSTsNode(7);
    root->right->right = new BSTsNode(9);
    root->right->left->left = new BSTsNode(6);
    //root->right->left->right = new BSTsNode(8);
    //std::cout << isBST_P52(root, INT_MIN, INT_MAX) << std::endl;
    //RangePrint_P66(root, 4, 11);
    // BSTsNode *root1 = new BSTsNode(10);
    // root1->left = new BSTsNode(5);
    // root1->right = new BSTsNode(20);
    // root1->right->left = new BSTsNode(15);
    // root1->right->right = new BSTsNode(30);
    // BSTsNode *root2 = new BSTsNode(10);
    // root2->left = new BSTsNode(5);
    // root2->right = new BSTsNode(15);
    // root2->right->right = new BSTsNode(30);
    // root2->right->right->left = new BSTsNode(20);
    // if(areTheSameBST(root1, root2)) {
    //     std::cout << "they are similar.\n";
    // }
    // else {
    //     std::cout << "they aren't similar. \n";
    // }
    // std::cout << CountTrees(3) << std::endl;
    // system("pause");
    GreaterConstant(root, 5);
    std::cout << keyCount << std::endl;
    system("pause");
    return 0;
}