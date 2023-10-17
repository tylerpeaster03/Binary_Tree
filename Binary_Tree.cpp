/*
Tyler Peaster
*/

#include <iostream>

struct TreeNode
{
    int value{};
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree
{
private:
    
public:
    TreeNode* GrabNewNode(int value)
    {
        TreeNode* newNode = new TreeNode();
        newNode->value = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    TreeNode* TreeInsert(TreeNode* root, int value)
    {
        //Handles if tree is empty
        if (root == NULL)
        {
            root = GrabNewNode(value);
            return root;
        }
        else if (value <= root->value)
        {
            root->left = TreeInsert(root->left, value);
        }
        else
        {
            root->right = TreeInsert(root->right, value);
        }
        return root;
    }

    int treeHeight(TreeNode* root)
    {
        if (root == NULL)
            return -1;

        int leftHeight, rightHeight;
        leftHeight = treeHeight(root->left);
        rightHeight = treeHeight(root->right);

        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }

    void Inorder(TreeNode* root) {
        if (root == NULL) 
            return;

        Inorder(root->left);       // Visit left subtree
        std::cout << root->value << " ";
        Inorder(root->right);      // Visit right subtree
    }

};



int main()
{
    BinaryTree tree;
    TreeNode* root = NULL;

    root = tree.TreeInsert(root, 8);
    root = tree.TreeInsert(root, 3);
    root = tree.TreeInsert(root, 10);
    root = tree.TreeInsert(root, 1);
    root = tree.TreeInsert(root, 6);
    root = tree.TreeInsert(root, 14);
    root = tree.TreeInsert(root, 4);
    root = tree.TreeInsert(root, 7);
    root = tree.TreeInsert(root, 13);

    int treeHeight = tree.treeHeight(root);
    std::cout << "Height of the tree: " << treeHeight << std::endl;

    //Print Nodes in Inorder
    std::cout << "Inorder: ";
    tree.Inorder(root);
    std::cout << "\n";
}