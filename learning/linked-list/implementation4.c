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

void reverse(struct Node **pt_head, struct Node *curr, struct Node *prev) {
  if (curr == NULL) {
    *pt_head = prev;
    return;
  }

  reverse(pt_head, curr->next, curr);

  curr->next = prev;
  return;
}

void print(struct Node *curr) {
  if (curr == NULL) {
    printf("\n");
    return;
  }

  printf("%d ", curr->data);
  print(curr->next);
}

int main() {

  struct Node *head = NULL;

  unsigned int n;
  scanf("%u", &n);

  while (n--) {
    int x;
    unsigned int pos;
    scanf("%d %u", &x, &pos);

    insert(&head, x, pos);
    print(head);
  }

  reverse(&head, head, NULL);
  print(head);

  return 0;
}
