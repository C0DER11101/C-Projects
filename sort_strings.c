#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(char**, int, int (*cmp_func)(char*, char*));

int sort_str(char*, char*);

int main(void)
{
	int n;

	printf("enter the number of strings: ");
	scanf("%d", &n);

	getchar();

	char *string[n];

	printf("\n\nenter strings:\n\n");

	for(int i=0; i<n; i++)
		string[i]=(char*)malloc(1024*sizeof(char));

	for(int i=0; i<n; i++)
		scanf("%s", string[i]);


	sort(string, n, sort_str);

	printf("\n\nthese are your sorted strings....\n\n");

	for(int i=0; i<n; i++)
		printf("%s\n", string[i]);


	for(int i=0; i<n; i++)
		free(string[i]);


	return 0;


}



void sort(char** string, int n, int (*cmp_func)(char*a, char*b))
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
			(*cmp_func)(string[j], string[j+1]);
	}
}


int sort_str(char*a, char*b)
{
	char *t;
	int l1, l2;
	t=(char*)malloc(1024*sizeof(char));
	if(strcmp(a, b)>0)
	{
		strcpy(t, a);
		strcpy(a, b);
		strcpy(b, t);
	}


	free(t);

	return 0;
}