#include <stdio.h>
struct node{
    unsigned dist[20];
    unsigned from[20];
}rt[10];

int main()
{
int costmat[20][20];
int i,j,k,count=0,nodes;

printf("Enter no. of nodes: ");
scanf("%d",&nodes);
printf("Enter the cost matrix: \n");
for(i=0;i<nodes;i++)
    {
    for(j=0;j<nodes;j++)
        {
            printf("Distance from %d to %d : ",i+1,j+1);
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    printf("\n");
    }
printf("Distance Table: \n");
for(i=0;i<nodes;i++)
    {
        printf("\n\nFor router %d :", i+1);
        for(j=0;j<nodes;j++)
            printf("\n\tDistance from node %d is %d via %d",j+1,rt[i].dist[j],rt[i].from[j]+1);
    }

printf("\n\nFinding shortest distance: \n");

do
{
    count = 0;
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
            if(i!=j)
                for(k=0;k<nodes;k++)
                    if(rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = rt[i].from[k];
                        count++;
                    }
}while(count>0);

printf("\n\nRouting Table : \n");
for(i=0;i<nodes;i++)
    {
        printf("\n\nFor router %d :", i+1);
        for(j=0;j<nodes;j++)
            printf("\n\tDistance from node %d is %d via %d",j+1,rt[i].dist[j],rt[i].from[j]+1);
    }

return 0;
}
