#include <bits/stdc++.h>
#define ll long long


/* Problem 1 - 4: check duplicates. */ 
void CheckDuplicates(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if(A[std::abs(A[i])] < 0) {
            std::cout << "Duplicates Exist\n";
            return;
        }
        else
            A[std::abs(A[i])] *= -1;
    }
    std::cout << "No duplicates in given array\n"; 
}

/* Problem 5-8: Find the element which appears the maximum number of times in the array. */
int MaxRepititions(int A[], int n) {
    int i = 0, max = 0, maxIndex = 0;
    for (i = 0; i < n; i++) {
        A[A[i] % n] += n;
    }
    for (i = 0; i < n; i++) {
        if(A[i]/n > max) {
            max = A[i] / n;
            maxIndex = i;
        }
    }
    return maxIndex;
}

/* Problem 9 - 12: Find the first element in the array which is repeated. */
int firstEleRepeat(int A[], int n) {
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if(mp.find(A[i]) == mp.end()) { /* !mp.count(A[i]) */
            mp[A[i]] = i + 1;
        }
        else if(mp[A[i]] > 0) {
            mp[A[i]] = -1 * mp[A[i]];
        }
    }
    int first_element_repeat = 0, max_value = INT_MIN;
    for(auto it : mp) {
        if(it.second < 0) {
            if(max_value < it.second) {
                max_value = it.second;
                first_element_repeat = it.first;
            }
        }
    }
    return first_element_repeat;
}

/* Problem 13 - 17: Finding the Missing Number. */ 

//Brute force Solution:
int FindMisingNumber(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if(A[j] == i){
                found = true;
                break;
            }
        }
        if(!found) {
            return i;
        }
    }
    return -1;
}

// We can use summation formula
int FindMisingNumber1(int A[], int n) {
    int r = *std::max_element(A, A + n); // each element of array is in the range of 1 to (r)
    int sum = r * (r + 1) / 2;
    int total = std::accumulate(A, A + n, 0);
    return std::abs(sum - total);
}

// Solution of Problem 17
int FindMisingNumber2(int A[], int n) {
    int r = *std::max_element(A, A + n);
    int i, X = 0, Y = 0;
    for (i = 0; i < n; i++) {
        X ^= A[i];
    }
    for (i = 1; i <= r; i++) {
        Y ^= i;
    }
    std::cout << X << " " << Y << std::endl;
    return X^Y;
}

/* Problem 18 : Find the Number Occurring an Old Number of Times*/
int FindNumberOccOleTimes(int A[], int n) {
    int X = 0;
    for (int i = 0; i < n; i++) {
        X ^= A[i];
    }
    return X;
}

/* Problem 19 - 24: Find the two repeating element in a given array */
void PrintRepeatedElement(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if( A[i] == A[j] ) {
                std::cout << A[i] << std::endl;
            }
        }
    }
}
//Time complexity: O(n^2), Space complexity: O(1)

// Solution of problem 20: Sorting 

// Solution of Problem 21: Counting Sort Application. 
void PrintRepeatedElement1(int A[], int size) {
    int *count = new int[100];
    std::memset(count, 0, 100*sizeof(int));
    for (int i = 0; i < size; i++) {
        count[A[i]]++;
    }
    for (int i = 0; i < 100; i++) {
        if(count[i] >= 2) {
            std::cout << i << std::endl;
        }
    }
}
//Time complexity: O(n), Space complexity: O(n)

// Solution of Problem 22: XOR Operator.

// Solution of Problem 23: Using these sum and product formulae
// S is the sum of the element. 
// P is the product of the element.
//  Sum: X + Y = S - n(n+1)/2.
//  Product: XY = P / n! 
std::pair<int,int> SolveEquation2(int a, int b, int c) {
    int delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        int x1 = (-b + sqrt(delta)) / (2 * a);
        int x2 = (-b - sqrt(delta)) / (2 * a);
        return {x1, x2};
    }
    else if (delta == 0)
    {
        int x = -b / 2 * a;
        return {x, x};
    }
    return {-1, -1}; // no exist value.
}
std::pair<int,int> Find_XY(int sum, int product) {
    if(sum * sum < 4 * product ) {
        std::cout << "No Exist Repeat Element.\n";
        return {-1, -1};
    }
    return SolveEquation2(1, -1 * sum, product);
}

void PrintRepeatElement2(int A[], int n, int s) {
    int sum = std::accumulate(A, A + n, 0) - (s * (s + 1) / 2);
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        p *= A[i];
    }
    int gt = 1;
    for (int i = 1; i < s; i++) {
        gt *= i;
    }
    int product = p / gt;
    std::pair<int, int> res = Find_XY(sum, product);
    std::cout << res.first << " " << res.second << std::endl;
}

/* Problem 25 - 28: Find two elements in the array such that their sum is equal to given element k */

// Solution of problem 25: brute force.
void BruteForceSearch(int A[], int n, int k) {
    for (int i = 0; i < n;i++) {
        for (int j = i + 1; j < n; j++) {
            if(A[i] + A[j] == k) {
                std::cout << i << " " << j << std::endl;
                return;
            }
        }
    }
    std::cout << "Item not found: No such elements.\n"; 
}

// Solution of problem 26 : Using Sort and two varialbe
void SearchWithSort(int A[], int n, int k) {
    std::sort(A, A+n);
    int hiIndex = n - 1;
    int loIndex = 0; 
    while(hiIndex > loIndex) {
        if(A[hiIndex] + A[loIndex] == k) {
            std::cout << loIndex << " " << hiIndex << std::endl;
            return;
        }
        else if(A[hiIndex] + A[loIndex] < k) {
            loIndex += 1;
        }
        else {
            hiIndex -= 1;
        }
    }
    std::cout << "Item not found: No such elements.\n";
}

/* Problem 29: Find three indices, i, j, k such that A[i]^2 + A[j]^2 = A[k]^2 */

// solution 
void FindThreeIndices(int A[], int n) {
    std::unordered_map<int, int> udmap;
    std::transform(A, A + n, A, [](int &n){ return n * n; });
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int sum = A[i] + A[j];
            if (udmap.find(sum) != udmap.end())
            {
                std::cout << i << " " << j << " " << udmap[sum] << std::endl;
            }
        }
        udmap[A[i]] = i;
    }
}

/* Problem 30: Two element whose sum is cloest to zero */

// Solution of Problem 30: brute force 
void TwoEleSumCloest0(int A[], int n) {
    if(n < 1) {
        std::cout << "Invaild Input \n";
        return;
    }
    int min_i = INT_MAX;
    int min_j = INT_MAX;
    int sum_cloest_zero = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = std::abs(A[i] + A[j]); 
            if(sum_cloest_zero > sum) {
                sum_cloest_zero = sum;
                min_i = i;
                min_j = j;
            }
        }
    }
    std::cout << "The two element are " << min_i << " " << min_j << std::endl;
}
// Time complexity: O(n^2), Space complexity: O(1).

// Solution of problem 31: using sort.

/* Problem 32 - 35: Findd three elements in the array such that their sum is equal to given element k */

// Solution of problem 32: brute force 
void BFSearch(int A[], int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int f = j + 1; f < n; f++) {
                if(A[i] + A[j] + A[f] == k) {
                    std::cout << "Item found: ";
                    std::cout << i << " " << j << " " << f << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "Item not found: No such elements\n";
}
// Time complexity: O(n^3), Space complexity: O(1). 

// Solution of problem 34: Using sort
void SSearch(int A[], int n, int k) {
    std::sort(A, A + n);
    for (int f = 0; f < n; f++) {
        int i = f + 1;
        int j = n - 1; 
        while(i < j) {
            if(A[i] + A[j] + A[f] == k) {
                std::cout << "Item fount: ";
                std::cout << i << " " << j << " " << f << std::endl;
                return;
            }
            else if(A[i] + A[j] + A[f] < k){
                i += 1;
            }
            else {
                j -= 1;
            }
        }
    }
    return;
}
// Time complexity: O(n^2), Space complexity: O(1).

// Solution of problem 35: using hash table.
void HTSearch(int A[], int n, int k) {
    std::unordered_map<int, std::pair<int,int>> udmap;
    // Insert all possible sums with pairs of elements into the hash table.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int sum = A[i] + A[j];
            udmap[sum] = {i, j}; 
        }
    }

    /*
        Check whether there exists a hash entry in the table with key: K - A[X], 
        If such element exist then scan the element pairs of K - A[X] and return all possible pairs by including A[X] also.
        If no such element exists (with K - A[X] as key) then go to next element. 
    */
    for (int i = 0; i < n; i++) {
        auto it = udmap.find(k - A[i]);
        if(it != udmap.end()) {
            std::cout << "Itme found: " << i << " " << it->second.first;
            std::cout << " " << it->second.second << std::endl;
            return;
        }
    }
}

/* Problem 37: Find k so that 0 < k < n such that A[0].....A[k] is an increasing sequence and A[k+1].....A[n] is an decreasing sequence.*/
int SearchK(int A[], int n){
    int low = 0, high = n - 1;
    while(low <= high) {
        // if the current array has size 1
        if (low == high)
        {
            return low;
        }
        // if the current array has size 2
        if (low == high - 1)
        {
            return A[low] > A[high] ? low : high;
        }
        int mid = low + (high - low) / 2;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
        {
            return mid;
        }
        else if (A[mid] > A[mid - 1] && A[mid] < A[mid + 1])
        {
            // an increasing sequence
            low = mid + 1;
        }
        else if (A[mid] < A[mid - 1] && A[mid] > A[mid + 1])
        {
            // an decreasing sequence
            high = mid - 1;
        }
    }
    return -1;
}

/* Problem 40 - 41: Find index an element of a arrray */
int FindPivot(int A[], int start, int finish) {
    if(finish - start == 0) {
        return start;
    }
    if(start == finish - 1) {
        return A[start] >= A[finish] ? start : finish;
    }
    int mid = start + (finish - start) / 2;
    if(A[start] >= A[mid]) {
        return FindPivot(A, start, mid);
    }
    else {
        return FindPivot(A, mid, finish);
    }
}
int SearchX(int A[], int n, int X) {
    int pivot = FindPivot(A, 0, n - 1);
    if(A[pivot] == X) {
        return pivot;
    }
    if(A[pivot] <= X) {
        return std::binary_search(A, A + pivot - 1, X);
    }
    else
        return std::binary_search(A + pivot + 1, A + n, X);
}
// Time complexity: O(logn)

// Solution of problem 41
int BinarySearchRotated(int A[], int start, int finish, int data) {
    int mid = start + (finish - start) / 2;
    if(start > finish) {
        return -1;
    }
    if(data == A[mid]) {
        return mid;
    }
    if(A[start] <= A[mid]) { // start half is in sorted order.
        if(data >= A[start] && data < A[mid])
            return BinarySearchRotated(A, start, mid - 1, data);
        else
            return BinarySearchRotated(A, mid + 1, finish, data); 
    }
    else{ // A[mid] <= AA[finish] half is in sorted order.
        if(data > A[mid] && data < A[finish]){
            return BinarySearchRotated(A, mid + 1, finish, data);
        }
        else
            return BinarySearchRotated(A, start, mid - 1, data);
    }
}
// Time complexity: O(logn)

/* Problem 42: Bitonic search */
int FindPV(int A[], int n) {
    int low = 0, high = n - 1;
    while(low < high) {
        if(low == high) {
            return low;
        }
        if(high - low == 1) {
            return A[low] >= A[high] ? low : high;
        }
        int mid = low + (high - low) / 2;
        if(A[mid] > A[mid - 1] && A[mid] > A[mid+1]){
            return mid;
        }
        if(A[mid] > A[mid-1] && A[mid] < A[mid + 1]) {
            low = mid + 1;
        }
        else if(A[mid] < A[mid - 1] && A[mid] > A[mid + 1]){
            high = mid - 1;
        }
    }
    return -1;
}
int binary_search(int A[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (A[mid] == key)
    {
        return mid;
    }
    if (A[mid] > key)
    {
        return binary_search(A, low, mid - 1, key);
    }
    return binary_search(A, mid + 1, high, key);
}
int BitonicSearch(int A[], int n, int key) {
    int pivot = FindPV(A, n); 
    if(A[pivot] == key) {
        return pivot;
    }
    int res1 = binary_search(A, 0, pivot - 1, key);
    int res2 = binary_search(A,pivot + 1, n - 1, key);
    return res1 > res2 ? res1 : res2;
}

/* Problem 46: find the index of the first orcurrence of the number in O(logn) time */
int BinarySearchFirstOrcurrence(int A[], int low, int high, int key) {
    if(low <= high) {
        int mid = low + (high - low) / 2;
        if((A[mid] == key && mid == low) || (A[mid] == key && A[mid - 1] < key)) {
            return mid;
        }
        if(key > A[mid]) {
            return BinarySearchFirstOrcurrence(A, mid + 1, high, key);
        }
        return BinarySearchFirstOrcurrence(A, low, mid - 1, key); 
    }
    return -1;
}
// Time complexity: O(logn).

/* Problem 47: Find the index of the last orcurrence of the number in O(logn) time */
int BinarySearchLastOrcurrence(int A[], int low, int high, int key) {
    if(low <= high){
        int mid = low + (high - low) / 2;
        if((A[mid] == key && mid == high) || (A[mid] == key && A[mid + 1] > key)){
            return mid;
        }
        if(key >= A[mid]) {
            return BinarySearchLastOrcurrence(A, mid + 1, high, key);
        }
        return BinarySearchLastOrcurrence(A, low, mid - 1, key);
    }
    return -1; 
}

/* Problem 48 - 50: Find the number of occurrences of a number */

//Solution of Problem 48: Brute force.
int LinearSearchCount(int Array[], int Length, int Key) {
    int Count = 0;
    for (int i = 0; i < Length; i++) {
        if(Array[i] == Key) {
            Count += 1;
        }
    }
    return Count;
}
//Time complexity: O(n).

//Solution of Problem 49-50: Binary Search
int OccurrencesOfKey(int Array[], int Length, int Key) {
    std::sort(Array, Array + Length); 
    int Numbers = std::upper_bound(Array, Array + Length, Key) - std::lower_bound(Array, Array + Length, Key);

    // int FirstKey = std::lower_bound(Array, Array + Length, Key) - std::begin(Array);
    // int LastKey = std::upper_bound(Array, Array + Length, Key) - std::end(Array);

    return Numbers;
}

/* Problem 52 - : Find second smallest number eficiently */

// Solution of Problem 52: Using Heap and Priority_queue.

// Solution of Problem 53: Using The tournament problem.
int FindSecondLargest(const std::vector<int> &V) {
    // Base case: If there is only one number, return it.
    if(V.size() == 2) {
        return std::min(V[0], V[1]);
    }

    // Split the numbers into pair.
    std::vector<int> Winners;
    for (int i = 0; i < V.size(); i += 2) {
        if(i + 1 < V.size()) {
            Winners.push_back(std::max(V[i], V[i + 1]));
        }
        else {
            Winners.push_back(V[i]);
        }
    }

    // Recursively call the function on the winners.
    return FindSecondLargest(Winners);
}
//  Time complexity: O(nlogn).




int main(int argc, char const *argv[])
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> V;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        V.push_back(x);
    }
    std::cout << FindSecondLargest(V) << std::endl;
    return 0;
}