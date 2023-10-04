/*
Problem-46: find modular node from the begin. 
    find the last element from the beginning whose n%k == 0. 
    Time complexity: O(n), Space complexity: O(1).
Problem-47: find modular node from the end. 
Solution: it is the same finding Kth elwmentt from the end of the linked list.
Problem-48: find fractional node
    Find the n/k element.
Solution: + Take two pointers temp and fractionalNode and initialize them with null and head respectively. 
          + For every k jumps of the temp pointers, make one jump of the fractionalNode. 
Problem-49: Find sqrt(n) Node 
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
    void print(Node *head) {
        Node *temp = head;
        while(temp){
            cout << temp->data << " "; 
            temp = temp->next;
        }
        cout << endl;
    }
    Node* modularNodefromBegin(int k, Node *head) {
        Node *ModularNode; 
        int i = 1; 
        if(k <= 0) {
            return nullptr;
        }
        while(head) {
            if(i % k == 0) {
                ModularNode = head;
            }
            i += 1;
            head = head->next;
        }
        return ModularNode;
    }
    Node* modularNodefromEnd(int k, Node *head) {
        Node *modularNode = head; 
        if(k <= 0) {
            return nullptr;
        }
        for(int i = 0; i < k; i++) {
            head = head->next;
        }
        while(head) {
            modularNode = modularNode->next;
            head = head->next;
        }
        return modularNode;
    }
    Node* FindfractionalNode(int k) {
        Node *temp = head; 
        Node *fractionalNode = NULL; 
        if(k <= 0 || !head) {
            return NULL;
        }
        int i = 0;
        while(temp) {
            if(i % k == 0) {
                if(fractionalNode == nullptr) {
                    fractionalNode = head;
                }
                else {
                    fractionalNode = fractionalNode->next;
                }
            }
            temp = temp->next;
            i += 1; 
        }
        return fractionalNode;
    }
    Node* FindsqrtN() {
        Node *temp = head;
        Node *sqrtNode = NULL;
        int i = 1, j = 1; 
        while(temp) {
            if(i == j*j) {
                if(sqrtNode == NULL) {
                    sqrtNode = head;
                }
                else {
                    sqrtNode = sqrtNode->next;
                }
                j++;
            }
            temp = temp->next;
            i++;
        }
        return sqrtNode;
    }
};

int main(int argc, char const *argv[]){
    ListNode <int> sll;
    for(int i = 5; i >= 1; --i) {
        sll.insert(i);
    }
    auto it = sll.FindfractionalNode(2);
    cout << it->data << endl;
    system("pause");
    return 0;
}