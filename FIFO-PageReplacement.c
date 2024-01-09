#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num_hits = 0;
int num_faults = 0;
struct Node{
int data;
struct Node *link;
};
typedef struct Node node;
node* createNode(int data){
node* newNode = (node*)malloc(sizeof(node));
newNode -> data = data;
newNode -> link = NULL;
return newNode; 
}
void createInitialNodes(node **head,int num_frames){
for(int i = 1;i <= num_frames;i++){
//create a new node with data part containing -1
node* newNode = createNode(-1);
//store the previous head address
newNode -> link = *head;
//make new node as head
*head = newNode;
}
}
void append(node **head,int data){
node* cur = *head;
while(cur -> link != NULL){
cur = cur -> link;
}
cur -> link = createNode(data);
}
void deleteBeg(node** head){
node* temp = *head;
*head = (*head)->link;
free(temp);
}
void display(node* head){
node *cur = head;
while(cur != NULL){
printf("%d ",cur->data);
cur = cur -> link;
}
}
int checkNodes(node **head,int data){
node *cur = *head;
while(cur!=NULL){
if(cur->data == data){ //check frames for page
num_hits++;//if page found increase hit count and return
return 1;
}
cur = cur->link;
}
//if page not found craete a node at the end and later remove 
the oldest node
append(head,data);
deleteBeg(head);
num_faults++;//increase the page faults as page not found
return 0;
}
int main(){
int a[50],frames,noOfPages;
node* head = NULL;
printf("Enter no of pages : ");
scanf("%d",&noOfPages);
printf("Enter the pages : ");
for(int i=0 ; i<noOfPages ; i++){
scanf("%d",&a[i]);
}
printf("Enter the number of frames : ");
scanf(" %d",&frames);
createInitialNodes(&head,frames);
for(int i=0 ; i<noOfPages ; i++){
int flag = checkNodes(&head,a[i]);
display(head);
printf("%s\n",flag==1?"-->HIT":"-->MISS");
} 
printf("Number of HITS : %d\n",num_hits);
printf("Number of FAULTS : %d\n",num_faults);
return 0;
}
