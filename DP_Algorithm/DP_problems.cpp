#include <bits/stdc++.h>
// Problem 1-3
int F[10000] = {0};
int f(int n) {
    F[0] = F[1] = 1;
    F[2] = 2 * F[1] * F[0];
    for (int i = 3; i <= n; i++) {
        F[i] = F[i - 1] + 2 * F[i - 1] * F[i - 2];
    }   
}

// Problem: Maximum value contiguous subsequence 4-8

int MaxContigousSum(int A[], int n) {
    int sumSoFar = 0, sumEndingHear = 0;
    for (int i = 0; i < n; i++) {
        sumEndingHear += A[i]; 
        if(sumEndingHear < 0) {
            sumEndingHear = 0;
            continue;
        }
        sumSoFar = std::max(sumSoFar, sumEndingHear);
    }
    return sumSoFar;
}

// Problem: Maximum value contiguous subsequence without selecting two contiguous numbers

int maxSumNoTwo(int A[], int n) {
    int M[n + 1];
    M[0] = A[0];
    M[1] = std::max(A[0], A[1]);

    for (int i = 2; i < n; i++) {
        M[i] = std::max(M[i - 1], M[i - 2] + A[i]);
    }
    return M[n - 1];
}

// Problem: Catalan Numbers 13-14
int CatalanNumber(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += CatalanNumber(i - 1) * CatalanNumber(n - i);
    }
    return count;
}

int Table[1024];
int CatalanNumber2(int n) {
    if(Table[n] != 1)
        return Table[n];

    Table[n] = 0;
    for (int i = 1; i <= n; i++) {
        Table[n] += CatalanNumber2(i - 1) * CatalanNumber2(n - i);
    }
    return Table[n];
}







