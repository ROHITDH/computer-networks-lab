#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[200],b[200];
    int i,j,n;

    printf("Enter the String: ");
    scanf("%s",a);
    n = strlen(a);

    b[0] = 'd';
    b[1] = 'l';
    b[2] = 'e';
    b[3] = 's';
    b[4] = 't';
    b[5] = 'x';

    j = 6;
    for(i=0;i<n;i++)
    {
        if(a[i]=='d' && a[i+1]=='l' && a[i+2]=='e')
        {
            b[j]='d';
            b[j+1]='l';
            b[j+2]='e';
            j = j + 3;
        }
        b[j]=a[i];
        j++;
    }

    b[j] = 'd';
    b[j+1] = 'l';
    b[j+2] = 'e';
    b[j+3] = 'e';
    b[j+4] = 't';
    b[j+5] = 'x';
    b[j+6] = '\0';
    printf("Frame After Stuffing: %s",b);

    return 0;
}
