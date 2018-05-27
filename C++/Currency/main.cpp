#ifndef CURRENCY_CONVERTER_H
#define CURRENCY_CONVERTER_H
#include <iostream>
#include <string>
#include "CurrencyConverter.cpp"

using namespace std;

class CurrencyConverter {

private:
  float amount;
  string type;

public:
  CurrencyConverter();
  void print();
  void print1();

  double toDollars();
  double toEuros();
  double toPounds();
  double toRupees();

};



int main(){

    CurrencyConverter first;
    int option;

    do{

        cout<<"Welcome to the dollar converter."<<endl;
        cout<<"Your options are:"<<endl;
        cout<<"0 Print your currently available currency."<<endl;
        cout<<"1 Convert your currency to Dollars."<<endl;
        cout<<"2 Convert your currency to Euros."<<endl;
        cout<<"3 Convert your currency to Pounds."<<endl;
        cout<<"4 Convert your currency to Rupees."<<endl;
        cout<<"5 (Re)Set your current currency type and balance."<<endl;
        cout<<"6 Quit."<<endl;
        cout<<"Please enter an option: ";
        cin>>option;

        if(option==0){
           first.print();
        }

        if(option==1){
            first.toDollars();
        }

        if(option==2){
            first.toEuros();
        }

        if(option==3){
            first.toPounds();
        }

        if(option==4){
            first.toRupees();
        }

        if(option==5){
            first.print1();
        }

        }while(option!=6);

    return 0;

}
#endif

