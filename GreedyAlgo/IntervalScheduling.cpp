#include <iostream>
#include <vector>
#include <algorithm>

struct Interval
{
    int start;
    int end;
};

bool compareIntervals(const Interval &a, const Interval &b)
{
    return a.end < b.end;
}

void maxNonOverlappingIntervals(std::vector<Interval> &intervals)
{
    // Sort intervals based on the end time
    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    // Vector to store the selected intervals
    std::vector<Interval> selectedIntervals;

    // Select the first interval
    selectedIntervals.push_back(intervals[0]);

    // Iterate over the remaining intervals
    for (size_t i = 1; i < intervals.size(); ++i)
    {
        // If the current interval's start time is after the end time
        // of the last selected interval, select it
        if (intervals[i].start >= selectedIntervals.back().end)
        {
            selectedIntervals.push_back(intervals[i]);
        }
    }

    // Print the selected intervals
    for (const auto &interval : selectedIntervals)
    {
        std::cout << "[" << interval.start << ", " << interval.end << "]" << std::endl;
    }
}

int main()
{
    // Example intervals
    std::vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 6}, {5, 7}, {8, 10}};

    // Call the function to find the maximum non-overlapping intervals
    maxNonOverlappingIntervals(intervals);

    return 0;
}
