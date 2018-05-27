#include <iostream>
#include <string>
#include "Payroll.h"
#include <fstream>

using namespace std;

//sets the dynamic arrays to null to get rid of junk
 payroll::payroll(){

    names=NULL;
    hourly_wages=NULL;
    employee_ids=NULL;

}

//deletes the data in the arrays
 payroll::~payroll(){

    delete [] names;
    delete [] hourly_wages;
    delete [] employee_ids;

}

//reads in a file name, opens the file, reads in the total number of employees and the check number and sets the dynamic arrays to the correct number of spots
void payroll::read_employee_data(){

    string file_name;

    cout<<"Please enter the data file name: ";
    cin>>file_name;

    ifstream infile;
    infile.open(file_name.c_str());

        infile>>total_employees;
        infile>>check_number;

    total=(total_employees-1);

    hours_worked=new int[total];
    names=new string[total];
    hourly_wages=new float[total];
    employee_ids=new int[total];
}

//read in all employee info and store it back into the file it was read from
void payroll::store_employee_data(){

    string file_name;


    int count=0;

    ifstream infile;
    infile.open(file_name.c_str());

        infile>>total_employees;
        infile>>check_number;

        getline(infile, names[count]);//eats up null character
        while(infile){
            getline(infile, names[count]);
            infile>>employee_ids[count];
            infile>>hourly_wages[count];
            infile>>hours_worked[count];
            getline(infile, names[count]);//eats up null character
            count++;
            }
}

//print employees info for matching employee ids
void payroll::print_employee_info(){

    int employee_id;

    cout<<"Please enter employee id: ";
    cin>>employee_id;

    for(int i=0; i<total_employees; i++){

        if(employee_ids[i]==employee_id){

            cout<<"employee info"<<endl;

        }
    }
}

//print paycheck of employee with matching employee id
void payroll::print_paycheck(){

    int employee_id;


    cout<<"Please enter employee id: ";
    cin>>employee_id;

    for(int i=0; i<total_employees; i++){

        employee_ids[i];

        if(employee_ids[i]==employee_id){

            cout<<"check"<<endl;

        }
    }
}

//pints all paychecks for all employees
void payroll::print_paychecks(){

    for(int i=0; i<total_employees; i++){

        cout<<"all checks"<<endl;

    }

}

int employee_index(int employee_id){



}

