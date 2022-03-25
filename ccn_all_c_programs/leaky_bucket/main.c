#include <stdio.h>

//Define the constants
#define bucket_size 1000
#define n 5

void leaky_bucket_output(int *bucket, int op_rate)
{
    if(*bucket>0 && *bucket>op_rate)
    {
        *bucket = *bucket - op_rate;
        printf("%d outputted from the bucket\n",op_rate);
        printf("%d is remaining in bucket\n",*bucket);
    }
    else if(*bucket>0)
    {
        printf("All remaining data outputted from bucket\n",*bucket);
        *bucket = 0;
    }
}

int main()
{
    int op_rate;
    int newpack,oldpack=0;
    int bucket=0;
    int wt;
    int i,j;

    printf("Enter the data rate: ");
    scanf("%d",&op_rate);

    for(i=1;i<=n;i++)
    {
        newpack = rand()%5000;
        printf("New packet size: %d\n",newpack);

        if(newpack+oldpack<bucket_size)
            bucket = newpack+oldpack;
        else
        {
            printf("%d = Sum of New pack and Old Pack is Greater than Bucket Size, So discarding..\n", newpack+oldpack);
            bucket = oldpack;
        }

        printf("Data in bucket: %d\n",bucket);
        wt = rand()%5;
        printf("The next packet will arrive at %d sec\n", wt);
        for(j=0;j<wt;j++)
        {
            leaky_bucket_output(&bucket,op_rate);
            sleep(1);
        }
        oldpack = bucket;
    }

    while(bucket>0)
        leaky_bucket_output(&bucket,op_rate);

    return 0;
}

