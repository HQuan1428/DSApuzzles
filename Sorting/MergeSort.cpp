/*
    TOPIC: MERGE SORT

    This algorithm is stable.

    Time complexity: O(nlogn).
*/

#include <bits/stdc++.h>
#define ll long long

//Implementation

void Merge(int A[], int left, int mid, int right) {
    int i, left_end, size, temp_pos;
    left_end = mid - 1;
    temp_pos = left;
    size = right - left + 1;
    int temp[right + 1]; // the combine array.
    while(left <= left_end && mid <= right) {
        if(A[left] < A[mid]) {
            temp[temp_pos] = A[left];
            temp_pos += 1;
            left += 1;
        }
        else {
            temp[temp_pos] = A[mid];
            temp_pos += 1;
            mid += 1;
        }
    }

    while(left <= left_end) {
        temp[temp_pos] = A[left];
        temp_pos += 1;
        left += 1;
    } 
    while(mid <= right) {
        temp[temp_pos] = A[right];
        temp_pos += 1;
        mid += 1;
    }
    for (int i = 0; i < size; i++) {
        A[right] = temp[right]; // right(True) but left(False) ? -> Ans: left isn't original.
        right -= 1;
    }
}

void MergeSort(int A[], int left, int right) {
    int mid; 
    if(right > left) {
        mid = left + (right - left) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid + 1, right); 
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

    MergeSort(A, 0, n - 1);

    std::cout << "Sorted: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}