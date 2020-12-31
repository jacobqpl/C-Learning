#include <iostream>
#include <string>
using namespace std;
int main() {
   int hour;
   double wage_rate;
   cout << "Enter number of hours worked:" ;
   cin >> hour;
   cout <<  "Enter wage rate:";
   cin >> wage_rate;
   if(hour > 40) {
       cout << "The total pay is" << wage_rate*40+(hour-40)*1.5*wage_rate;
   } else if(hour < 40) {
          cout << "The total pay is:" << wage_rate*hour;
   } 
     return 0;
}