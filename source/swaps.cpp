#include <iostream>

using namespace std;

void swap_v(int a, int b) //value-t cserél 
{
	int temp = a;
	a = b;
	b = temp;

	cout << "swap_v: " << a << "\t" << b << endl;
}

void swap_r(int& a, int& b) //referenciát cserél, igazából is megcserélődnek
{
	int temp = a;
	a = b;
	b = temp;

	cout << "swap_r: " << a << "\t" << b << endl;
}

void swap_cr(const int& a, const int& b)
{
	int temp1 = a;
	int temp2 = b;

	swap_r(temp1,temp2);

	cout << "swap_cr: " << temp1 << "\t" << temp2 << endl;
}





int main()
{
	int x = 7;
	int y = 9;
	swap_r(x,y); cout << endl << "\t" << x << "\t" << y << endl;
	swap_cr(7,9);

	cout << "-----------------------------------------------------------------------\n";

	
	const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);	cout << endl << "\t" << cx << "\t" << cy << endl;
	swap_cr(7.7,9.9);

	cout << "-----------------------------------------------------------------------\n";

	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy); cout << endl << "\t" << dx << "\t" << dy << endl;
	swap_cr(7.7,9.9);
}
