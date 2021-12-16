#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// program to sort strings based on distinct number of characters!!!

// HERE ARE THE CREDITS: THANK YOU GEEKS FOR GEEKS
//   https://www.geeksforgeeks.org/sort-an-array-of-strings-based-on-count-of-distinct-characters/

// this program is case-sensitive, enter strings only in lowercase

void sort(char**, int, int (*cmp_func)(char*, char*));

int sort_distinct(char*, char*);


int main(void)
{
	int n;

	printf("enter the number of strings: ");
	scanf("%d", &n);

	getchar();

	char *string[n];

	printf("\n\nenter the strings>>>>\n\n");

	for(int i=0; i<n; i++)
		string[i]=(char*)malloc(1024*sizeof(char));

	for(int i=0; i<n; i++)
		scanf("%s", string[i]);

	sort(string, n, sort_distinct);

	printf("\n\n>>>\n\n");

	for(int i=0; i<n; i++)
		printf("%s ", string[i]);


	for(int i=0; i<n; i++)
		free(string[i]);

	printf("\n\n\n");


	return 0;
}


void sort(char** string, int n, int(*cmp_func)(char*a, char*b))
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
			(*cmp_func)(string[j], string[j+1]);
	}


}

int sort_distinct(char*a, char*b)
{
	int l1, l2, dnt_a=0, dnt_b=0, index=0;
	char t[]="abcdefghijklmnopqrstuvwxyz", *temp;

	temp=(char*)malloc(1024*sizeof(char));

	l1=strlen(a);
	l2=strlen(b);

	// counting the number of distinct characters in the strings:::::::
	for(int i=0; a[i]!='\0'; i++)
	{
		for(int j=0; t[j]!='\0'; j++)
		{
			if(a[i]==t[j])
			{
				index=j;
				while(t[index]!='\0')
				{
					t[index]=t[index+1];
					index++;
				}


				dnt_a++;
				break;

			}
		}
	}

	strcpy(t, "abcdefghijklmnopqrstuvwxyz");

	for(int i=0; b[i]!='\0'; i++)
	{
		for(int j=0; t[j]!='\0'; j++)
		{
			if(b[i]==t[j])
			{
				index=j;
				while(t[index]!='\0')
				{
					t[index]=t[index+1];
					index++;
				}

				dnt_b++;
				break;

			}
		}
	}

	/* 1) if two words have equal number of distinct characters then the word with larger length comes first
	   
	   2) if two words have equal number of distinct characters and same length then the word that comes before
	   the other in the sentence comes first
	   
	   3) if the number of distinct characters and length of two words are not equal, then the word with lower length comes first

	   4) if two words have same length but different number of distinct characters then the word with less number of distinct
	   characters comes first
	*/

	if(dnt_a==dnt_b && l1<l2)  // 1)
	{
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
	}

	else if(dnt_a==dnt_b && l1==l2)  // 2)
	{
		;
	}

	else if(((dnt_a>dnt_b) || (dnt_a<dnt_b)) && l1>l2)  // 3)
	{
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
	}

	else if(dnt_a>dnt_b && l1==l2)   //4)
	{
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
	}


	free(temp);



	return 0;


}