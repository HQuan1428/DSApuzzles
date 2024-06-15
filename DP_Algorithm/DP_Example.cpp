#include <bits/stdc++.h>
#define ll long long

/*
    LCS PROBLEM
*/

// Recursive Solution
// Input: n is length of X, 
//  m is length of Y, 
//  i is the starting index of X,
//  j is the starting index of Y
int LCSLength(int X[], int i, int Y[], int j, int n, int m) {
    if(j == m || i == n) {
        return 0;
    }

    if(X[i] == Y[j]) {
        return LCSLength(X, i + 1, Y, j + 1, n, m);
    }
    else {
        return std::max(LCSLength(X, i + 1, Y, j, n, m), LCSLength(X, i, Y, j + 1, n, m));
    }
} 
// time complexity: O(2^n)

//  DP Solution: Adding Memoization.

// We directly implement the recursive solution -> Add some code to our recursive solution.
int LCS[1024][1024]; 
int LCSLength(int X[], int m, int Y[], int n) {
    for (int i = 0; i <= m; i++) {
        LCS[i][n] = 0;
    }
    for (int i = 0; i <= n; i++) {
        LCS[m][i] = 0;
    }

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; j++) {
            LCS[i][j] = LCS[i + 1][j + 1]; //matching X[i] to Y[j] 

            if(X[i] == Y[j]) {
                LCS[i][j]++;
            }

            //the other two cases - inserting a gap
            if(LCS[i][j+1] > LCS[i][j]) {
                LCS[i][j] = LCS[i][j + 1];
            }
            if(LCS[i+1][j] > LCS[i][j]) {
                LCS[i][j] = LCS[i + 1][j];
            }

        }
    }
    return LCS[0][0];
}

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}