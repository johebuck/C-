/*
Jonathan Wilbert, John Buckley, and Alex Schuck
03/11/15
main.cpp file
This is the driver function to test the cd_collection class
*/
#include "cd_collection.h"
#include "cd_collection.cpp"

using namespace std;

int main(){
  int option; string file_name; cd_collection cdcollection;
  
  do{
    cout<<"Welcome to your ancient fossil (CD) database. You may select one of the following options:" <<endl;
    cout<<"1.) Read a database from a file. "<<endl;
    cout<<"2.) Write the database to a file. "<<endl;
	cout<<"3.) Print the database. "<<endl;
	cout<<"4.) Search for CDs by a specific artist. "<<endl;
	cout<<"5.) Add a CD. "<<endl;
	cout<<"6.) Delete a CD. "<<endl;
	cout<<"7.) Quit and realize it's 2015 and buy an MP3 player. "<<endl;
	cout<<"Please enter your choice now: ";
        cin>>option;
	
	
	if(option==1){
	  cout << "Please enter the name of your file: ";
	  string myfile;
	  cin >> myfile;
	  cdcollection.read_from_file(myfile);
	}
	
	if(option==2){
	  cout << "Please enter the name of your file: ";
	  string myfile;
	  cin >> myfile;
	  cdcollection.write_to_file(myfile);
	}
	
	if(option==3){
	  cdcollection.print_database();
	}
	
	if(option==4){
	  cout << "Please enter the name of your artist: ";
	  string targetArtist;
	  cin.get();
	  getline(cin,targetArtist);
	  cdcollection.find_artist(targetArtist);
	}
	
	if(option==5){
	  string newAlbum, newArtist;
	  int newRelease, newTracks;
	  cin.get();
	  cout << "Please enter the name of the artist: ";
	  getline(cin,newArtist);
	  cout << "Please enter the name of the album: ";
	  getline(cin,newAlbum);
	  cout << "Please enter the release year: ";
	  cin >> newRelease;
	  cout << "Please enter the number of tracks: ";
	  cin >> newTracks;
	  cdcollection.insert_sorted(newArtist,newAlbum,newTracks,newRelease);
	}
	
	if(option==6){
	  string deleteArtist, deleteAlbum;
	  cin.get();
	  cout << "Please enter the name of the artist: ";
	  getline(cin,deleteArtist);
	  cout << "Please enter the name of the album: ";
	  getline(cin,deleteAlbum);
	  cdcollection.delete_cd(deleteArtist,deleteAlbum);
	}
	
  }
  while(option!=7);
  
  cout<<"No. Seriously. Go buy an IPod or something"<<endl;
  
  return 0;
}
