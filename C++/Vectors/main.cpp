#include <iostream>
#include <fstream>
#include "int_vector.cpp"
#include "int_vector.h"

using namespace std;

int main()
{
    string file_name; int sum=0; int element=0; IntVector blah; double average;



    cout<<"Please enter the data file name: ";
    cin>>file_name;

    ifstream infile;
    infile.open(file_name.c_str());


    infile>>element;


    while(infile){


        blah.push_back(element);

        sum=sum+element;

        infile>>element;


        }

        cout<<"This is the contents of the file that were read into the vector: "<<endl;


    for(int i=0; i<blah.size(); i++){

        cout<<blah.at(i)<<endl;

    }

    cout<<endl;

    average=sum/blah.size();

    cout<<"the average is: "<<average<<endl;

    cout<<endl;

    for(int i=0; i<blah.size(); i++){

        if(blah.at(i)>average){

            cout<<blah.at(i)<<" is above the average."<<endl;

        }
    }

    cout<<endl;
    cout<<endl;


    for(int i=0; i<blah.size(); i++){

        if(blah.at(i)<average){

            cout<<blah.at(i)<<" is below the average."<<endl;

        }
    }








    cin.get();
    cin.get();
    return 0;
}
