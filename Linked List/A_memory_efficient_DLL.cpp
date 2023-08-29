#include <iostream>

template <typename T>
class MemoryEfficientDoublyLinkedList {
private:
    struct Node {
        T data;
        Node* both; // Combined prev and next pointer
        Node(const T& val) : data(val), both(nullptr) {}
    };

    Node* head;

public:
    MemoryEfficientDoublyLinkedList() : head(nullptr) {}

    void addNode(const T& val) {
        Node* newNode = new Node(val);
        newNode->both = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(head) ^ 0); // XOR with 0 is itself

        if (head) {
            Node* nextNode = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(head->both) ^ 0);
            head->both = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(newNode) ^ reinterpret_cast<uintptr_t>(nextNode));
        }

        head = newNode;
    }

    void printList() {
        Node* current = head;
        Node* prev = nullptr;

        while (current) {
            std::cout << current->data << " ";

            Node* temp = current;
            current = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(current->both) ^ reinterpret_cast<uintptr_t>(prev));
            prev = temp;
        }

        std::cout << std::endl;
    }
};

int main() {
    MemoryEfficientDoublyLinkedList<int> list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    
    list.printList(); // Output: 3 2 1
    system("pause"); 
    return 0;
}

