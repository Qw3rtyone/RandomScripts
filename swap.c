#include <stdio.h>
#include <string.h>

void xor_swap(char * str)
{
	char * start = str;
	char * end = str + strlen(str) -1;
	
	
	while(start < end)
	{
		
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		
		start++;
		end--;
	}
	
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		int i = 1;
		char *input = NULL;
		while(i < argc)
		{
			input = argv[i];

			xor_swap(input);
			
			printf("%s\n",input);
			i++;

		}
	}
	else
	{
		char str1[] = "Hellllllllllooooooooooo!!!!!!";
		char str2[] = "Run Run Run RUNR UNRURN URNUN";
		char str3[] = "The world is a jolly big thing";
		char str4[] = "123456789";
		char str5[] = "Run with an input!!!tupni na htiw nuR";
		
		xor_swap(str1);	
		xor_swap(str2);	
		xor_swap(str3);	
		xor_swap(str4);
		xor_swap(str5);
		
		printf("%s\n",str1);
		printf("%s\n",str2);
		printf("%s\n",str3);
		printf("%s\n",str4);
		printf("%s\n",str5);
	}
	return 0;
}

