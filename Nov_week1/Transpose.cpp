#include <stdio.h>


void enterData(int A[][10], int B[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond);
void multiplyMatrices(int A[][10], int B[][10], int multResult[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond);
void display(int mult[][10], int rowFirst, int columnSecond);

int main()
{
	int A[10][10], B[10][10], mult[10][10], rowFirst, columnFirst, rowSecond, columnSecond, i, j, k;

	printf("Enter rows and column for first matrix: ");
	scanf_s("%d %d", &rowFirst, &columnFirst);

	printf("Enter rows and column for second matrix: ");
	scanf_s("%d %d", &rowSecond, &columnSecond);

	while (columnFirst != rowSecond)
	{
		printf("Error! column of first matrix not equal to row of second.\n");
		printf("Enter rows and column for first matrix: ");
		scanf_s("%d%d", &rowFirst, &columnFirst);
		printf("Enter rows and column for second matrix: ");
		scanf_s("%d%d", &rowSecond, &columnSecond);
	}


	enterData(A, B, rowFirst, columnFirst, rowSecond, columnSecond);

	multiplyMatrices(A, B, mult, rowFirst, columnFirst, rowSecond, columnSecond);


	display(mult, rowFirst, columnSecond);

	return 0;
}

void enterData(int firstMatrix[][10], int secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
	int i, j;
	printf("\nEnter elements of matrix 1:\n");
	for (i = 0; i < rowFirst; ++i)
	{
		for (j = 0; j < columnFirst; ++j)
		{
			printf("Enter elements a%d%d: ", i + 1, j + 1);
			scanf_s("%d", &firstMatrix[i][j]);
		}
	}

	printf("\nEnter elements of matrix 2:\n");
	for (i = 0; i < rowSecond; ++i)
	{
		for (j = 0; j < columnSecond; ++j)
		{
			printf("Enter elements b%d%d: ", i + 1, j + 1);
			scanf_s("%d", &secondMatrix[i][j]);
		}
	}
}

void multiplyMatrices(int A[][10], int B[][10], int mult[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
	int i, j, k;

	
	for (i = 0; i < rowFirst; ++i)
	{
		for (j = 0; j < columnSecond; ++j)
		{
			mult[i][j] = 0;
		}
	}

	
	for (i = 0; i < rowFirst; ++i)
	{
		for (j = 0; j < columnSecond; ++j)
		{
			for (k = 0; k < columnFirst; ++k)
			{
				mult[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void display(int mult[][10], int rowFirst, int columnSecond)
{
	int i, j;
	printf("\nOutput Matrix:\n");
	for (i = 0; i < rowFirst; ++i)
	{
		for (j = 0; j < columnSecond; ++j)
		{
			printf("%d  ", mult[i][j]);
			if (j == columnSecond - 1)
				printf("\n\n");
		}
	}
}