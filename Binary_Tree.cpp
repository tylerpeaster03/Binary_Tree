/*
Tyler Peaster
*/

#include <iostream>

struct TreeNode
{
    //Nodes that store a value and have left/right pointers
    int value{};
    TreeNode* left;
    TreeNode* right;

    TreeNode() { left = right = nullptr; } //Initalize the variables in construct
};

class BinaryTree
{
private:
    
public:
    TreeNode* GrabNewNode(int value)
    {
        TreeNode* newNode = new TreeNode(); //Allocate memory for new node
        newNode->value = value; //Set newNode to value
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    TreeNode* TreeInsert(TreeNode* root, int value)
    {
        if (root == nullptr)   //For when there is no root
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
        if (root == nullptr)
            return -1;

        int leftHeight, rightHeight;
        leftHeight = treeHeight(root->left);    //Finds height of left subree
        rightHeight = treeHeight(root->right);  //Finds height of right subtree

        if (leftHeight > rightHeight)   //Outputs the greater height of the two subtrees
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }

    void Inorder(TreeNode* root) {
        if (root == nullptr) //Will return when there are no more nodes in subtree
            return;

        Inorder(root->left);    //Searches left subtree   
        std::cout << root->value << " ";
        Inorder(root->right);   //Searches right subtree      
    }

};


int main()
{
    BinaryTree tree;
    TreeNode* root = nullptr;

    //Inserting values
    root = tree.TreeInsert(root, 8);
    root = tree.TreeInsert(root, 3);
    root = tree.TreeInsert(root, 10);
    root = tree.TreeInsert(root, 1);
    root = tree.TreeInsert(root, 6);
    root = tree.TreeInsert(root, 14);
    root = tree.TreeInsert(root, 4);
    root = tree.TreeInsert(root, 7);
    root = tree.TreeInsert(root, 13);

    //Finding tree height
    int treeHeight = tree.treeHeight(root);
    std::cout << "Height of the tree: " << treeHeight << std::endl;

    //Print nodes inorder
    std::cout << "Inorder: ";
    tree.Inorder(root);
    std::cout << "\n";
}