#include <climits>
 bool helper_BST (Node* node, int min, int max) {
     if (node == NULL)
         return true;

     if (node->data > max || node->data < min)
         return false;

     else
         return (helper_BST(node->left, min, node->data-1) && helper_BST(node->right, node->data+1, max));
 }


 bool checkBST(Node* root) {
     return helper_BST (root, INT_MIN, INT_MAX);
   }
