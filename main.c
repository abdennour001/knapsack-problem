/* A recursive implementation (Brute force and Optimized solution) of Knapsack problem */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 999

// Max between a and b, a and b are integers.
int max(int a, int b) {
	return (a > b) ? a : b;
}

// Brute force solution.
int knap_sack_brute_force(int M, int n, int value[], int weight[]) {
		// Base case
	if (M == 0 || n == 0) {
		return 0;
	}

	// Recursive calls.

	// If the nth element weight is greater than the maximum weight M then we remove it.
	if (weight[n-1] > M) {
		return knap_sack_brute_force(M, n-1, value, weight);
	}

	/**
		Return the maximum of the cases where nth element is included or not. 
	*/
	return max( value[n-1] + knap_sack_brute_force(M - weight[n-1], n-1, value, weight), knap_sack_brute_force(M, n-1, value, weight) );
}

// Dynamic programming solution.
/**
	In this solution we are going to use a global table to save the previous recursive calls, so we don't have to compute it again.
*/
int knap_sack_dynamic(int M, int n, int value[], int weight[]) {
	int K[n+1][M+1];

	for (int i=0; i<=n; i++) {
		for (int j=0; j<=M; j++) {
			if (i == 0 || j == 0) {
				K[i][j] = 0;
			} else if (weight[i-1] > j) {
				K[i][j] = K[i-1][j];
			} else {
				K[i][j] = max(value[i-1] + K[i-1][j - weight[i-1]], K[i-1][j]);
			}
		}

	}

	return K[n][M];
}

void random_test() {

}

void manual_test() {
	
}

int main(int argc, char** argv) {
	
	// value table
	int value[MAX] = {60, 100, 120, 90};
	// weight table
	int weight[MAX] = {10, 20, 30, 50};
	// maximum capacity
	int M = 99;
	// size of the table
	int n=4;
	
	printf("%d\n", knap_sack_brute_force(M, n, value, weight));
	printf("%d\n", knap_sack_dynamic(M, n, value, weight));

	return EXIT_SUCCESS;
}