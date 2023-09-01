#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*Problem-15:Insert a node in a sorted Linked List. 
Solution: Traverse the list and find a position for the element and insert it.
    Time complexity: O(n). 
    Space complexity: O(1).  
*/
/*Problem-16: reverse a singly linked list.
    Time complexity: O(n). 
    Space complexity: O(1)
Recursive version: 
    Time complecity: O(n).
    Space complexity: O(n).
*/
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

    Node* getNode(){
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
    void InsertNodeOfTheSortedLinkedList(T data){
        Node *newNode = new Node(data);
        Node *current = head, *temp = NULL;
        if(!head){
            cout << "LIST EMPTY\n"; 
            return;
        }
        while(current && current->data < newNode->data){
            temp = current; 
            current = current->next; 
        }
        if(temp){
            newNode->next = current; 
            temp->next = newNode;
        } else {
            newNode->next = head; 
            head = newNode;
        }
    }
    Node* Reverse() {
        Node *current = NULL;
        Node *temp = NULL;
        if(!head){
            cout << "LIST EMPTY\n"; 
            return head;
        } 
        while(head){
            temp = head;
            head = head->next; 
            temp->next = current;
            current = temp;
        }
       return temp;
    }
    Node* recursiveReverse(Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *secondElem = head->next; 
        head->next = NULL;
        Node *reverseRest = recursiveReverse(secondElem);
        secondElem->next = head;
        return reverseRest;
    }
};
int main(int argc, char const *argv[]){
    ListNode<int> SLL; 
    SLL.insert(5);
    SLL.insert(4);
    SLL.insert(2);
    SLL.insert(1);
    SLL.print(SLL.getNode());
    SLL.print(SLL.Reverse());
    SLL.print(SLL.recursiveReverse(SLL.getNode())); 
    system("pause");
    return 0;
}