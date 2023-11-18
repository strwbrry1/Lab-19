#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

void load();
void saveRes();

int n;
int* pa;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	load();
	saveRes();

	free(pa);
}

void load() {
	FILE* fin = fopen("in2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);

	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void saveRes() {
	float res;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pa[i];
	}
	res = sum / n;
	
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] > res) {
			m++;
		}
	}

	FILE* fout = fopen("out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден");
		return;
	}
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] > res) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
}

