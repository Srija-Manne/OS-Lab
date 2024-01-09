#include<stdio.h>
#include<stdlib.h>
int minDistance(int queue[],int queueSize,int header){
int distance = 999,i,index;
for(i = 0; i < queueSize;i++){
if(abs(header - queue[i]) < distance){
distance = abs(header - queue[i]);
index = i;
}
}
return index;
}
void sstf(int queue[],int queueSize,int header){
int cycleMov=0,value,index;
while(queueSize >0){
index = minDistance(queue,queueSize,header);
value = queue[index];
for(int i = index;i < queueSize;i++){
queue[i] = queue[i+1];
}
cycleMov += abs(header - value);
header = value;
queueSize--;
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
sstf(queue,queueSize,header);
}
