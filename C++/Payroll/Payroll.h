#ifndef PAYROLL_H
#define PAYROLLH
#include <iostream>
#include <string>

using namespace std;

class payroll {
  /*
   * Purpose:
   *    Gives the user the option to choose between printing entire payroll, selecting a specific user, or printing there information.
   */

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
  /*
   * Description:
   *   initializes each array pointer to NULL
   *
   */

  ~payroll();
  /*
   * Description:
   *   calls delete[] for each array when the object goes out of scope
   *
   *
   */


   void read_employee_data();
  /*
   * Description:
   *   opens the file file_name and reads in the data (total_employees, check_number), declares room for the appropriate number of entries
   * in each dynamic array, and loads the employee data from the file. You should store the file name in payroll_file so you can write data
   * back to the file in the next method.
   *
   *
   */

   void store_employee_data();
    /*
   * Description:
   *   opens the file file_name and prints all employee data back to the file it was read from (stored in payroll_file) including the updated
   * check number. Remember, your data should be readable by your program later.
   *
   */

  void print_employee_info();
  /*
   * Description:
   *   prints the data of a single employee
   *
   *
   */

  void print_paycheck();
  /*
   * Description:
   *   prints the paycheck of an employee
   *
   *
   */


  void print_paychecks();
  /*
   * Description:
   *   prints the paycheck of an employee
   *
   *
   */


   int employee_index();
  /*
   * Description:
   *   searches the array employee_ids[] and returns the numerical index of the employee with the provided id
   * (makes the implementation of the preceding three functions easier.
   *
   *
   */

};

#endif
