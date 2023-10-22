/*
Problem-4: Maximum sum in sliding window
    refer piority queue
Problem-5: 
Problem-6: a formule menber of elements int the queue in terms front, rear, n;
    Formula: if(front == rear) rear - front + 1 
             else  rear - front + n. 

*/
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>
#include <limits>
#include "Queue_Implementation.h"
#define ll long long

//brute force 
ll MaxSumSW(int *a, int n, int k) {
    ll sum = 0; 
    for(int i = 0; i < k; i++) {
        sum += 1ll*a[i]; 
    }
    ll maximum = LONG_LONG_MIN;
    maximum = std::max(maximum, sum);  
    for(int i = k; i < n; i++) {
        sum += a[i]*1ll - a[i-k]*1ll;
        maximum = std::max(maximum, sum);
    }
    return maximum;   
}
//

int main(int argc, char const *argv[]){
    Queue<int> qe(5);
    qe.EnQueue(1);
    qe.EnQueue(2);
    qe.EnQueue(3);
    qe.EnQueue(4);
    std::cout << qe.getfront() << " " << qe.getrear() << std::endl;
    system("pause");
    return 0;
}