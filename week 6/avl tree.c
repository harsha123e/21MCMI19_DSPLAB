#include<stdio.h>

#include<malloc.h>

typedef struct node {
  int data;
  struct node * left, * right;
  int ht;
}
node;

node * insertNode(node * , int);
node * DeleteNode(node * , int);
void preorder(node * );
void inorder(node * );
void postorder(node * );
void print_tree_level_order(node * root);
void print_level(node * root, int level_no);
int height(node * );
node * rotateright(node * );
node * rotateleft(node * );
node * RR(node * );
node * LL(node * );
node * LR(node * );
node * RL(node * );
int BF(node * );

int main() {
  node * root = NULL;
  int x, n, i, op;
  do {
    printf("\n1)Create:");
    printf("\n2)Insert:");
    printf("\n3)Delete:");
    printf("\n4)Print:");
    printf("\n5)Sum of left sub tree:");
    printf("\n0)Quit:");
    printf("\n\nEnter Your Choice:");
    scanf("%d", & op);
    if (op == 1) {

      printf("\nEnter no. of elements:");
      scanf("%d", & n);
      printf("\nEnter tree data:");
      root = NULL;
      for (i = 0; i < n; i++) {
        scanf("%d", & x);
        root = insertNode(root, x);
      }
    }
    if (op == 2) {

      printf("\nEnter a data:");
      scanf("%d", & x);
      root = insertNode(root, x);
    }
    if (op == 3) {

      printf("\nEnter a data:");
      scanf("%d", & x);
      root = DeleteNode(root, x);
    }
    if (op == 4) {

      printf("\nPreorder sequence:\n");
      preorder(root);
      printf("\n\nInorder sequence:\n");
      inorder(root);
      printf("\n\nPostorder sequence:\n");
      postorder(root);
      printf("\n\nLevel order sequence:\n");
      print_tree_level_order(root);
      printf("\n");
    }
    if (op == 5) {
      if (root != NULL)
        printf("\nSum of all nodes in left sub tree:%d\n", sum_of_nodes(root -> left));
      else
        printf("\nTree doesn't exist\n");
    }
  } while (op != 0);
  return 0;
}

node * insertNode(node * T, int x) {
  if (T == NULL) {
    T = (node * ) malloc(sizeof(node));
    T -> data = x;
    T -> left = NULL;
    T -> right = NULL;
  } else
  if (x > T -> data) // insert in right subtree
  {
    T -> right = insertNode(T -> right, x);
    if (BF(T) == -2)
      if (x > T -> right -> data)
        T = RR(T);
      else
        T = RL(T);
  } else
  if (x < T -> data) {
    T -> left = insertNode(T -> left, x);
    if (BF(T) == 2)
      if (x < T -> left -> data)
        T = LL(T);
      else
        T = LR(T);
  }
  T -> ht = height(T);
  return (T);
}

node * DeleteNode(node * T, int x) {
  node * p;
  if (T == NULL) {
    return NULL;
  } else
  if (x > T -> data) // insert in right subtree
  {
    T -> right = DeleteNode(T -> right, x);
    if (BF(T) == 2)
      if (BF(T -> left) >= 0)
        T = LL(T);
      else
        T = LR(T);
  } else
  if (x < T -> data) {
    T -> left = DeleteNode(T -> left, x);
    if (BF(T) == -2) //Rebalance during windup
      if (BF(T -> right) <= 0)
        T = RR(T);
      else
        T = RL(T);
  } else {
    //data to be deleted is found
    if (T -> right != NULL) { //delete its inorder succesor
      p = T -> right;
      while (p -> left != NULL)
        p = p -> left;
      T -> data = p -> data;
      T -> right = DeleteNode(T -> right, p -> data);
      if (BF(T) == 2) //Rebalance during windup
        if (BF(T -> left) >= 0)
          T = LL(T);
        else
          T = LR(T);\
    } else
      return (T -> left);
  }
  T -> ht = height(T);
  return (T);
}

int height(node * T) {
  int lh, rh;
  if (T == NULL)
    return (0);
  if (T -> left == NULL)
    lh = 0;
  else
    lh = 1 + T -> left -> ht;
  if (T -> right == NULL)
    rh = 0;
  else
    rh = 1 + T -> right -> ht;
  if (lh > rh)
    return (lh);
  return (rh);
}

node * rotateright(node * x) {
  node * y;
  y = x -> left;
  x -> left = y -> right;
  y -> right = x;
  x -> ht = height(x);
  y -> ht = height(y);
  return (y);
}

node * rotateleft(node * x) {
  node * y;
  y = x -> right;
  x -> right = y -> left;
  y -> left = x;
  x -> ht = height(x);
  y -> ht = height(y);
  return (y);
}

node * RR(node * T) {
  T = rotateleft(T);
  return (T);
}

node * LL(node * T) {
  T = rotateright(T);
  return (T);
}

node * LR(node * T) {
  T -> left = rotateleft(T -> left);
  T = rotateright(T);
  return (T);
}

node * RL(node * T) {
  T -> right = rotateright(T -> right);
  T = rotateleft(T);
  return (T);
}

int BF(node * T) {
  int lh, rh;
  if (T == NULL)
    return (0);

  if (T -> left == NULL)
    lh = 0;
  else
    lh = 1 + T -> left -> ht;

  if (T -> right == NULL)
    rh = 0;
  else
    rh = 1 + T -> right -> ht;

  return (lh - rh);
}

void preorder(node * T) {
  if (T != NULL) {
    printf("%d(Bf=%d)", T -> data, BF(T));
    preorder(T -> left);
    preorder(T -> right);
  }
}

void inorder(node * T) {
  if (T != NULL) {
    inorder(T -> left);
    printf("%d(Bf=%d)", T -> data, BF(T));
    inorder(T -> right);
  }
}

void postorder(node * T) {
  if (T != NULL) {
    postorder(T -> left);
    postorder(T -> right);
    printf("%d(Bf=%d)", T -> data, BF(T));
  }
}

int tree_height(node * root) {
  int left_height, right_height;
  if (!root)
    return 0;
  else {
    left_height = tree_height(root -> left);
    right_height = tree_height(root -> right);
    if (left_height >= right_height)
      return left_height + 1;
    else
      return right_height + 1;
  }
}

void print_level(node * root, int level_no) {
  if (!root)
    return;
  if (level_no == 0) {
    printf("%d -> ", root -> data);
  } else {
    print_level(root -> left, level_no - 1);
    print_level(root -> right, level_no - 1);
  }

}

void print_tree_level_order(node * root) {
  int i;
  if (!root)
    return;
  int node_height = tree_height(root);
  for (i = 0; i < node_height; i++) {
    printf("Level %d: ", i);
    print_level(root, i);
    printf("\n");
  }
  printf("\n-----Complete Level Order Traversal:-----\n");
  for (i = 0; i < node_height; i++) {
    print_level(root, i);
  }
  printf("\n");
}

int sum_of_nodes(node * root) {

  if (root == NULL)
    return 0;
  return (root -> data + sum_of_nodes(root -> left) + sum_of_nodes(root -> right));
}
