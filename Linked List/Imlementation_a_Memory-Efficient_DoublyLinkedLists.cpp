#include<bits/stdc++.h>
#define ll long long

using namespace std;

template <typename T> 

class MemoryEfficientDLL {
private:
    struct Node {
        T data;
        Node* both;
        //constructor
        Node(const T& val) : data(val), both(nullptr) {}
    };

    Node *head;
public:    
    MemoryEfficientDLL() : head(nullptr) {}
//function declared
    void InsertNode(const T& val, int position);
    void DeleteNode(int position);
    void Traversal(); 
};
//function Definitions
template <typename T>
void MemoryEfficientDLL<T> :: InsertNode(const T& val, int position) {
    Node *temp = head, *prev = nullptr; 
    Node *newNode = new Node(val);
    int k = 1;  
    
    if(position == 1){
        newNode->both = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (head) ^ 0);
        if(head){
            Node *nextNode = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (head->both) ^ 0); 
            head->both = reinterpret_cast <Node*>(reinterpret_cast <uintptr_t> (newNode) ^ reinterpret_cast <uintptr_t> (nextNode)); 
        }
        head = newNode;
        return;
    }

    while(k < position && temp) {
        k += 1;
        Node *tmp = temp; 
        temp = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t>(temp->both) ^ reinterpret_cast <uintptr_t> (prev)); 
        prev = tmp;
    }
    if(k != position){
        cout << "Desired does not position exist \n"; 
        return;
    }
    if(temp){
        Node *next_Node = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (temp->both) ^ reinterpret_cast <uintptr_t> (prev)); 
        temp->both = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (newNode) ^ reinterpret_cast <uintptr_t> (next_Node)); 
    }
    newNode->both = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (prev) ^ reinterpret_cast <uintptr_t> (temp));
    Node *prev_Node = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (prev->both) ^ reinterpret_cast <uintptr_t> (temp)); 
    prev->both = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (prev_Node) ^ reinterpret_cast <uintptr_t> (newNode));
}
template <typename T> 
void MemoryEfficientDLL<T> :: DeleteNode (int position) {
    Node *temp = head, *Prev_temp = nullptr;
    int k = 1; 
    if(head == NULL){
        cout << "LIST EMPTY \n"; 
        return;
    }

    if(position == 1){
        Node *newHead = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (head->both) ^ 0); 
        Node *nextNode = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (newHead->both) ^ reinterpret_cast <uintptr_t> (head));
        newHead->both = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (nextNode) ^ 0);
        head = newHead;
        delete temp;
        return;
    }

    while(k < position && temp){
        Node *tmp = temp;
        temp = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (temp->both) ^ reinterpret_cast <uintptr_t> (Prev_temp)); 
        Prev_temp = tmp;
        k += 1; 
    }
    if(k != position){
        cout << "Desired does not position exist \n"; 
        return;
    }
    //the temp position is deleted. 
    Node *Next_temp = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (temp->both) ^ reinterpret_cast <uintptr_t> (Prev_temp));
    Node *prev_Node = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (Prev_temp->both) ^ reinterpret_cast <uintptr_t> (temp)); 
    Prev_temp->both = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (prev_Node) ^ reinterpret_cast <uintptr_t> (Next_temp)); 
    if(Next_temp){
        Node *next_Node = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (Next_temp->both) ^ reinterpret_cast <uintptr_t> (temp)); 
        Next_temp->both = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (Prev_temp) ^ reinterpret_cast <uintptr_t> (next_Node)); 
    } 
    delete temp;
}
template <typename T> 
void MemoryEfficientDLL<T> :: Traversal() {
    Node *current = head;
    Node *prev = nullptr;
    while(current) {
        cout << current->data << ' '; 
        Node *temp = current;
        current = reinterpret_cast <Node*> (reinterpret_cast <uintptr_t> (current->both) ^ reinterpret_cast <uintptr_t> (prev));
        prev = temp; 
    }
    cout << endl;
}

int main(int argc, char const *argv[]){
    MemoryEfficientDLL <int> list;
    list.InsertNode(1, 1); 
    list.InsertNode(2, 1); 
    list.InsertNode(3, 1);
    list.InsertNode(10, 4);
    list.DeleteNode(4); 
    list.Traversal();
    system("pause");    
    return 0;
}






 
