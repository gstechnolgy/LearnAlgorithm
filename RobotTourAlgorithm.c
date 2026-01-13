#include<stdio.h>
#include<limits.h>
/*
 Program to optimize the robot tour to minimize the total distance traveled
    Given a set of points (x,y) representing locations to be visited by the robot,
    find the order of visiting these points such that the total distance traveled is minimized.
 Approach: Nearest Neighbor Heuristic
 1. Start from an arbitrary point as the current point.
 2. Mark the current point as visited.
 3. While there are unvisited points:
    a. Find the nearest unvisited point from the current point.
    b. Move to that point and mark it as visited.
 4. Return to the starting point to complete the tour.
 Time Complexity: O(n^2)
 Space Complexity: O(n)
*/
typedef struct {
    int x;
    int y;
} Point;    
double distance(Point a, Point b) {
    return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}
void robot_tour(Point points[], int n, int tour[]) {
    int visited[100] = {0}; // Assuming a maximum of 100 points
    int current_index = 0;
    tour[0] = current_index;
    visited[current_index] = 1;

    for (int i = 1; i < n; i++) {
        double min_dist = INT_MAX;
        int next_index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                double dist = distance(points[current_index], points[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    next_index = j;
                }
            }
        }
        tour[i] = next_index;
        visited[next_index] = 1;
        current_index = next_index;
    }
}
int main() {
    Point points[] = {{0, 0}, {1, 2}, {3, 1}, {6, 5}, {7, 8}};
    int n = sizeof(points) / sizeof(points[0]);
    int tour[100];

    robot_tour(points, n, tour);

    printf("Optimized Robot Tour Order:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%d, %d)\n", tour[i], points[tour[i]].x, points[tour[i]].y);
    }
    return 0;
}
