/*
Problem-22: Finding spans
    Time complexity: O(n^2), Space complexity: O(1)
Problem-23: Finding spans (Improve the complexity).
Solution: Finding the closest the day preceding i, such that the price is greater on that day than the price on the day i
    Time complexity: O(n), Space complexity: O(n) [for stack]

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
#include <new>
#define ll long long

//brute force 
int* FindingSpans(int n, int *a) {
    int *s = new int[n]; 
    for(int i = 0; i < n; i++) {
        //j constains the numbers of day 
        int j = 1;//why? : count the current day
        while(j <= i && a[i] > a[i-j]) {
            j = j + 1; 
        }
        s[i] = j; 
    }
    return s; 
}
//iprove complexity
int* FindingSpansImprove(int n, int *a) {
    int *s = new int[n]; 
    std::stack<int> st; 
    int p = 0; //contains the closest day preceding i 
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] > a[st.top()]) {
            st.pop(); 
        }
        if(st.empty()) {
            p = -1;
        } else {
            p = st.top(); 
        }
        s[i] = i - p; 
        st.push(i);
    }
    return s; 
}

int main(int argc, char const *argv[]){
    int n; std::cin >> n; 
    int *a = new int[n]; 
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    } 
    int *s = FindingSpans(n, a); 
    for(int i = 0; i < n; i++) {
        std::cout << s[i] << " ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}