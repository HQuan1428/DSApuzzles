/*
    TOPIC: BUCKET SORT

    Algorithm:
        Create n empty buckets (Or lists) and do the following for every array element arr[i]
        + Insert arr[i] into bucker[n*array[i]].
        + Sort individual buckers using insertion sort.
        + Concatenate all sort buckets.

*/

#include <bits/stdc++.h>
#define ll long long

#define BUCKETS 10

//Implementation

// Accoding to DSA Puzzles.

// void BucketSort(int A[], int array_size) {
//     int i, j, k;
//     int bucket[BUCKETS];
//     for (j = 0; j < BUCKETS; j++) {
//         bucket[j] = 0; 
//     }
//     for (int i = 0; i < array_size; i++) {
//         bucket[A[j]] += 1;
//     }
//     for (i = 0, j = 0; j < BUCKETS; j++) {
//         for (k = bucket[j]; k > 0; --k) {
//             A[i++] = j;
//         }
//     }
// }


//According to geeksforgeeks
void BucketSort(int A[], int array_size) {
    // 1) Create n empty buckets
    std::vector<int> B[array_size];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < array_size; i++) {
        // Index in buckets
        int bi = A[i] % 10;
        std::cout << bi << std::endl;
        B[bi].push_back(A[i]); 
    }

    //3) Sort individual buckets
    for (int i = 0; i < array_size; i++) {
        if(!B[i].empty())
            std::sort(B[i].begin(), B[i].end());
    }

    //4) Concatenate all buckets into A[]
    int index = 0;
    for (int i = 0; i < array_size; i++) {
        for (int j = 0; j < B[i].size(); j++) {
            A[index++] = B[i][j];
        }
    }
}

int main(int argc, char const *argv[]){

    freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

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

    BucketSort(A, n);

    std::cout << "Sorted: ";
    for (int x : A)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}