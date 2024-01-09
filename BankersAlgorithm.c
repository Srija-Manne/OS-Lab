#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qsize = 0,size = 5;
    int allocation[5][3] = { { 0, 1, 0 },
                        { 2, 0, 0 },
                        { 3, 0, 2 },
                        { 2, 1, 1 },
                        { 0, 0, 2 } };
    int max[5][3] =  { { 7, 5, 3 },
                      { 3, 2, 2 },
                      { 9, 0, 2 },
                      { 4, 2, 2 },
                      { 5, 3, 3 } };
    int available[3] = {3,3,2};
    int need[5][3];
    int queue[6];
    int pr[6] = {0,1,2,3,4,5};
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 3;j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }
    int count = 0;
    for(int i = 0,k = 1;qsize <= 5;i++,k++)
    {
       // printf("\nhiiiiiiiiiii\n");
         if(pr[k] == 0)
            continue;
        for(int j = 0;j < 3;j++)
        {
            if(available[j] < need[i][j])
               count++;
        }
        
        if(count == 0)
        {

        //printf("Insert:%d\n",pr[k]);
        queue[qsize] = pr[k];
        pr[k] = 0;
        qsize = qsize + 1;
        available[0] += allocation[i][0];
        available[1] += allocation[i][1];
        available[2] += allocation[i][2];
        }
        count = 0;
        if(k == 5)
        {
            i = -1;
            k = 0;
        }
    }
    for(int i = 0;i < 5;i++)
    printf("%d\n",queue[i]);

}

