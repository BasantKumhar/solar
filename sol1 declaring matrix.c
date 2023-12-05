//1) Solution 1 – By declaring matrix elements.
#include <stdio.h>
#include <omp.h>
#define SIZE 4
int main() {
 	int A[SIZE][SIZE] = {{1, 2, 3, 4},
 				{5, 6, 7, 8},
 				{9, 10, 11, 12},
 {13, 14, 15, 16}};
 int B[SIZE][SIZE] = {{17, 18, 19, 20},
 				{21, 22, 23, 24},
 	{25, 26, 27, 28},
 				{29, 30, 31, 32}};
 	int sum_result = 0;
 	int min_result = A[0][0] + B[0][0];
 int max_result = A[0][0] - B[0][0];
 #pragma omp parallel for num_threads(4) reduction(+:sum_result)
reduction(min:min_result) reduction(max:max_result)
 for (int i = 0; i < SIZE; ++i) {
 	for (int j = 0; j < SIZE; ++j) {
 // i. Sum of elements in A and B
 sum_result += A[i][j] + B[i][j];
 // ii. Minimum element in A and B
 if (A[i][j] + B[i][j] < min_result) {
 	min_result = A[i][j] + B[i][j];
 }
 // iii. Maximum element in A and B
 if (A[i][j] - B[i][j] > max_result) {
 max_result = A[i][j] - B[i][j];
 }
 }
 }
 printf("i. Sum of elements in A and B: %d\n", sum_result);
 printf("ii. Minimum element of A + Minimum element of B: %d\n", min_result);
 printf("iii. Maximum element of A - Maximum element of B: %d\n", max_result);
 return 0;
}
