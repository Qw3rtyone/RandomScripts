#include <stdio.h>
#include <stdlib.h>

int * sort(int* numbers, int arr_size)
{
	int i,j,initial = 0, current = 0, tmp = 0;

	for(i = 0; i <= arr_size; i++)
	{
		initial = numbers[i];
		printf("\nloop %d \n", i);
		for(j = 0; j <= arr_size; j++)
		{
			current = numbers[j];
			printf("current = %d and initial = %d\n", current, initial);
			if((i > j) && (initial < current))					//left side
			{
				printf("swap %d < %d\n", initial, current);
				
				numbers[i] = current;
				
				tmp = numbers[j];
				numbers[j] = initial;
				
				initial = tmp;
			}
			else if((i < j) && (initial > current))				//right side
			{
				printf("swap %d > %d\n", initial, current);
				numbers[i] = current;
				
				tmp = numbers[j];
				numbers[j] = initial;
				
				initial = tmp;		
			}
			else
			{
				printf("no swap %d and %d\n", initial, current);
			}
		}
		
	}
	
	printf("\n  \n");
	
	return numbers;
}

void main(int argc, char *argv[])
{
	int size = argc -1;
	int arr_size = size -1;
	int *numbers = NULL;
	int i,j;
	
	numbers = malloc(sizeof(int)* size);
	
	for(i = 0; i < size; i++)
	{
		numbers[i] = atoi(argv[i+1]);
	}
	
	sort(numbers, arr_size);
	
	for(i = 0; i < size; i++)
		printf("%d ",numbers[i]);
	
	free(numbers);	
}
