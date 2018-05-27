#include <iostream>
#ifndef PAYROLL_H
#define PAYROLL_H
#include "Payroll.h"
#include "Payroll.cpp"

using namespace std;

class payroll {

 private:
   int *hours_worked; //a dynamic array of hours worked
   string *names; //a (dynamic) array of employee names
   float *hourly_wages; //a dynamic array of each employee's hourly wage
   int *employee_ids; //dynamic arrays containing each employee's unique ID and the number of hours they have worked this pay period
   int total_employees;//stores total employees
   int check_number; //stores check number
   string payroll_file; // Stores the name of the payroll file read by read_employee_data() so that it can be written again by store_employee_data().
   int total; // array size

 public:
    payroll();
    ~payroll();
    void read_employee_data();
    void store_employee_data();
    void print_employee_info();
    void print_paycheck();
    void print_paychecks();
    int employee_index();
};


int main()
{
    payroll first;
    int option;

    do{

        cout<<"Welcome to our Awesome Payroll Program (TM)."<<endl;
        cout<<"What would you like to do:"<<endl;
        cout<<"1 Print a single paycheck."<<endl;
        cout<<"2 Print all entire payroll"<<endl;
        cout<<"3 Print employee information."<<endl;
        cout<<"4 Quit"<<endl;
        cout<<"Please enter your choice: ";
        cin>>option;

        if(option==1){
            first.read_employee_data();
            first.store_employee_data();
            //first.print_paycheck();
        }

        if(option==2){
            first.read_employee_data();
            first.store_employee_data();
            //first.print_paychecks();
        }

        if(option==3){
            first.read_employee_data();
            first.store_employee_data();
            //first.print_employee_info();
        }

        }while(option!=4);

    return 0;

}
#endif




