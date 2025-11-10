//Circular Queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cq[MAX],rear=-1,front=-1,count=0;
void enqueue(int val){
    if(front==0&&rear==MAX-1||rear==front-1){
        printf("Queue Full!\n");
        return;
    }
    if(front==-1){
        front=rear=0;
    }else if(rear==MAX-1)
        rear=0;
    else{
        rear+=1;
    }
    cq[rear]=val;
    count++;
}
void dequeue(){
    if(front==-1){
        printf("Queue Empty!\n");
        return;
    }
    int val=cq[front];
    if(front==rear)
        front=rear=-1;
    else
        front+=1;
    printf("%d deleted\n",val);
    count--;
}
void display(){
    if(rear==-1){
        printf("Queue Empty!\n");
        return;
    }
    printf("Elements:");
    if(front<=rear){
        for(int i=front;i<=rear;i++)
        printf("%d  ",cq[i]);
    }else{
        for(int i=0;i<=rear;i++)
        printf("%d  ",cq[i]);
        for(int i=front;i<MAX;i++)
        printf("%d  ",cq[i]);
        
    }
}
int main(){
    int val,ch;
    do{
        printf("\n-----Circular Queue-----\n1.Enqueue\n2.Dequeue\n3.Display\n4.Count\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter value:");
                   scanf("%d",&val);
                   enqueue(val);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:printf("Number of elements:%d",count);
                   break;
            case 5:
            default:printf("Invalid Choice!\n");
        }
    }while(ch!=5);
}
