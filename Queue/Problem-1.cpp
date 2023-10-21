/*
Problem-1: Reversing a queue.
    time complextity: O(n)
Problem-2: Implementation queue with two stack. 
Problem-3: Implementation stack with two queue.
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

//Problem-1 
std::queue<int> ReverseQueue(std::queue<int> qe) {
    std::stack<int> st;
    std::queue<int> qu; 
    while(!qe.empty()) {
        st.push(qe.front()); 
        qe.pop(); 
    }
    while(!st.empty()) {
        qu.push(st.top()); 
        st.pop();
    }
    return qu;
} 


int main(int argc, char const *argv[]){
    std::queue<int> qe;
    qe.push(1);
    qe.push(2);
    qe.push(3);
    qe.push(4);
    qe.push(5);
    std::queue<int> qu = ReverseQueue(qe); 
    while(!qe.empty()) {
        std::cout << qe.front() << " ";
        qe.pop(); 
    }
    std::cout << std::endl;
    while(!qu.empty()) {
        std::cout << qu.front() << " ";
        qu.pop(); 
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}