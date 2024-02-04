/*
    TOPIC: SELECTION SORT

    Algorithm: 
        1. Find the minimum value in the list.
        2. Swap it with the value in the current position. 
        3. Repeat this process for all the elements until the entire array is sorted.

    Selection sort is best suits for elements with bigger values and small keys.
*/
#include <bits/stdc++.h>
#define ll long long

void SelectionSort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int min_value = i;
        for (int j = i + 1; j < n; j++) {
            min_value = A[min_value] > A[j] ? j : min_value;
        }
        std::swap(A[i], A[min_value]);
    }
}


int main(int argc, char const *argv[]){

    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int n;
    std::cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }

    std::cout << "Non sort: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    SelectionSort(A, n);

    std::cout << "Sorted: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}