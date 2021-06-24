#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int i, p;
} tarefa ;

short int compare_tarefa(tarefa a, tarefa b) {
	if (a.p > b.p) return 1;
	if (a.p < b.p) return -1;
	return a.i <= b.i ? -1 : 1;
}

void swap(tarefa arr[], int i, int j) {
	tarefa aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

int partition (tarefa arr[], int start, int end) {
	tarefa p = arr[end];  
 
	int i = (start - 1);
	for (int j = start; j <= end - 1; j++) {
		if (compare_tarefa(arr[j], p) < 0) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, end);
	return i + 1;
}


void quicksort(tarefa arr[], int start, int end) {
	if (start < end) {
		int p = partition(arr, start, end);
		quicksort(arr, start, p - 1); 
		quicksort(arr, p + 1, end);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	tarefa tarefas[n];

	for (int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);
		tarefas[i] = (tarefa) { i + 1, p};
	}

	quicksort(tarefas, 0, n - 1);

	int cs[n];
	int c = 0;
	for (int i = 0; i < n; i++) {
		c = c + tarefas[i].p;
		cs[i] = c;
	}

	c = 0;
	for (int i = 0; i < n; i++) {
		c += cs[i];
	}

	printf("%d\n", c);
	printf("%d", tarefas[0].i);
	for (int i = 1; i < n; i++) {
		printf(" %d", tarefas[i].i);
	}
	printf("\n");
}

