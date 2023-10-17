/*
Problem-28: Remove all adjacent duplicates Using stack
Problem-29: Replace every element with nearest greater element on right of that element
    Time complexity: O(n^2), Space complexity: O(1).

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
#include <set>
#include <new>
#define ll long long

void RemoveAdjacentDuplicates(std::string s) {
    std::stack<char> st;
    std::reverse(s.begin(), s.end());
    std::cout << s << std::endl;  
    for(int i = 0; i < s.length(); i++) {
        while(!st.empty() && st.top() == s[i]) {
            i++;
            st.pop(); 
        }
        st.push(s[i]);
    }
    while(!st.empty()) {
        std::cout << st.top();
        st.pop();
    }
    std::cout << std::endl;
    // std::string t; 
    // for(char x:s) {
    //     if(t.find(x) == std::string::npos) {
    //         t += x;
    //     }
    // }
    // std::cout << t << std::endl;
}
void replaceWithNearestGreaterElement(int *a, int n) {
    int nextNearestGreater = INT_MIN; 
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[i]) {
                nextNearestGreater = a[j]; 
                break;
            }
        }
        std::cout << nextNearestGreater << " ";
    }
    std::cout << std::endl;
}
void replaceWithNearestGreaterElementImprove(int *a, int n) {
    std::stack<int> st; 
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] >= a[st.top()]) {
            a[st.top()] = a[i]; 
            st.pop(); 
        }
        st.push(i);
    }
    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[]){
    int n; 
    std::cin >> n; 
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    replaceWithNearestGreaterElementImprove(a, n); 
    system("pause");
    return 0;
}