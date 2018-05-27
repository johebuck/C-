#include <iostream>
#include <string>
#include "CurrencyConverter.h"
using namespace std;


CurrencyConverter::CurrencyConverter(){

    amount=1.00;
    type="dollars";

}


void CurrencyConverter::print1(){

    float new_amount; string new_type;

    cout<<"Please enter your new currency amount: ";
    cin>>new_amount;
    cout<<"Please enter your new currency type: ";
    cin>>new_type;
    cout<<endl;

    amount=new_amount;
    type=new_type;

}


void CurrencyConverter::print(){

    cout<<"You have: "<<amount<<".00 "<<type<<endl;
    cout<<endl;

}

double CurrencyConverter::toDollars(){

    if(type=="euros"){
        cout<<"You have: "<<(amount*1.28)<<" dollars"<<endl;
        cout<<endl;
    }

    if(type=="pounds"){
        cout<<"you have: "<<(amount*1.61)<<" dolalrs"<<endl;
        cout<<endl;
    }

    if(type=="rupees"){
        cout<<"You have: "<<(amount*.016)<<" dollars"<<endl;
        cout<<endl;
    }

    if(type=="dollars"){
        cout<<"You have: "<<amount<<" dolalrs"<<endl;
        cout<<endl;
    }

}

double CurrencyConverter::toEuros(){

    if(type=="dollars"){
        cout<<"You have: "<<(amount*.78)<<" euros"<<endl;
        cout<<endl;
    }

    if(type=="pounds"){
        cout<<"You have: "<<(amount*1.25)<<" euros"<<endl;
        cout<<endl;
    }

    if(type=="rupees"){
        cout<<"You have: "<<(amount*.013)<<" euros"<<endl;
        cout<<endl;
    }

    if(type=="euros"){
        cout<<"You have: "<<amount<<" euros"<<endl;
        cout<<endl;
    }

}

double CurrencyConverter::toPounds(){

    if(type=="dollars"){
        cout<<"You have: "<<(amount*.62)<<" pounds"<<endl;
        cout<<endl;
    }

    if(type=="euros"){
        cout<<"You have: "<<(amount*.80)<<" pounds"<<endl;
        cout<<endl;
    }

    if(type=="rupees"){
        cout<<"You have: "<<(amount*.010)<<" pounds"<<endl;
        cout<<endl;
    }

    if(type=="pounds"){
        cout<<"You have: "<<amount<<" pounds"<<endl;
        cout<<endl;
    }

}

double CurrencyConverter::toRupees(){

    if(type=="dollars"){
        cout<<"You have: "<<(amount*61.52)<<" rupees"<<endl;
        cout<<endl;
    }

    if(type=="euros"){
        cout<<"You have: "<<(amount*78.93)<<" rupees"<<endl;
        cout<<endl;
    }

    if(type=="pounds"){
        cout<<"You have: "<<(amount*98.96)<<" rupees"<<endl;
        cout<<endl;
    }

    if(type=="rupees"){
        cout<<"You have: "<<amount<<" rupees"<<endl;
        cout<<endl;
    }

}

