#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#define limit 20
struct File
{
    char data[limit];
    struct File *next;
};

struct Node
{
    char data[limit];
    struct Node *left;
    struct Node *next;
    struct File *file;
};

typedef struct File File;
typedef struct Node Node;
Node *head = NULL,*tail = NULL;
File *fhead = NULL,*ftail = NULL;


Node * create(char data[])
{
    Node *pnew = (Node *) malloc(sizeof(Node));
    strcpy(pnew -> data,data);
    pnew -> next = NULL;
    pnew -> file = NULL;
    pnew -> left = NULL;
    return pnew;
}

File * createF(char data[])
{
    File *pnew = (File *) malloc(sizeof(File));
    strcpy(pnew -> data,data);
    pnew -> next = NULL;
    return pnew;
}

void createDirectory(char data[])
{
    Node *ptr = create(data);
    if(head == NULL)
    {
        head = ptr;
        tail = ptr;
        ptr -> left = NULL;
    }
    else
    {
        ptr -> left = tail;
        tail -> next = ptr;
        tail = ptr;
    }
}

Node *findDirLocation(char dir[])
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(dir,ptr -> data) == 0)
          return ptr;
        ptr = ptr -> next;
    }
    return NULL;
}

bool findFile(Node *ptr,char data[])
{
    File *pnew = ptr -> file;
    while(pnew != NULL)
    {
        if(strcmp(data,pnew -> data) == 0)
           return true;
        pnew = pnew -> next;
    }
    return false;
}

bool findDirectory(char data[])
{
    Node *pnew = head;
    while(pnew != NULL)
    {
        if(strcmp(data,pnew -> data) == 0)
           return true;
        pnew = pnew -> next;
    }
    return false;
}
bool createFile(char dir[],char file[])
{
    Node *ptr = findDirLocation(dir);
     if(ptr ==  NULL)
       return false;
    if(findFile(ptr,file))
       return false;
    File *fptr = createF(file);
    File *ptr2 = ptr -> file;
    
    if(ptr2 == NULL)
    {
      // fhead = fptr;
       ptr2  = fptr;
       ptr -> file = fptr;
    }
    else
    {
         while(ptr2 -> next != NULL)
               ptr2 = ptr2 -> next;
         if(ptr != NULL)
        {
         ptr2 -> next = fptr;
        }
        return true;
     }
}

bool removeDir(char data[]) 
{
    Node *ptr = findDirLocation(data);
    if(ptr != NULL)
    {
       if(ptr -> left == NULL)
          head = head -> next;
       else if(ptr -> next == NULL && ptr -> left != NULL)
      {
         tail = tail -> left;
         tail -> next = NULL;
      }
      else
     {
         Node *pt = ptr -> left;
         pt -> next -> next -> left = pt;
     }
     return true;
    }
    return false;
}

bool removeFile()
{
    
}
void display()
{
    Node *dir = head;
    File *f1;
    printf("Directory           File\n");
    while(dir != NULL)
    {
        
        f1 = dir -> file;
        printf("%s    ",dir -> data);
        while(f1 != NULL)
        {
            printf(" \t %s -> ",f1 -> data);
            f1 = f1 -> next;
        }
        printf("\n");
        dir = dir -> next;
    }
}

int main()
{
    Node *ptr;
    char data[limit];
    char data2[limit];
   /* printf("Enter the directory:\n");
    scanf("%s",&data);
    scanf("%s",&data2);
    createDirectory(data);
    //createDirectory(data2);
    //if(createFile(data,data2))
   */
    int choice = 0;
    while(1)
    {
        printf("Enter 1.CreateDirectory 2.CreateFile 3.Display Files");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  printf("Enter Directory:\n");
                  scanf("%s",&data);
                  createDirectory(data);
                  //memset(data,'\0',sizeof(data));
                  break;
            case 2:
                  printf("Enter the directory Name and File name\n");
                  scanf("%s %s",&data,&data2);
                  printf("Enter file name\n");
                  createFile(data,data2);
                  ///memset(data,'\0',sizeof(data));
                  break;
            case 3:
                   display();
                   break;
            case 4:
             printf("Enter Directory to remove:\n");
                  scanf("%s",&data);
                   removeDir(data);
                  break;
        }
    }

    display();
}



