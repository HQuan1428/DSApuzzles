#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <new>
#define ll long long

//Using circular array 
// template <class T> 
// class Queue
// {
// private:
//     struct ArrayQueue {
//         int front, rear;
//         int capacity; 
//         T *array;
//     };
//     ArrayQueue *que;
// public:
//     Queue(int size) {
//         que = new ArrayQueue; 
//         que->capacity = size; 
//         que->array = new T[size]; 
//         que->front = -1; 
//         que->rear = -1;
//     }
    
//     //Empty? 
//     bool isEmpty() {
//         //if the condition is true then 1 is returned 0 else 0 is returned
//         return que->front == -1; 
//     }
//     //full?
//     bool isFull() {
//         return (que->rear + 1) % que->capacity == que->front;
//     }
//     //insert 
//     void EnQueue(T data) {
//         if(isFull()) {
//             std::cout << "Queue overflow " << std::endl;
//             return;
//         }
//         que->rear = (que->rear + 1) % que->capacity;
//         que->array[que->rear] = data; 
//         if(que->front == -1) {
//             que->front = que->rear; 
//         }
//     }
//     //delete returned the value is poped.
//     T DeQueue() {
//         T data = 0; 
//         // if(isEmpty()) {
//         //     std::cout << "Queue underflow" << std::endl;
//         //     return -1; 
//         // }
//         data = que->array[que->front]; 
//         if(que->front == que->rear) {
//             que->front = -1; 
//             que->rear = -1; 
//         }
//         else {
//             que->front = (que->front + 1) % que->capacity;
//         }
//         return data;
//     }
//     ~Queue() {
//         if(!que) {
//             if(!que->array) {
//                 delete[] que->array;
//             }
//             delete que;
//         }
//     }
// };

// struct ArrayQueue {
//     int front, rear; 
//     int capacity; 
//     int *array;
// };
// ArrayQueue* Queue(int size) {
//     ArrayQueue *Q = new ArrayQueue; 
//     if(!Q) {
//         return NULL;
//     }
//     Q->capacity = size; 
//     Q->front = Q->rear = -1; 
//     Q->array = new int[size]; 
//     if(!Q->array) 
//         return NULL;
//     return Q;
// }
// int IsEmptyQueue(ArrayQueue *Q) {
//     return Q->front == -1;
// }
// int IsFullQueue(ArrayQueue *Q) {
//     return (Q->rear + 1) % Q->capacity == Q->front;
// }
// int QueueSize(ArrayQueue *Q) {
//     return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;  
// }
// void EnQueue(ArrayQueue *Q, int data) {
//     if(IsFullQueue(Q)) {
//         std::cout << "Queue overflow" << std::endl;
//     }
//     else {
//         Q->rear = (Q->rear+ 1) % Q->capacity; 
//         Q->array[Q->rear] = data;
//         if(Q->front == -1) {
//             Q->front = Q->rear;
//         }
//     }
// }
// int DeQueue(ArrayQueue *Q) {
//     int data = 0; 
//     if(IsEmptyQueue(Q)) {
//         std::cout << "Queue underflow " << std::endl;
//         return 0;
//     }
//     data = Q->array[Q->front]; 
//     if(Q->front = Q->rear) {
//         Q->front = Q->rear = -1;
//     }
//     else {
//         Q->front = (Q->front + 1) % Q->capacity;
//     }
//     return data;
// }
// void DeleteQueue(ArrayQueue *Q) {
//     if(Q) {
//         if(Q->array)
//             delete[] Q->array; 
//         delete Q;
//     }
// }

//Using Linked List 
template <class T> 
class Queue
{
private:
    struct Node
    {
        T data; 
        Node *next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node *front;
    Node *rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    //Operations
    //Empty?
    bool isEmpty() {
        return front == NULL;
    }
    //Insert element
    void EnQueue(const T& newItem) {
        Node *newNode = new Node(newItem); 
        if(rear != NULL) {
            rear->next = newNode;
        }
        rear = newNode;
        if(front == NULL) {
            front = rear;
        }
    }
    //delete element
    T DeQueue() {
        if(isEmpty()) {
            return -1;
        }
        Node* temp = nullptr; 
        temp = front; 
        if(front == rear) {
            rear = nullptr;
        }
        front = front->next;
        T value = temp->data;
        delete temp; 
        return value;
    }
    //returned top value
    T topValue() {
        return front->data; 
    }
};
