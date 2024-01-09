#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define limit 20
struct File
{
    char fname[limit];
    int index;
    int length;
};

typedef struct File File;
void allocate(File file[],int noOfFiles,int dsize,int count[])
{
    int fsize = 0,index = 0;
    char fname[limit];
    int tempSize = 0;
    int countidx = 0;
    for(int i = 0;i  < noOfFiles;i++)
    {
        printf("Enter file name:\n");
        scanf("%s",&fname);
        printf("Enter File Size\n");
        scanf("%d",&fsize);

        tempSize += fsize;
        if(tempSize > dsize)
        {
           printf("File %s cannot be allocated due to insufficiency of memory \n ",fname);
           tempSize -= fsize;
        }
        else
        {
           strcpy(file[i].fname,fname);
           file[i].index = index;
           file[i].length = fsize;
           index += fsize;
           count[countidx++] = i;
        }
    }
}

void display(File file[],int size,int count[])
{
   printf("FileName       Index     Length\n");
   int i = 0,t = 0;
   while(i < size)
   {
       t = count[i];
       printf("%s           %d          %d\n",file[t].fname,file[t].index,file[t].length);
       i++;
   }
}

int main()
{
    int noOfFiles,dsize;
   
    printf("Enter disk size:\n");
    scanf("%d",&dsize);
    int count[dsize];
    printf("Enter No of files:\n");
    scanf("%d",&noOfFiles);
    File file[noOfFiles];

    allocate(file,noOfFiles,dsize,count);
    display(file,dsize,count);

    return 0;
}

