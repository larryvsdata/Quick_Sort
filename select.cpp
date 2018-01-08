#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "TestBed.cpp"

int main()
{

	

	

	
	int type, k;

	
	cout << "Enter type" << endl;
	cin >> type;
	cout << "Enter k" << endl;
	cin >> k;

	
	TestBed *tr = new TestBed();
	tr->setAlgorithm(type, k);
	tr->execute();

	
	int z;

	cin >> z;


}