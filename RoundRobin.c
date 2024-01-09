/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Queue
{
  int *list;
  int capacity;
  int rear;
  int front;
};
struct GantChart
{
    int p;
    int initial;
    int ct;
};
typedef struct Queue Queue;
typedef struct GantChart gantchart;
void sort(Queue *,int *,int *,int *,int);
void roundrobin(Queue *,gantchart [],int *,int *,int *,int);
void displayChart(gantchart []);

Queue * create(int cap)
{
    Queue* ptr = NULL;
    ptr = (Queue *)malloc(sizeof(Queue));
    ptr -> capacity = cap;
    ptr -> rear = -1;
    ptr -> front = 0;
    ptr -> list = (int *)malloc(cap*sizeof(int));
    return ptr;
}
void insert(int elem,Queue *ptr)
{
    //if(ptr -> rear == ptr -> capacity - 1)
    //return false;
    ptr -> rear++;
    ptr -> list[ptr -> rear] = elem;
    //return true;
}

bool isEmpty(Queue *ptr)
{
    if(ptr -> front == ptr -> rear + 1)
       return true;
    else
       return false;
}
void delete(Queue *ptr)
{   //if(ptr -> front == ptr -> capacity)
      // return false;
    ptr -> front++;
    //return true;
}
void display(Queue *ptr)
{
    for(int i = ptr -> front;i <= ptr -> rear;i++)
        printf("|%d|",ptr -> list[i]);

}
void displayChart(gantchart gant[20])
{   
    printf("\n");
    for(int i = 0;i < 10;i++)
    {
        printf("%d",gant[i].p);
        printf("    %d",gant[i].initial);
        printf("        %d",gant[i].ct);
        printf("\n");
    }
}
int main()
{
   Queue *pnew = NULL;
   gantchart gant[20];
   int size,ch,elem;
   int *arrivaltime,*process,*bursttime;
   bool res;
   
    printf("Enter size of the queue");
    scanf("%d",&size);
    pnew = create(15);
                 
    process = (int *)malloc(sizeof(int)*size);
    arrivaltime = (int *)malloc(sizeof(int)*size);
    bursttime = (int *)malloc(sizeof(int)*size);
    printf("Enter processes");
    for(int i = 0;i < size;i++)
        scanf("%d",process + i);

    printf("Enter arrivaltime");
    for(int i = 0;i < size;i++)
        scanf("%d",arrivaltime + i);

    printf("Enter bursttime");
    for(int i = 0;i < size;i++)
        scanf("%d",bursttime + i);

    sort(pnew,arrivaltime,process,bursttime,size);
    roundrobin(pnew,gant,arrivaltime,process,bursttime,size);

    displayChart(gant);

}

void roundrobin(Queue* ptr,gantchart gant[20],int *at,int *pr,int *bt,int size)
{
     int ts = 3;
     int q2 = 0;
     int q[10];
     int ub[size];
     int count = 0;
     int updatedBurst[size];
     for(int i = 0;i < size;i++)
     {
         updatedBurst[pr[i]] = bt[i];
         ub[i] = pr[i];
     }
     insert(pr[0],ptr);
     int k = ptr -> list[ptr -> front];
     printf("k:%d\n",k);
     gant[0].p = pr[0];
     gant[0].initial = at[0];

     if(updatedBurst[ub[0]] < 3)
    {
         gant[0].ct =  updatedBurst[k];
         delete(ptr);
         updatedBurst[ub[0]] = 0;
      //   display(ptr);
    }
    else
    {

        gant[0].ct = gant[0].initial + 3;
        delete(ptr);
       // for(int i = 0;i < size;i++)
         //   printf("at[%d]=%d\n",i,at[i]);
        for(int i = 1;i < size;i++)
        {
            if(at[i] <= 3)
            {  
                
                q[q2] = pr[i];
                q2++;
            }
        }
        //for(int i = 0;i < q2;i++)
        //printf("q2[i]:%2d",q[i]);
       // printf("\n");
        
         for(int y= 0;y < q2;y++)
         {
             for(int i = ptr -> front;i <= ptr -> rear;i++)
             {
                 if(q[y] == ptr -> list[i])
                     count++;
             }
             if(count == 0)
             {   
                 printf("q[y]:%d",q[y]);
                 insert(q[y],ptr);
             }
             count  = 0;
         }
           for(int i = 0;i < 10;i++)
               q[i] = 0;
          printf("pr[0]:%d\n",pr[0]);
         insert(pr[0],ptr);
         updatedBurst[ub[0]] = (bt[0] - (gant[0].initial + gant[0].ct));
         display(ptr);
    }
            for(int i = 1;i < 10;i++)
         {  
              for(int j = 0;j < 10;j++)
                  q[i] = 0;
              k = ptr -> list[ptr -> front];
              delete(ptr);
              gant[i].p = k;
              gant[i].initial = gant[i - 1].ct;
              //for(int i = 0;i < size;i++)
                   //printf("updatedBurst[%d]:%d\n",i,updatedBurst[ub[i]]);
             
             if(updatedBurst[k] < ts)
             {
                   gant[i].ct = gant[i].initial +  updatedBurst[k];
                   updatedBurst[k] = 0;
                   display(ptr);
             }
             else
             {     
                   q2 = 0;
                   gant[i].ct = gant[i].initial + 3;
                  
                   for(int j = i + 1;j < size;j++)
                   {
                       if(at[j] <= gant[i].ct)
                      {
                        
                         q[q2] = pr[j];
                         q2++;
                      }
                   }
                    for(int j = 0;j < q2;j++)
                    {
                        for(int x = ptr -> front;x <= ptr -> rear;x++)
                        {
                              if(q[j] == ptr -> list[x])
                              count++;
                        }
                       if(count == 0)
                       {  
                           insert(q[j],ptr);
                       }
                       count  = 0;
                    }
                    for(int x = 0;x < q2;x++)
                        q[x] = 0;
                    insert(pr[i],ptr);
                    updatedBurst[k] = (updatedBurst[k] - ( gant[i].ct - gant[i].initial));
                     printf("\n");
                     display(ptr);
                  
             }
         }
             for(int i = size;true == isEmpty(ptr);i++)
             {     
                   
                   k = ptr -> list[ptr -> front];
                   delete(ptr);
                   gant[i].p = k;
                   gant[i].initial = gant[i - 1].ct;
                   //  for(int i = 0;i < size;i++)
                   //printf("updatedBurst[%d]:%d\n",i,updatedBurst[ub[i]]);
                   printf("first:k:");
                   display(ptr);
                  printf("\n");
                  if(k == 0)
                     exit(0);
                  if(updatedBurst[k] < ts)
                  {
                     gant[i].ct = gant[i].initial +  updatedBurst[k];
                     updatedBurst[k] = 0;
                   //  display(ptr);
                  }
                  else
                  {
                       gant[i].ct = gant[i].initial + 3;
                       insert(pr[i],ptr);
                       updatedBurst[k] = (updatedBurst[k] - ( gant[i].ct - gant[i].initial));
                     //  display(ptr);
                  }
             }

         }


 

void sort(Queue* ptr,int *at,int *process,int *bt,int size)
{
    int temp = 0;
    for(int j = 0;j < size - 1;j++)
    {
        for(int i = 0;i < size - 1;i++)
        {
            if(at[i] > at[i + 1])
            {
                temp = at[i];
                at[i] = at[i + 1];
                at[i+ 1] = temp;
                temp = process[i];
                process[i] = process[i + 1];
                process[i + 1] = process[i];
                temp = bt[i];
                bt[i] = bt[i + 1];
                bt[i + 1] = bt[i];
            }
        }
    }
}


