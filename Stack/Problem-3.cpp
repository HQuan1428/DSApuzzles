/*
Problem-8-9-10: palindome or not 
Problem-11: reverse stack.
Problem 12-13: refer queue chapter.
Problem 14-15-16-17: Implementation m stack in the one array, that array indexes are from 1 to n. 
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

void InsertAtBottom(std::stack<int>*, int); 

//Using recursion to iterator though each element in the stack and each component to the bottom of the stack. 
void ReverseStack(std::stack<int> *st) {
    int data; 
    if((*st).empty()) return; 
    data = (*st).top(); 
    (*st).pop(); 
    ReverseStack(st); 
    InsertAtBottom(st, data); 
}
//Insert the element at the bottom of the stack 
void InsertAtBottom(std::stack<int> *st, int data) {
    int temp; 
    if((*st).empty()) {
        (*st).push(data);
        return;
    }
    temp = (*st).top(); (*st).pop();
    InsertAtBottom(st, data); 
    (*st).push(temp); 
}


int main(int argc, char const *argv[]){
    std::stack<int> *stPtr; 
    std::stack<int> st; 
    stPtr = &st; 
    for(int i = 1; i <= 10; i++) {
        st.push(i); 
    }
    ReverseStack(stPtr); 
    while(!st.empty()) {
        std::cout << st.top() << " "; 
        st.pop(); 
    }
    system("pause");
    return 0;
}