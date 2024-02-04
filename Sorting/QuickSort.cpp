/* 
    TOPIC: QUICK SORT.

    Algorithm:
        The recursive algorithm consists of four steps:
            1) If there are one or on elements int he array to be sorted, return.
            2) Pick an element in the array to serve as the "pivot" point (Usually the left-most element in the array is used).
            3) Split the array into two parts - one with elements larger than the pivot and the orther with elements smaller than the pivot
            4) Recursively repeat the algorithm for both halves of the original array.

    This algorithm is not stable.
*/

#include <bits/stdc++.h>
#define ll long long


//Implementation.
int Partition(int A[], int low, int high) {
    int left, right, pivot_item = A[low];
    left = low;
    right = high;
    while(left < right) {
        /* Move left while item < pivot */
        while(A[left] <= pivot_item){
            left += 1;
        }
        /* Move right while item > pivot */
        while(A[right] > pivot_item) {
            right--;
        }
        if(left < right){
            std::swap(A[left], A[right]);
        }
    }
    /* right is final position for the pivot */
    A[low] = A[right];
    A[right] = pivot_item;
    return right;
}
void QuickSort(int A[], int low, int high) {
    int pivot;
    /* Termination condition! */
    if(high > low) {
        pivot = Partition(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high); 
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

    QuickSort(A, 0, n - 1); 

    std::cout << "Sorted: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}