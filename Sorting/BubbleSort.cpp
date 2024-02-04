
/*
    TOPIC: BUBBLE SORT.
*/

#include <bits/stdc++.h>
#define ll long long

void BubbleSort(int A[], int n) {
    for (int pass = n - 1; pass >= 0; pass--) {
        for (int i = 0; i <= pass-1; i++) {
            if(A[i] > A[i+1]){
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
}

void BubbleSortImproved(int A[], int n) {
    int swapped = 1;
    for (int pass = n - 1; pass >= 0;pass--) {
        swapped = 0;
        for (int i = 0; i <= pass-1; i++) {
            if(A[i] > A[i+1]) {
                std::swap(A[i], A[i + 1]);
                swapped = 1;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int n;
    std::cin >> n;
    int A[n];
    for (int i = 0; i< n; i++) {
        std::cin >> A[i]; 
    }

    std::cout << "Non sort: "; 
    for(int x : A) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    BubbleSortImproved(A, n); 

    std::cout << "Sorted: ";
    for(int x:A) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}