#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct File
{
   struct File *left;
   char data[20];
   struct File *right;
};
int limit = 20;
typedef struct File File;
File *head = NULL,*tail = NULL;

File * create(char data[])
{
   File *pnew = (File *) malloc(sizeof(File));
   pnew -> left = NULL;
   //fgets(pnew -> data,limit,stdin);
   strcpy(pnew -> data,data);
   //pnew -> data = data;
   pnew -> right = NULL;
   
   return pnew;
}

void insert(char data[])
{
   File *pnew = create(data);
   File *ptr = NULL;
   if(head == NULL)
   {
      head = pnew;
      tail = pnew;
   }
   else
   {
      tail -> right = pnew;
      ptr = tail;
      tail = pnew;
      tail -> left = ptr -> right;
   }
   
}
void display()
{
   File *ptr = head;
   printf("Directory Name:%s \n",ptr -> data);
   printf("File Names:");
   ptr = ptr -> right;
   while(ptr != NULL)
   {
      printf("[%s] -> ",ptr -> data);
      ptr = ptr -> right;
   }
   printf("\n");
}

bool search(char name[])
{
     File *ptr = head;
     while(ptr != NULL)
     {
         if(strcmp(ptr -> data,name) == 0)
            return true;
         ptr = ptr -> right;
     }
     return false;
}
int main()
{
   char dir[limit];
   printf("Enter directory name:\n");
   fgets(dir,limit,stdin);
   insert(dir);
   char ch[limit];
   char c = 'y';
   int sw = 0;
   
    while(1)
    {
        printf("Enter Ch 1.insert 2.exit\n");
        scanf("%d",&sw);
        switch(sw)
        {
        case 1:
              printf("Enter file name:\n");
              scanf("%s",&ch);
              if(search(ch))
                 printf(" File is already exist\n");
              else
              {
                 insert(ch);
                 memset(ch,'\0',sizeof(ch));  // Method to clear the array
               }
              break;
       case 2:
               display();   
              exit(0);
              break;
        }
    }
             
}
