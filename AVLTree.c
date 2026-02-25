#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
   int value;
   struct Node* left;
   struct Node* right;
   int height;
}NODE;

NODE* get_new_node(int val) {
   NODE* node = (NODE*)malloc(sizeof(NODE));
   node->value = val;
   node->right = NULL;
   node->left = NULL;
   node->height = 1;
   return(node); 
}

// getting the height
int get_height(NODE* node) {
   return ( node == NULL) ? 0:node->height;
}

// find max of nodes height
int max(int a, int b) {
   return (a>b)?a:b;
}

// function to get balance of the node 
int get_balance(NODE* node) {
   return (node == NULL) ? 0:get_height(node->left)-get_height(node->right);
}

// Left Rotate
NODE* left_rotate(NODE* x) {
   NODE* y = x->right;
   NODE* T2 = y->left;

   // perform rotation
   y->left = x;
   x->right = T2;

   // update height
   x->height = 1 + max(get_height(x->left),get_height(x->right));
   y->height = 1 + max(get_height(y->left),get_height(y->right));

   // return new root
   return y;
}

// Right Rotate
NODE* right_rotate(NODE* y) {
   NODE* x = y->left;
   NODE* T2 = x->right;
   // perform rotation
   x->right = y;
   y->left = T2;
   // update height
   y->height = 1 + max(get_height(y->left),get_height(y->right));
   x->height = 1 + max(get_height(x->left),get_height(x->right));
   // return new root
   return x;
}

// inserting the node in BST
NODE* insert_node(NODE* node, int val) {
   // 1-standard BST Insertion
   if(node == NULL) { 
      return (get_new_node(val));
   }

   //2-checking the left posiiton or right position
   if(val < node->value) {
      // insert left side 
      node->left = insert_node(node->left,val);
   } else if (val > node->value) {
      // insert right side 
      node->right = insert_node(node->right,val);
   } else {
      // equal values are not allowed in BST
      return node;
   }

   // 3- update the height based in the ancestor node
   node->height = 1 + max(get_height(node->left),get_height(node->right));
   
   // 4 - get the balance factor to check if it become unbalance after insert
   int balance = get_balance(node);

   // 5 - LL case
   if(balance > 1 && val < node->left->value) {
      return right_rotate(node);
   }
   
   // 6 - RR case
   if(balance < -1 && val > node->right->value) {
      return left_rotate(node);
   }

   // 7 - LR Case
   if(balance > 1 && val > node->left->value) {
      node->left = left_rotate(node->left);
      return right_rotate(node);
   }

   // 8 - RL Case
   if(balance < -1 && val < node->right->value) {
      node->right = right_rotate(node->right);
      return left_rotate(node);
   }
    return node;
   
}

int main() {
   NODE* root = NULL; // initail node of the AVL Tree
   /*
    10,20,30 (RR)
    40,50 (RR)
    25 (RL)
   */
   root = insert_node(root,10);
   printf("\n Pre Order of the AVL Tree\n");
   pre_order(root);
}
