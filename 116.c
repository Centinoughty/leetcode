// Populating next right pointers in each node
// MEDIUM

#include <stdio.h>

struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};

int countNodes (struct Node* root) {
  if (root) {
    return 1 + countNodes(root->left) + countNodes(root->right);
  }

  return 0;
}

void enque (struct Node** queue, int* rear, struct Node* root) {
  queue[(*rear) ++] = root;
}

struct Node* deque (struct Node** queue, int* front) {
  return queue[(*front) ++];
}

int isEmpty (int front, int rear) {
  return front == rear;
}

struct Node* connect(struct Node* root) {
  if (!root) {
    return NULL;
  }

  int n = countNodes(root);
	struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
  int front = 0, rear = 0;
  enque(queue, &rear, root);

  while (!isEmpty(front, rear)) {
    int levelSize = rear - front;
    struct Node** listNodes = (struct Node**)malloc(levelSize * sizeof(struct Node*));

    for (int i = 0; i < levelSize; i ++) {
      struct Node* temp = deque(queue, &front);
      listNodes[i] = temp;

      if (temp->left) {
        enque(queue, &rear, temp->left);
      }

      if (temp->right) {
        enque(queue, &rear, temp->right);
      }
    }

    for (int i = 0; i < levelSize - 1; i ++) {
      listNodes[i]->next = listNodes[i + 1];
    }

    listNodes[levelSize - 1]->next = NULL;
    free(listNodes);
  }
  
  free(queue);
  return root;
}


// Alternative solution
void connectTwoNode (struct Node* p, struct Node* q) {
  if (!p) {
    return;
  }

  p->next = q;
  connectTwoNode(p->left, p->right);
  connectTwoNode(p->right, q->left);
  connectTwoNode(q->left, q->right);
}

struct Node* connect(struct Node* root) {
	if (!root) return NULL;
    connectTwoNode(root->left, root->right);
    return root;
}
