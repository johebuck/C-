/*
John Buckeley and Alex Schuck
04/16/15
bst.h file
This is the header file for the bst class
*/

#ifndef BST_H
#define BST_H
#include "node.h"
#include <fstream>

using namespace std;

class bst{
 private:
  Node *root;

  void destructorHelper(Node* current);
  /*
    Purpose: Recursive function to be called by the destructor; makes a recursive call to the left and right child of the current node before deleting the current node and returning
    Arguments:
      Node* current - a Node pointer to the current node
    Returns: N/A
   */

  void setHelper(Node*& current, string new_key, int new_data);
  /*
    Purpose: Recursive function to be called by the set function; compares the given key to that of the current node, the either assigns its data to that node or moves to one of its children. If a null pointer is reached, the function creates a new node with the given key and data
    Arguments:
      Node*& current - A reference to a pointer to the current node, reassigned in the case of a new node
      string new_key - a string containing the key to assign data to
      int new_data - An integer value to be assigned to the the matching/new node
    Returns: N/A
   */

  int findHelper(Node* current, string find_key);
  /*
    Purpose: A recursive function to be called by the find function; compares the given key to that of the current node, then either returns the node's data in the case of a match or makes a recursive call to the left or right child. Returns 0 if current is null.
    Arguments:
      Node* current - a pointer to the current node
      string find_key - a string containing the key to return data from
    Returns: an integer value matching the data of the node matching the target key or a 0 if the node does not exist
   */

  void printHelper(Node* current);
  /*
    Purpose: A recursive function to be called by the print function; makes a recursive call to the left child of the current node, prints the current node's values, and then makes a recursive call to the right child before returning. If current is null, the function returns immediately.
    Arguments:
      Node* current - A pointer to the current node
    Returns: N/A
   */

  void minHelper(Node* current);
  /*
    Purpose: A recursive function to be called by the min function; checks that the current node has a left child, then makes a recursive call to that left child if it exists. Otherwise, it prints the current node's values and returns.
    Arguments:
      Node* current - a pointer to the current node
    Returns: N/A
   */

  void maxHelper(Node* current);
  /*
    Purpose: A recursive function to be called by the max function; checks that the current node has a right child, then makes a recursive call to that right child if it exists. Otherwise, it prints the current node's values and returns.
    Arguments:
      Node* current - a pointer to the current node
    Returns: N/A
   */

  void saveHelper(Node* current, ostream &ofile);
  /*
    Purpose: A recursive function to be called by the save function; makes a recursive call to the current node's left child, sends the current node's values to the stream, then makes a recursive call to the right child. If current is null, the function returns.
    Arguments:
      Node* current - a pointer to the current node
      ostream &ofile - a reference to the stream containing the file to save to
    Returns: N/A
   */

  void removeHelper(Node*& current, string target_key);
  /*
    Purpose: A recursive function to be called by the remove function; attempts to locate the node with a key matching the target key, and if it finds one, deletes those values in the tree after ensuring the order of the tree.
    Arguments:
      Node*& current - a reference to a pointer to the current node, from the parent node
      string target_key - a string which matches the key of the node to be removed
    Returns: N/A
   */

 public:
  bst();
  /*
    Purpose: Default constructor; sets root to null
    Arguments: N/A
   */

  ~bst();
  /*
    Purpose: Default destructor; makes a call to destructorHelper on root
    Arguments: N/A
   */

  void set(string new_key, int new_data);
  /*
    Purpose: Used to add a new node to the tree (or overwrite a matching one). Makes a call to setHelper on root, passing in the given arguments.
    Arguments:
      string new_key - a string containing the key to be added to the tree
      int new_data - an integer value to be assigned to the node
    Returns: N/A
   */

  int find(string find_key);
  /*
    Purpose: Used to return the data value of a node with a key matching the given argument. Makes a call to findHelper on root, passing in find_key, and returns the return value of that function.
    Arguments:
      string find_key - a string containing the key of the node to return data from
    Returns: an integer matching the data value in the node with key matching the passed in argument; returns a 0 if the node did not exist
   */

  void print();
  /*
    Purpose: Used to print the contents of the entire tree, key and data of each node. Makes a call to printHelper on root.
    Arguments: None.
    Returns: N/A
   */

  void min();
  /*
    Purpose: Used to find the node with the smallest key. Makes a call to minHelper on root.
    Arguments: None.
    Returns: N/A
   */

  void max();
  /*
    Purpose: Used to find the node with the largest key. Makes a call to maxHelper on root.
    Arguments: None.
    Returns: N/A
   */

  void save_file(string file_name);
  /*
    Purpose: Used to save the keys and data values of each node in the tree to a plain text file. Opens a stream to a file with name matching the given argument, then makes a call to saveHelper on root, passing in the stream. Finishes by closing the file and returning.
    Arguments:
      string file_name - a string containing the name of the file to save to
    Returns: N/A
   */

  void remove(string target_key);
  /*
    Purpose: Used to remove a node from the tree. Makes a call to removeHelper on root, passing in the given argument.
    Arguments:
      string target_key - a string containing the key of the node to delete
    Returns: N/A
   */

  int& operator[] (string in_key);
  /*
    Purpose: Operator overload for the bracket operator. Returns a reference to the data value of the node with key matching the given argument, creating one if necessary.
    Arguments:
      string in_key - a string with the key of the node to return the data value of
    Returns: a reference to the data member of the node with key matchign the given argument
   */

};

#endif
