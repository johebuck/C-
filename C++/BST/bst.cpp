/*
John Buckeley and Alex Schuck
04/16/15
bst.cpp file
This is the cpp file containing the implementations for the bst class
*/

#include "bst.h"
#include <iostream>
#include <fstream>

using namespace std;

bst::bst(){
  root = NULL;
}

bst::~bst(){
  destructorHelper(root);
}

void bst::destructorHelper(Node *current){
  if(current==NULL)
    return;
  destructorHelper(current->left_child());
  destructorHelper(current->right_child());
  delete current;
  return;
}

void bst::set(string new_key, int new_data){
  setHelper(root, new_key, new_data);
}

void bst::setHelper(Node*& current, string new_key, int new_data){
  if(current==NULL){
    current = new Node(new_key);
    current -> insert(new_data);
  }
  else if(current->get_key() == new_key){
    current -> insert(new_data);
  }
  else{
    if(new_key.compare(current->get_key())>0){
      //Move right
      setHelper(current->right_child(),new_key,new_data);
    }
    else{
      //Move left
      setHelper(current->left_child(),new_key,new_data);
    }
  }
}

int bst::find(string find_key){
  int value = 0;
  value = findHelper(root, find_key);
  return value;
}

int bst::findHelper(Node *current, string find_key){
  if(current==NULL)
    return 0;
  if(current->get_key() == find_key){
    return current -> get_data();
  }
  else{
    if(find_key.compare(current->get_key())>0){
	//Search right
	return findHelper(current->right_child(),find_key);
      }
      else{
	//Search left
	return findHelper(current->left_child(),find_key);
      }
  } 
}
void bst::print(){
  cout << "The contents of the tree are:" << endl;
  printHelper(root);
  cout << endl;
}

void bst::printHelper(Node* current){
  if(current==NULL)
    return;
  printHelper(current->left_child());
  cout << current->get_key() << " : " << current->get_data() << endl;
  printHelper(current->right_child());
  return;
}

void bst::min(){
  if(root==NULL)
    cout << "The tree is empty." << endl;
  else
    minHelper(root);
}

void bst::minHelper(Node *current){
  if(current->left_child()==NULL)
    cout << "The minumum is " << current->get_key() << " : " << current->get_data() << endl;
  else
    minHelper(current->left_child());
}

void bst::max(){
  if(root==NULL)
    cout << "The tree is empty." << endl;
  else
    maxHelper(root);
}

void bst::maxHelper(Node *current){
  if(current->right_child()==NULL)
    cout << "The maximum is " << current->get_key() << " : " << current->get_data() << endl;
  else
    maxHelper(current->right_child());
}

void bst::save_file(string file_name){
  ofstream ofile;
  cout << "Saving to file " << file_name << "...";
  ofile.open(file_name.c_str());
  saveHelper(root,ofile);
  ofile.close();
  cout << " Done." << endl;
}

void bst::saveHelper(Node* current, ostream &ofile){
  if(current==NULL)
    return;
  else{
    saveHelper(current->left_child(),ofile);
    ofile << current->get_key() << " : " << current->get_data() << endl;
    saveHelper(current->right_child(),ofile);
    return;
  }
}

void bst::remove(string target_key){
  removeHelper(root, target_key);
}

void bst::removeHelper(Node*& current, string target_key){
  if(current==NULL){
    return;
  }
  if(target_key.compare(current->get_key())>0){
    //Go right
    removeHelper(current->right_child(),target_key);
    return;
  }
  if(target_key.compare(current->get_key())<0){
    //Go left
    removeHelper(current->left_child(),target_key);
    return;
  }
  if(current->left_child()==NULL){
    //Reroute current to left child and delete this node
    Node *temp = current;
    current = current->left_child();
    delete current;
    return;
  }
  if(current->right_child()==NULL){
    //Do like above
    Node *temp = current;
    current = current->right_child();
    delete current;
    return;
  }
  
  //The big one
  Node *temp = current->left_child();
  while(temp->right_child()!=NULL){
    temp = temp->right_child();
  }
  current->reassign(temp->get_key(),temp->get_data());
  removeHelper(temp,temp->get_key());
  return;
}

int& bst::operator[] (string in_key){
  Node* current=root;
  int done=0;
  if(current == NULL){
    root = new Node(in_key);
    return current->get_data();
  }
  else if(current->get_key()==in_key){
    return current->get_data();
  }
  else{
    Node* prev=root;
    int wentright = 0;
    while(!done){
      if(current==NULL)
	done=1;
      else if(current->get_key()==in_key)
      done=1;
      else{
	if(in_key.compare(current->get_key())>0){
	  prev = current;
	  wentright = 1;
	  current = current->right_child();
	}
	else{
	  prev = current;
	  wentright = 0;
	  current = current->left_child();
	}
      }
    }
    if(current!=NULL){
      return current->get_data();
    }
    else{
      if(wentright)
	prev->right_child() = new Node(in_key);
      else
	prev->left_child() = new Node(in_key);
      return current->get_data();
    }
    
  }
}
