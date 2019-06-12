//
//  bst.cpp
//  aug_bst
//  Created by Julian Rincon on 2018-11-18.
//

#ifdef bst_hpp

template <typename keyType>
bst<keyType>::bst() {
    tree = nullptr;
    count = 0;
}


template <typename keyType>
bst<keyType>::~bst() {
    clear();
}

template <typename keyType>
int bst<keyType>::size() const{
  return size(tree);
}

template <typename keyType>
int bst<keyType>::size(bstNode * tmp) const{
  if(tmp->left == nullptr && tmp->right == nullptr){
    return 1;
  }
  else if(tmp->left == nullptr && tmp->right != nullptr){
    return 1 + size(tmp->right);
  }
  else if(tmp->left != nullptr && tmp->right == nullptr){
    return 1 + size(tmp->left);
  }
  else{
    return 1 + size(tmp->left) + size(tmp->right);
  }
}

template <typename keyType>
int bst<keyType>::height() const{
  return height(tree,0);
}

template <typename keyType>
int bst<keyType>::height(bstNode *tmp, int max) const{
  if(tmp->left == nullptr && tmp->right == nullptr){
    return max + 1;
  }
  else if(tmp->left == nullptr && tmp->right != nullptr){
    return height(tmp->right, max + 1);
  }
  else if(tmp->left != nullptr && tmp->right == nullptr){
    return height(tmp->left, max + 1);
  }
  else{
    if(height(tmp->left, max + 1) > height(tmp->right, max + 1)){
      return height(tmp->left, max + 1);
    }
    else{
      return height(tmp->right, max + 1);
    }
  }
}

template <typename keyType>
void bst<keyType>::insert(bstNode * & bush, keyType key) {
    if (bush == nullptr) {
        count++;
        bush = new bstNode;
        bush->key = key;
        bush->left = nullptr;
        bush->right = nullptr;
    } else {
        if (key != bush->key) {
            if (key < bush->key) {
                insert(bush->left, key);
            } else {
                insert(bush->right, key);
            }
        }
    }
}


template <typename keyType>
void bst<keyType>::insert(keyType key) {
    insert(tree, key);
}


template <typename keyType>
void bst<keyType>::remove(bstNode * & bush, keyType key) {
    if (bush == nullptr) return;

    if (key < bush->key) {
        remove(bush->left, key);
    } else if (key > bush->key) {
        remove(bush->right, key);
    } else if (bush->left == nullptr) {
        bstNode *tmp = bush;
        bush = bush->right;
        delete tmp;
        count--;
    } else if (bush->right == nullptr) {
        bstNode *tmp = bush;
        bush = bush->left;
        delete tmp;
        count--;
    } else if (bush->left != nullptr && bush->right != nullptr) {
        bush->key = min(bush->right)->key;
        remove(bush->right, bush->key);
    }
}


template <typename keyType>
void bst<keyType>::remove(keyType key) {
    remove(tree, key);
}


template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::find(bstNode * bush, keyType key) const {
    if (bush == nullptr) return nullptr;
    if (key == bush->key) return bush;

    if (key < bush->key) {
        return find(bush->left, key);
    } else {
        return find(bush->right, key);
    }
}


template <typename keyType>
bool bst<keyType>::find(keyType key) const {
    if (find(tree, key) != nullptr) {
        return true;
    } else {
        return false;
    }
}


template <typename keyType>
void bst<keyType>::display(bstNode * bush, std::ostream & out) const {
    if (bush != nullptr) {
        display(bush->left, out);
        out << "key: " << bush->key << std::endl;
        display(bush->right, out);
    }
}


template <typename keyType>
void bst<keyType>::display(std::ostream & out) const {
    out << "Tree " << tree << " nodes: " << count << std::endl;
    out << "This is the size of the tree: " << size() << std::endl;
    out << "This is the height of the tree: " << height() << std::endl;
    display(tree, out);
}


template <typename keyType>
void bst<keyType>::clear(bstNode * & bush) {
    if (bush != nullptr) {
        clear(bush->left);
        clear(bush->right);
        delete bush;
        count--;
    }
    bush = nullptr;
}


template <typename keyType>
void bst<keyType>::clear(void) {
    clear(tree);
}


template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::min(bstNode *bush) const {
    if (bush == nullptr) {
        return nullptr;
    } else {
        return bush->left == nullptr ? bush : min(bush->left);
    }
}


#endif /* bst_hpp */
