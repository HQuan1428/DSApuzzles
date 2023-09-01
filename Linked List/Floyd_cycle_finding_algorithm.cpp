#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*Problem 1: Check whether the given linked list is either NULL-terminated of ends in a cycle 
Solution: 
    -Brutr force: 
        +Start with the first node ane see whether there is any node whose next pointer if the current node's address
        Time complexity: O(n^2). 
    -Using Hash table 
        +Traverse the linked list nodes one by one
        +Check if the addess of the node is available in the hash table or not
        +If it is already available in the hash table, that indicates that we are visiting the node that was already visited.
         this is possible only if the given linked list has a loop in it.
        +If the address of the node is not available in the hash table, insert that node's address into the hash table.
        +Continue this process until we reach the end of the kinked oist of we find the loop.
        Time complexity: O(n). 
        Space complexity: O(n).
    -Efficient Approach (the Floyd cycle finding algorithm)
        +Using two pointers moving (fast pointer and slow pointer) at diffenrent speeds to walk the linked list.
        +Slow pointer moves one node at time. 
        +Fast pointer moves two node at time. 
        +Once they enter the loop they are ecpected to meet, which denotes that there is a loop.
        *Note: analysis of algorithm
            A faster moving pointer would point to the same location as a lower moving pointer is if somehow the entire list or a part of it is circular.
        Time complexity: O(n). 
        Space complexity: O(1).
*/

//Problem 2: Check and Find the start node of the loop.
/* 
-The principle at play here is based on calculating the distance covered by "fastPtr" and "slowPtr" in the iteration of the loop.
 When they meet, we have completed either a full loop or a multiple of the loop's length, bringing them back to the same position
 within the loop. Consequently, resertting "slowPtr" to the head of the Linked List advancing both pointers on step at a time
 will eventually lead them to the starting point of the loop.
-Application: We use this method for removing the loops.
 Time complexity: O(n). 
 Space complexity: O(1).
-Can Use steps 2 and 3 instead of steps 1 and 2 ?.
-> Yes, but the complexity might be high.  
*/

/*Problem 3: Find the length of the loop by Floyd cycle algorithm.
Solution: After finding the loop in the linked list, keep the slowPtr as it is. The fastPtr keeps moving until it again comes
    back to slowPtr. While moving fastPtr, use a count variable which increments at the rate of 1. 
This solution is also an extension of the basic cycle detection problem.
Time complexity: O(n). 
Space complexity: O(1).
*/

template <typename T> 
class SinglyLinkedList {
private:
    struct Node {
        T data; 
        Node *next; 
        Node(const T& val) : data(val), next(nullptr) {}
    };
    Node *head;
public:
    SinglyLinkedList() : head(nullptr) {}

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
    int SolBruteForce(){
        Node *temp = head; 
        while(temp){
            Node *ans = temp->next; 
            while(ans != temp && ans != NULL){
                if(ans == temp){
                    return 1; // has a cycle.
                }
                ans = ans->next;
            }
            temp = temp->next;
        }
        return 0; //hasn't cycle. 
    }
    int SolUsingHashTable(){
        set <Node*> s;
        Node *temp = head;
        while(temp){
            if(s.find(temp) != s.end()){
                return 1; // has a cycle. 
            }
            s.insert(temp); 
            temp = temp->next; 
        }
        return 0; 
    }
    int FloydCyclefinding(){
        Node *slowPtr = head, *fastPtr = head;
        while(fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next; 
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr){
                return 1;
            }
        }
        return 0;
    }
    Node* FindTheStartNodeOfTheLoop(){
        Node *slowPtr = head, *fastPtr = head;
        bool loopExists = false; 
        while(fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next; 
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr){
                loopExists = true; 
                break;
            }
        }
        if(loopExists) {
            slowPtr = head;
            while(slowPtr != fastPtr){
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            return slowPtr;
        }
        return NULL;
    }
    int FindTheLengthOfTheLoop(){
        Node *slowPtr = head, *fastPtr = head;
        bool loopExists = false; 
        while(fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next; 
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr){
                loopExists = true; 
                break;
            }
        }
        if(loopExists){
            int count = 0; 
            fastPtr = fastPtr->next; 
            while(fastPtr != slowPtr){
                fastPtr = fastPtr->next;
                count += 1;  
            }
            return count;
        }
        return 0;
    }

};

int main(int argc, char const *argv[]){
    SinglyLinkedList <int> SLL; 
    SLL.insert(1);
    SLL.insert(1);
    SLL.insert(1);
    SLL.insert(1);
    SLL.insert(9);
    SLL.insert(10);
    cout << SLL.SolBruteForce() << endl; 
    cout << SLL.SolUsingHashTable() << endl;
    cout << SLL.FloydCyclefinding() << endl;
    system("pause");
    return 0;
}