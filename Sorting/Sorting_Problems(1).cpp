#include <bits/stdc++.h>
#define ll long long

//Problem 3-4: which repeated the maximum number of times? 
int CheckWhoWinTheElection(int A[], int n)
{
    std::sort(A, A + n);
    int currentCounter = 1, maxCounter = 1;
    int currentCandidate = A[0], maxCandidate = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] == currentCandidate)
        {
            currentCounter += 1;
        }
        else
        {
            currentCandidate = A[i];
            currentCounter = 1;
        }
        if (currentCounter > maxCounter)
        {
            maxCandidate = currentCandidate;
            maxCounter = currentCounter;
        }
    }
    return maxCandidate;
}

//Problem 9: Given a number K, give an O(nlogn) time algorithmfor determining whether there exists a belong to A and b belong to B such that a + b = K.
int Find(int A[], int B[], int n, int K) {
    std::sort(A, A + n);
    for (int i = 0; i < n;i++) {
        int key = K - B[i]; 
        if(std::binary_search(A, A+n, key)){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]){
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int n; 
    std::cin >> n;
    int A[n];
    for(int &x:A) {
        std::cin >> x;
    }

    std::cout << CheckWhoWinTheElection(A, n) << std::endl;

    system("pause");
    return 0;
}