#include<stdio.h>
#include<stdlib.h>
void fcfs(int queue[],int queueSize,int header){
int cycleMov=0;
for(int i = 0;i < queueSize;i++){
cycleMov += abs(header-queue[i]);
header = queue[i];
}
printf("The total cycle movements : %d\n",cycleMov);
}
int main(){
int queue[20],header,queueSize;
printf("Enter the queue size : ");
scanf(" %d",&queueSize);
printf("Enter the elements in queue :\n");
for(int i = 0; i < queueSize;i++){
scanf(" %d",&queue[i]);
}
printf("Enter the header : ");
scanf(" %d",&header);
fcfs(queue,queueSize,header);
}
