#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rx, cx, ry, cy, p;
} movimento;

typedef struct {
	int reais;
	int cx;
} caminho;

int main(){
	int n;

	scanf("%d", &n);

	int nlinhas = (n - 1) * (2*2 + 3*(n - 2));

	movimento*** movimentos = (movimento***) malloc(sizeof(movimento**) * n);

	for (int i = 0; i < n; i++) {
		movimentos[i] = (movimento**) malloc(sizeof(movimento*) * n);
		for (int j = 0; j < n; j++) {
			movimentos[i][j] = (movimento*) malloc(sizeof(movimento) * 3);
		}
	}

	for (int i = 0; i < nlinhas; i++) {
		int rx, cx, ry, cy, p;
		scanf("%d %d %d %d %d", &rx, &cx, &ry, &cy, &p);
		int j = cx - cy + 1;
		movimentos[ry][cy][j] = (movimento) { rx, cx, ry, cy, p };
	}

	caminho** caminhos = (caminho**) malloc(sizeof(caminho*) * n);

	for (int i = 0; i < n; i++) {
		caminhos[i] = (caminho*) malloc(sizeof(caminho) * n);
		for (int j = 0; j < n; j++) {
			caminhos[i][j].reais = 0;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			movimento melhor_movimento = movimentos[i][j][1];
			int acc = caminhos[i - 1][melhor_movimento.cx].reais + melhor_movimento.p;
			if (j > 0 &&
					caminhos[i - 1][movimentos[i][j][0].cx].reais + movimentos[i][j][0].p >= acc) {
				melhor_movimento = movimentos[i][j][0];
				acc = caminhos[i - 1][melhor_movimento.cx].reais + melhor_movimento.p;
			}
			if (j < n - 1 &&
					caminhos[i - 1][movimentos[i][j][2].cx].reais + movimentos[i][j][2].p > acc) {
				melhor_movimento = movimentos[i][j][2];
				acc = caminhos[i - 1][melhor_movimento.cx].reais + melhor_movimento.p;
			}
			int cx = melhor_movimento.cx;
			caminhos[i][j].cx = cx;
			caminhos[i][j].reais += caminhos[i - 1][cx].reais + melhor_movimento.p;
		}
	}

	caminho melhor_caminho = caminhos[n - 1][0];
	int j_melhor = 0;
	for (int j = 1; j < n; j++) {		
		if (caminhos[n - 1][j].reais > melhor_caminho.reais) {
			j_melhor = j;
			melhor_caminho = caminhos[n - 1][j];
		}
	}

	int* colunas = (int*) malloc(sizeof(int) * n);
	colunas[n - 1] = j_melhor;
	for (int j = n - 2; j >= 0; j--) {
		colunas[j] = melhor_caminho.cx;
		if (j > 0) {
			melhor_caminho = caminhos[j][melhor_caminho.cx];
		}
	}

	printf("%d\n", caminhos[n - 1][j_melhor].reais);
	printf("%d", colunas[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", colunas[i]);
	}
	printf("\n");
}
