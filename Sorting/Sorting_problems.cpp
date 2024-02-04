/*
    TOPIC: THE PROBLEMS OF SORTING
*/
#include <bits/stdc++.h>
#define ll long long

// Problem 1-2: checking repeat 
bool CheckDuplicatesInArray(int A[], int n) {
    std::sort(A, A + n);
    for (int i = 1; i < n; i++) {
        if(A[i] == A[i - 1]) {
            return true;
        }
    }
    return false;
} 





int main(int argc, char const *argv[]){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int n;
    int A[n];
    std::cin >> n;
    for (int &x:A) {
        std::cin >> x;
    }
    std::sort(A, A + n);

    return 0;
}