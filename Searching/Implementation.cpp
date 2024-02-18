/*
    TOPIC: TYPES OF SEARCHING

    1) Unordered Linear Search.
    2) Ordered/Sorted Linear Search.
    3) Binary Search.
    4) Interpolation Search. 
    5) Binary Search Trees. 
    6) Symbol Tables and Hashing. 
    7) String Searching Algorithms. 
*/
#include <bits/stdc++.h>
#define ll long long

// Unordered Linear Searching. 
int UnOrderedLinearSearch (int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if(A[i] == key) {
            return 1;
        }
    }
    return 0;
}
// Time Complexity: O(n)

// Sorted/Ordered Linear Searching. 
int SortedLinearSearching (int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if(A[i] == key) {
            return 1;
        }
        else if(A[i] > key) {
            return 0;
        }
    }
    return 0;
}
// Time complexity: O(n)

// Binary Search 
int BinarySearchIterative(int A[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(A[mid] == key) {
            return mid; 
        }
        else if(A[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
int BinarySearchRecursive(int A[], int low, int high, int key) {
    int mid = low + (high - low) / 2;
    if(low > high) {
        return -1; 
    }
    if(A[mid] == key) {
        return mid;
    }
    else if(A[mid] < key) {
       return BinarySearchRecursive(A, mid + 1, high, key);
    }
    else {
        return BinarySearchRecursive(A, low, mid - 1, key); 
    }
    return -1;
}
// Time complexity: O(logn)

// Interpolation Search
int InterpolationSearch(int A[], int n, int key) {
    int low = 0, mid, high = n - 1;
    while(low <= high) {
        mid = low + ((key - A[low] * (high - low)) / (A[high] - A[low]));/* Below */
        if(A[mid] == key) {
            return mid + 1; 
        }
        if (key < A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}
/* -> The fomula pos can be derived as follows: 
Let's assume that the elements of the array are linearly distributed.

General equation of line : y = m*x + c.
y is the value in the array and x is its index.

Now putting value of lo,hi and x in the equation
arr[hi] = m*hi+c ----(1)
arr[lo] = m*lo+c ----(2)
x = m*pos + c     ----(3)

m = (arr[hi] - arr[lo] )/ (hi - lo)

subtracting eqxn (2) from (3)
x - arr[lo] = m * (pos - lo)
lo + (x - arr[lo])/m = pos
pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])
*/

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}