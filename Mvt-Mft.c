#include<stdio.h>
#include<stdbool.h>
int main(){
int
i,j,in_frag=0,ex_frag=0,block[10],p[10],flag_block[10],n_p,n_blocks,
count=0;
printf("Enter the number of blocks : ");
scanf(" %d",&n_blocks);
for(i = 0;i<n_blocks;i++){
printf("size of block[%d] : ",i);
scanf(" %d",&block[i]);
flag_block[i] = 0;
}
printf("Enter the number of processes : ");
scanf(" %d",&n_p);
for(i = 0;i<n_p;i++){
printf("size of process[%d] : ",i);
scanf(" %d",&p[i]);
}
for(i = 0 ; i< n_p;i ++){
for(j = 0 ; j < n_blocks;j++){ 
if(p[i] <= block[j] && flag_block[j] == 0){
in_frag += (block[j]-p[i]);
flag_block[j] = 1;
count++;
break;
}
}
}
if(count < n_p){
for(i = 0; i < n_blocks;i++){
if(flag_block[i] == 0){
for(j = 0 ;j < n_p;j++){
if(flag_block[i] < p[j]){
ex_frag += block[i];
break;
}
}
} 
}
}
printf("Internal fragmentation is : %d\n",in_frag);
printf("External fragmentation is : %d",ex_frag);
printf("\n");
return 0;
}
