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
        this->head;
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
    //get the middle of the linked list. 
    Node* getMiddle(){
        Node *fastPtr = head, *slowPtr = head; 
        while(fastPtr->next && fastPtr->next->next){
            slowPtr = slowPtr->next; 
            fastPtr = fastPtr->next->next;
        }
        Node *Mid = slowPtr->next;
        slowPtr->next = NULL;
        return Mid;
    }
    //Reverse the second half of the linked list 
    Node* Reverse(Node *head){ 
        if(!head || !head->next) {
            return head;
        }
        Node *temp = head->next;
        head->next = nullptr; 
        Node *res = Reverse(temp);
        temp->next = head; 
        return res;
    }
    //compare two list
    int compare(Node *head1, Node *head2) {
        while(head1 && head2){
            if(head1->data != head2->data) {
                return 0;
            }
            head1 = head1->next; 
            head2 = head2->next;
        }
        if(head1 || head2) {
            return 0;
        }
        return 1; 
    }
    //solving Solution 
    void isPalindrome(){
        Node *temp1 = head; 
        Node *temp2 = getMiddle(); 
        temp2 = Reverse(temp2);
        print(temp1);
        print(temp2); 
        if(compare(temp1, temp2)) {
            cout << "Palindrome\n";
        }
        else cout << "No Palindrome\n";
    }
};

int main(int argc, char const *argv[]){
    ListNode<int> sll;
    sll.insert(1);
    sll.insert(2);
    sll.insert(2);
    sll.insert(1);
    sll.insert(3);
    sll.isPalindrome();
    system("pause");
    return 0;
}