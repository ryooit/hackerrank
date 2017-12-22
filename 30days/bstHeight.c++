int getHeight(Node* root){
  //Write your code here
    if (root == NULL)
        return -1;
    else {
        int lhs = getHeight(root->left);
        int rhs = getHeight(root->right);
        return 1 + max(lhs, rhs);
    }
}
