/*
Problem-55: Given a list, List1 = {A1, A2,...., An-1, An} with data, reorder it ro {A1, A2,...., An-1, An} without using any extra space. 
Solution: Find the middle node of the linked list, we reverse the right half then we so for in a palace merge of the two halves
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
    void print() {
        Node *temp = head;
        while(temp){
            cout << temp->data << endl; 
            temp = temp->next;
        }
    }
    void orderList() {
        Node *temp = NULL; 
        //find the middle of the list
        Node *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next; 
        slow->next = NULL; 
        slow = fast;
        //reverse
        Node *cur = slow; 
        while(cur) {
            Node *t = cur->next;
            cur->next = temp; 
            temp = cur;
            cur = t;
        }
        //merge 
        temp = NULL; 
        fast = head;
        while(fast && slow) {
            temp = fast->next; 
            fast->next = slow; 
            fast = temp; 
            temp = slow->next;
            slow->next = fast; 
            slow = temp; 
        }
    }
};

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}