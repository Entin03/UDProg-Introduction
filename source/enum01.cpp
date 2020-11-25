#include "std_lib_facilities.h"

const vector<string> months =
{ 
  "January"
  "February"
  "March"
  "April"
  "May"
  "June"
  "July"
  "August"
  "September"
  "October"
  "November"
  "December"
};

enum class Month
{
   jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m)
{
   m = (m == Month::dec) ? Month::jan : Month(int(m)+1); //egyszerű if
   return m;
}

 ostream& operator<<(ostream& os, Month m)
 {
   return os << months[int(m)];
 }

int main()
{
   Month m = Month::jan;
   m = Month::apr;
   //m = Month(7);  //ha lehet ne hasznűljik így...
   //m=6;

   ++m;

   cout << m << endl;

  return 0;
}

