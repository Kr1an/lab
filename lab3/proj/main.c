#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

#define TRUE 1
#define FALSE 0
#define nil 0x0
static const int EXIT_TRUE = 0;
/*@unused@*/ static const int EXIT_FALSE = -1;
static const int INPUT_EXIT = -2;
static const int _NULL = 0;
static int SIZE_COLMS = 0;
static int SIZE_RAWS = 0;

static void inputClose()
{
	while ((char)getchar() != '\n') {
	}
	return;
}

static void inputError()
{
	printf("\nError: press key to exit...");
	inputClose();
	(void)getchar();
	printf("\n");
	exit(INPUT_EXIT);
}

static int intcmp(const void *num1, const void *num2)
{
	return (*((int *)num1) - (*((int *)num2)));
}

static int colCmp(const int *col_1, const int *col_2, const int length)
{
	int i = _NULL;
	for (i = _NULL; i < length; i++) {
		if (col_1[i] != col_2[i])
			return FALSE;
	}
	return TRUE;
}

static void sortFunc(int **a, int raw, int colm)
{
	int empty = TRUE;
	int i = _NULL, j = _NULL;
	int **temp;
	if ((temp = (int **)malloc(sizeof(int *) * colm)) == nil)
		inputError();
	for (i = _NULL; i < colm; i++)
		if ((temp[i] = (int *)malloc(sizeof(int) * raw)) == nil)
			inputError();
	for (i = _NULL; i < colm; i++)
		for (j = _NULL; j < raw; j++)
			temp[i][j] = a[j][i];
	for (i = _NULL; i < colm; i++)
		qsort(temp[i], (size_t) raw, sizeof(int), intcmp);
	for (i = _NULL; i < raw; i++)
		for (j = _NULL; j < colm; j++)
			a[i][j] = temp[j][i];
	printf("\tEqual coloms:\n");
	for (i = _NULL; i < colm - TRUE; i++)
		for (j = i + TRUE; j < colm; j++)
			if (colCmp(temp[i], temp[j], raw) == TRUE) {
				printf("colomn '%d' is equal to colomn '%d'\n",
				       i + TRUE, j + TRUE);
				empty = _NULL;
			}
	if (empty == TRUE)
		printf("None\n");
	for (i = _NULL; i < colm; i++)
		free(temp[i]);
	free(temp);
	return;
}

int main(void)
{
	int **mass;
	int i = _NULL, j = _NULL;
	printf("\t\tLaboratory 3: comparing array coloms\n");
	printf("Enter the number of raws: ");

	if (scanf("%d", &SIZE_RAWS) == _NULL || SIZE_RAWS <= _NULL) {
		inputError();
	}
	inputClose();
	printf("Enter the number of coloms: ");
	if (scanf("%d", &SIZE_COLMS) == _NULL || SIZE_COLMS <= _NULL) {
		inputError();
	}
	if ((mass = (int **)malloc(sizeof(int *) * SIZE_RAWS)) == nil)
		inputError();
	for (i = _NULL; i < SIZE_RAWS; i++)
		if ((mass[i] = (int *)malloc(sizeof(int) * SIZE_COLMS)) == nil)
			inputError();
	inputClose();
	printf("\t Enter mass:\n");
	for (i = _NULL; i < SIZE_RAWS; i++)
		for (j = _NULL; j < SIZE_COLMS; j++)
			if (scanf("%d", &mass[i][j]) == _NULL)
				inputError();
	sortFunc(mass, SIZE_RAWS, SIZE_COLMS);
	for (i = _NULL; i < SIZE_RAWS; i++)
		free(mass[i]);
	free(mass);
	return EXIT_TRUE;
}
