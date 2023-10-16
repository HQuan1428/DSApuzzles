/*
Problem-24: Largest rectangle under histogram: 
Solution: go to each bar in the histogram and find the maximum possible area in the histogram for it.
    Time complextity: O(n).
Problem-25: Largest rectangle under histogram impove complexity. 
solution: 
    1.Create an empty stack.
    2.Start from the first bar, and do the following for every bar hist[i] where ‘i‘ varies from 0 to n-1
        1.If the stack is empty or hist[i] is higher than the bar at top of the stack, then push ‘i‘ to stack. 
        2.If this bar is smaller than the top of the stack, then keep removing the top of the stack while the top of the stack is greater. 
        3.Let the removed bar be hist[tp]. Calculate the area of the rectangle with hist[tp] as the smallest bar. 
        4.For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i‘ (current index).
    3.If the stack is not empty, then one by one remove all bars from the stack and do step (2.2 and 2.3) for every removed bar

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
#include <limits>
#define ll long long

//brute force 
int FindLargestRectangle(int n, int *a) {
    int *s  = new int[n];
    int width = 0, height = 0; 
    for(int i = 0; i < n; i++) { 
        width = 1; 
        height = a[i];
        s[i] = INT_MIN;
        for(int j = i + 1; j < n; j++) {    
            width += 1; 
            height = std::min(height, a[j]);
            s[i] = std::max(s[i], (width*height));
        }
    }
    int temp = *(std::max_element(s+0, s+n)); 
    return temp; 
}
// Using stack 
int FindlargestRectangleImprove(int n, int *a) {
    std::stack<int> st; 
    int area_max = INT_MIN; 
    int i = 0; 
    while(i < n) {
        if(st.empty() || a[i] >= a[st.top()]) {
            st.push(i++); 
        }
        else {
            int idx = st.top(); 
            st.pop(); 
            if(st.empty()) {
                area_max = std::max(area_max, a[idx] * (i));
            } 
            else {
                area_max = std::max(area_max, a[idx] * (i - st.top() - 1));
            } 
        }
    }
    while(!st.empty()) {
        int idx = st.top(); 
        st.pop(); 
        if(st.empty()) {
            area_max = std::max(area_max, a[idx] * i); 
        }
        else { 
            area_max = std::max(area_max, a[idx] * (i - st.top() - 1)); 
        }
    }
    return area_max; 
}

int main(int argc, char const *argv[]){
    int n; 
    std::cin >> n; 
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        std::cin >> a[i]; 
    }
    std::cout << FindlargestRectangleImprove(n, a) << std::endl;
    system("pause");
    return 0;
}