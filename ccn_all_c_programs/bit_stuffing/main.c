#include <stdio.h>
#include <stdlib.h>

// 0111 1110

int main()
{
    int n,i,j,k,count;
    int a[30],b[30];

    printf("Enter Frame Lemgth: ");
    scanf("%d",&n);

    printf("Enter input Frame: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    count = 1;
    j = 0;
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            b[j] = a[i];
            for(k=i+1; k<n && a[k]==1 && count<5;k++)
            {
                j++;
                b[j] = a[k];
                count++;
                if(count==5)
                {
                    j++;
                    b[j] = 0;
                }
                i=k;
            }
        }
        else
            b[j] = a[i];
        j++;
        count = 1;
    }

    printf("After Stuffing: \n");
    printf("01111110");
    for(i=0;i<j;i++)
        printf("%d",b[i]);
    printf("01111110");
    return 0;
}
