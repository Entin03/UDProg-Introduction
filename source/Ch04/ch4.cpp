#include "std_lib_facilities.h"

int main()
{
double a,b,x=0;

   /* while (cin>>a>>b)
      {
       cout<<a<<" "<<b<<"\n"; //1. feladat
      }
      while (cin>>a>>b)
      {
       if (a>b) 
        {
         cout<<"Higher value: "<<a<<" smaller value: "<<b<<"\n";
         x=a-b;
        }
       else if (a==b){
         cout<<"The two numbers are equal";
     }
    else  {                                                  //2. és 3. 5. feladat
        cout<<"Higher value: "<<b<<" smaller value: "<<a<<"\n";
        x=b-a;
    }
    if (x<1.0/100){
        cout<<"The numbers are equal \n";
    }
}
  bool k = true;
  double smallest,largest;
while(cin>>a){
  cout<<a<<"\n";
  if(k){
    smallest = a;
    largest = a;
    k=false;
}else if (a<smallest) {
    cout<<"The smallest so far "<<"\n";     //6.feladat
    smallest = a;
}else if (a>largest){
    cout<<"The large so far "<<"\n";
    largest = a;
  }
} */

string unit;
double sum=0;
double smallest,largest,db=0;
bool k=true;
vector <double> v;


cout<<"Enter a number and unit: \n";

while (cin>>a>>unit) {
    		if (unit == "cm"){
            a=a/100;
			sum +=a;
			db++;
			}
		else if (unit == "in"){
            a=(a/100)*2.54;
			sum +=a;
			db++;
			}
		else if (unit == "ft"){
		    a=(a/100)*2.54*12;
			sum +=a;
			db++;
			}
		else if (unit == "m"){
			sum +=a;
			db++;
		}
		else
			cout << "wrong unit\n";
        v.push_back(a);
  if(k){
    smallest = a;
    largest = a;
    k=false;
}else if (a<smallest) {
    cout<<"The smallest so far "<<"\n";
    smallest = a;
}else if (a>largest){
    cout<<"The large so far "<<"\n";
    largest = a;

}
}
cout<<"Largest: "<<largest<<'\n';
cout<<"Smallest: "<<smallest<<'\n';
cout<<"Sum: "<<sum<<'\n';
cout<<"DB: "<<db<<'\n';

sort(v.begin(),v.end());
 for (int i = 0;i<v.size();i++){
   cout<<v[i]<<" ";
 }

return 0;
}
