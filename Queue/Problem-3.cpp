/*
Problem-8: Implement doubly ended queues
Problem-9: Check whether each successive pair of numbers in the stack
Solution:Revesed stack by using queue
         check whether each successive pair of numbers 
            if(non consecutive) ischeck = false 
    Time complexity: O(n), Space complexity: O(n)
Problem-10: merge two halves of the list 
Solution: transfer size(queue)/2 from queue to stack and restrans all elements of stack to queue 
          Enqueue size(queue)/2 times front of queue
          Transfer size(queue)/2 times front of queue to stack.
          transerved still stack is empty and then Dequeue and pop elements.
Problem-11: Revese the order of the k elements of the queue.   
          
*/
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
#define ll long long

//Problem-9:
bool isStackPairConsecution(std::stack<int> st) {
    bool issafe = true;
    std::queue<int> qe;
    while(!st.empty()) {
        qe.push(st.top()); 
        st.pop(); 
    }
    while(!qe.empty()) {
        st.push(qe.front()); 
        st.pop();
    }
    while(!st.empty()) {
        int n = st.top(); 
        st.pop();
        qe.push(n); 
        if(!st.empty()) {
            int m = st.top();//Note
            st.pop();
            qe.push(m); 
            if(abs(m-n) != 1) 
                issafe = false;
        }
    }
    return issafe;
}
//Problem-10: 
void Rearrange(std::queue<int> qe) {
    std::stack<int> st;
    if(qe.size() % 2 != 0) {
        return;
    }
    int halfsize = qe.size() / 2; 
    for(int i = 1; i <= halfsize; i++) {
        st.push(qe.front()); 
        qe.pop(); 
    }
    while(!st.empty()) {
        qe.push(st.top()); 
        st.pop(); 
    }
    for(int i = 1; i <= halfsize; i++) {
        qe.push(qe.front()); 
        qe.pop();
    }
    for(int i = 1; i <= halfsize; i++) {
        st.push(qe.front()); 
        qe.pop(); 
    }
    while(!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
         std::cout << qe.front() << " "; 
        qe.pop();   
    } 
    std::cout << std::endl;
}
//Problem-11: Reversed the K elements first
void ReverseK(std::queue<int> qe, int k) {
    if(qe.empty() || k > qe.size()) {
        return;
    }
    std::stack<int> st; 
    for(int i = 1; i <= k; i++){
        st.push(qe.front()); 
        qe.pop(); 
    }
    while(!st.empty()) {
        std::cout << st.top() << " "; 
        st.pop(); 
    }
    while(!qe.empty()) {
        std::cout << qe.front() << " "; 
        qe.pop();
    }
    std::cout << std::endl;
}
void ReverseK2(std::queue<int> qe, int k) {
    if(qe.empty() || k > qe.size()) {
        return;
    }
    std::stack<int> st; 
    for(int i = 1; i <= k; i++){
        st.push(qe.front()); 
        qe.pop(); 
    }
    while(!st.empty()) {
        qe.push(st.top());
        st.pop();
    }
    for(int i = 1; i <= qe.size() - k; i++) {
        qe.push(qe.front()); 
        qe.pop();
    }
    while(!qe.empty()) {
        std::cout << qe.front() << " "; 
        qe.pop(); 
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]){
    int k = 4; 
    std::queue<int> qe;
    for(int i = 1; i < 10; i++) {
        qe.push(i*10);
    }
    ReverseK2(qe, k);
    system("pause");
    return 0;
}