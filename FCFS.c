#include<stdio.h>
int main(void){
int n,i;
printf("Enter the number of processess : ");
scanf(" %d",&n);
float bt[n],at[n],wt[n],tat[n];
wt[0]=0;
tat[0]=0;
float ct[n],sum_wt=0,sum_tat=0;
printf("Enter arrival time and burst time corresponding to 
process\n");
for(i = 0;i<n;i++)
{
printf("p[%d] : ",i+1);
scanf("%f",&at[i]);
scanf("%f",&bt[i]); 
}
ct[0]=bt[0];
for(i = 0;i<n;i++)
{
ct[i+1]=ct[i]+bt[i+1];
//calculate completion time
tat[i]= ct[i]-at[i];//turn around time = completion time -
arrival time
wt[i] =tat[i]- bt[i];//waiting time = turn around time - burst 
time
sum_wt+=wt[i];
sum_tat+=tat[i];
}
printf("process\t\tArrival time\t\tburst time\t\tcompletion 
time\t\tturn around time\t\twaiting time\n");
for(i = 0; i<n;i++){
printf("p[%d]\t\t\t%.f\t\t\t%.f\t\t\t%.f\t\t\t%.f\t\t\t%.f\n",
i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("Average waiting time is : %.2f\n",sum_wt/n);
printf("Average turn arround time is : %.2f\n",sum_tat/n);
printf("\n");
return 0;
}
