#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void insert(struct Node **pt_head, int data, unsigned int pos) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;

  if (*pt_head == NULL) {
    *pt_head = node;
    node->next = NULL;
    node->prev = NULL;
    return;
  }

  if (pos == 1) {
    node->next = *pt_head;
    (*pt_head)->prev = node;
    *pt_head = node;
    node->prev = NULL;
    return;
  }

  struct Node *head = *pt_head;
  for (unsigned int i = 0; head != NULL; i++, head = head->next) {
    if (i == pos - 2) {
      node->prev = head;
      node->next = head->next;
      head->next = node;
      if (node->next) {
        (node->next)->prev = node;
      }
      return;
    }
  }
}
void print(struct Node *head) {
  if (head == NULL) {
    printf("\n");
    return;
  }

  printf("%d ", head->data);
  print(head->next);
}

int main() {

  struct Node *head = NULL;

  unsigned int n;
  scanf("%d", &n);

  while (n--) {
    int data;
    unsigned int pos;
    scanf("%d %d", &data, &pos);

    insert(&head, data, pos);
    print(head);
  }

  return 0;
}
