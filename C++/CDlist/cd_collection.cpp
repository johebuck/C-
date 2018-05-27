/*
Jonathan Wilbert, John Buckley, and Alex Schuck
03/11/15
cd_collection.cpp file
This is the .cpp file for the cd_collection class
*/

#include "cd_collection.h"

using namespace std;


cd_collection::cd_collection(){
  head = NULL;
}

cd_collection::~cd_collection(){
  delete_all(head);
}

void cd_collection::delete_all(cd *currentNode){
  if(currentNode==NULL)
    return;
  delete_all(currentNode -> next);
  delete currentNode;
}

void cd_collection::insert_sorted(string new_artist, string new_album, int new_tracks, int new_release){
  //Exception 1: If the list is empty, create the first node.
  if(head==NULL){
    head = new cd;
    head -> artistName = new_artist;
    head -> albumName = new_album;
    head -> numTracks = new_tracks;
    head -> releaseYear = new_release;
    return;
  }
  //Exception 2: If the first node's name comes after the input node's alphabetically, insert immediately.
  if(new_artist.compare(head->artistName)<0){
    cd *second = head;
    head = new cd;
    head -> artistName = new_artist;
    head -> albumName = new_album;
    head -> numTracks = new_tracks;
    head -> releaseYear = new_release;
    head -> next = second;
    return;
  }
  //Exception 3: If there's only one node in the list, create the second node.
  if(head->next==NULL){
    head->next = new cd;
    cd *second = head->next;
    second -> artistName = new_artist;
    second -> albumName = new_album;
    second -> numTracks = new_tracks;
    second -> releaseYear = new_release;
    return;
  }

  //Else: run through the list and find the appropriate spot to insert
  
  cd *prev = head;
  cd *temp = prev -> next;
  int done = 0;
  while(!done){
    if(new_artist.compare(temp->artistName)<0){
      done = 1;
    }
    else{
      prev=temp;
      temp=temp->next;
      if(temp==NULL){
	done = 1;
      }
    }
  }
  
  
  //Assignment
  prev -> next = new cd;
  prev = prev -> next;
  prev -> next = temp;
  prev -> artistName = new_artist;
  prev -> albumName = new_album;
  prev -> numTracks = new_tracks;
  prev -> releaseYear = new_release;
  return;
}

void cd_collection::print_database(){
  cd *temp = head;
  cout << "Printing collection." << endl << endl;
  while(temp!=NULL){
    cout << temp -> artistName << " - " << temp -> albumName << endl;
    cout << "Number of tracks: " << temp -> numTracks << endl;
    cout << "Release year: " << temp -> releaseYear << endl;
    cout << endl;
    temp = temp -> next;
  }
  cout << "Finished printing." << endl;
}

void cd_collection::find_artist(string artist_name){
  cd *temp = head;
  cout << "List of " << artist_name << "'s " << " releases: " << endl << endl;
  while(temp != NULL)
    { 
      if(temp -> artistName == artist_name){
	cout << temp -> albumName << endl;
	  cout << "Number of tracks: " <<  temp -> numTracks << endl;
	  cout << "Release Year: " << temp -> releaseYear << endl;
	  cout << endl;
      }
      
      temp = temp -> next;
    }  
}

void cd_collection::write_to_file(string file_name){
  ofstream ofile;
  ofile.open(file_name.c_str(),ofstream::trunc);
  cd *current = head;

  while(current!=NULL){
    ofile << current -> artistName << endl;
    ofile << current -> albumName << endl;
    ofile << current -> numTracks << " " << current -> releaseYear << endl;
    current = current -> next;
  }

  cout << "Writing to file (" << file_name << ") complete." << endl;
  ofile.close();
}  

void cd_collection::read_from_file(string file_name){
  ifstream ifile;
  ifile.open(file_name.c_str());
  string new_album, new_artist;
  int new_release, new_tracks;

  cout << "Reading from file." << endl;
  getline(ifile, new_artist);
  getline(ifile, new_album);
  ifile >> new_tracks >> new_release;
  ifile.get();

  while(ifile){
    insert_sorted(new_artist,new_album,new_tracks,new_release);
    getline(ifile, new_artist);
    getline(ifile, new_album);
    ifile >> new_tracks >> new_release;
    ifile.get();
  }

  cout << "Reading from file (" << file_name << ") complete." << endl;
  ifile.close();
}

void cd_collection::delete_cd(string target_artist, string target_album){
  //Check if the list is empty.
  if(head==NULL){
    cout << "The collection is empty." << endl;
    return;
  }
  
  //Check if the target is the first item in the list.
  cd *temp = head;
  if((head->artistName==target_artist)&&(head->albumName==target_album)){
    head = head -> next;
    delete temp;
    cout << "Deleted " << target_album << "(" << target_artist << ")." << endl;
    return;
  }
  
  //Search through the collection for the target.
  temp = head -> next;
  cd *prev=head;
  while(temp!=NULL){
    
    //Check if this is the target; delete and return if confirmed.
    if((temp->artistName==target_artist)&&(temp->albumName==target_album)){
      prev -> next  = temp -> next;
      delete temp;
      cout << "Deleted " << target_album << "(" << target_artist << ")." << endl;
      return;
    }
    prev = temp;
    temp = temp -> next;
  }

  
  cout << "Entry not found." << endl;
  return;
}
