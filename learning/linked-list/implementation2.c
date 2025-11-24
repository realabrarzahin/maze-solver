#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
  
void insert(struct Node** pt_head, int x, unsigned int pos){
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  struct Node* head = *pt_head;

  node -> data = x;

  if(pos == 0){
    node -> next = (*pt_head);
    *pt_head = node;
  }
  else{
    int i = 0;
    struct Node* prev = head;
    while(prev != NULL){
      if(i == pos - 1){
        node -> next = prev -> next;
        prev -> next = node;
      }
  
      // printf("data: %d next: %p\n", prev -> data, prev -> next);

      prev = prev -> next;
      i++;
    }
  }
}

void print(struct Node* head){
  while(head != NULL){
    printf("%d ", head -> data);
    head = head -> next;
  }
  printf("\n");
}


int main(){
  
  struct Node* head = NULL;
  
  unsigned int n;
  scanf("%u", &n);
  
  while(n--){
    int x;
    unsigned int pos;
    scanf("%d %u", &x, &pos);
  
    insert(&head, x, pos - 1);
    print(head);
  }

  return 0;
}

