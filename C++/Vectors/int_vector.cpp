#include "int_vector.h"
#include <iostream>
#include <fstream>

using namespace std;

IntVector::IntVector(){

    vec_ptr=NULL;
    current_size=0;
    capacity=0;

}

IntVector::~IntVector(){

    delete[] vec_ptr;

}

void IntVector::debug(){

    for(int i=0; i<current_size; i++){

        cout<<vec_ptr[i];

    }

}

int IntVector:: size(){

    return current_size;
}

 int& IntVector:: at(int pos){

    return vec_ptr[pos];


 }

 void IntVector:: push_back(int element){

        if(current_size==capacity)
            IntVector::resize();
        vec_ptr[current_size++]=element;

 }

 void IntVector:: resize(){

    int *temp;

    if(capacity==0){

        capacity=1;

    }


    else
        capacity=capacity*2;


    temp=new int [capacity];


    for(int i=0; i<current_size; i++){

        temp[i]=vec_ptr[i];

    }
        delete [] vec_ptr;

        vec_ptr=temp;

 }
