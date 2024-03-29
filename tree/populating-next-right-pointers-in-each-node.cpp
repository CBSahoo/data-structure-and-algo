Node* connect(Node* root) {
      if(root == NULL) return NULL;

      Node *curr = root;

      while(curr->left != NULL) {
          Node *temp = curr;

          while(curr) {
              curr->left->next = curr->right;
              if(curr->next) curr->right->next =  curr->next->left;
              curr = curr->next;
          }

          curr = temp->left;
      }

      return root;
  }
