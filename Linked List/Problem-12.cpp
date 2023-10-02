/* Problem: Cloning the list 
Solution: 
1. HashTable

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
        Node(const T& val): data(val), next(nullptr) {}
    };
    Node *head;
public:
    ListNode(): head(nullptr) {}
    Node* getHead() {
        return this->head;
    }
    void Insert(const T& val) {
        Node *newNode = new Node(val);
        if(!head) {
            head = newNode;
            return;
        }
        Node *temp = head; 
        while(temp->next) {
            temp = temp->next; 
        }
        temp->next = newNode; 
    }
    void print(Node *head) {
        if(!head){
            cout << "list is empty" << endl;
            return;
        }
        while(head) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    Node* clone(Node *head) {
        Node *X, *Y; 
        map <Node*, Node*> mp; 
        X = head;
        //created HashTable. 
        while(X) {
            Y = new Node(X->data); 
            mp.insert(X, Y); 
            X = X->next;
        }
        //associate
        X = head; 
        while(X) {
            Y = mp[X];
            Y->next = mp[X->next]; 
            X = X->next; 
        }
        return mp[head]; 
    }
};



int main(int argc, char const *argv[]){
    ListNode <int> sll;
    for(int i = 1; i <= 10; i++) {
        sll.Insert(i); 
    }
    sll.print(sll.getHead());
    sll.print(sll.clone(sll.getHead()));
    system("pause");
    return 0;
}