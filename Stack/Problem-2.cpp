/*
Problem-3: Discuss postfix evaluation using stack? 

*/
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdexcept>
#include<exception>
#include<vector>
#include<stack>
#include<queue>
#include<limits.h>
#include <map>
#define ll long long

int isOperator(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '/' || c == '*' || c == '%') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}
//Apply the operator 
ll Operation(int a, int b, char c) {
    switch (c)
    {
        case '+':
            return b + a;
            break; 
        case '-':
            return b - a;
            break;  
        case '^':
            return pow(b, a);
            break; 
        case '*':
            return b * a;
            break;  
        case '/':
            if(a == 0) {
                throw(std::runtime_error("Division by zero. \n"));
            } 
            return b / a;
            break; 
        case '%':
            return b % a;
            break;  
        default:
            throw(std::runtime_error("Operator does not exist. \n"));
            break; 
    }
}
std::string ConvertInfixToPostfix(std::string Infix) {
    std::map<char, char> symbolSafe{{')', '('}, {'}', '{'}, {']', '['}};
    std::string Postfix = "";
    std::stack<char> st; 
    for(int i = 0; i < Infix.length(); i++) {
        if(isspace(Infix[i])) continue;
        if(isOperator(Infix[i])){
            while(!st.empty() && isOperator(st.top()) >= isOperator(Infix[i])){
                Postfix += st.top(); 
                st.pop(); 
            }
            st.push(Infix[i]);
        }
        else if(Infix[i] == '[' || Infix[i] == '(' || Infix[i] == '{') {
            st.push(Infix[i]);
        }
        else if(Infix[i] == ']' || Infix[i] == ')' || Infix[i] == '}') {
            while(!st.empty() && st.top() != symbolSafe[Infix[i]]) {
                Postfix += st.top(); 
                st.pop(); 
            }
            if(!st.empty()) {
                st.pop(); 
            }
        }
        else {
            Postfix += Infix[i]; 
        }
    }
    while(!st.empty()) {
        Postfix += st.top(); 
        st.pop(); 
    }
    return Postfix;
}
ll PostfixEvaluate(std::string Postfix) {
    std::stack<int> st; 
    for(int i = 0; i < Postfix.length(); i++) {
        if(isOperator(Postfix[i])) {
            int a = st.top(); 
            st.pop(); 
            int b = st.top(); 
            st.pop(); 
            int c = Operation(a, b, Postfix[i]); 
            st.push(c); 
        }
        else {
            st.push(Postfix[i] - '0');
        }
    }
    return st.top(); 
}

int main(int argc, char const *argv[]){
    std::string s; 
    s = "(2*3+4)-9*3";
    std::cout << PostfixEvaluate(ConvertInfixToPostfix(s)) << std::endl;
    system("pause");
    return 0;
}