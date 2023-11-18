#include<stdio.h>

int sent;
void reciever(int a);
void sender(int a);
void sender(int a)
{
    printf("Sending Frame : %d",a);
    sent=a;
    reciever(a);
}
void reciever(int a)
{
        printf("        Recieved Frame : %d\n",a);
        if(sent==a)
    printf("Acknowledgement : %d\n\n",a);
}
int main()
{
    int n,i;
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    printf("Sender has to send frames: ");
    for(i=1;i<=n;i++)
    printf("%d ",i);
    printf("\n\n    Sender                   Reciever\n\n");
    for(i=1;i<=n;i++)
    {
        sender(i);
    }
}