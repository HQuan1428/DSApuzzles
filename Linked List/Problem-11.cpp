

#include<bits/stdc++.h>
#define ll long long

using namespace std;

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        bool sword;
        Node* next;
        Node(const T& val) : data(val), sword(false), next(nullptr) {}
    };

    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}
    Node* getHead() {
        return head;
    }

    // Insert a node at the beginning of the list
    void insert(const T& val) {
        Node* newNode = new Node(val);
        newNode->next = newNode; 
        if (!head) {
            head = newNode;
            return;
        } 
        Node *temp = head; 
        while(temp->next != head) {
            temp = temp->next; 
        }
        newNode->next = head; 
        temp->next = newNode;
    }

    // Traverse and print the circular linked list
    void print() {
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
    
    //size of list. 
    int Size(Node *head) {
        int count = 0;
        Node *temp = head; 
        do {
            temp = temp->next;
            count++; 
        }while (temp != head);
        return count;
    }

    //Josephus Circle
    int JoseCircle(int n, int k, Node *head) {
        Node *temp = head;
        while(Size(temp) > 1) {
            for(int i = 1; i < k-1; i++) {
                temp = temp->next;
            }
            Node *p = temp->next; 
            temp->next = temp->next->next;
            delete p;
            temp = temp->next;
        }
        return temp->data;
    }
};

int main(int argc, char const *argv[]){
    CircularLinkedList <int> cll;
    int n, k; 
    cin >> n >> k; 
    for(int i = 1; i <=n ; i++) {
        cll.insert(i);
    }
    cout << cll.Size(cll.getHead()) << endl;
    cout << cll.JoseCircle(n, k, cll.getHead()) << endl;
    system("pause");
    return 0;
}