/*
    TOPIC: COUNTING SORT

    Time complexity: O(n)
    Space complexity: O(n)
*/

#include <bits/stdc++.h>
#define ll long long

// Implementation
void CountingSort(int A[], int n) {
    const int k = *(std::max_element(A, A + n)) + 1;
    int B[k] = {0};
    int C[k];
    //Complexity O(k)
    for (int i = 0; i < k; i++) {
        C[i] = 0; 
    }

    //Complexity: O(n)
    for (int j = 0; j < n; j++) {
        C[A[j]] += 1;
    }
    // C[i] now contains the number of elements equal to i.
    //Complexity: O(k)
    for (int i = 1; i < k; i++){
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
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

    CountingSort(A, n);

    std::cout << "Sorted: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}