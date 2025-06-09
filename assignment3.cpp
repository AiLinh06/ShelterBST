// AiLinh
// assignment3.cpp

#include <iostream>
#include "ShelterBST.h"
using namespace std;

void menu();
void generate(int choice, ShelterBST& tree);

int main(){
  int choice;
  ShelterBST tree;
  menu();
  cin >> choice;
  while ( choice > 0 && choice < 16){
    generate(choice, tree);
    menu();
    cin >> choice;
  }

  cout << endl << endl << "Thank you and Goodbye" << endl;
  return 0;
}

void menu(){
  
  cout << endl << endl << "Welcome to my implementation of BST" << endl;
  cout << "Please choose the operation you want: " << endl;
  cout << "1.  Insert a node" << endl;
  cout << "2.  Search a value" << endl;
  cout << "3.  Delete a node" << endl;
  cout << "4.  Print in order" << endl;
  cout << "5.  Print pre order" << endl;
  cout << "6.  Print post order" << endl;
  cout << "7.  Find the parent node" << endl;
  cout << "8.  Find the predecessor" << endl;
  cout << "9.  Find the number of node" << endl;
  cout << "10. Find the number of internal node" << endl;
  cout << "11. Find the number of nodes at a given level" << endl;
  cout << "12. Find the height of tree" << endl;
  cout << "13. Check balance" << endl;
  cout << "14. Delete entire tree" << endl;
  cout << "15. Test function" << endl;
  cout << "16. Exit" << endl << endl;
}


void generate( int choice, ShelterBST& tree){

  int num;
  string name;
  
  switch(choice){

  case 1:
    cout << "Insert a node." << endl;
    cout <<"Please enter the pet's name: ";
    cin >> name;
    cout << "Please enter the pet's age: ";
    cin >> num;
    tree.insertPet(name,num);
    break;

  case 2:
    cout << "Search a value" << endl;
    cout << "Enter the pet's name to search: " ;
    cin >> name;
    tree.searchPet(name);
    break;

  case 3:
    cout << "Delete a node" << endl;
    cout << "Enter the pet's name to delete: ";
    cin >> name;
    // call function to delete
    tree.delOneDisplay(name);
    break;


  case 4:
    cout << "Print in order" << endl;
    tree.inorderDisplay();
    break;

  case 5:
    cout << "Print pre order" << endl;
    tree.preorderDisplay();
    break;

  case 6:
    cout << "Print post order" << endl;
    tree.postorderDisplay();
    break;

  case 7:
    cout << "Find the parent node" << endl;
    cout << "Enter the pet's name to find parent: ";
    cin >> name;
    // call function
    tree.parentNodeDisplay(name);
    break;

  case 8:
    cout <<"Find the predecessor" << endl;
    cout << "Enter the pet's name to find predecessor: ";
    cin >> name;
    // call function
    tree.predecessorDisplay(name);
    break;

  case 9:
    cout <<"Find the number of node" << endl;
    // call function
    tree.numNodeDisplay();
    break;

  case 10:
    cout <<"Find the number of internal node" << endl;
    // call function
    tree.internalNodeDisplay();
    break;

  case 11:
    cout <<"Find the number of nodes at a given level" << endl;
    cout <<"Enter level: ";
    cin >> num;
    tree.nodeAtGivenLevelDisplay(num);
    break;
    
  case 12:
    cout <<"Height of tree" << endl;
    // call funtion
    tree.heightDisplay();
    break;

  case 13:
    cout << "Check balance" << endl;
    // call funtion
    tree.checkBalance();
    break;

  case 14:
    cout <<"Delete entire tree" << endl;
    // call function
    tree.destroyDisplay();
    break;

  case 15:
    cout << "Testing ..." << endl;
    // call funtion
    tree.testFunction();
    break;
    
  }
  
}
