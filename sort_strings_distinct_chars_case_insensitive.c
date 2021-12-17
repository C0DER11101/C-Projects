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
    
    char *string[n];
    
    printf("enter the strings......\n\n");
    
    for(int i=0; i<n; i++)
        string[i]=(char*)malloc(1024*sizeof(char));
    
    for(int i=0; i<n; i++)
        scanf("%s", string[i]);
    
    sort(string, n, sort_str);
    
    printf("\n\n>>>>>\n\n");
    
    for(int i=0; i<n; i++)
        printf("%s ", string[i]);
    
    for(int i=0; i<n; i++)
        free(string[i]);
    
    printf("\n\n\n\n");
    
    return 0;
}

void sort(char** string, int n, int (*cmp_func)(char*, char*))
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
            (*cmp_func)(string[j], string[j+1]);
    }
    
}


int sort_str(char*a, char*b)
{
    char t[]="abcdefghijklmnopqrstuvwxyz", *temp;
    int dis_a=0, dis_b=0, index, l1, l2;  // dis_a -> number of distinct characters of string a and dis_b for string b
    
    l1=strlen(a);
    l2=strlen(b);
    temp=(char*)malloc(1024*sizeof(char));
    
    /*
     * if two strings have same number of distinct characters and have the same length
     * then the string that comes before the other string in the statement will come first
     * 
     * if two strings have equal number of distinct characters then the string with higher length comes first
     * 
     * if two strings have different number of distinct characters and different lengths then the string with lower length comes first
     * if two strings have different number of distinct characters and same lengths then the string with less number of distinct characters comes
     * first
     */
    
    // counting the number of distinct characters in both the strings, trying to make it case-insensitive
    
    for(int i=0; a[i]!='\0'; i++)
    {
        if((int)a[i]>=97 && (int)a[i]<=122)
        {
            for(int j=0; t[j]!='\0'; j++)
            {
                if((int)a[i]==(int)t[j])
                {
                    
                    index=j;
                    while(t[index]!='\0')
                    {
                        t[index]=t[index+1];
                        index++;
                    }
                    
                    dis_a++;
                    break;
                }
            }
        }
        
        else if((int)a[i]>=65 && (int)a[i]<=90)  // checking if the character is uppercase
        {
            
            for(int j=0; t[j]!='\0'; j++)
            {
                if(((int)a[i]+32)==(int)t[j]) // comparing after temporarily converting the uppercase character into lowercase
                {
                    
                    index=j;
                    while(t[index]!='\0')
                    {
                        t[index]=t[index+1];
                        index++;
                    }
                    
                    dis_a++;
                    break;
                }
            }
        }            
        
    }
    
    strcpy(t, "abcdefghijklmnopqrstuvwxyz");
    
    for(int i=0; b[i]!='\0'; i++)
    {
        if((int)b[i]>=97 && (int)b[i]<=122)
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
                    
                    dis_b++;
                    break;
                }
                
            }
        }
        
        else if((int)b[i]>=65 && (int)b[i]<=90)
        {
            for(int j=0; t[j]!='\0'; j++)
            {
                if(((int)b[i]+32)==(int)t[j])
                {
                    index=j;
                    while(t[index]!='\0')
                    {
                        t[index]=t[index+1];
                        index++;
                    }
                    
                    dis_b++;
                    break;
                }
            }
        }
        
    }
    
    //______END OF COUTING OF DISTINCT CHARACTERS________
    
    //______BEGINNING OF COMPARISION________
    
    if(dis_a == dis_b && l1<l2)
    {
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }
    
    else if(dis_a == dis_b && l1 == l2)
    {
        ;
    }
    
    else if(dis_a != dis_b && l1>l2)
    {
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }
    
    else if(dis_a > dis_b && l1==l2)
    {
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    }
    
    free(temp);
    
    return 0;
}
