#include<stdio.h>

int search(int prio[],int at[],int bt[],int size,int burst)
{
    int j = 0;
    while(bt[j] == 0)
          j++;
    int max = j;
    for(int i = 0;i < 4;i++)
    {
        if(prio[i] > prio[max] && bt[i] != 0 && at[i] <= burst)
        {
            max = i;
        }
    }
    return max;
}
int sjf(int prio[],int p[],int at[],int bt[],int size,int p2[],int init[],int fin[])
{
    int fsize = 0;
    p2[0] = p[0];
    init[0] = 0;
    fin[0] = 1;
    bt[0] = bt[0] - 1;
    int count = 1;
    for(int i = 0;i < 20;i++)
    {
        if(fsize >= 4)
           break;
        int index = search(prio,at,bt,size,fin[count - 1]);
        p2[count] = p[index];
        init[count] = fin[count - 1];
        fin[count] = init[count] +  1;
        bt[index] = bt[index] - 1;
        if(bt[index] == 0)
           fsize++;
        count++;
    }
    return count;
}

void table(int p[],int p2[],int init[],int fin[],int fsize,int size,int ct[])
{
    int space = 0;
    for(int i = 0;i < size;i++)
    {
        int min = p[i];
        for(int j = 0;j < fsize;j++)
        {
            if(min == p2[j])
               ct[space] = fin[j];
        }
        space++;
    }
  
}
void display(int p[],int at[],int bt[],int ct[],int size)
{       printf(" P    Arrival Time  Burst Time, Completion\n");
    for(int i = 0;i < size;i++)
        printf(" %d        %d           %d           %d\n",p[i],at[i],bt[i],ct[i]);
}
void display2(int p2[],int init[],int fin[],int size)
{
     for(int i = 0;i < size;i++)
        printf(" %d        %d           %d\n",p2[i],init[i],fin[i]);
}

int main()
{
    int prio[] = {10,20,30,40};
    int p[] = {1,2,3,4};
    int at[] = {0,1,2,4};
    int bt[] = {5,4,2,1};
    int ub[] = {5,4,2,1};
    int size = 4;
    int p2[20],init[20],fin[20];
    int ct[4];
    int fsize = sjf(prio,p,at,ub,size,p2,init,fin);
  
    //table(p,p2,init,fin,fsize,size,ct);
    //display(p,at,bt,ct,size);
    display2(p2,init,fin,fsize);
    
}

