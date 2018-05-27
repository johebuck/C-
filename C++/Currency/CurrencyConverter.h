#ifndef CURRENCY_CONVERTER_H
#define CURRENCY_CONVERTER_H
#include <iostream>
#include <string>
using namespace std;

class CurrencyConverter {
  /*
   * Purpose:
   *    To convert US Dollars to, Euros, Pounds, and Rupees.
   */

 private:
   float amount;
   string type;

 public:
   CurrencyConverter();
  /*
   * Description:
   *   A default constructor (sets the dollar amount to 1.00 and the type to "dollars".
   *
   * Inputs:
   *   None
   *
   * Return:
   *   None
   */

  void print();
  /*
   *Description:
   *   prints the current amount
   */

   void print1();
    /*
   *Description:
   *   reads in new amount and new type
   */

  double toDollars();
  /*
   * Description:
   *   converts to dollars
   *
   * Inputs:
   *   None
   *
   * Return:
   *   double- dollars
   */


  double toEuros();
  /*
   * Description:
   *   converts to euros
   *
   * Inputs:
   *   None
   *
   * Return:
   *   double-euros
   */


  double toPounds();
  /*
   * description:
   *   converts to pounds
   *
   * Return:
   *   double-pounds
   */


   double toRupees();
  /*
   * description:
   *   converts to rupees
   *
   * return:
   *   double-rupees
   */

};

#endif
