/*
Problem-22: Finding spans  
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