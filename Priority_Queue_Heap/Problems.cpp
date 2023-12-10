
/*
    TOPIC: THE PROBLEMS OF PRIORITY_QUEUES and HEAPS. 
*/


#include <bits/stdc++.h>
#include "Heap.h"
#define ll long long


//Problem 7: finding the maximum element. 
int FindMaxInMinheap(Heap* h) {
    int Max_value = INT_MIN;
    for (int i = (h->count - 1) / 2; i < h->count; i++) {
        Max_value = std::max(Max_value, h->array[i]);
    }
}
//Time complexity: O(n/2)

//Problem 9: deleting the ith element in min_heap
int Delete(Heap *h, int i) {
    if(h->count == 0) {
        return -1;
    }
    if(h->count < i) {
        std::cout << "wrong error\n";
        return -1;
    }
    int key = h->array[i];
    std::swap(h->array[i], h->array[h->count - 1]);
    h->count -= 1;
    PercolateDown(h, i);
    return key;
}
//Time complexity: O(logn)

//Problem 28-29-30: Maximum Number of Sliding Window
void MaxSlidingWindow(int A[], int n, int w, int B[]) {
    std::deque<int> Q;
    for (int i = 0; i < w; i++) {
        while(!Q.empty() && A[i] >= A[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for (int i = w; i < n; i++) {
        B[i - w] = A[Q.front()]; 

        while(!Q.empty() && A[i] >= A[Q.back()]) {
            Q.pop_back();
        }
        while(!Q.empty() && Q.front() <= i - w) {
            Q.pop_front();
        }
        Q.push_back(i);
    }
    B[n - w] = A[Q.front()];// the array store maximum number each sliding window.
}



int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}