#include "std_lib_facilities.h"

namespace UDChrono{
 class Year
 {
    static constexpr int min = 1800;
    static constexpr int max = 2077;
   public:
    class Invalid {};
    Year(int x): y(x) { if (x < min || x > max) throw Invalid{}; }
    int year() { return y; }
    void increment() { y++;  if (y > max) throw Invalid{}; }
   private:
    int y;
 };
 
 Year operator++(Year& year)
 {
   return year; // year.increment()
 }
 
 ostream& operator<<(ostream& os, Year year)
 {
    return os << year.year();
 }

const vector<string> months =
{
   "January",
   "February",
   "March",
   "April",
   "May",
   "June",
   "July",
   "August",
   "September",
   "October",
   "November",	
   "December",
};

enum class Month {
	jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m)
{
    m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);//egyszerűsített if
    return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}
class Date 
{
private:
   Year year;
   Month month;
   int day;
public:   
   class Invalid {};
   Date(): year(Year{2001}), month(Month::jan), day(1) {}
   Date(Year y, Month m, int d): year(y), month(m), day(d) {if (!is_valid()) throw Invalid{}; }
   bool is_valid();
   void add_day(int n);
   
   Year get_year() const { return(year); }
   Month get_month() const { return(month); }
   int get_day() const { return(day); } 
};

bool Date::is_valid()
{
   if (day < 1 || day > 31) 
      return false;
      
      return true;
}

/*
Date::Date(int y, int m, int d)
{
  if (y > 0)
   year = y;
  else 
    error("Invalid year");
    
  if (m <= 12 && m > 0)
    month = m;
  else 
    error("Invalid month");
  
  if (d <= 31 && d > 0)
   day = d;
  else 
    error("Invalid day");       
}
*/
 void Date::add_day(int n)
 {
    day += n;
    if (day > 31)
    {
      ++month;
      day -=31;
      if (month == Month::jan)
      {
        ++year;
      }
    }
 }

} // UDChrono end!
int main()
try{

  UDChrono::Date today {UDChrono::Year{2020}, UDChrono::Month::aug, 25};
  
  cout << "Date: " << today.get_year() << ". "
       << today.get_month() << ' ' << today.get_day() << ".\n";
       
  UDChrono::Date tomorrow {today};
  cout << "Date: " << today.get_year() << ". "
       << today.get_month() << ' ' << today.get_day() << ".\n";
    
  vector<UDChrono::Date> dates(10);
  for (const auto& date : dates)
    cout << "Date: " << today.get_year() << ". "
       << today.get_month() << ' ' << today.get_day() << ".\n";
       

  return 0;
}catch (exception& e) 
{ 
 cout << e.what() << endl;
 return 1;
}
catch (UDChrono::Date::Invalid) 
{ 
 cout << "Invalid date!\n";
 return 2;
}
 catch (UDChrono::Year::Invalid) 
{ 
 cout << "Invalid year!\n";
 return 3;
}
