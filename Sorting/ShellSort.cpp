/*
    TOPIC: SHELL SORT

    This sorting algorithm is a generalization of insertion sort. Shell sort is also known as n-gap insertion sort.

    Algorithm:
    Step 1: Start
    Step 2: Initialize the value of gap size. Example: h
    Step 3: Divide the list into smaller sub-part. Each must have equal intervals to h
    Step 4: Sort these sub-lists using insertion sort
    Step 5: Repeat this step 2 until the list is sorted.
    Step 6: Print a sorted list.
    Step 7: Stop.

    Pseudocode
    PROCEDURE SHELL_SORT(ARRAY, N)  
    WHILE GAP < LENGTH(ARRAY) /3 :
            GAP = ( INTERVAL * 3 ) + 1      
    END WHILE LOOP
    
    WHILE GAP > 0 :
        FOR (OUTER = GAP; OUTER < LENGTH(ARRAY); OUTER++):
                INSERTION_VALUE = ARRAY[OUTER]
                INNER = OUTER;
                WHILE INNER > GAP-1 AND ARRAY[INNER – GAP] >= INSERTION_VALUE:
                    ARRAY[INNER] = ARRAY[INNER – GAP]
                    INNER = INNER – GAP
                END WHILE LOOP
                    ARRAY[INNER] = INSERTION_VALUE
        END FOR LOOP
        GAP = (GAP -1) /3;    
    END WHILE LOOP
    END SHELL_SORT

    The best case in Shell sort is when the array is already sorted in the right order. The number of comparisons is less.
    The running time of Shellsort depends on the choice of increament sequence.

*/

#include <bits/stdc++.h>
#define ll long long


// Implementation
void ShellSort(int A[], int array_size) {
    for (int gap = array_size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < array_size; i += 1) {
            int temp = A[i];
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
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

    ShellSort(A, n);

    std::cout << "Sorted: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    return 0;
}