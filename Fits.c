#include<stdio.h>
void swap(int a[],int pass ,int i){
int temp = a[pass];
a[pass] = a[i];
a[i] = temp;
}
void cal_int_frag(int block[],int p[],int flag_block[],int n,int
n_b){
int int_frag=0,count=0,ex_frag=0,i,j;
for(int i = 0; i < n;i ++){
for(int j = 0;j < n_b;j++){
if(p[i] <= block[j] && flag_block[j] == 0){
int_frag += block[j] - p[i];
flag_block[j] = 1;
count++;
break;
}
}
}
if(count < n){
for(i = 0; i < n_b;i++){
if(flag_block[i] == 0){
for(j = 0 ;j < n;j++){
if(flag_block[i] < p[j]){
ex_frag += block[i];
break;
}
}
} 
}
}
printf("Internal fragmentation is : %d\n",int_frag);
printf("external fragmentation is : %d\n",ex_frag);
}
void best_fit(int block[],int p[],int n_b,int n,int flag_block[]){
int i,j;
for(i = 0;i < n_b;i++)
flag_block[i] = 0;
for(int pass = 0;pass < n_b-1;pass ++){
for(i = pass+1;i < n_b;i++){
if(block[pass] > block[i]){
swap(block,pass,i);//swap blocks
}
}
}
cal_int_frag(block,p,flag_block,n,n_b);
}
void first_fit(int block[],int p[],int n_b,int n,int flag_block[]){
int i,j;
for(i = 0;i < n_b;i++)
flag_block[i] = 0;
cal_int_frag(block,p,flag_block,n,n_b);
return;
}
void worst_fit(int block[],int p[],int n_b,int n,int flag_block[]){
int i,j;
for( i = 0;i < n_b;i++)
flag_block[i] = 0;
for(int pass = 0;pass < n_b-1;pass ++){
for( i = pass+1;i < n_b;i++){
if(block[pass] < block[i]){
swap(block,pass,i);//swap blocks
}
}
}
cal_int_frag(block,p,flag_block,n,n_b);
return;
}
int main(){
int n,n_blocks,block[10],p[10],flag_block[10],temp_block[10];
int i,choice;
change:
printf("Enter the number of blocks : ");
scanf(" %d",&n_blocks);
for(i = 0;i<n_blocks;i++){
printf("size of block[%d] : ",i);
scanf(" %d",&block[i]);
temp_block[i] = block[i];
}
printf("Enter the number of processes : ");
scanf(" %d",&n);
for(i = 0;i<n;i++){
printf("size of process[%d] : ",i);
scanf(" %d",&p[i]);
}
do{
printf("\n1.BEST FIT\n2.FIRST FIT\n3.WORST FIT\n4.ENTER NEW 
VALUES\n5.EXIT\nEnter your choice :");
scanf(" %d",&choice);
switch(choice){
case 1:best_fit(block,p,n_blocks,n,flag_block);
break;
case 2: first_fit(temp_block,p,n_blocks,n,flag_block);
break;
case 3: worst_fit(block,p,n_blocks,n,flag_block);
break;
case 4: goto change;//can use a function instead
case 5: printf("choosed to exit\n");
return 0;
default : printf("invalid choice");
}
}while(1);
printf("\n");
return 0;
