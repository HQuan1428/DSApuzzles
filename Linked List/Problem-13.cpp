/* 
Problem-43: deleting node given in the Singly linked list. 
Solution: moving the data from the next node into the current node and then deleting the next node. 
Time complexity: O(1), Space complexity: O(1).
Problem-44: Linked list with even and odd numbers, create an algorithm for making changes to the list in such a way that all even numbers appear at the beginning. 
Solution: the splitting logic 
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
    Node* getHead() {
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
    void Insert2(T val, Node *&head) {
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
    void DeleteWithConstComplexity(Node *currNode) {
        Node *temp = currNode->next; 
        currNode->data = temp->data; 
        currNode->next = temp->next; 
        delete temp; 
    }
    void DeleteTail(Node *head) {
        Node *temp = head;
        Node *prevNode = head; 
        if(!head) {
            cout << "List Empty" << endl; 
        }
        while(temp->next) {
            prevNode = temp; 
            temp = temp->next; 
        }
        prevNode->next = temp->next; 
        delete temp; 
    }
    Node* Problem_44(Node *head) {
        Node *newHead = NULL;
        Node *temp = head; 
        while(temp) {
            if(temp->data % 2) {
                Insert2(temp->data, newHead);
                Node *temp2 = temp->next;
                if(!temp2){
                    //delete temp;
                    DeleteTail(head);
                    break;
                } 
                temp->data = temp2->data; 
                temp->next = temp2->next; 
                delete temp2; 
            }
            else {
                temp = temp->next; 
            } 
        }
        Node *temp2 = newHead; 
        while(temp2->next) {
            temp2 = temp2->next; 
        }
        temp2->next = head;
        return newHead;  
    }
};

int main(int argc, char const *argv[]){
    ListNode <int> sll;
    for(int i = 1; i <= 6; i++) {
        sll.insert(i); 
    }
    sll.print(sll.getHead());
    sll.print(sll.Problem_44(sll.getHead()));
    system("pause");
    return 0;
}
