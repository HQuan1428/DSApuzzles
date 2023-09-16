/*Problem 35: split a Circulat linked list into two equal parts
*Solution: 
    + Store the middle and the last of cirular linked list using floyd cycle finding algorithm. 
    + Make the seconde half circular. 
    + Make the first half circular. 
    + Set head pointers of the two linked lists.
Problem 36: concatenate two linked lists.  
*/

#include <bits/stdc++.h>

using namespace std; 

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    struct TwoList {
        Node *fiHead; 
        Node *seHead;
        TwoList() : fiHead(nullptr), seHead(nullptr) {}
    };
    Node* head;
    TwoList *heads;
public:
    CircularLinkedList() : head(nullptr), heads(new TwoList) {}

    // Insert a node at the finishing of the list
    void insert(const T& val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode; // Point to itself if it's the only node
            head = newNode;
            return;
        } 
        Node *temp = head; 
        while(temp->next != head){
            temp = temp->next;
        }
        newNode->next = head; 
        temp->next = newNode;
    }
    // Traverse and print the circular linked list
    void print(Node *head) {
        if (!head) {
            return; // List is empty
        }

        Node* current = head->next;
        std::cout << head->data << " ";

        while (current != head) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
    //get node head in linked list
    Node* getHead(){
        return head;
    }
    TwoList* SplitCLL() {
        Node *fastPtr = head; 
        Node *slowPtr = head; 
        while(fastPtr->next != head && fastPtr->next->next != head) {
            fastPtr = fastPtr->next->next; 
            slowPtr = slowPtr->next; 
        }
        if(fastPtr->next->next == head){
            fastPtr = fastPtr->next;
        }
        //make the fist list
        heads->seHead = slowPtr->next; 
        fastPtr->next = heads->seHead;
        //make the second list.
        heads->fiHead = head; 
        slowPtr->next = head;
        return heads;
    }
};

int main() {
    CircularLinkedList<int> cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);
    cll.insert(5);
    cll.print(cll.getHead()); // Output: 3 2 1
    auto temp = cll.SplitCLL();
    cll.print(temp->fiHead); 
    cll.print(temp->seHead);
    system("pause");
    return 0;
}
