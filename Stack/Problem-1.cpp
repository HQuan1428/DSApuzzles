/*
Problem-1: Balancing of Symbols 
Solution: Each time the parser reads one character at atime. If the character is an opening delimiter then it is written to the stack.
        When a closing delimiter is encountered the stack popped. 
    Time complexity: O(n), Space complextity: O(n). 
Problem-2: convert infix expression to postfix expression.
Solution: resovle this Problem with a stack. 

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
#include <map>
#include <utility>
#define ll long long

int BlancingOfSymbols(std::string s) {
    std::map<char, char> symbolSafe{{')', '('}, {'}', '{'}, {']', '['}};
    std::stack<char> st; 
    for(char c:s) {
        for(auto it:symbolSafe) {
            if(c == it.second) {
                st.push(c);
            }
            else if(c == it.first) {
                if(st.empty()){
                    return 0;
                }
                if(st.top() == symbolSafe[it.first]) {
                    st.pop();
                }
                else {
                    return 0;
                }
            }
        }
    }
    if(!st.empty()) {
        return 0;
    }
    return 1; 
}

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
bool isParentheses (char c) {
    if(c == '[' || c == ']' || c == '(' || c == ')' || c == '{' || c == '}'){
        return true;
    }
    return false;
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

int main(int argc, char const *argv[]){
    std::string s; 
    s = "3+4*2";
    std::cout << ConvertInfixToPostfix(s) << std::endl;
    system("pause");
    return 0;
}