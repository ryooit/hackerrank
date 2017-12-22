void levelOrder(Node * root){
    //Write your code here
      queue<Node *> q;

      q.push(root);

      while (!q.empty()) {
          Node *v = q.front();
          cout << v->data << " ";

          if (v->left != NULL)
              q.push(v->left);
          if (v->right != NULL)
              q.push(v->right);

          q.pop();
      }
}
