#include <bits/stdc++.h>
#define ll long long

//Problem 11: Find in Infinite Array
int FindInfiniteSeries(int A[]) {
    int mid, l = 1, r = 1;
    while(A[r] != '$') {
        l = r;
        r = r * 2;
    }
    while((r - l) > 1) {
        mid = (r - l) / 2 + 1;
        if(A[mid] == '$') {
            r = mid;
        }
        else
            l = mid;
    }
}

//Problem 12: check whether there is an index i for which A[i] = i in a sorted Array of non-repeated interger
int FindInSortedArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        if(A[i] == i) {
            return i;
        }
    }
    return -1;
}

//Problem 13- 15: Find the median element of two array (L1, L2)

int FindMedian(int L1[], int L2[], int l1, int r1, int l2, int r2){
    int m1 = (r1 - l1)/2 + 1;
    int m2 = (r2 - l2)/2 + 1;

    if((r1 - l1 + 1) == 2 && (r2 - l2 + 1) == 2) {
        return (std::max(L1[l1], L2[l2]) + std::min(L1[r1], L2[r2]))/2;
    }

    if(m1 > m2) {
        return FindMedian(L1, L2, l1, m1, m2, r2);
    }
    else if(m2 < m1) {
        return FindMedian(L1, L2, m1, r1, l2, m2);
    }
    return m1;
}

//Problem 16: Upper_bound
int UpperBound(int A[], int n, int k) {
    int l = 0, r = n - 1;
    int HighesIndex = -1;
    while( (r - l) > 1) {
        int mid = l + (r - l) / 2;
        if(A[mid] == k) {
            HighesIndex = mid;
            l = mid + 1;
        }
        else if(A[mid] < k) {

            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return HighesIndex;
}

// Problem 29: caculate n^k 
int Exponential(int k, int n) {
    if(n == 0) {
        return 1;
    }
    if( n % 2 == 1) {
        int a = Exponential(k, n - 1);
        return a * k;
    }
    else {
        int a = Exponential(k, n / 2);
        return a * a;
    }
}



int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}