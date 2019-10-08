struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};


int rangeSumBST(struct TreeNode* root, int L, int R) {
  int sum = 0;
  if (root == NULL) {
    return 0;
  } else {
    if ((L <= root->val) && (root->val <= R)) {
      sum += root->val;
    }
    if (L < root->val) {
      sum += rangeSumBST(root->left, L, R);
    }
    if (root->val < R) {
      sum += rangeSumBST(root->right, L, R);
    } 
  }
  return sum;
}
