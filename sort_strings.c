#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// THE CODE INCOMPLETE!!!
void sort(char**, int, int (*cmp_func)(char*, char*));

int sort_strings(char*, char*);

int main(void)
{
	int n;
	printf("enter the number of strings: ");
	scanf("%d", &n);

	char *string[n];

	int i=0;

	for(; i<n; i++)
		string[i]=(char*)malloc(1024*sizeof(char));

	printf("\n\nenter the strings.....\n\n");

	for(i=0; i<n; i++)
		scanf("%s", string[i]);

	sort(string, n, sort_strings);

	printf("\n\nthese are your sorted strings.....\n\n");

	for(i=0; i<n; i++)
		printf("%s\n", string[i]);

	for(i=0; i<n; i++)
		free(string[i]);

	return 0;

}

void sort(char **string, int n, int (*cmp_func)(char*a, char*b))
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			(*cmp_func)(string[j],string[j+1]);
		}
	}
}


int 