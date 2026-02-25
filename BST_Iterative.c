/*
 Code to check the binary search tree 
*/

#include<stdio.h>
#include<memory.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
  int value;
  struct Node* parent; // optional
  struct Node* left;
  struct Node* right;
}NODE;

// Searching the node in the given tree
NODE* search_node(NODE* tree, int val) {
  if(tree == NULL) return(NULL);
  if(tree->value == val) return(tree); // found the value at tree 
  if(tree->value<val) {
    return(search_node(tree->right,val));
  } else {
    return(search_node(tree->left,val));
  }
}

//finding the minimum value of the tree
NODE* find_minimum(NODE* tree) {
  if(tree == NULL) return(NULL);
  NODE* minNode = tree;
  while(minNode->left != NULL) {
    minNode=minNode->left;
  }
  return(minNode);
}

//finding the minimum value of the tree
NODE* find_maximum(NODE* tree) {
  if(tree == NULL) return(NULL);
  NODE* minNode = tree;
  while(minNode->right!= NULL) {
    minNode=minNode->right;
  }
  return(minNode);
}

void inorder_traversal(NODE* tree) {
  if(tree != NULL) {
    inorder_traversal(tree->left);
    printf("\n %d \n", tree->value);
    inorder_traversal(tree->right);
  }
}

void insertion_tree(NODE** tree, int val, NODE* parent) {
  NODE* p;
  if(*tree == NULL) { // root node of the insertion
    p=(NODE*)malloc(sizeof(NODE));
    p->value = val;
    p->left = p->right = NULL;
    p->parent = parent;
    *tree = p;
    return;
  }
  if(val <(*tree)->value) {
    insertion_tree(&(*tree)->left,val,*tree);
  } else {
    insertion_tree(&(*tree)->right,val,*tree);
  }
}


NODE* get_rightmost_from_left_sub_tree(NODE** tree){
     NODE* itr = *tree;
     while(itr  != NULL && itr->right != NULL) {
         itr=itr->right;
     }
     return itr;
}


/* Deleting the node from the tree
   condition 1: If the given node is root then left portion and right most
   element need to insert
*/

bool isNodeDeleted(NODE** tree, int val) {
  if(*tree == NULL) { 
    // there is not node in the tree.
    return false;
  }
  
  //checking if the root->value = value
  NODE* itr=*tree;
  if(itr->value == val) {
       NODE* rightMostNode = get_rightmost_from_left_sub_tree(&itr->left);
       rightMostNode->right = itr->right;
       *tree = itr->left;
  }
  return true;
}


// Code to delete the node in the tree - iterative order
NODE* delete_node(NODE* root, int val) {
  // deleting the node from the tree in the iterative order
  NODE* current = root; // Considering the current node is root for intial case
  NODE* parent = NULL; // initally previous node - current's parent is NULL

  // finding the node with matching val
  while(current != NULL && current->value != val) {
    parent = current; // assiging the parent 
    if(val < current->value) {
       // moving towards the right tree
       current = current->left;
    } else {
       // movind towards the right subtree
       current = current->right;
    }
    // end of while loop
   }

   // if the value not found in given tree
   if(current == NULL) { return root; }

   // if the child has two child,
   if(current->left != NULL && current->right != NULL) {
       NODE* successor_parent = current;
       NODE* successor = current->right; // we have to get the right most left node
       while(successor->left != NULL)
       {
         successor_parent = successor;
         successor->left = successor;
       }
       // replacing the current node with successor
       current->value = successor->value;

       parent = successor_parent;
       current=successor;
       
   }
   
   // in case the current node has 0/1 child
   NODE* child = current->left!=NULL?current->left:current->right;
   
   if(parent == NULL) { free(current); return child;}

   if(current == parent->left) { parent->left = child; } 
   else { parent->right = child; }

  free(current);
  return root;
     
  }

int main() {
  NODE* tree=NULL;
  insertion_tree(&tree,1,tree);
  insertion_tree(&tree,2,tree);
  insertion_tree(&tree,3,tree);
  insertion_tree(&tree,4,tree);
  inorder_traversal(tree);
  NODE* min_node = find_minimum(tree);
  printf("\n MIN: %d",min_node->value);
  isNodeDeleted(&tree,2);
  inorder_traversal(tree);
}
   
