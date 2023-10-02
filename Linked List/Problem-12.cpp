/* Problem: Cloning the list 
Solution: 
1. HashTable
    Time complexity: O(n), Space complexity: O(n).
2. optimus space complexity. 
    Step1:  put temp->random in temp2
            So that we can reuse the temp->random field to point to temp2.
    Step2:  setting temp2->random. temp2->next is the old copy of the node that
            temp2->random shold point to, so temp->next->random is the new copy.
    Step3:  Repair damage to old list and fill in next pointer in new list.
    Time complexity: O(n), Space complexity: O(1). 
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
        Node *random; 
        Node(const T& val): data(val), next(nullptr), random(nullptr) {}
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
            Y->random = mp[Y->random]; 
            X = X->next; 
        }
        return mp[head]; 
    }
    Node* Clone2(Node *head) {
        Node *cur, *temp;
        //step 1 
        cur = head; 
        while(cur) {
            temp = new Node(cur->data); 
            temp->next = cur->random;
            cur->random = temp; 
            cur = cur->next; 
        }
        //step 2
        cur = head; 
        while(cur) {
            temp = cur->random; 
            temp->random = temp->next->random; 
            cur = cur->next; 
        }
        Node *newHead = head->random; 
        //step 3. 
        cur = head; 
        while(cur) {
            temp = cur->random;
            cur->random = temp->next;  
            temp->next = cur->next->random; 
            cur = cur->next; 
        }
        return newHead;
    }

};



int main(int argc, char const *argv[]){
    ListNode <int> sll;
    for(int i = 1; i <= 10; i++) {
        sll.Insert(i); 
    }
    sll.print(sll.getHead());
    sll.print(sll.Clone2(sll.getHead()));
    system("pause");
    return 0;
}