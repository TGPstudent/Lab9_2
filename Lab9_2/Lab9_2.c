/*lab9_2.c Обрахунок добутку елементів масиву з парними номерами та суми елементів масиву, 
           розташованих до максимального за модулем елемента за допомогою функцій та застосовуючи посилання*/
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

void  Input_Gener_Arr(int N, int *a);
void Out_Arr(int N, int *a);
long Dob_Arr(int N, int *a);
int Sum_max_abs(int N, int *a);

int N;
int main(void)
{
	setlocale(LC_CTYPE, "ukr");
	
	printf("\n Введiть кiлькiсть елементiв в масивi N="); scanf_s("%d", &N);
	int *a = (int*)malloc(sizeof(int)*N);
	system("cls");
	Input_Gener_Arr(N, a);
	Out_Arr(N, a);
	printf("\n Добуток елементiв з парники коєфiцiєнтами рiвний: %ld;", Dob_Arr(N, a));
	printf("\n Сума елементiв до максимального за модулем елементу: %ld.", Sum_max_abs(N, a));

	int getch(); getch();
	free(a);
	return 0;
}

//Функція - генератор масиву розміром N випадковими числами від Low до High
void Input_Gener_Arr(int N, int *a)
{
	const int Low = -100, High = 100;
	srand((unsigned)time(0));
	for (int i=0; i < N; i++)
		*(a+i) = Low + rand() % (High - Low + 1);
}

//Функція виведення одномірного масиву на екран розміром N
void Out_Arr(int N, int *a)
{
	printf("\n Згенерований вектор;\n A[1,%d] = {", N);
	int *Last = a + (N-1);
	for (a; a <= Last; a++)
		printf("%d, ", *a);
	printf("\b\b}");
}

//Функція обрахунок добутку елементів масиву з парними номерами
long Dob_Arr(int N, int *a)
{
	int D = 1;
	int *Last = a + (N-1);
	printf("\n\n 1) Вектор елементiв з парними коефiцiєнтами: \n B[1,%d] = {", N/2);
	for (a=a+1; a <= Last; a += 2)
	{
		printf("%d, ", *a);
		D = D * (*a);
	}
	printf("\b\b}");
	return D;
}

//Функція суми елементів масиву, розташованих до максимального за модулем елемента
int Sum_max_abs(int N, int *a)
{
	int *Ind = NULL, k=0;
	int Max = abs(*a), S = 0;
	int *Last = a + (N-1);
	for (a; a <= Last; a++)
	{
		if (Max < abs(*a)) 
		{
			Max = abs(*a); Ind = a; k++;
		}
	}
	printf("\n\n 2) Mаксимальний за модулем елемент масиву Max =%d", Max); 
	if (k == 0) printf("\n\n Mаксимальний за модулем елемент масиву знаходиться на першiй позицiї");
	else {
		printf("\n Вектор елементiв до максимального за модулем елемента \n C[1,%d] = {", k);
		for ((a = a - N); a < Ind; a++)
		{
			S = S + *a;
			printf("%d, ", *a);
		}
		printf("\b\b}");
		}
	return S;
}
