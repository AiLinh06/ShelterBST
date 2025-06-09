// AiLinh
// header file for ShelterBST

#include <iostream>
using namespace std;

#ifndef SHELTERBST_H
#define SHELTERBST_H

class ShelterBST{

 private:
  struct Pet {
    string name;
    int age;
    
    
    Pet( string pName, int pAge){
      name = pName;
      age = pAge;
    }
  };

  struct TreeNode {
    Pet* pet;
    TreeNode* left;
    TreeNode* right;
  };

  TreeNode* root;

  TreeNode* insert(TreeNode * &root, Pet* pet);

  TreeNode* search(TreeNode *root, string name);

  void inorder(TreeNode * root);

  void preorder(TreeNode * root);

  void postorder(TreeNode * root);

  TreeNode* findParent (TreeNode * root, string name, TreeNode* parent);

  TreeNode* predecessor (TreeNode * root, string name);

  int numNode(TreeNode * root);

  int internalNode(TreeNode * root);

  int nodeAtGivenLevel (TreeNode * root, int level, int stage);

  int height (TreeNode * root);

  bool isBalanced (TreeNode * root);

  TreeNode* deleteOne (TreeNode * &root, string name);

  TreeNode* destroy( TreeNode * &root);
  
 public:

  ShelterBST();
  
  void insertPet(string name, int age);
  
  void searchPet(string name);
  
  void inorderDisplay();
  
  void preorderDisplay();
  
  void postorderDisplay();
  
  void parentNodeDisplay(string name);

  void predecessorDisplay(string name);

  void numNodeDisplay();

  void internalNodeDisplay();

  void nodeAtGivenLevelDisplay(int level);

  void heightDisplay();

  void checkBalance();

  void delOneDisplay(string name);

  void destroyDisplay();

  void testFunction();
  
};

#endif
