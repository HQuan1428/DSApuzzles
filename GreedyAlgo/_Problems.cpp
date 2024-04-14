/*
    TOPIC: THE PROBLEM OF GREEDY ALGORITHM

    Problem 1: Merge file
        - Algorithm:
            + Store file sizes in a priority queue, the key of element
            + Repeat the following until there is only one file.
                * Extract two smallest element X and Y.
                * Merge X and Y and insert this new file in the priority queue.
    Problem 2: Interval scheduling
        - Algorithm:
            + Sort interval accrocding to the right-most ends [end time].
            + For every consecutive interval{
                * If the left-most end is after the right-most end of the last selected interval, then we select this interval.
                * Otherwise we skip it and go to the next interval.
            }

    Problem 3: The interval coloring problem
        - Algrithm:
            + Process the classes in
            increasing order of start times. Assume that we are processing class C. If there is a room R
            such that R has been assigned to an earlier class, and C can be assigned to R without
            overlapping previously assigned classes, then assign C to R. Otherwise, put C in a new
            room. Does this algorithm solve the problem?

    Problem 4: 
*/
#include <bits/stdc++.h>
#define ll long long




int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}