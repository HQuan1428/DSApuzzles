/*
    TOPIC: STRING MATCHING ALGORITHM

    15.3 Brute Force Method. 
    15.4 Rabin-Karp.
    15.5 String Matching with Finite Automata.
    15.6 KMP Algorithm.
    15.7 Boyer-Moore Algorithm.
*/
#include <bits/stdc++.h>
#define ll long long

/*
    15.3
    Input: two Array, two Var
    Ouput: int.
    Time complexity: O(n*m).
    Space complexity: O(1).
*/
int BruteForceMethod(int T[], int n, int P[], int m) {
    for (int i = 0; i < n - m + 1; i++) {
        int j = 0; 
        while(j < m && P[j] == T[i+j]) {
            j += 1;
        }
        if(j == m) {
            return 1;
        }
    }
    return -1;
}

//15.5
/*
    Input: String pattern P, length of P
    Goal:
*/
int F[10000];
void Prefix_Table(int P[], int m) {
    int i = 1, j = 0;
    F[0] = 0;
    while(i < m) {
        if(P[i] == P[j]) {
            F[i] = j + 1;
            i++;
            j++;
        }
        else if( j > 0 ) {
            j = F[j - 1];
        }
        else {
            F[j] = 0;
            i++;
        }
    }
}

/*
    Input: String text T, Pattern P, length of T, length of P
    Goal: Find start index of P in T if P match T.
*/
int KMPAlgo(char T[], int n, int P[], int m) {
    int i = 0, j = 0;
    Prefix_Table(P, m); 
    while( i < n ) {
        if(T[i] == P[j]) {
            if(j = m - 1){
                return i - j; 
            }
            else {
                i++;
                j++;
            }
        }
        else if (j > 0) {
            j = F[j - 1];
        }
        else
            i++;
    }
    return -1;
}



int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}