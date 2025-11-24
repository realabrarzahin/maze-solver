#include<stdio.h>
#include<stdlib.h>
  
struct Node{
  int data;
  struct Node* next;
};

void insert(struct Node** pointer_head, int x){
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));

  node -> data = x;
  node -> next = *pointer_head;

  *pointer_head = node;
}
  
void print(struct Node* head){
  while(head != NULL){
    printf("%d ", head -> data);
    head = head -> next;
  }
};

  

int main(){
 
  struct Node* head = NULL;
  
  int n; scanf("%d", &n);
  
  while(n--){
    int x;
    scanf("%d",&x);

    insert(&head, x);
  }

  print(head);

  return 0;
}
