#include<stdio.h>


int search(int at[],int bt[],int size,int burst)
{
    int i = 0;
    while(bt[i] == -1)
          i++;
    int min = i;
    int index = 0;
    for(int j = 0;j < size;j++)
    {
        if(bt[j] <= bt[min] && at[j] <= burst && bt[j] != -1)
           min = j;
    }
    return min;
}
void sjf(int p[],int at[],int bt[],int size,int p2[],int init[],int fin[])
{
    p2[0] = p[0];
    init[0] = at[0];
    fin[0] = init[0] + bt[0];
    bt[0] = -1;
    for(int i = 1;i < size;i++)
    {
        int index = search(at,bt,size,fin[i - 1]);
        p2[i] = p[index];
        init[i] = fin[i - 1];
        fin[i] = init[i] + bt[index];
        bt[index] = -1;
    }
}
void display(int p2[],int init[],int fin[])
{
    for(int i = 0;i < 5;i++)
        printf("P2:%d   init:[%d]   fin:[%d]\n",p2[i],init[i],fin[i]);
}
int main()
{
    int p[] = {1,2,3,4,5};
    int at[] = {1,2,3,4,5};
    int bt[] = {7,5,1,2,8};
    int size = 5;
    int p2[size],init[size],fin[5];
    
    sjf(p,at,bt,size,p2,init,fin);
    display(p2,init,fin);
    
}
