/* Problem-24/DSA puzzles : Find the middle of the linked list. 
Solution: 
-Brute force.
    +For each of the node, count how many nodes are there in the list and see whether it is the middle node of the list. 
->Tinme complexity: O(n^2).
->Space complexity: O(1).
-Improve the complexity.
    +Traverse the list and find the length of the list. 
    +After finding the length, again scan the list and locate n/2 node from the begining. 
-Using Hash table.
-Efficient Approach.
    +Use two pointers. Move one pointer at twice the speed of the second. 
    +When the first pointer reaches the end of the list, the second pointer will be pointing to the middle node.
    *Note: if the list has an even number of nodes, the middle node will be of floor(n/2).
->Time complexity: O(n).
->Space complexity: O(1).
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
    Node* FindMiddle() {
        Node *fastPtr = head, *slowPtr = head;
        while(fastPtr && fastPtr->next) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
};

int main(int argc, char const *argv[]){
    ListNode<int> SLL;
    SLL.insert(5);
    SLL.insert(4);
    SLL.insert(0);
    SLL.insert(2);
    SLL.insert(1);
    SLL.insert(3);
    cout << SLL.FindMiddle()->data << endl;
    system("pause");
    return 0;
}