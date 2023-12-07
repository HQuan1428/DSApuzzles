
/*
    TOPIC: BUILD HEAP and HEAP SORT 
*/

#include <bits/stdc++.h>
#define ll long long


//STRUCT HEAP 
struct Heap {
    int *array;
    int count;      //Number of elements in Heap
    int capacity;   //Size of the heap
    int heap_type;  //Min Heap of Max Heap
};

//Creating Heap
Heap* CreateHeap(int capacity, int heap_type) {
    Heap *h = new Heap;
    h->heap_type = heap_type;
    h->capacity = capacity;
    h->count = 0;
    h->array = new int[h->capacity];
    return h;
}

// Parent of node
int Parent(Heap* h, int i) {
    if(i <= 0 || i >= h->count) {
        return -1;
    }
    return i - 1 / 2;
} 

//child of node
int LeftChild(Heap *h, int i) {
    int left = 2 * i + 1;
    if(left >= h->count) {
        return -1;
    }
    return left; 
}
int RightChile(Heap *h, int i) {
    int right = 2 * i + 2;
    if(right >= h->count) {
        return -1;
    }
    return right;
}

// Getting the Maximum Element
int GetMaximum(Heap *h) {
    if(h->count == 0) {
        return - 1;
    }
    return h->array[0]; 
}

//Heapifying an Element

//Percolate Down
void PercolateDown(Heap *h, int i) {
    int left = LeftChild(h, i);
    int right = RightChile(h, i);
    int max_index = INT_MIN;
    if(left != -1 && h->array[left] > h->array[i]) {
        max_index = left;
    }
    else
        max_index = i;
    if(right != -1 && h->array[right] > h->array[max_index]) {
        max_index = right;
    }

    if(max_index != i) {
        std::swap(h->array[i], h->array[max_index]);
        PercolateDown(h, max_index); 
    }
}


//Deleting an Element
int DeleteMax(Heap *h) {
    if(h->count == 0) {
        return -1;
    }
    int data = h->array[0]; 
    std::swap(h->array[0], h->array[h->count - 1]);
    h->count -= 1;
    PercolateDown(h, 0);
    return data;
}
// Note: Deleting an element uses PercolateDown, and inserting an element uses PercolateUp

//Inserting an Element
void ResizeHeap(Heap *h) {
    int *array_old = h->array;
    h->array = new int[h->capacity * 2];
    for (int i = 0; i < h->capacity; i++) {
        h->array[i] = array_old[i];
    }
    h->capacity *= 2;
    delete array_old;
    array_old = NULL;
}

int Insert(Heap *h, int data) {
    if(h->count == h->capacity) {
        ResizeHeap(h); 
    }
    h->count += 1;
    int i = h->count - 1; 
    while(i >= 0 && data > h->array[(i-1)/2]) {
        h->array[i] = h->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->array[i] = data;
}

//Build Heap
void BuildHeap(Heap *h, int A[], int n) {
    if(h == NULL) {
        return;
    }
    while(n > h->capacity) {
        ResizeHeap(h); 
    }
    for (int i = 0; i < n; i++) {
        h->array[i] = A[i]; 
    }
    h->count = n;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        PercolateDown(h, i); 
    }
}

//Heap Sort
void Heapsort(int A[], int n) {
    Heap *h = CreateHeap(n, 0);
    BuildHeap(h, A, n);
    int size = h->count;
    for (int i = n - 1; i >= 0; i++) {
        std::swap(h->array[0], h->array[i]);
        h->count -= 1;
        PercolateDown(h, i); 
    }
    h->count = size;
}

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}