//Efficient Approach: using two pointer (pNthNode and pTemp)
// pNthNode starts moving only after pTemp has made n moves. 
// From there both move forward until pTemp reaches the end of the list. 
// the result: pNtheNode points to n-th node from the end of the linked list. 
#include<bits/stdc++.h>
#define ll long long

using namespace std;

//implementation singly linked list. 
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
    Node* NthNodeFromEnd(){
        int n; 
        cout << "input n: "; cin >> n; 
        Node *pNthNode = NULL, *pTemp = head; 
        for(int count = 1; count < n; count++){
            pTemp = pTemp->next;
        }
        while(pTemp){
            if(!pNthNode){
                pNthNode = head;
            }
            else {
                pNthNode = pNthNode->next; 
            }
            pTemp = pTemp->next; 
        }
        return pNthNode; 
    }
};


int main(int argc, char const *argv[]){
    ListNode<int> *List; 
    int n = 5; 
    for(int i = 0; i < 5; i++){
        int x; cin >> x; 
        List->insert(x); 
    }
    auto tempNode = List->NthNodeFromEnd(); 
    cout << tempNode->data << endl; 
    system("pause");
    return 0;
}