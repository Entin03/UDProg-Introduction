#include "std_lib_facilities.h"

int main()
{
 cout<< "Success!\n";
 cout<< "Success!\n";
 cout<< "Success"  << "!\n";
 cout<< "Success!" <<"\n";

  int res =7;
  vector<int> v(10); 
  v[5] = res; 
  
  cout << "Success!\n";
  //vector <int> v(10);
  v[5] = 7; 
  
  if (v[5]=7) 
   cout << "Success!\n";
   
   bool cond =true;
  if (cond) 
   cout << "Success!\n";
  else 
   cout << "Fail!\n";   
   
  
    bool c = true;
   if (c) 
    cout << "Success!\n"; 
   else 
     cout << "Fail!\n";
   
//bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";

  string s = "ape"; //bool c =true; 
    if (c) 
     cout << "Success!\n";
     
 // string s = "ape"; 
   if (s=="ape") 
     cout << "Success!\n";
     
   s = "fool"; 
   if (s=="fool") 
     cout << "Success!\n";

   s = "ape"; 
    if (s=="ape") 
      cout << "Success!\n";
      
  vector<char> v1(5); 
   for (int i=0; i<v.size(); i++) cout << "Success!\n";
  
  vector<char> v2(5); 
   for (int i=0; i<=v.size(); i++) cout << "Success!\n";
  
  string s1 = "Success!"; 
  for (int i=0; i<8; i++) cout << s1[i];
   if (true) cout << "Success!\n"; 
    else cout << "Fail!\n";
  
  int x = 2000; int c1 = x; 
  if (c==2000) cout << "Success!\n";

  string s2 = "Success!\n"; 
   for (int i=0; i<8;i++) cout << s2[i];
  
  vector <int> v3(5); 
  for (int i=0; i<=v.size(); i++) cout << "Success!\n";

  int i=0, j = 9; 
  while (i<10){ i++; if (j<i) cout << "Success!\n";}
  
  int x1 = 2; double d =4.5; 
  if (d==2*x1+0.5) cout << "Success!\n";
  
  string s3 = "Success!"; 
  for (int i=0; i<=7; i++) cout << s3[i];
  
  int i1=0; int j1=9; 
  while (i1<10){ i1++; if (j1<1) cout << "Success!\n";} 

  int x2 = 4; double d2 = 5/x-2; 
  if (d2==(x2-2+0.5)) cout << "Success!\n";
  cout <<"Success!\n"; 

  return 0;
}
