/*
Problem-28: display from the end of the list.
->Solution: traverse recursively till the end of the linked list. While coming coming back, start printing the elements.
->Time/Space complexity: O(n). 
Problem-29: check whether the given linked list length is even or odd. 
->Solution: Use a 2x pointer. Take a pointer that moves at 2x [two nodes at a time]. At the end, if the length is even, then the pointer will be NULL;
  otherwise it will point to the last node.
->Time complexity: O(n).
->Space complexity: O(1).
Problem-30: if the head of a linked list is pointing to kth element, then how will you get the elements before kth element? 
->Solution: Use Memory Efficient linked lists[XOR linked lists].
Problem-31: how to merge two sorted list into the third list in sorted order?
->Solution: 
    -Recursive: Time complexity O(n+m).
    -iterrative: Time complexity O(n+m).
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
    Node* getHead(){
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
            cout << temp->data << " "; 
            temp = temp->next;
        }
        cout << endl;
    }
    void PrintListFromEnd(Node *head){
        if(!head){
            cout << endl;
            return;
        }
        PrintListFromEnd(head->next); 
        cout << head->data << " "; 
    }
    bool IsLinkedListLengthEven(Node *head) {
        while(head && head->next) {
            head = head->next->next; 
        }
        if(!head) {
            return true;
        }
        return false;
    }
    //Recursive version.
    Node* MergeSortedList(Node *A, Node *B) {
        Node *result = NULL; 
        if(!A) return B; 
        if(!B) return A;
        if(A->data <= B->data) {
            result = A; 
            result->next = MergeSortedList(A->next, B);
        } else {
            result = B; 
            result->next = MergeSortedList(B->next, A); 
        }
        return result; 
    }
    //Iterative version. 
    Node* MergeSortedList2(ListNode<T> &A, ListNode<T> &B) {
        Node *Result;
        Node *headA = A.head, *headB = B.head;
        Node *temp = new Node(0);
        Result = temp;  
        while(headA && headB){
            if(headA->data <= headB->data){
                temp->next = headA; 
                temp = temp->next; 
                headA = headA->next;
            }
            else {
                temp->next = headB; 
                temp = temp->next; 
                headB = headB->next;
            }
        }
        if(headA) {
            temp->next = headA;
        }
        else {
            temp->next = headB;
        }
        Result = Result->next;  
        return Result; 
    }
};

int main(int argc, char const *argv[]){
    ListNode<int> SLL1; 
    SLL1.insert(9);
    SLL1.insert(8);
    SLL1.insert(7);
    SLL1.insert(5);
    SLL1.insert(2);
    SLL1.insert(0);
    SLL1.print(SLL1.getHead()); 
    ListNode<int> SLL2; 
    SLL2.insert(10);
    SLL2.insert(6);
    SLL2.insert(4);
    SLL2.insert(3);
    SLL2.insert(1);
    SLL2.insert(0);
    SLL2.print(SLL2.getHead());
    SLL2.print(SLL2.MergeSortedList2(SLL1, SLL2));
    system("pause");
    return 0;
}