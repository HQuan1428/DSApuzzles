#pragma once

/*
    TOPIC: IMPLEMENTATION DISJOINT SETS
*/

//Fast UNION Implementation (slow FIND)

//MAKESET
void MAKESET(int S[], int size) {
    for (int i = size - 1; i >= 0; --i) {
        S[i] = i;
    }
}

//FIND
int FIND(int S[], int size, int X) {
    if(!(X>=0 && X < size)) {
        return -1;
    }
    if(S[X] == X) {
        return X;
    }
    return FIND(S, size, S[X]);
}

//UNION
void UNION(int S[], int size, int root1, int root2) {
    if(FIND(S, size, root1) == FIND(S, size, root2)) {
        return;
    }
    if(!((root1 >= 0 && root1 < size) && (root2 >= 0 && root2 < size))) {
        return;
    }
    S[root1] = root2; 
}


//Fast UNION Implementation (Quick FIND)

//MAKESET
void MAKESET(int S[], int size) {
    for (int i = 0; i < size; i++) {
        S[i] = -1;
    }
}

//FIND
int FIND(int S[], int size, int X) {
    if(!(X >= 0 && X < size)) {
        return -1;
    }
    if(S[X] == -1) {
        return X;
    }
    return FIND(S, size, S[X]);
}

//UNION by Size
void UNIONBySizse(int S[], int size, int root1, int root2) {
    if((FIND(S,size,root1) && FIND(S,size,root2)) && FIND(S, size, root1) != -1) {
        return;
    }
    if(S[root1] < S[root2]) {
        S[root1] = root2;
        S[root2] += S[root1];
    }
    else {
        S[root2] = root1;
        S[root1] += S[root2];
    }
}

//UNION by height
void UNIONByHeight(int S[], int size, int root1, int root2) {
    if(FIND(S, size, root1) == FIND(S, size, root2) && FIND(S, size, root1) != -1) {
        return;
    }
    if(S[root1] < S[root2]) {
        S[root1] == root2;
    }
    else {
        if(S[root1] == S[root2]) {
            S[root1]--;
            S[root2] = root1;
        }
    }
}

//FIND with path compression
int FIND(int S[], int size, int X) {
    if(!(X >= 0 && X < size)) {
        return -1;
    }
    if(S[X] <= 0) {
        return X;
    }
    return S[X] = FIND(S, size, S[X]);
} 