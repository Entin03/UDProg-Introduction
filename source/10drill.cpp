#include "std_lib_facilities.h"

struct Point{
	double x = 0;
	double y = 0;

	Point(double a, double b): x(a), y(b) {};
};

ostream& operator<< (ostream& os,const vector<Point>& p)
{
	for(int i = 0;i < p.size(); i++)
		os << p[i].x << " " << p[i].y << endl;

	return os;
}

istream& operator>> (istream& is, vector<Point>& p)
{
	for(int i = 0;i < 7; i++)
	{
		double a = 0, b = 0;
		is >> a >> b;

		p.emplace_back(a, b);
	}

	return is;
}

bool equal(const vector<Point>& p1, const vector<Point>& p2)
{
	for(int i = 0;i < p1.size(); i++)
	{
		if(p1[i].x != p2[i].x || p1[i].y != p2[i].y) return false;
	}
	return true;
}

int main()
{
	vector<Point> original_points;
	vector<Point> processed_points;

	cout << "Please enter 7 points!\n";
	for(int i = 0;i < 7 ;i++)
	{
		double a = 0, b = 0;
		cin >> a >> b;

		original_points.emplace_back(a, b);
	}


	cout << endl << "original points: \n" << original_points;

	ofstream ost{"mydata"};
	ost << original_points;
	ost.close();

	ifstream ist{"mydata"};
	ist >> processed_points;
	ist.close();

	cout << endl << "processed points: \n" << processed_points;

	if(!equal(original_points,processed_points)) 
		cout << "\nSomethings wrong!\n";

	return 0;
}
