#include<stdio.h>
#include<stdlib.h>
void look(int queue[], int queueSize,int header){
int cycleMov=0,previous,next;
for(int i = 0; i < queueSize-1;i++){
for(int j = i+1;j < queueSize;j++){
if(queue[i]>queue[j]){
int temp = queue[i];
queue[i] = queue[j];
queue[j] = temp;
}
}
}
//find the index of smaller and greater values than header
int i = 0;
while(queue[i]<header){
i++;
}
previous = i-1;
next = i;
if(abs(header-0) < abs(header - 199)){
//traverse left most end
while(previous >=0){
cycleMov+= abs(header-queue[previous]);
header = queue[previous];
previous--;
} 
//traverse right side
while(next < queueSize){
cycleMov+= abs(header-queue[next]);
header = queue[next];
next++;
}
}
else{
//traverse right end
while(next < queueSize){
cycleMov+= abs(header-queue[next]);
header = queue[next];
next++;
}
//traverse left end
while(previous >=0){
cycleMov+= abs(header-queue[previous]);
header = queue[previous];
previous--;
} 
}
printf("The total cycle movements: %d\n",cycleMov);
} 
int main(){
int queue[20], header, queueSize; 
printf("Enter the queue size : ");
scanf("%d",&queueSize); 
printf("Enter the elements in queue : \n");
for(int i = 0; i < queueSize;i++){
scanf("%d", &queue[i]);
}
printf("Enter the header : ");
scanf("%d", &header); 
look(queue, queueSize, header);
return 0;
}
