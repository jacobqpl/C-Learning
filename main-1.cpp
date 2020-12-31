#include <iostream>
#include <cstdio> // for printf()
using namespace std;
int main() {
int i = 1;
double x; 
double y ;
cout << "Enter the initial value in inches: ";
cin >> x;
for(int i=1; i < 11; i++)
printf("Inches = %f, Centimeters = %f \n",x++, y= (2.54*(x-1)));
return 0;
}