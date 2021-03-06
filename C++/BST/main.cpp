/*
John Buckeley and Alex Schuck
04/16/15
main.cpp file
This is the driver for testing the bst class
*/

#include <iostream>
#include <fstream>
#include "bst.h"
#include "node.h"
#include "bst.cpp"
#include "node.cpp"

using namespace std;

int main(){
  int option; 
  bst my_bst;
  
  do{
    cout<<"Welcome to Fun(debatable term to use) with Binary Search Trees. You may select one of the following options:"<<endl;
    cout<<"1.) Read a selection of txt from a file"<<endl;
    cout<<"2.) Take a string and an integer as parameters and stores the pair in the BST."<<endl;
    cout<<"3.) Take a string parameter and return the value already in the BST."<<endl;
    cout<<"4.) Print the contents of the BST."<<endl;
    cout<<"5.) Print the smallest value in the tree."<<endl;
    cout<<"6.) Print the largest value in the tree."<<endl;
    cout<<"7.) Save the file."<<endl;
    cout<<"8.) Remove a string."<<endl;
    cout<<"9.) Quit and go have some REAL fun.(like Bioshock 2)"<<endl;
    cout<<"Please enter your option now: ";
    cin>>option;
    
    if(option==1){
      string infile_name;
      cout << "Enter the file name: ";
      cin >> infile_name;
      cout << "Reading from file: ";
      ifstream infile;
      infile.open(infile_name.c_str());
      
      string current_word;
      infile >> current_word;
      
      while(infile){
	
	//Punctuation sort here
	for(int i=0, length = current_word.size(); i < length; i++){
	  
	  if(ispunct(current_word[i])){
	    current_word.erase(i--,1);
	    length = current_word.size();
	  }
	  else if(isupper(current_word[i])){
	    current_word[i]+=32;
	  }
	}
	
	if(current_word!=""){
	  
	  int current_number = my_bst.find(current_word) + 1;
	  my_bst.set(current_word,current_number);
	}
	
	infile >> current_word;
      }
      
      cout << "Finished. Closing file...";
      infile.close();
      cout << "Done." << endl;
    }

    if(option==2){
      cout << "Enter the key: ";
      string new_key;
      cin >> new_key;
      cout << "Enter the value: ";
      int new_data;
      cin >> new_data;
      my_bst.set(new_key,new_data);
      cout << "Done." << endl;
      
    }

    if(option==3){
      cout << "Enter the key: ";
      string new_key;
      cin >> new_key;
      int x = my_bst.find(new_key);
      cout << "The value of " << new_key << " is " << x << endl;
    }

    if(option==4){
      cout << "Beginning print." << endl;
      my_bst.print();
      cout << "Finished." << endl;
    }

    if(option==5){
      my_bst.min();
    }

    if(option==6){
      my_bst.max();
    }
    
    if(option==7){
      string outfile_name;
      cout << "Enter the file name: ";
      cin >> outfile_name;
      my_bst.save_file(outfile_name);
      cout << "Finished." << endl;
    }
    
    if(option==8){
      cout << "Enter the key: ";
      string find_key;
      cin >> find_key;
      my_bst.remove(find_key);
      cout << "Removed." << endl;
    }
  }
    while(option!=9);
    //The occasional sass to break away from the norm.
    cout<<"Just kidding about Bioshock 2 being fun."<<endl;

    return 0;
  }
