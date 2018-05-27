/*
John Buckeley and Alex Schuck
04/16/15
node.cpp file
This is the cpp file containing the implementions to functions for the node class.
*/

#include "node.h"

using namespace std;

Node::Node(string new_key){
  left = NULL;
  right = NULL;
  key = new_key;
  data = 0;
}

void Node::reassign(string new_key, int new_data){
  key = new_key;
  data = new_data;
}

void Node::insert(int new_data){
  data = new_data;
}

string Node::get_key(){
  return key;
}

int& Node::get_data(){
  return data;
}

Node*& Node::left_child(){
  return left;
}

Node*& Node::right_child(){
  return right;
}
