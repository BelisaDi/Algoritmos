#ifdef _bst_hpp_

template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::min(bst<keyType>::bstNode *root) const{
  bstNode *tmp = root;
  if(tmp != nullptr){
    while(tmp->left != nullptr){
      tmp = tmp->left;
    }
  }
  return tmp;
}

template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::max(bst<keyType>::bstNode *root) const{
  bstNode *tmp = root;
  if(tmp != nullptr){
    while(tmp->right != nullptr){
      tmp = tmp->right;
    }
  }
  return tmp;
}

template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::successor(bst<keyType>::bstNode *root) const{
  bstNode *tmp = root;
  if(tmp == nullptr){
    return tmp;
  }
  else{
    if(tmp->right == nullptr){
      return tmp;
    }
    tmp = tmp->right;
    while(tmp->left != nullptr){
      tmp = tmp->left;
    }
    return tmp;
  }
}

template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::predecessor(bst<keyType>::bstNode *root) const{
  bstNode *tmp = root;
  if(tmp == nullptr){
    return tmp;
  }
  else{
    if(tmp->left == nullptr){
      return tmp;
    }
    tmp = tmp->left;
    while(tmp->left != nullptr){
      tmp = tmp->left;
    }
    return tmp;
  }
}

template <typename keyType>
void bst<keyType>::remove(bst<keyType>::bstNode * &root, keyType key){
  bstNode *tmp = find(root, key);
  bstNode *other = tmp;
  if(tmp != nullptr){
    if(tmp->left == nullptr && tmp->right == nullptr){
      tmp = tmp->parent;
      if(tmp != nullptr){
        if(tmp->left == other){
          tmp->left = nullptr;
        }
        else if(tmp->right == other){
          tmp->right = nullptr;
        }
      }
      else{
        tree = nullptr;
      }
      delete other;
    }
    else if(tmp->left == nullptr && tmp->right != nullptr){
      tmp = tmp->parent;
      if(tmp != nullptr){
        if(key < tmp->key){
          tmp->left = other->right;
        }
        else if(key > tmp->key){
          tmp->right = other->right;
        }
      }
      else{
        tree = other->right;
        tree->parent = nullptr;
      }
      delete other;
    }
    else if(tmp->left != nullptr && tmp->right == nullptr){
      tmp = tmp->parent;
      if(tmp != nullptr){
        if(key < tmp->key){
          tmp->left = other->left;
        }
        else if(key > tmp->key){
          tmp->right = other->left;
        }
      }
      else{
        tree = other->left;
        tree->parent = nullptr;
      }
      delete other;
    }
    else{
      bstNode *other2 = predecessor(other);
      other->key = other2->key;
      remove(other2, other2->key);
      count++;
    }
    count--;
  }
}

template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::copy(bst<keyType>::bstNode *root, bst<keyType>::bstNode *parent){
  bstNode *out = nullptr;
  if(root != nullptr){
    out = new bstNode;
    out->parent = parent;
    out->key = root->key;
    out->left = copy(root->left, out);
    out->right = copy(root->right, out);
  }
  return out;
}

template <typename keyType>
void bst<keyType>::clear(bstNode * &root){
  if(tree != nullptr){
    bstNode *izq = root->left;
    bstNode *der = root->right;
    delete root;
    clear(izq);
    clear(der);
  }
}

template <typename keyType>
void bst<keyType>::display(bst<keyType>::bstNode *root, ostream &out, size_t times) const{
  if(root != nullptr){
    if(times < count){
      display(root->left, out, ++times);
      out << root->key << ", ";
      display(root->right, out, ++times);
    }
    else{
      cout << root->key;
    }
  }
}

template <typename keyType>
void bst<keyType>::insert(bst<keyType>::bstNode * &root, keyType key, bst<keyType>::bstNode *parent){
  if(root == nullptr){
    root = new bstNode;
    root->key = key;
    root->parent = parent;
    root->left = nullptr;
    root->right = nullptr;
  }
  else{
    if(key < root->key){
      insert(root->left, key, root);
    }
    else if(key > root->key){
      insert(root->right, key, root);
    }
  }
}

template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::find(bst<keyType>::bstNode *root, keyType key) const{
  if(root == nullptr){
    return nullptr;
  }
  else{
    if(key == root->key){
      return root;
    }
    else if(key < root->key){
      return find(root->left, key);
    }
    else{
      return find(root->right, key);
    }
  }
}

template <typename keyType>
bst<keyType>::bst(){
  tree = nullptr;
  count = 0;
}

template <typename keyType>
bst<keyType>::bst(const bst &rhs){
  tree = copy(rhs.tree, nullptr);
  count = rhs.count;
}

template <typename keyType>
bst<keyType>::~bst(){
  clear();
}

template <typename keyType>
void bst<keyType>::remove(keyType key){
  remove(tree, key);
}

template <typename keyType>
bool bst<keyType>::empty(void) const{
  return count == 0;
}

template <typename keyType>
void bst<keyType>::clear(void){
  clear(tree);
  tree = nullptr;
  count = 0;
}

template <typename keyType>
bool bst<keyType>::find(keyType key) const{
  if(find(tree, key) == nullptr){
    return false;
  }
  else{
    return true;
  }
}

template <typename keyType>
void bst<keyType>::insert(keyType key){
  insert(tree, key, nullptr);
  count++;
}

template <typename keyType>
void bst<keyType>::display(ostream & out) const{
  cout << "[";
  display(tree, out, 1);
  cout << "]" << endl;
}

#endif //_bst_hpp_
