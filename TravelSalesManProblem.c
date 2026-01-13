#include<stdio.h>
/*
 Program to travel all cities minimizing the total travel distance
    Given a set of cities and distances between each pair of cities,
    find the shortest possible route that visits each city exactly once and returns to the origin city.
 Approach: Nearest Neighbor Heuristic
 1. Start from an arbitrary city as the current city.
 2. Mark the current city as visited.
 3. While there are unvisited cities:
    a. Find the nearest unvisited city from the current city.
    b. Move to that city and mark it as visited.
 4. Return to the starting city to complete the tour.
 Time Complexity: O(n^2)
 Space Complexity: O(n)
*/
#define MAX_CITIES 100
void travel_salesman(int distance_matrix[MAX_CITIES][MAX_CITIES], int n, int tour[]) {
    int visited[MAX_CITIES] = {0};
    int current_city = 0;
    tour[0] = current_city;
    visited[current_city] = 1;
    for (int i = 1; i < n; i++) {
        int min_dist = __INT_MAX__;
        int next_city = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distance_matrix[current_city][j] < min_dist) {
                min_dist = distance_matrix[current_city][j];
                next_city = j;
            }
        }
        tour[i] = next_city;
        visited[next_city] = 1;
        current_city = next_city;
    }
}
int main() {
    int distance_matrix[MAX_CITIES][MAX_CITIES] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int n = 4; // Number of cities
    int tour[MAX_CITIES];
    travel_salesman(distance_matrix, n, tour); 
    printf("Optimized Travel Salesman Tour Order:\n");
    for (int i = 0; i < n; i++) {
        printf("City %d\n", tour[i]);
    }
    return 0;
}
