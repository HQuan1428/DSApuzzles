#include <bits/stdc++.h>

template <class T>
class BinaryTree
{
private:
    struct BinaryTreeNode
    {
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        BinaryTreeNode(int value) : data(value), left(NULL), right(NULL){}
    };
    BinaryTreeNode *Root;

public:
    BinaryTree() : Root(NULL){}

    // Operation
    void PreOrder(BinaryTreeNode *R) {
        if(!R) {
            std::cout << R->data << std::endl;
            PreOder(R->right);
            PreOrder(R->left);
        }
    }
    void PreOrderNonRecursive() {
        BinaryTreeNode *temp = Root; 
        std::stack<BinaryTreeNode> S; 
        while(1) {
            while(temp) {
                std::cout << temp->data << std::endl;
                S.push(temp);
                temp = temp->left;
            } 
            if(!S.empty()) {
                break;
            }
            temp = S.top();
            S.pop();
            temp = temp->right;
        }
    }
    void InOrder(BinaryTreeNode *R) {
        if(!R){
            InOrder(R->left);
            std::cout << R->data << std::endl;
            InOrder(R->right);
        }
    } 
    void InOrderNonRecursive() {
        std::stack<BinaryTreeNode> S;
        BinaryTreeNode *Temp;
        while(1) {
            while(Temp) {
                S.push(Temp);
                Temp = Temp->left;
            }
            if(!S.empty()) {
                break;
            }
            Temp = S.top();
            S.pop();
            std::cout << Temp->data << std::endl;
            Temp->right;
        } 
    }
    void PostOrder(BinaryTreeNode *R) {
        if(!R) {
            PostOrder(R->left);
            PostOrder(R.right);
            std::cout << R->data << std::endl;
        }
    }
    void PostOrderNonRecursive() {
        BinaryTreeNode *Temp = Root;
        std::stack<BinaryTreeNode> S;
        BinaryTreeNode *previous = NULL; 
        do {
            while(Temp) {
                S.push(Temp);
                Temp = Temp->left;
            }

            while(Temp == NULL && !S.empty()) {
                Temp = S.top(); 
                if(Temp->right == NULL || Temp->right == previous) {
                    std::cout << Temp.data << std::endl;
                    S.pop();
                    previous = Temp;
                    Temp == NULL;
                } else {
                    Temp = Temp->right;
                }
            }
        } while (!S.empty());
    }
    void LevelOrder() {
        BinaryTreeNode *Temp = Root;
        std::queue<BinaryTreeNode> qe; 
        if(Temp) {
            qe.push(Temp);
        }
        while(!qe.empty()) {
            Temp = qe.front();
            qe.pop();
            std::cout << Temp->data << std::endl;
            if(Temp->left) {
                qe.push(Temp->left);
            }
            if(Temp->right) {
                qe.push(Temp->right);
            }
        }
    }
};

//Generic Trees
struct TreeNode {
    int data;
    TreeNode *firstChild;
    TreeNode *nextSibling; 
};


int main(int argc, char const *argv[]) {
    std::cout << "hello world" << std::endl;
    system("pause");
    return 0;
}
