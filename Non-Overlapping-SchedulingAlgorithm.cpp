#include<iostream>
#include<vector>
#include<algorithm>
/*
 Program to schedule non-overlapping intervals to maximize the number of intervals scheduled
    Given a set of intervals with start and end times, select the maximum number of non-overlapping intervals.
 Approach: Greedy Algorithm
    1. Sort the intervals based on their end times.
    2. Initialize an empty list to store selected intervals.
    3. Iterate through the sorted intervals and select an interval if its start time is greater than or equal to the end time of the last selected interval.
 Time Complexity: O(n log n) due to sorting
 Space Complexity: O(n) for storing selected intervals
*/
struct Interval {
    int start;
    int end;
}; 
bool compareEndTimes(Interval a, Interval b) {
    return a.end < b.end;
}
std::vector<Interval> nonOverlappingScheduling(std::vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), compareEndTimes);
    std::vector<Interval> selectedIntervals;
    int lastEndTime = -1;
    for (const auto& interval : intervals) {
        if (interval.start >= lastEndTime) {
            selectedIntervals.push_back(interval);
            lastEndTime = interval.end;
        }
    }
    return selectedIntervals;
}
int main() {
    std::vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    std::vector<Interval> result = nonOverlappingScheduling(intervals);
    std::cout << "Selected Non-Overlapping Intervals:\n";
    for (const auto& interval : result) {
        std::cout << "[" << interval.start << ", " << interval.end << "]\n;
    }
    return 0;
}
