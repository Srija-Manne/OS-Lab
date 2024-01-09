#include<stdio.h>
int main(void){
int n,i;
printf("Enter the number of processess : ");
scanf(" %d",&n);
float bt[n],wt[n],tat[n],sum_tat=0.0,sum_wt=0.0;
wt[0]=0;
tat[0]=0;
printf("Enter burst time : \n");
for(i = 0;i<n;i++)
{
printf("p[%d] : ",i+1);
scanf(" %f",&bt[i]); // read burst time
wt[i+1] =wt[i]+ bt[i];
tat[i]= bt[i]+wt[i];
sum_wt+=wt[i];
sum_tat+=tat[i];
}
printf("process\t\t\tburst time\t\twaiting time\t\tturn around 
time\t\n");
for(i = 0; i<n;i++){
printf("p[%d]\t\t\t%.f\t\t\t%.f\t\t\t%.f\t\n",i+1,bt[i],wt[i],
tat[i]);
}
printf("Average waiting time is : %.2f\n",sum_wt/n);
printf("Average turn arround time is : %.2f\n",sum_tat/n);
printf("\n");
return 0;
}
