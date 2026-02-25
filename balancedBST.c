#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} NODE;

NODE* create_node(int val) {
  NODE* node = (NODE*)malloc(sizeof(NODE));
  if(node != NULL) // successfully allocated the memory
  {
     node->left = NULL;
     node->right= NULL;
     node->value = val;
  }
  return node;
}

void print_tabs(int num_of_tabs) {
  for(int i=0; i<num_of_tabs; i++) {
    printf("\t");
  }
}

// function to print the tree
void print_rec(NODE* root, int level) {
  
  if(root == NULL) {
     print_tabs(level);
     printf("---<empty>---");
     return;
  }
  
  print_tabs(level);
  printf("value = %d\n", root->value);
  print_tabs(level);
  printf("left\n");

  print_rec(root->left,level+1);
  print_tabs(level);
  printf("right\n");

  print_rec(root->right, level+1);
  print_tabs(level);
  printf("done\n");
}

void print_tree(NODE* tree) {
   print_rec(tree,0);
}


int main() {
  NODE *n1 = create_node(10);
  NODE *n2 = create_node(11);
  NODE *n3 = create_node(12);
  NODE *n4 = create_node(13);
  NODE *n5 = create_node(14);

  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right=n5;
  
  print_tree(n1);

  return 0;
}
