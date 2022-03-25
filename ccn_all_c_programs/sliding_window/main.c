#include <stdio.h>
#include <stdlib.h>

#define RTT 5

int main()
{
    int win_size,f,frames[20];
    int i;

    printf("Enter window size: ");
    scanf("%d",&win_size);

    printf("Enter No. of Frames to Transmit: ");
    scanf("%d",&f);

    printf("Enter the %d Frames: ",f);
    for(i=1;i<=f;i++)
        scanf("%d",&frames[i]);

    printf("After Sending %d Frames at each stage, Sender waits for ACK\n",win_size);
    printf("Sending frames in followig manner: \n");

    for(i=1;i<=f;i++)
    {
        if(i%win_size !=0) // Send frames equal to one window size, So, i%win_size becomes 0 when i=win_size.
            printf("%d\t",frames[i]);
        else
        {
            printf("%d\t\n",frames[i]);

            printf("SENDER: Waiting For ACK..\n");
            sleep(RTT/2);
            printf("RECEIVER: Frames Received..ACK Sent..\n");
            sleep(RTT/2);
            printf("SENDER: ACK Received..Sending Next Frames..\n");
        }
    }

    if(f%win_size!=0)
    {
        printf("\nSENDER: Waiting For ACK..\n");
        sleep(RTT/2);
        printf("RECEIVER: Frames Received..ACK Sent..\n");
        sleep(RTT/2);
        printf("SENDER: ACK Received..\n");
    }
    return 0;
}
