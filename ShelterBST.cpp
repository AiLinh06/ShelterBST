// AiLinh
// ShelterBST.cpp

#include <iostream>
#include <stdlib.h>
#include "ShelterBST.h"
#include <string>
using namespace std;

ShelterBST:: ShelterBST(){
  root = nullptr;
}



ShelterBST::TreeNode* ShelterBST::insert(TreeNode * &root, Pet* pet) {
    
  if (root == nullptr){
    TreeNode* newNode = new TreeNode();   
    newNode->pet = pet;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
  }

  if (root->pet->name == pet->name){
    cout << endl << "Duplicate" << endl;
    return root;
  }
  
  if ( pet->name < root->pet->name ){
    root->left = insert(root->left, pet);
  }
  else {
    root->right = insert( root->right, pet);
  }

  return root;
  
}

ShelterBST::TreeNode* ShelterBST::search(TreeNode *root, string name) {
  
  if ( root == nullptr || root->pet->name == name){
    return root;
  }
  else if ( name > root->pet->name){
    return search(root->right, name);
  }
  else {
    return search( root->left, name);
  }
  
}

void ShelterBST:: inorder(TreeNode * root) {
  
  if ( root == nullptr){
    return;
  }
  inorder(root->left);
  cout << root->pet->name << ": " << root->pet->age << endl;
  inorder(root->right);
}


void ShelterBST:: preorder(TreeNode * root) {
  
  if ( root == nullptr){
    return;
  }
  cout << root->pet->name << ": " << root->pet->age << endl;
  preorder(root->left);
  preorder(root->right);
  
}

void ShelterBST:: postorder(TreeNode * root) {
  
  if (root == nullptr){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->pet->name << ": " << root->pet->age << endl;
}

ShelterBST:: TreeNode* ShelterBST::findParent(TreeNode * root, string name,
                                              TreeNode * parent){
  
  if (root == nullptr){
    return root;
  }
  
  if (root->pet->name == name){
    return parent;
  }
  
  TreeNode * leftSearch = findParent( root->left, name, root);
  
  if ( leftSearch != nullptr){
    return leftSearch;
  }
  
  return findParent(root->right, name, root);
    
}


ShelterBST:: TreeNode* ShelterBST:: predecessor(TreeNode * root, string name){
  
  TreeNode * pred = nullptr;
  TreeNode * curr = root;
  
  
  while ( curr != nullptr){
    
    if ( name < curr->pet->name){
      
      curr = curr->left;
    }
    else if ( name > curr->pet->name){
      curr = curr->right;
    }
    else {
      
      if ( curr->left != nullptr && curr->right != nullptr){
        pred = curr->left;
        
        while ( pred->right != nullptr){
          pred = pred->right;
        }
        return pred;
      }
      else {
        return nullptr; 
      }
      
    }
  } 
  
  return nullptr;
}

int ShelterBST:: numNode( TreeNode * root){

  if ( root == nullptr){
    return 0;
  }

  int nLeft = numNode(root->left);
  int nRight = numNode(root->right);

  return 1+ nLeft + nRight;
}

int ShelterBST:: internalNode ( TreeNode * root){

  if ( root == nullptr || ( root->left == nullptr && root->right == nullptr)){
    return 0;
  }

 
  return 1+ internalNode(root->left) + internalNode(root->right);
 
}

int ShelterBST::nodeAtGivenLevel (TreeNode * root, int level, int currLevel){

  if ( root == nullptr){
    return 0;
  }

  if ( level == currLevel){
    return 1;
  }
  else {
    return nodeAtGivenLevel(root->left,level,currLevel+1) + nodeAtGivenLevel(root->right,level,currLevel+1);
  }

}

int ShelterBST:: height (TreeNode * root){
  if (root == nullptr){
    return -1;
  }

  int leftH = height(root->left);
  int rightH = height(root->right);

  return 1+max(leftH, rightH) ;
}

bool ShelterBST::isBalanced (TreeNode * root){
  if ( root == nullptr){
    return true;
  }

  int leftH =  height(root->left);
  int rightH = height(root->right);

  if ( abs(leftH - rightH) > 1){
    return false;
  }

  return isBalanced(root->left) && isBalanced(root->right);
}

ShelterBST::TreeNode* ShelterBST:: deleteOne (TreeNode* &root, string name){

  if ( root == nullptr){
    cout << "No pet in BST" << endl;
    return nullptr;
  }

  if ( root->pet->name > name){
    root->left = deleteOne( root->left, name);
  }
  else if ( root->pet->name < name){
    root->right = deleteOne( root->right, name);
  }
  else {

    if ( root->left == nullptr){
      TreeNode* temp = root->right;
      delete root->pet;
      delete root;
      root = nullptr;
      return temp;
    }
    else if ( root->right == nullptr){
      TreeNode* temp = root->left;
      delete root->pet;
      delete root;
      root = nullptr;
      return temp;
    }
    else {
      TreeNode* pre = predecessor(root, name);
      Pet* temp  = new Pet( *pre->pet);
      delete root->pet;
      root->pet = temp;
      root->left = deleteOne(root->left, pre->pet->name);
    }
    
  }
  return root;
  
}

ShelterBST::TreeNode* ShelterBST:: destroy( TreeNode * &root){

  if ( root == nullptr){
    return nullptr;
  }

  destroy( root->left);
  destroy( root->right);

  delete root->pet;
  delete root;
  
  return nullptr;

}


void ShelterBST:: insertPet(string name, int age){
  Pet* newPet =  new Pet(name, age);
  root = insert(root, newPet);
  cout << endl <<"Complete" << endl;

}


void ShelterBST::searchPet(string name){
  TreeNode* result  = search(root, name);
  // display name of pet found or
  // message if not found

  if ( result == nullptr){
    cout << endl << endl << "Pet is not found." << endl << endl;
  }
  else {
    cout << endl << endl;
    cout << result->pet->name << ": " << result->pet->age;
    cout << endl << endl;
  }
}



void ShelterBST::inorderDisplay(){
  if (root == nullptr){
    cout <<"There is nothing to print" << endl;
  }
  else {
    inorder(root);
  }
}

void ShelterBST:: preorderDisplay(){
  if (root == nullptr){
    cout <<"There is nothing to print" << endl;
  }
  else{
    preorder(root);
  }
}

void ShelterBST::postorderDisplay(){
  if (root == nullptr){
    cout <<"There is nothing to print" << endl;
  }
  else{
    postorder(root);
  }
}


void ShelterBST:: predecessorDisplay( string name){
  TreeNode* temp = predecessor(root, name);
  if ( temp == nullptr){
    cout << "No predecessor" << endl;
  }
  else {
    cout << temp->pet->name <<": " <<  temp->pet->age << endl;
  }
}

void ShelterBST:: parentNodeDisplay(string name){
  TreeNode* temp = findParent(root, name, nullptr);
  if ( temp == nullptr){
    cout << "No parent" << endl;
  }
  else {
    cout << temp->pet->name <<": " <<  temp->pet->age << endl;
  }
}
void ShelterBST:: numNodeDisplay(){
  cout << numNode(root) << endl;
}

void ShelterBST:: internalNodeDisplay(){
  cout << internalNode(root) << endl;
}

void ShelterBST:: nodeAtGivenLevelDisplay(int level){
  cout << nodeAtGivenLevel(root, level,0) << endl;
}

void ShelterBST:: heightDisplay(){
  cout << height(root) << endl;
}

void ShelterBST:: checkBalance(){
  if (isBalanced(root)){
    cout << " Tree is balanced " << endl;
  }
  else {
    cout << "Tree is unbalanced" << endl;
  }
}

void ShelterBST:: delOneDisplay(string name){
  deleteOne(root,name);
  cout << endl <<"Complete"<< endl;
}

void ShelterBST::destroyDisplay(){

  if (destroy(root) == nullptr){
    cout << endl <<"Destroy tree" << endl;
  }
  root = nullptr;
}

void ShelterBST:: testFunction(){
  cout << endl <<"Testing insert function..." << endl << endl;
  cout << " Insert pet's name Eren, age 11 ...";  
  insertPet("Eren", 11);
  
  cout << " Insert pet's name Adam, age 5 ...";
  insertPet( "Adam", 5);
  
  cout << " Insert pet's name Seola, age 8 ...";
  insertPet( "Seola", 8);

  cout << " Insert pet's name Booh, age 3 ...";
  insertPet("Booh", 3);

  cout << " Insert pet's name Nany, age 12 ...";
  insertPet( "Nany", 12);

  cout << " Insert pet's name Zona, age 2 ...";
  insertPet( "Zona", 2);

  cout << endl << endl ;
  cout << "Inorder display: " << endl << endl;
  inorderDisplay();

  cout << endl;
  cout << "Preorder display: " << endl << endl;
  preorderDisplay();

  cout << endl;
  cout << "Postorder display: " << endl << endl;
  postorderDisplay();

  cout << endl << "Succesful search (name: Adam):" << endl;
  searchPet("Adam");
  cout << endl;

  cout << endl << "Unsuccesful search (name: Leona):" << endl;
  searchPet("Leona");
  cout << endl << endl;

  cout << "Find parent node of pet's name Nany:" << endl;
  parentNodeDisplay("Nany");
  cout << endl;

  cout << "Find parent node of pet's name Eren (root):" << endl;
  parentNodeDisplay("Eren");
  cout << endl << endl;

  cout << "Number of nodes: " << endl;
  numNodeDisplay();
  cout << endl << endl;

  cout << "Number of internal nodes: " << endl;
  internalNodeDisplay();
  cout << endl << endl;

  cout << "Numbers of nodes at a given level (level 1): " << endl;
  nodeAtGivenLevelDisplay(1);
  cout << endl << endl;

  cout << "Height of the tree:" << endl;
  heightDisplay();
  cout << endl << endl;

  cout << "Check balance: " << endl;
  checkBalance();
  cout << endl << endl;


  cout << "Delete a node: (name: Seola)" << endl;
  delOneDisplay("Seola");
  cout << endl << endl;

  cout << "Inorder display: " << endl << endl;
  inorderDisplay();
  cout << endl << endl;

  cout << "Number of nodes: " << endl;
  numNodeDisplay();
  cout << endl << endl;

  cout << "Delete entire tree: " << endl;
  destroyDisplay();
  cout << endl << endl;

  cout << "Number of nodes: " << endl;
  numNodeDisplay();
  cout << endl << endl;

}
