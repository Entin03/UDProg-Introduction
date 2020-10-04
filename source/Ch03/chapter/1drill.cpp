#include "std_lib_facilities.h"
int main()
{
    string first_name;
    string friend_name;
    string s;
    int  age=0;
    char friend_sex=0;
    
    cout<<"Who do you want to write to?:\n";
    cin>>first_name;
    cout<<"Nice "<<first_name<<", How are you?\n";
    cin>>s;
     
     
    cout<<"Please enter your friend name:\n";
    cin>>friend_name;
    cout<<"I've seen  "<<friend_name<<"-for a long time, you've been watching lately?\n";
    cout<<"What is your gender if a man then 'f' is the answer, if no then 'n' \n";
    cin>>friend_sex;
    
    if (friend_sex=='f') {
        cout<<"Tell him to call (male)\n";
        }
    else if (friend_sex=='n'){
        cout<<"Tell her to call (woman)\n";
    }  

   cout<<"How old?\n";
    cin>>age;
    
    if (age<0 || age>110){
       simple_error("you're kidding now!");
        }  
        
cout <<"I heard now was the " << age << ". your birthday\n" ;

if ( age < 12 )
	cout <<"Next year" << age + 1 << " you will be\n" ;
else if (age == 17)
	cout << "You can vote next year. \n" ;
else if (age > 70)
	cout <<"I hope you enjoy your retirement!\n";
	
	
 cout<<"Regards\n\nValentin\nValentin"   ;
 
 
  return 0;

}
