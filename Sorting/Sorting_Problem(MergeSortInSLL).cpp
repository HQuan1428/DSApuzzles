/*
    TOPIC: SORTING PROBLEM -> MERGE SORT FOR SINGLE LINKED LIST.

    Algorithms: This algorithm resembles merge sort for arrays.

    Merge(head):
        1) If the head is NULL or there is only one element in the linked list.
            then return.
        2) Else divide the linked list into two halves.
            FrontBackSplit(head, &a, &b)
        3) Sort the two halves a and b.
            MergeSort(a);
            MergeSort(b); 
        4 Merge the sorted a and b (Using Merge())
*/

#include <bits/stdc++.h>
#define ll long long

class Node {
public:
    int data;
    Node *next;

}; 
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
}

Node *Merge(Node *a, Node *b);
void FrontBackSplit(Node *src, Node **frontRef, Node **backRef); 

void MergeSort(Node **headRef) {
    Node *head = *headRef;
    Node *a;
    Node *b;

    if(head == NULL || head->next == NULL) {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

   *headRef = Merge(a, b); 
}

void FrontBackSplit(Node *src, Node **frontRef, Node **backRef) {
    Node *fast = src->next;
    Node *slow = src; 

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *frontRef = src;
    *backRef = slow->next;
    slow->next = NULL; // Create an ending for the section. 
}

Node *Merge(Node *a, Node *b) {
    Node *result = NULL; 
    if(a == NULL) {
        return b; 
    }
    else if(b == NULL) {
        return a;
    }

    if(a->data <= b->data) {
        result = a;
        result->next = Merge(a->next, b); 
    }
    else {
        result = b;
        result->next = Merge(a, b->next); 
    }
    return result;
}

int main(int argc, char const *argv[]){
    /* Start with the empty list */
    Node *res = NULL;
    Node *a = NULL;

    /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    /* Sort the above created Linked List */
    MergeSort(&a);

    std::cout << "Sorted Linked List is: \n";
    printList(a);
    system("pause");
    return 0;
}