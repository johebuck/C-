#include <iostream>
#include "Overload.h"
#include "Overload.cpp"

using namespace std;

int main()
{

   rational x, y(3, 4), z;

   cout<<"x is: "<<x<<endl;
   cout<<"y is: "<<y<<endl;
   cout<<"z is: "<<z<<endl;
   x.equals(y);
   cout<<endl;

   z=x+y;
   cout<<"adding x and y, z is: ";
   z.print();
   cout<<endl;

   z=x-y;
   cout<<"subtracting x and y, z is: ";
   z.print();
   cout<<endl;

   z=x*y;
   cout<<"multiplying x and y, z is: ";
   z.print();
   cout<<endl;

   z=x/y;
   cout<<"dividing x and y, z is: ";
   z.print();

    //needed because program would close out immedietly on my computer
    cin.get();

    return 0;
}
