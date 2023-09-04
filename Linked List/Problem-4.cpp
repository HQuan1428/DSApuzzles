/* Problem-17/ DSA puzzles: Find Intersect Node.
Solution: 
-Brute-force:
    one easy sotution is to compare every node pointer 
     in the first with every other node pointer in the seacond list by which the mathching node pointer will lead is to the intersecting node. 
     But, the time complexity in this case will be O(mn) which will be high
-Using Hash Table: 
    +Select a list which have a less number of node (if we don't know the lengths beforehead then select one list randomly)
    +Now, traverse the orther list and for each node pointer of this list check the same node pointer exists in the hash table.
    +If there is a merge point for the given lists then we will definitely encounter the node pointer in the hash table.
-> Time complexity: Time for creating the hash table + Time for scanning the second list = O(m) + O(n) (or O(n) + O(M))
-> Space complexity: O(n) or O(m).
-Using stacks: 
    +Creat two stacks: one for the first list and one for the second list. 
    +Traverse the first list and push all the node addresses onto the first list. 
    +Traverse the second list end push all the node addresses onto the second list. 
    +Now both stacks contain the node address of the corresponding lists. 
    +If they are same, take the top elements form both the stacks and keep them in some temporary variable. 
    +Contine this process until the top node addresses of the stacks aren't the same. 
    +This point is the one where the lists merge into sa single list. 
    +Return the value of the temporary variable.
->Time complexity: O(m + n)
->Space complexity: O(m + n)
-Using combining sorting and searching techniques. 
    + Using binary search and sort
->Time complexity: O(max(nlogn, mlogm)).
->Space complexity: O(Max(m,n)).
-Efficient approach.
    +Find lengths (L1 and L2) of both lists - O(n) + O(m) = O(max(m, n)).
    +Take the difference d of the lengths --O(1).
    +Make d steps in longer list --O(d).
    +Step in both lists in parallel until links to next node match -- O(min(m,n)).
->Total time complexity: O(max(m, n)).
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
    Node* FindNodeIntersect(ListNode<T> &A, ListNode<T> &B){
        Node* temp = A.head;
        Node* temp2 = B.head; 
        while(temp){
            while(temp2) {
                if(temp == temp2){
                    return temp1; 
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        return NULL;
    }
    Node* FNIUsingHashTable(ListNode<T> &A, ListNode<T> &B){
        Node* temp = A.head; 
        Node* temp2 = B.head;
        unordered_map <Node*, bool> Hash_SLL; 
        while(temp) {
            Hash_SLL[temp] = true; 
            temp = temp->next;
        }
        while(temp2){
            if(Hash_SLL.find(temp2) != Hash_SLL.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
    Node* FNIUsingStacks(ListNode<T> &A, ListNode<T> &B){
        stack<Node*> fiStack, seStack; 
        Node *temp1 = A.head; 
        Node *temp2 = B.head; 
        while(temp1){
            fiStack.push(temp1);
            temp1 = temp1->next;
        }
        while(temp2){
            seStack.push(temp2);
            temp2 = temp2->next;
        }
        Node *intersectNode = NULL;
        while(!fiStack.empty() && !seStack.empty() && fiStack.top() == seStack.top()){
            intersectNode = fiStack.top();
            fiStack.pop(); 
            seStack.pop();
        }
        return intersectNode;
    }
    Node* FNIEfficientApproach(ListNode<T> &A, ListNode<T> &B) {
        int L1 = 0, L2 = 0, diff = 0; 
        Node *head1 = A.head, *head2 = B.head;
        while(head1){
            L1 += 1; 
            head1 = head1->next;
        }
        while(head2){
            L2 += 1;
            head2 = head2->next;
        }
        if(L1 < L2){
            head1 = B.head; 
            head2 = A.head; 
            diff = L2 - L1;
        }
        else {
            head1 = A.head; 
            head2 = B.head; 
            diff = L1 - L2;
        }
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
        while(head1 && head2){
            if(head1 == head2){
                return head1;
            }
            head1 = head1->next; 
            head2 = head2->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}