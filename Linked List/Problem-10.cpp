/*
Problem-38: For a given K value (k > 0) reverse blocks of K nodes in a list. 
Solution: To reverse blocks of K nodes in a list, we simply need to move each node except the first node in fornt of 
the first node one by one and repeat process untill the loop ends.
*/


#include<bits/stdc++.h>
#define ll long long

using namespace std;
template <typename T> 
class ListNode {
private:
    struct Node {
        T data; 
        Node *next; 
        Node(const T& val) : data(val), next(nullptr) {}
    };
    Node *head;
public:
    ListNode() : head(nullptr) {}
    Node *getHead(){
        return this->head;
    }
    void insert(T val) {
        Node *newNode = new Node(val); 
        if(!head){
            head = newNode;
            return;
        }
        newNode->next = head; 
        head = newNode;
    } 
    void print(Node *head) {
        Node *temp = head;
        while(temp){
            cout << temp->data << " "; 
            temp = temp->next;
        }
        cout << endl;
    }
    //k: number of block.
    //head: Node begin of block.
    //Function:  swapping block with Node start is head and number of blocks is k. 
    Node* ReverseOfBlocks_Recursive(int k, Node *head) {
        //stop condition. 
        if(!head) {
            return nullptr;
        }
        //variable declaration 
        Node *cur = head;
        Node *prevNode = nullptr;
        Node *nextNode = nullptr;
        int count = 0; // count number of Node traversed. 

        //Swapping. 
        while(cur && count < k) {
            nextNode = cur->next; 
            cur->next = prevNode; 
            prevNode = cur; 
            cur = nextNode;
            count++; 
        }
        //recursively call for the list starting from current.
        //Both cur and nextNode serve the same purpose. 
        if(cur /*nextNode*/ != nullptr) {
            head->next = ReverseOfBlocks(k, cur);
        }
        return prevNode;
    }
    Node* ReverseOfBlock_Iterative(int k, Node *head) {
        //head is null and k = 1 or 0 return head. 
        if(!head || k == 1 || k == 0) {
            return head;
        } 
        //using var stored node start of new list. 
        Node *dummy = new Node(-1); 
        dummy->next = head; 
        //declaration var prevNode, currNode, nextNode 
        Node *prevNode = dummy; //stored node finish of block.
        Node *currNode = dummy; //stored node start of block.
        Node *nextNode = dummy; //stored node must be moved in front of the first node. 
        int count = 0; 
        //count length of list. 
        while(currNode->next) {
            currNode = currNode->next;  
            count++;
        }
        while(nextNode) {
            //set curr points node start of block. 
            currNode = prevNode->next; 
            //set next points Node next curr
            nextNode = currNode->next;
            if(count < k) break;
            for(int i = 1; i < k; i++) {
                currNode->next = nextNode->next; 
                nextNode->next = prevNode->next; 
                prevNode->next = nextNode; 
                nextNode = currNode->next;
            }
            prevNode = currNode;
            count -= k; 
        }
        return dummy->next; 
    }
};

int main(int argc, char const *argv[]){
    ListNode <int> sll;
    for(int i = 12; i >= 1; --i){
        sll.insert(i);
    }
    sll.print(sll.ReverseOfBlock_Iterative(3, sll.getHead()));
    system("pause");
    return 0;
}