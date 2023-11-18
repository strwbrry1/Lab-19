#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

void load();
void saveRes();

int n;
int avg = 0;
int a[1000];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	load();
	saveRes();

}

void load() {
	FILE* fin = fopen("in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]);
	}
	fclose(fin);
}

void saveRes() {
	float res;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	res = sum / n;
	
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > res) {
			m++;
		}
	}

	FILE* fout = fopen("out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден");
		return;
	}
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (a[i] > res) {
			fprintf(fout, "%d ", a[i]);
		}
	}
}

