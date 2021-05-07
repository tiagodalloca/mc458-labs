#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

long double findMaxProduct(int n, long double ns[])
{
	long double maxLinha = 0, minLinha = 0, currMax = 0;
 
	for (int i = 0; i < n; i++)
		{
			long double aux = maxLinha;
			maxLinha = max(ns[i], max(ns[i] * maxLinha, ns[i] * minLinha));
			minLinha = min(ns[i], min(ns[i] * aux, ns[i] * minLinha)); 
			currMax = max(currMax, maxLinha);
		}
	return currMax;
}

int main(int argc, char** args){
	int n;

	scanf("%d", &n);

	long double* ns = (long double*) malloc(sizeof(long double)*n);

	for (int i = 0; i < n; i++) {
		scanf("%LF", &(ns[i]));
	}

	long double max = findMaxProduct(n, ns);

	printf("%6LF\n", (max > 1 ? max : 1));

	free(ns);
}

