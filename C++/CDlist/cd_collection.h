/*
Jonathan Wilbert, John Buckley, and Alex Schuck
03/11/15
cd_collection.h file
This is the header file for the cd_collection class
*/
#ifndef CD_COLLECTION_H
#define CD_COLLECTION_H
#include "cd.h"
#include <fstream>

using namespace std;

class cd_collection{
 private:
  
  cd *head;
  
 public:
  
  cd_collection();
  /*
    Purpose: initializing the cd_collection class by setting head to NULL
    Arguments: N/A
    Returns: N/A
  */	
  
  ~cd_collection();
  /*
    Purpose: deletes the list by calling delete_all with head
    Arguments: N/A
    Returns: N/A
  */
  
  void delete_all(cd *current);
  /*
    Purpose: deletes the cd at the passed in pointer after recursively calling itself for all cds after the given one
    Arguments:
      cd* currentNode - a pointer to the node to delete
    Returns: N/A
 */
  
  void insert_sorted(string new_artist, string new_album, int new_tracks, int new_release);
  /*
    Purpose: takes all the data for the new cd and goes through the list to find the first cd in the list which has an artist name whose alphabetical value comes after the input cd, then inserts the input list before that one. Lowercase names will be placed after Uppercase names.
    Arguments: 
      string new_artist - the name of the input cd's artist
      string new_album - the album title
      int new_tracks - the number of tracks on the album
      int new_release - the release year of the album
    Returns: N/A
  */

  void find_artist(string artist_name);
  /*
    Purpose: Goes through the list and prints out the details of all cds with artist name matching the given input
    Arguments:
      string artist_name - the name of the artist whose albums are to be printed
    Returns: N/A
  */
  
  void print_database();
  /*
    Purpose: Prints out the entire list of cds and all of their details
    Arguments: N/A
    Returns: N/A
  */
  
  void read_from_file(string readFileName);
  /*
  Purpose: Opens a file indicated by the user to read in the cd information listed in it and ADD those cds to the current database.
  Arguments:
    string file_name - the name of the file to be read
  Returns: N/A
 */
  
  void write_to_file(string writeFileName);
  /*
    Purpose: Creates a file with a name given by the user which is compatible with the read_from_file function.
    Arguments:
      string file_name - the name of the file to be created/overwritten
    Returns: N/A
  */
  
  void delete_cd(string artistName, string albumName);
  /*
    Purpose: Deletes the first cd in the list that matches both the artist name and album name given by the user. If none found, the process does nothing.
    Arguments:
      string target_artist - the name of the artist on the cd to be deleted
      string target_album - the name of the album on the cd to be deleted
    Returns: N/A
 */
};

#endif // CD_COLLECTION_H
