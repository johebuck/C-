/*
Jonathan Wilbert, John Buckley, and Alex Schuck
03/11/15
cd.h file
This is the header file for the linked list using nodes
*/
#ifndef CD_H
#define CD_H
#include<iostream>
#include<string>

using namespace std;

struct cd{
	cd *next = NULL; 
// points to the net CD in the linked list
	string artistName; // artist name
	string albumName; // album name
	int numTracks; // number of tracks on the CD
	int releaseYear; // year of release
};

#endif // CD_H
