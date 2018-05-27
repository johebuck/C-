/*
John Buckeley and Alex Schuck
04/16/15
node.h file
This is the header file for the node class
*/

#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node {
 private:
  Node *left, *right;
  string key;
  int data;
 public:
  Node(string new_key);
  /*
    Purpose: constructor
    Arguments:
      string new_key - a string containing the key value
    Returns: N/A
   */

  void reassign(string new_key, int new_data);
  /*
    Purpose: overwriting both a node's values
    Arguments:
      string new_key - a string containing the key value
      int new_data - an integer value to assign to data
    Returns: N/A
   */

  void insert(int new_data);
  /*
    Purpose: inserting new data into the node
    Arguments:
      int new_data - an integer value to assign to the data
    Returns: N/A
   */

  string get_key();
  /*
    Purpose: reading the key of the node
    Arguments: None
    Returns: a string matching the key of the node
   */

  int& get_data();
  /*
    Purpose: reading the data value of the node
    Arguments: None
    Returns: a reference to the data integer stored in the node class
   */

  Node*& left_child();
  /*
    Purpose: returning a pointer to the node's left child to allow access and manipulation
    Arguments: None
    Returns: a reference to the pointer pointing to the left child
   */

  Node*& right_child();
  /*
    Purpose: returning a pointer to the node's right child to allow access and manipulation
    Arguments: None
    Returns: a reference to the pointer pointing to the right child
   */


};

#endif
