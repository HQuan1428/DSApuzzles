/*Problem-32: Reverse the linked list in pairs
    *Note: Remember to connect the node after the current pair to the reversed list.     
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
    struct SeacondList {
        Node *fiHead; 
        Node *seHead;
        SeacondList() : fiHead(nullptr), seHead(nullptr) {}
    };
    Node *head;
    SeacondList *TwoList;
public:
    ListNode() : head(nullptr) {}
    Node* gethead() {
        return head;
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
            cout << temp->data << ' '; 
            temp = temp->next;
        }
        cout << endl;
    }
    Node* ReversePairRecusive(Node *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* temp; 
        temp = head->next;
        head->next = temp->next; 
        temp->next = head; 
        head = temp; 
        head->next->next = ReversePairRecusive(head->next->next); 
        return head;
    }
    Node* ReversePairIterative(Node *head) {
        Node *newHead = nullptr; 
        Node *current = head;
        Node *Next = nullptr;
        while(current != nullptr && current->next != nullptr) {
            if(Next != nullptr) {
                Next->next->next = current->next;
            }
            Next = current->next;
            current->next = Next->next; 
            Next->next = current; 
            if(newHead == NULL){
                newHead = Next;
            }
            current = current->next;
        }
        return newHead;
    }
};

int main(int argc, char const *argv[]){
    ListNode<int> SLL; 
    SLL.insert(5);
    SLL.insert(4);
    SLL.insert(3);
    SLL.insert(2);
    SLL.insert(1);
    SLL.print(SLL.gethead());
    SLL.print(SLL.ReversePairIterative(SLL.gethead()));
    SLL.print(SLL.ReversePairRecusive(SLL.gethead()));
    system("pause");
    return 0;
}