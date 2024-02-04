/*
    TOPIC: INSERTION SORT.

    Advantages:
        + Simple implementation.
        + Efficient for small data.
        + Adaptive: if the input list is presorted [may nor be completely] then insertions sort
            takes O(n+ d), where d is the number of inversions.
        + Practically more efficient than selection and bubble sort, even though all of them have O(n^2) worst case complecity.
        + Stable: Maintains relative order of input data if the keys are same.
        + In-place: It requires only a constant amout O(1) of additional memory space.
        + Online: Inserttion sort can sort

    Algorithm:
    + Every repetition of insertion sort removes an element from the input data, and inserts it into
      the correct position in the already-sorted list until no input elements remain. Sorting is typically done in-place.
      The reslting array after k iterations has the property where the first k + 1 entries are sorted.
    + Each element greater than x is copied to the right as it is compares against x.

    Performance
    + Worst case complexity: O(n^2)
    + Best case complexity: O(n)
    + Average case complexity: O(n^2)
    + Worst case space complexity: O(n^2) total, O(1) auxiliary

    Insertion sort is almost linear for partially sorted input.
*/

#include <bits/stdc++.h>
#define ll long long

// Implementation.
void InserttionSort(int A[], int n) {
    int i, j, v;
    for (i = 1; i <= n - 1; i++) {
        v = A[i];
        j = i;
        while(A[j-1] > v && j >= 1) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = v;
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

    InserttionSort(A, n);

    std::cout << "Sorted: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}