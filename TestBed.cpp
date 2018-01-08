#include <string>
#include <iostream>

using namespace std;
#include "SelectionAlgorithm.h"

#include "AlgorithmSortQuick.cpp"

class TestBed
{
public:

	TestBed() {};
	~TestBed() {};

	void setAlgorithm(int type, int kn)
	{
		
 if (type == 4)
		{
			algorithm = new AlgorithmSortQuick(kn);

		}

	}


	void execute()
	{
		
		algorithm->select() ;
		
	};

	SelectionAlgorithm *algorithm;
};