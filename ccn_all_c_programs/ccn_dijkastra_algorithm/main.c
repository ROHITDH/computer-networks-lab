#include <stdio.h>

//Define Constants
#define INF 99
#define MAX 10
#define startnode 0

//Function initialization
void dijkstra(int costmat[MAX][MAX],int n);


//main
int main()
{
    int nodes,i,j;
    int costmat[MAX][MAX];

    //Read total no. of nodes
    printf("Enter no. of nodes: ");
    scanf("%d",&nodes);

    //Read cost matrix
    printf("Enter the cost matrix: \n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf("Distance from %d to %d : ",i+1,j+1);
            scanf("%d",&costmat[i][j]);
        }
    printf("\n");
    }

    //Call Function
    dijkstra(costmat,nodes);

    return 0;
}


void dijkstra(int costmat[MAX][MAX],int n)
{
    //Initialization -- DVR - DVP
    int distance[MAX],visited[MAX],pred[MAX];
    //Initialization of 5 variables -- mn
    int i,j,count,mindistance,nextnode;


    //initial assign
    for(i=0;i<n;i++)
    {
        distance[i] = costmat[startnode][i]; //Get the distance from cost matrix. It's the distance from Start node to Other node
        visited[i] = 0; // Do we visited any nodes? No.. So it's zero
        pred[i] = startnode; // Where we started the prediction? It's from startnode.
    }


    //Now we are at the startnode. So again conside DVP
    distance[startnode] = 0; //distance from startnode to startnode = 0
    visited[startnode] = 1; //yes we visited the startnode just now..
    pred[startnode] = startnode; // Where we started the prediction? It's from startnode. Actually it's not needed..


    //Now we have to start to visit other nodes. So we need a counter.Remember we already visited start node. so count = 1
    count = 1;
    //Ya..lets start visiting remaining n-1 nodes
    while(count<n-1)
    {
        //Why we are visiting? To find min distance. So Initially we don't know the min distance. So, we assign it to INF
        mindistance = INF;
        //visiting all nodes
        for(i=0;i<n;i++)
        {
            //Try to find min distance., dont stuck by visiting same node again and again.. !!
            if(distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i; //mindistance and next node are always friends, so mn..
            }
        }

        //We completed visiting all nodes from startnode. Now go to other node.
        visited[nextnode] = 1;
        for(i=0;i<n;i++)
        {
            //Try to find less distance than INF, dont stuck by visiting same node again and again.. !!
            //change sign from less than to greater than
            if(distance[i] > mindistance + costmat[nextnode][i]  && !visited[i])
            {
                distance[i] = mindistance + costmat[nextnode][i];
                pred[i] = nextnode;
            }
        }
        count++;
    }

    //Print
    for(i=0;i<n;i++)
    {
        if(i!=startnode)
        {
            printf("\nDistance to node %d is %d\n",i,distance[i]);
            printf("\nPath: %d",i);
            j = i; // Dont forget this! Else you stuck in inf loop like me before..
            do{
                j = pred[j];
                printf("->%d",j);
            }while(j!=startnode);
        }
    }
}
