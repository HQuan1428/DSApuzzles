/*
    TOPIC-BINARY TREES: PROBLEM & SOLUTION
*/

#include <bits/stdc++.h>
#define ll long long
#define BTN  BinaryTreeNode

struct BinaryTreeNode
{
    int data;
    BTN *left;
    BTN *right;
    BTN(int value) : data(value), left(NULL), right(NULL) {}
};

//Problem 1: Find max element in binary tree
int findMaxRecursive(BTN *Root) {
    int root_val, left, right, max_val = INT_MIN;
    if(!Root) {
        root_val = Root->data;
        left = findMaxRecursive(Root->left);
        right = findMaxRecursive(Root->right); 
        max_val = std::max({max_val, left, root_val, right});
    }
    return max_val;
}

int findMaxIterative(BTN *Root) {
    std::queue<BTN *> qe;
    int max_val = INT_MIN;
    if(Root) {
        qe.push(Root);
    }
    while(!qe.empty()) {
        max_val = std::max(qe.front()->data, max_val);
        qe.pop(); 
        if(qe.front()->left) {
            qe.push(qe.front()->left);
        }
        if(qe.front()->right) {
            qe.push(qe.front()->right);
        }
    }
    return max_val;
}

//Problem 2: Search an element in binary tree
bool FindInBinaryTreeUsingRecursion(BTN *root, int data) {
    //base case: root == NULL
    if(!root) {
        return false;
    }
    else {
        if(data == root->data) {
            return true;
        }
        else {
            bool temp = FindInBinaryTreeUsingRecursion(root->left, data); 
            if(temp)
                return temp;
            else
                return FindInBinaryTreeUsingRecursion(root->right, data); 
        }
    }
    return false;
}

bool FindInBinaryTreeUsingLevelOrder(BTN *root, int data) {
    std::queue<BTN *> qe; 
    if(root)
        qe.push(root);
    while(!qe.empty()) {
        BTN *temp = qe.front(); 
        if(temp->data == data) {
            return true;
        }
        qe.pop(); 
        if(temp->left) {
            qe.push(temp->left); 
        }
        if(temp->right) {
            qe.push(temp->right);
        }
    }
    return false;
}


//Problem 3: Inserting element 
void InsertInBinaryTree(BTN *root, int data) {
    BTN *newNode = new BTN(data); 
    if(!newNode) {
        return;
    }
    if(!root) {
        root = newNode;
        return;
    }

    std::queue<BTN *> qe;
    if(!root) {
        qe.push(root);
    }
    while(!qe.empty()) {
        BTN *temp = qe.front();
        qe.pop(); 
        if(temp->left) {
            qe.push(temp->left);
        }
        else {
            temp->left = newNode;
            return;
        }
        
        if(temp->right) {
            qe.push(temp->right); 
        }
        else {
            temp->right = newNode;
            return;
        }
    }
}

//Problem 4: the size of binary tree
int SizeOfBinaryTree(BTN *root) {
    if(!root) {
        return 0;
    }
    return SizeOfBinaryTree(root->left) + SizeOfBinaryTree(root->right) + 1; 
}

int SizeOfBTUsingLevelOrder(BTN *root) {
    int count = 0;
    std::queue<BTN *> qe;
    if(root) {
        ++count;
        qe.push(root);
    }
    while(!qe.empty()) {
        BTN *temp = qe.front();
        qe.pop();
        count += 1; 
        if(temp->left) {
            qe.push(temp->left);
        }
        if(temp->right) {
            qe.push(temp->right);
        }
    }
    return count;
}

//Problem 5: print the level order data in reverse order. 
void LevelOrderTraversalInReverse(BTN *root) {
    std::queue<BTN *> Q;
    std::stack<int> S;
    if(root) {
        Q.push(root);
    }
    while(!Q.empty()) {
        BTN *temp = Q.front();
        Q.pop();
        S.push(temp->data);
        if(temp->left) {
            Q.push(temp->left);
        }
        if(temp->right) {
            Q.push(temp->right);
        }
    }
    while(!S.empty()) {
        std::cout << S.top() << std::endl;
        S.pop(); 
    }
}

//Problem 6: delete the tree
void DeleteBinaryTree(BTN *root) {
    if(root == NULL)
        return;
    DeleteBinaryTree(root->left);
    DeleteBinaryTree(root->right);
    delete root;
    root == NULL;
}

//Problem 7: find the height(or depth) of the binary tree
int HeightOfBinaryTree(BTN *root) {
    if(root == NULL)
        return 0;
    int leftHeight = HeightOfBinaryTree(root->left);
    int rightHeight = HeightOfBinaryTree(root->right);
    return std::max(leftHeight + 1, rightHeight + 1); 
}

int HeightOfBinaryTreeIteration(BTN *root) {
    std::queue<BTN *> Q;
    int level = 0;
    if(root) {
        Q.push(root); 
    }
    Q.push(NULL);
    while(!Q.empty()) {
        root = Q.front();
        Q.pop();
        
        // root == NULL thi front la mot leaf
        if(root == NULL) {
            if(!Q.empty()) {
                Q.push(NULL);
            }
            ++level;
        }
        else {
            if(root->left) {
                Q.push(root->left);
            }
            if(root->right) {
                Q.push(root->right);
            }
        }
    }
    return level;
}

//Problem 8: find the deepest element of binary tree
//Solution: Using level order traverse.
BTN* DeepestNode(BTN *root) {
    BTN *temp;
    std::queue<BTN *> Q; 
    if(root)
        Q.push(root); 
    while(!Q.empty()) {
        temp = Q.front();
        Q.pop(); 
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
    return temp;// node cuoi cung trong cay.
}

//Problem 9: delete element wiht data is given
BTN* findElement(BTN *root, int data) { 
    // PreOrder
    if(!root) {
        return NULL;
    }
    if(root->data == data) {
        return root;
    }
    findElement(root->left, data);
    findElement(root->right, data);
}
void DeleteElement(BTN *root, int data) {
    BTN *delNode = findElement(root, data);
    BTN *deepNode = DeepestNode(root);
    BTN *temp = delNode;
    delNode = deepNode;
    deepNode = delNode;
    delete delNode;
    delNode = NULL;
}

//Problem 10: find the number of leaves
int findNumberOfLeavesInBTusingLevelOrder(BTN *root) {
    int count = 0;
    std::queue<BTN *> Q;
    if(root) {
        Q.push(root); 
    }
    while(!Q.empty()) {
        BTN *temp = Q.front();
        Q.pop(); 
        if(temp->left == NULL && temp->right == NULL) {
            count += 1; 
        }
        else {
            if(temp->left) {
                Q.push(temp->left);
            }
            if(temp->right) {
                Q.push(temp->left);
            }
        }
    }
    return count;
}

//Problem 11: find number of full node in binary tree
int findNumberOfLeavesInBTusingLevelOrder(BTN *root)
{
    int count = 0;
    std::queue<BTN *> Q;
    if (root)
    {
        Q.push(root);
    }
    while (!Q.empty())
    {
        BTN *temp = Q.front();
        Q.pop();
        if (temp->left && temp->right)
        {
            count += 1;
        }
        else
        {
            if (temp->left)
            {
                Q.push(temp->left);
            }
            if (temp->right)
            {
                Q.push(temp->left);
            }
        }
    }
    return count;
}

//Problem 12: find numbers of half node
int findNumberOfLeavesInBTusingLevelOrder(BTN *root)
{
    int count = 0;
    std::queue<BTN *> Q;
    if (root)
    {
        Q.push(root);
    }
    while (!Q.empty())
    {
        BTN *temp = Q.front();
        Q.pop();
        if ((temp->left && temp->right == NULL) || (temp->left == NULL && temp->right))
        {
            count += 1;
        }
        else
        {
            if (temp->left)
            {
                Q.push(temp->left);
            }
            if (temp->right)
            {
                Q.push(temp->left);
            }
        }
    }
    return count;
}

//Problem 13: check tructurally identical 
bool AreStructurallySameTree(BTN *root1, BTN *root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    if(root1 == NULL && root2 == NULL) {
        return false;
    }
    return root1->data == root2->data && AreStructurallySameTree(root1->left, root2->left) && AreStructurallySameTree(root1->right, root2->left);
}

//Problem 14 : find the diameter of the binary tree
int findDiamesterOfTree(BTN *root, int &diameter) {
    if(!root) {
        return 0;
    }
    int leftHeight = findDiamesterOfTree(root->left, diameter);
    int rightHeight = findDiamesterOfTree(root->right, diameter);
    diameter = std::max(diameter, leftHeight + rightHeight);
    return std::max(leftHeight, rightHeight) + 1; 
}

//Problem 15: find the level that has the maximum sum in the tree
int findLevelwithMaxSum(BTN *root) {
    BTN *temp;
    int Level = 0, maxLevel = INT_MIN;
    int currentSum = 0, maxSum = INT_MIN;
    std::queue<BTN *> Q; 
    if(!root) {
        return 0;
    }
    Q.push(root);
    Q.push(NULL); 
    while(!Q.empty()) {
        temp = Q.front();
        Q.pop(); 
        if(temp == NULL) { 
            if(currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = Level;
            }
            currentSum = 0; // resert currentSum each of level.
            if(!Q.empty()) {
                Q.push(NULL); 
            }
            Level += 1; 
        }
        else {
            currentSum += temp->data; 
            if(temp->left) {
                Q.push(temp->left); 
            }
            if(temp->right) {
                Q.push(temp->right); 
            }
        }
    }
    return maxLevel;
}

//Problem 16: print out all its root-to-leaf paths
void findPathRecur(BTN *root, int path[], int pathlen) {
    if(!root){
        return;
    }
    path[pathlen] = root->data; 
    if(!root->left && !root->right) {
        printPath(path, pathlen);
    }
    else {
        if(root->left) {
            findPathRecur(root->left, path, pathlen + 1);
        }
        if(root->right) {
            findPathRecur(root->right, path, pathlen + 1); 
        }
    }
}
void printPath(int p[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

//Problem 17: Check the existence of path with given sum
bool CheckPathEqualSum(BTN *root, int sum, int sumPath) {
    if(!root) {
        return false;
    }
    if(!root->left && !root->right && sumPath == sum) {
        return true;
    }

    if(root->left) {
        CheckPathEqualSum(root->left, sum, sumPath + root->data); 
    }
    if(root->right) {
        CheckPathEqualSum(root->right, sum, sumPath + root->data); 
    }
}

bool CheckPathEqualSum2(BTN *root, int sum) {
    if(!root) {
        return false;
    }
    bool ans = false;
    sum -= root->data;
    if(sum == 0 && root->left == NULL && root->right == NULL) {
        return true;
    }
    if(root->left) {
        ans = CheckPathEqualSum2(root->left, sum); 
    }
    if(root->right) {
        ans = CheckPathEqualSum2(root->right, sum); 
    }
    return ans;//bien xac nhan
}

//Problem 18: finding the sum of all elements in binary tree
int Add(BTN *root) {
    if(!root) {
        return 0;
    }
    return root->data + Add(root->left) + Add(root->right);
}

int sumOfBTUsingLevelOrder(BTN *root) {
    std::queue<BTN *> Q; 
    int sum = 0; 
    if(root) {
        Q.push(root);
    }
    while(!Q.empty()) {
        BTN *temp = Q.front(); 
        Q.pop();
        sum += temp->data;
        if(temp->left) {
            Q.push(temp->left);
        }
        if(temp->right) {
            Q.push(temp->right);
        }
    }
    return sum;
}

//Problem 19: converting a tree to its mirror. 
BTN* MirrorOfBinaryTree(BTN *root) {
    // if(!root) {
    //     return NULL;
    // }
    // BTN *temp = root->left;
    // root->left = root->right;
    // root->right = temp;
    // MirrorOfBinaryTree(root->left);
    // MirrorOfBinaryTree(root->right);
    // return root;

    if(root) {
        MirrorOfBinaryTree(root->left); 
        MirrorOfBinaryTree(root->right);
        BTN *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

//Problem 20: checking the two tree mirror of each other. 
bool AreMirros(BTN *root1, BTN *root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    if(root1 == NULL || root2 == NULL) {
        return false;
    }
    if(root1->data != root2->data) {
        return false; 
    }
    return AreMirros(root1->left, root2->right) && AreMirros(root1->right, root2->left); 
}

//Problem 21: LCA(Least Common Acestor)  
BTN* LCA(BTN *root, BTN *child1, BTN *child2) {
    if(root == NULL)
        return root;
    if(root == child1 || root == child2)
        return root;
    BTN *left = LCA(root->left, child1, child2);    //search left subtree 
    BTN *right = LCA(root->right, child1, child2);  //search right subtree
    /*
    if left and right exist, root is ancestor of two nodes left and right.
    else left exist return left and right. 
    */
    if(left && right) {
        return root; 
    }
    else {
        return left ? left : right;
    }
}

//Problem 22: constructing binary tree from given Inorder and Preorder 
BTN* BuildBinaryTree(int inOrder[], int preOrder[], int inOderStart, int inOderEnd) {
    static int preOderIndex = 0;
    if(inOderStart > inOderEnd) {
        return NULL;// stop condition. 
    }
    BTN *newNode = new BinaryTreeNode(preOrder[preOderIndex]);
    preOderIndex += 1; 
    if(inOderStart == inOderEnd) {
        return newNode;
    }
    int inOrderIndex = 0; 
    for (int i = inOderStart; i <= inOderEnd; i++) {
        if(inOrder[i] == newNode->data) {
            inOrderIndex == i;
            break;
        }
    }
    newNode->left = BuildBinaryTree(inOrder, preOrder, inOderStart, inOrderIndex - 1);
    newNode->right = BuildBinaryTree(inOrder, preOrder, inOrderIndex + 1, inOderEnd);
    return newNode;
}

//Problem 23: print all the ancestors
bool PrintAllAncestors(BTN *root, BTN *node) {
    if(root) {
        return false;
    }
    if(root->left == node || root->right == node || PrintAllAncestors(root->left, node) || PrintAllAncestors(root->right, node)) {
        std::cout << root->data << " ";
        return true;
    }
    return false;
}

//Problem 24: Zigzag tree traversal:
void ZigzagTraversal(BTN *root) {
    if(!root) {
        return;
    }
    bool leftToright = true;
    std::stack<BTN *> nextLevel;
    std::stack<BTN *> currentLevel; 
    currentLevel.push(root); 
    while(!currentLevel.empty()) {
        BTN *temp = currentLevel.top();
        currentLevel.pop(); 
        if(temp) {
            std::cout << temp->data << " "; 
            if(leftToright) {
                if(temp->left)
                    nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);
            }
            else {
                if(temp->right)
                    nextLevel.push(temp->right);
                if(temp->left)
                    nextLevel.push(temp->left);
            }
        }
        //true is finish one level of tree
        if(currentLevel.empty()) {
            leftToright = !leftToright;
            std::swap(currentLevel, nextLevel); 
        }
    } 
}

// Problem 25: the vertical sum of binary tree. 
void VerticalSumBinaryTree(BTN *root, int column, int hash[]) {
    if(root == NULL) {
        return;
    }

    VerticalSumBinaryTree(root->left, column - 1, hash);
    hash[column] += root->data;
    VerticalSumBinaryTree(root->right, column + 1, hash);
}

//Problem 26: construct the tree with preorder traversal of this tree
BTN* BuildTreeFromPreOrder(char *A, int *i) {
    BTN *newNode = new BTN((int)A[*i]); 
    if(A == NULL) {
        delete newNode;
        newNode = NULL;
        return NULL;
    }
    if(A[*i] == 'L') {
        return newNode;
    }
    *i = *i + 1;
    newNode->left = BuildTreeFromPreOrder(A, i);
    *i = *i + 1;
    newNode->right = BuildTreeFromPreOrder(A, i);

    return newNode;
}

//Problem 27: 



int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}