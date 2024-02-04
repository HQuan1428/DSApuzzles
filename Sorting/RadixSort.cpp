/*
    TOPIC: RADIX SORT

    Algorithm: 
    1) Take the least siginificant digit of each element.
    2) Sort the list of elements based on that digit, but keep the order of element with the
        same digit(this is the definition of a stable sort).
    3) Repeat the sort with each more significant digit.

    How does Radix Sort Algorithm work? 
    Step1: Find the largest element in the array, which is 802. It has three digits, so we will iterate three times, once for each significant place.
    Step2: Sort the element based on the unit place digits(X = 0).
        We use a stable sorting technique, such as counting sort, to sort the digits at each significant place.
    Step3: Sort the element based on the tens place digits.
    Step4: Sort the elements based on the hundreds place digits.
    Step5: The array is now sorted in assecding order.
*/

#include <bits/stdc++.h>
#define ll long long

void countSort(int A[], int n, int exp) {
    int Output[n];
    int i, count[10] = {0}; 
    
    // Store count of occurrences
    // in Count[]
    for (int i = 0; i < n; i++) {
        count[(A[i] / exp) % 10]++;
    }

    //change count[i] so that count[i]
    //now contains actual position
    // of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    //build the output array
    for (int i = n - 1; i >= 0; --i) {
        Output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10] -= 1;
    }

    // Copy the output array to A[]
    // so that A[] now contains sorted
    // numbers according to current digit
    for(int i = 0; i < n; i++) {
        A[i] = Output[i];
    }
}

void RadixSort(int A[], int array_size) {
    int m = *(std::max_element(A, A + array_size));
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(A, array_size, exp); 
    }
} 


int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}