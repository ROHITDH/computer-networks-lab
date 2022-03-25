#include <stdio.h>
#include <string.h>

#define N strlen(g)

char ts[28],cs[28];
char g[]="1101100000000000";
int a,i,j;

void xor()
{
    for(j=1;j<N;j++)
        cs[j] = (cs[j] == g[j])?'0':'1';
}
void crc()
{
    for(i=0;i<N;i++)
        cs[i] = ts[i];
    do
    {
        if(cs[0] == '1')
            xor();
        for(j=0;j<N-1;j++)
            cs[j] = cs[j+1];
        cs[j] = ts[i++];
    }
    while(i<=a+N-1);
}

int main()
{
    printf("Enter the Data: ");
    scanf("%s",ts);

    printf("Generating polynomial is: %s\n",g);
    a = strlen(ts);
    for(i=a;i<a+N-1;i++)
        ts[i] = '0';
    printf("Modified Data: %s\n",ts);

    crc();
    printf("CheckSum: %s\n",cs);

    for(i=a;i<a+N-1;i++)
        ts[i] = cs[i-a];
    printf("Final CodeWord: %s\n",ts);

    printf("Enter Received code: ");
    scanf("%s",ts);
    crc();
    for(i=0;(i<N-1)&&(cs[i]!='1');i++);
    if(i<N-1)
        printf("Error Detected\n");
    else
        printf("No Error Detected\n");

    return 0;

}
