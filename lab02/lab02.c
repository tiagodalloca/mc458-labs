#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int* count = (int*) malloc(sizeof(int) * (n*n + 1));
	int* input = (int*) malloc(sizeof(int) * n);
	int* output = (int*) malloc(sizeof(int) * n);

	for (int i = 0; i < (n*n + 1); i++) {
		count[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		count[x] += 1;
		input[i] = x;
	}

	int total = 0;
	for (int i = 0; i < (n*n + 1); i++) {
		int aux = count[i];
		count[i] = total;
		total += aux;
	}

	for (int i = 0; i < n; i++) {
		output[count[input[i]]] = input[i];
		count[input[i]] += 1;
	}

	printf("%d", output[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", output[i]);
	}

	printf("\n");

	return 0;
}
