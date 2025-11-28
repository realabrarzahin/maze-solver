#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insert(struct Node **pt_head, int x, unsigned int pos) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = x;

  if (pos == 1) {
    node->next = *pt_head;
    *pt_head = node;
    return;
  } else {
    struct Node *temp = *pt_head;

    for (unsigned int i = 0; temp != NULL; i++, temp = temp->next) {
      if (i == pos - 2) {
        node->next = temp->next;
        temp->next = node;
        return;
      }
    }
  }
}

void delete(struct Node **pt_head, unsigned int pos) {

  if (pos == 1) {
    struct Node *temp = (*pt_head)->next;
    free(*pt_head);
    *pt_head = temp;
    return;
  }

  struct Node *head = *pt_head;
  for (unsigned int i = 0; head != NULL; i++, head = head->next) {
    if (i == pos - 2) {
      struct Node *temp = (head->next)->next;
      free(head->next);
      head->next = temp;
      return;
    }
  }
}

void reverse(struct Node **pt_head) {

  struct Node *curr = *pt_head;
  if (curr == NULL)
    return;

  struct Node *prev = NULL;
  struct Node *temp = curr->next;

  while (1) {
    if (temp == NULL) {
      *pt_head = prev;
      break;
    }

    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
}

void print(struct Node *head) {

  if (head == NULL)
    return;

  for (; head != NULL; head = head->next) {
    printf("%d ", head->data);
  }
  printf("\n");
}

int main() {

  struct Node *head = NULL;

  unsigned int n;
  scanf("%u", &n);

  while (n) {
    int x;
    unsigned int pos;
    scanf("%d %u", &x, &pos);

    insert(&head, x, pos);
    print(head);
  }

  reverse(&head);
  print(head);

  return 0;
}
