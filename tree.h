typedef struct treenode
{
  int data;
  struct treenode *left;
  struct treenode *right;
} node, *root;

root tree_create(int);
void tree_insert(root, int);
node *tree_search(root, int);
node *tree_search_pre(root, int);
root tree_delete(root, int);
void tree_destory(root);