#include <iostream>

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert a node at the beginning of the list
    void insert(const T& val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode; // Point to itself if it's the only node
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
        head = newNode; // Update the head to the newly inserted node
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
};

int main() {
    CircularLinkedList<int> cll;
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);

    cll.print(); // Output: 3 2 1

    return 0;
}
