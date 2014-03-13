#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int LUT[38] = { 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4 };
	int Count = 0, dir = 0;
	int i, j, z, chisla_dir = 0;
	int total_dirs;
	int Posoka = 0;
	int *arr = NULL;
	char *arr_posoka = NULL;
	int chislo = 1;
	int check_digits = 0;
	int pos = 0;
	int broi_cifri_v_kolona;
	int current_arr_pos = 0;
	int NumDigits_biggestPossible_number = 16;
	printf("Enter Some number(bigger than 1): \n");
	scanf("%d", &Count);
	
	/*  FUTURE WORK
	fflush(stdin);
	printf("vyvedi posoka(0 ili 1): \n");
	scanf("%d", &Posoka);

	arr_posoka = (char*)calloc(Count*Count, sizeof(char));
	if (arr_posoka == NULL) { printf("cannot allocate memory");  return 0; }

	printf("Izbranata posoka e: \n");
	if (Posoka == 0)
	{
		for (i = 0; i < Count; i++)
		{
			//printf the direction with arrows
		}
	}
	else
	{
		for (i = 0; i < Count; i++)
		{
			//printf the direction with arrows
		}
	}
	*/
	arr = (int*)calloc(Count*Count, sizeof(int));
	if (arr == NULL) { printf("cannot allocate memory");  return 0; }

	total_dirs = 2 * Count - 1;
	broi_cifri_v_kolona = LUT[Count];

	dir = 0;
	chisla_dir = Count;
	for (i = 0; i < total_dirs; i++)
	{
		for (j = 0; j < chisla_dir; j++)
		{
			if (dir == 0)
			{
				arr[current_arr_pos++] = chislo++;
				if(j == chisla_dir - 1) current_arr_pos = current_arr_pos - 1;
			}
			if (dir == 1)
			{
				current_arr_pos = current_arr_pos + Count;
				arr[current_arr_pos] = chislo++;
			}
			
			if (dir == 2)
			{
				current_arr_pos = current_arr_pos - 1;
				arr[current_arr_pos] = chislo++;

			}
			
			if (dir == 3)
			{
				current_arr_pos = current_arr_pos - Count;
				arr[current_arr_pos] = chislo++;
			}
			
		}
		if (dir == 3) 
		{
			dir = 0; 
			current_arr_pos++;
		}
		else dir++;
		if (i % 2 == 0) chisla_dir--;
	}
	
	printf("\nA square with size: %d\n\n", Count);
	for (i = 0; i < Count; i++)
	{
		for (j = 0; j < Count; j++)
		{
			check_digits = arr[i*Count + j];
			for (z = 0; z < NumDigits_biggestPossible_number; z++)
			{
				check_digits /= 10;
				if (check_digits == 0) break;
			}
			for (; z < broi_cifri_v_kolona; z++ )
			{
				printf(" ");
			}
			printf("%d ", arr[i*Count+j]);
		}
		printf("\n");
	}
	_getch();

	return 0;
}
