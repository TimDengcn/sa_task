#include "tree.h"
#include <malloc.h>
#include <iostream>

root tree_create(int data_root) {
  root newtree = (root)malloc(sizeof(node));
  newtree->data = data_root;
  newtree->left = nullptr;
  newtree->right = nullptr;
  return newtree;
}

root tree_delete(root treeroot, int data) {
  if (treeroot->data == data) {
    node *nownode = treeroot->right;
    while (nownode->left != nullptr) {
      nownode = nownode->left;
    }
    nownode->left = treeroot->left;
    root newroot = treeroot->right;
    free(treeroot);
    return newroot;
  }

  node *targetnode = tree_search_pre(treeroot, data);
  if (targetnode != nullptr) {
    if (data > targetnode->data) {
      if (targetnode->right->left == nullptr &&
          targetnode->right->right == nullptr) {
        free(targetnode->right);
        targetnode->right = nullptr;
      } else if (targetnode->right->left != nullptr &&
                 targetnode->right->right != nullptr) {
        node *nownode = targetnode->right->right;
        while (nownode->left != nullptr) {
          nownode = nownode->left;
        }
        nownode->left = targetnode->right->left;
        node *nodetodelete = targetnode->right;
        targetnode->right = targetnode->right->right;
        free(nodetodelete);
      } else if (targetnode->right->left != nullptr) {
        node *nodetodelete = targetnode->right;
        targetnode->right = targetnode->right->left;
        free(nodetodelete);
      } else {
        node *nodetodelete = targetnode->right;
        targetnode->right = targetnode->right->right;
        free(nodetodelete);
      }
    } else {
      if (targetnode->left->left == nullptr &&
          targetnode->left->right == nullptr) {
        free(targetnode->left);
        targetnode->left = nullptr;
      } else if (targetnode->left->left != nullptr &&
                 targetnode->left->right != nullptr) {
        node *nownode = targetnode->left->right;
        while (nownode->left != nullptr) {
          nownode = nownode->left;
        }
        nownode->left = targetnode->left->left;
        node *nodetodelete = targetnode->left;
        targetnode->left = targetnode->left->right;
        free(nodetodelete);
      } else if (targetnode->left->left != nullptr) {
        node *nodetodelete = targetnode->left;
        targetnode->left = targetnode->left->left;
        free(nodetodelete);
      } else {
        node *nodetodelete = targetnode->left;
        targetnode->left = targetnode->left->right;
        free(nodetodelete);
      }
    }
  }
  return treeroot;
}

void tree_destory(root treenode) {
  if (treenode->left != nullptr) {
    tree_destory(treenode->left);
    treenode->left = nullptr;
  }
  if (treenode->right != nullptr) {
    tree_destory(treenode->right);
    treenode->right = nullptr;
  }

  free(treenode);
}

void tree_insert(root nownode, int data) {
  if (data < nownode->data) {
    if (nownode->left != nullptr) {
      tree_insert(nownode->left, data);
    } else {
      node *newnode = (root)malloc(sizeof(node));
      newnode->data = data;
      newnode->left = nullptr;
      newnode->right = nullptr;
      nownode->left = newnode;
    }
  } else if (data > nownode->data) {
    if (nownode->right != nullptr) {
      tree_insert(nownode->right, data);
    } else {
      node *newnode = (root)malloc(sizeof(node));
      newnode->data = data;
      newnode->left = nullptr;
      newnode->right = nullptr;
      nownode->right = newnode;
    }
  }
}

node *tree_search(root nownode, int data) {
  if (data == nownode->data) {
    return nownode;
  } else if (data < nownode->data) {
    if (nownode->left == nullptr) {
      return nullptr;
    } else {
      return tree_search(nownode->left, data);
    }
  } else if (data > nownode->data) {
    if (nownode->right == nullptr) {
      return nullptr;
    } else {
      return tree_search(nownode->right, data);
    }
  }
  return nullptr;
}

node *tree_search_pre(root nownode, int data) {
  if (nownode->left != nullptr) {
    if (nownode->left->data == data) return nownode;
  }
  if (nownode->right != nullptr) {
    if (nownode->right->data == data) return nownode;
  }
  if (data < nownode->data) {
    if (nownode->left == nullptr) {
      return nullptr;
    } else {
      return tree_search_pre(nownode->left, data);
    }
  } else if (data > nownode->data) {
    if (nownode->right == nullptr) {
      return nullptr;
    } else {
      return tree_search_pre(nownode->right, data);
    }
  }
  return nullptr;
}

int main() {
  root mytree = tree_create(10);
  tree_insert(mytree, 5);
  tree_insert(mytree, 7);
  tree_insert(mytree, 1);
  tree_insert(mytree, 8);
  tree_insert(mytree, 22);
  tree_insert(mytree, 12);
  tree_insert(mytree, 5);
  tree_insert(mytree, 30);
  tree_insert(mytree, 23);
  tree_insert(mytree, 3);
  tree_insert(mytree, 4);
  tree_insert(mytree, 11);
  tree_insert(mytree, 14);
  tree_insert(mytree, 6);
  tree_insert(mytree, 13);

  node *rsnode;
  rsnode = tree_search(mytree, 8);

  std::cout << rsnode->data << std::endl;

  mytree = tree_delete(mytree, 5);

  tree_destory(mytree);

  return 0;
}