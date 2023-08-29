#include<bits/stdc++.h>
#define ll long long

using namespace std;

int blockSize; 

struct ListNode {
    int value;
    ListNode *next;
};
struct LinkedBlock {
    LinkedBlock *next;
    ListNode *head;
    int nodeCount;
};
LinkedBlock *blockHead; 

//create an empty block 
LinkedBlock* newLinkedBlock() {
    LinkedBlock *block = new LinkedBlock;
    block->next = NULL;
    block->head = NULL;
    block->nodeCount = 0; 
    return block;
}
//creat a node
ListNode* newListNode(int value) {
    ListNode *temp = new ListNode;
    temp->next = NULL;
    temp->value = value;
    return temp;
}
//function declared. 
void searchElement(int k, LinkedBlock **fLinkedBlock, ListNode **fListNode); 
void shift(LinkedBlock *A); 
void addElement(int k, int x); 
int searchElement(int k); 
int testUnRolledLinkedList(); 

int main(int argc, char const *argv[]){
    testUnRolledLinkedList();
    system("pause");
    return 0;
}

//function definition
void searchElement(int k, LinkedBlock **fLinkedBlock, ListNode **fListNode) {
    //find the block 
    int j = (k + blockSize - 1) / blockSize; // k-th node is int the j-th block. 
    LinkedBlock *p = blockHead; 
    for(int i = 1; i < j; i++) { // while(--j)
        p = p->next;
    }
    *fLinkedBlock = p; 
    
    //find the node. 
    ListNode *q = p->head; 
    k = k % blockSize; 
    if(k == 0){
        k = blockSize; 
    }
    k = p->nodeCount + 1 - k;
    while(k--) {
        q = q->next;
    }
    *fListNode = q;
}

void shift(LinkedBlock *A) {
    LinkedBlock *B; 
    ListNode *temp; 
    while(A->nodeCount > blockSize) {
        if(A->next == NULL){
            A->next = newLinkedBlock();
            B = A->next;
            temp = A->head->next;
            temp->next = temp; 
            A->head->next = A->head->next->next; 
            B->head = temp;
            A->nodeCount -= 1;
            B->nodeCount += 1;
        } else {
            B = A->next; 
            temp = A->head->next; 
            A->head->next = A->head->next->next; 
            temp->next = B->head->next;
            B->head->next = temp;  
            B->head = temp; 
            A->nodeCount -= 1; 
            B->nodeCount += 1; 
        }
        A = B; 
    }
}