#include <string>
#include <iostream>
#include <ctime>
using namespace std;

#include "SelectionAlgorithm.h"

class AlgorithmSortQuick :public SelectionAlgorithm
{

public:
	AlgorithmSortQuick(int kk) : SelectionAlgorithm(kk)
	{
		k = kk;
	}

	int select()
	{

		int N;

		

		cout << "Enter N" << endl;
		cin >> N;


		cout << "Enter all numbers" << endl;
		int *numbers;

		numbers = new int[N];

		for (int i = 0; i < N; i++)
		{
			cin>> numbers[i];
		}



		int resultFinal = -11;


		clock_t start = clock();
		
		resultFinal = quickselect(numbers, 0, N - 1, k);
	

	
		clock_t end = clock();
		double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		cout << "The number  " << resultFinal << " is found in  " << cpu_time << "  seconds " << endl;

		return resultFinal;
	}


	int static quickselect(int *num, int left, int right, int k)
	{
		if (right - left + 1 <= 10)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int key = num[i];
				int position = i;

				while (position > left && key < num[position - 1])
				{
					num[position] = num[position - 1];
					position--;
				}
				num[position] = key;

			}



			return num[left + k - 1];
		}
		else
		{
		


			int pivotIndex=-11;
			partition(num, left, right, pivotIndex);

	

			if (k < pivotIndex - left + 1)
				return quickselect(num, left, pivotIndex - 1, k);
			else if (k == pivotIndex - left + 1)
				return num[pivotIndex];
			else
				return quickselect(num, pivotIndex + 1, right, k-(pivotIndex-left+1));

			 


		}


	}



	void static choosePivot(int *num, int left, int right)
	{
		int iPivot = (left + right) / 2;
		int temp = num[iPivot];
		 num[iPivot] = num[left];
		 num[left] = temp;
	}




	void static swap(int *theArray, int k1, int k2)
	{
		int temp = theArray[k1];
		theArray[k1] = theArray[k2];
		theArray[k2] = temp;
	}

	void static partition(int *theArray,int first,int last,int &pivotIndex)
	{
		choosePivot(theArray, first, last);
		int pivot = theArray[first];

		int lastS1 = first;
		int firstUnknown = first + 1;

		for (; firstUnknown <= last; ++firstUnknown)
		{
			if (theArray[firstUnknown] < pivot)
			{
				++lastS1;
				swap(theArray,firstUnknown,lastS1);
			}
		}
		swap(theArray, first, lastS1);
		pivotIndex = lastS1;
	}

};

