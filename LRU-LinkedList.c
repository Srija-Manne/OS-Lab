#include <stdio.h>
#include<stdbool.h>
int stack[3];   
int pop[3];

int top = -1;
int tpop = -1;
int frame = 3;

void display()
{
    for(int i = 0;i <= top;i++)
    {
       printf("%d -> ",stack[i]);
    }
    printf("\n");
}

bool search(int data)
{
    for(int i = 0;i <= top;i++)
    {
       if(stack[i] == data)
          return true;
    }
    return false;
}
bool pollSearch(int data)
{ 
    for(int i = 0;i <= tpop;i++)
    {
       if(pop[i] == data)
          return true;
    }
    return false;
    
}
void clear()
{
    tpop = -1;
}

int solve(int arr[],int index)
{
    clear();
     for(int i = index - 1;i >= 0;i--)
     {
         if(tpop == frame - 1)
            break;
         if(search(arr[i]))
         {
             if(!pollSearch(arr[i]))
             {
                 pop[++tpop] = arr[i];
             }
         }
    }
      return pop[tpop];
}


int main()
{
    int a[20] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int hits = 0,faults = 0;
   // printf("Hello World");
    for(int i = 0;i < 20;i++)
    {
        if(top < frame - 1)
        {
            if(!search(a[i]))
            {
               stack[++top] = a[i];
               faults++;
            }
            else
                hits++;
        }
        else
        {
             if(!search(a[i]))
             {
                 int data = solve(a,i);
                 int k = 0;
                 for(k = 0;k < 3;k++)
                 {
                      if(stack[k] == data)
                         break;
                 }
                  stack[k] = a[i];
                  faults++;
             }
             else
                 hits++;
        
        }
        display();
        
    }
    printf("Hits :%d, Faults:%d",hits,faults);
    return 0;
}
