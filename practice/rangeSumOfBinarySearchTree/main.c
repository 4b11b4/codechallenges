#include <stdio.h>
#include "rangeSumBST.c"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* There are two ways of accessing members via a pointer in C.
 * 1. (*pointer).member
 * 2. pointer->member
 */

/* Note about Binary Search Trees implemented as an array.
 * Let the parent node be some index i
 * then the left node is at index = (2*i)
 * and the right node is at index = (2*i)+1
 */

int main() {
  int L = 0;
  int R = 11;

  struct TreeNode *rootPtr, root;
  rootPtr = &root;
  rootPtr->val = 10;
  printf("Root Val: %d\n", (*rootPtr).val);
  struct TreeNode *rightPtr, right;
  rightPtr = &right;
  rightPtr->val = 8;
  rightPtr->left=NULL;
  rightPtr->right=NULL;
  printf("R1 Val: %d\n", (*rightPtr).val);
  struct TreeNode *leftPtr, left;
  leftPtr = &left;
  leftPtr->val = 12;
  leftPtr->left=NULL;
  leftPtr->right=NULL;
  printf("L1 Val: %d\n", (*leftPtr).val);
  rootPtr->left=leftPtr;
  rootPtr->right=rightPtr;

  printf("Range Sum BST L=0,R=11: %d\n", rangeSumBST(rootPtr, L, R));
}
