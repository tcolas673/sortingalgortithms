#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdlib.h>  // for rand
#include <time.h>    // time
#include "Timer.h"
#include "sorting.h"
#include <iomanip>
#include <vector>
#include <conio.h>

const int NUM_OF_SORTS = 10;
void randomFill(int x[], int length);

int main()
{
	Timer t;
	double time1;
	double avg = 0.0;

	int size1 = 16384;
	int size2 = 32768;
	int size3 = 65536;

	// put your code below 
	//initialize arrays
	int a[16384];
	int b[32768];
	int c[65536];

	std::vector<double> myvector;

	//Selection Sort
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(a, size1);
		t.markTime();
		selectionSort(&a[0], &a[size1]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Selection Sort 1 : " <<avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(b, size2);
		t.markTime();
		selectionSort(&b[0], &b[size2]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Selection Sort 2 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(c, size3);
		t.markTime();
		selectionSort(&c[0], &c[size3]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Selection Sort 3 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	//Exchange Sort 1
	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(a, size1);
		t.markTime();
		exchangeSort1(&a[0], &a[size1]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Exchange Sort (1) 1 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(b, size2);
		t.markTime();
		exchangeSort1(&b[0], &b[size2]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Exchange Sort (1) 2 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(c, size3);
		t.markTime();
		exchangeSort1(&c[0], &c[size3]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Exchange Sort (1) 3 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	//Exchange Sort 2
	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(a, size1);
		t.markTime();
		exchangeSort2(&a[0], &a[size1]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Exchange Sort (2) 1 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(b, size2);
		t.markTime();
		exchangeSort2(&b[0], &b[size2]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Exchange Sort (2) 2 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(c, size3);
		t.markTime();
		exchangeSort2(&c[0], &c[size3]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Exchange Sort (2) 3 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	//Heap Sort
	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(a, size1);
		std::make_heap(&a[0], &a[size1]);
		t.markTime();
		std::sort_heap(&a[0], &a[size1]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Heap Sort 1 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(b, size2);
		std::make_heap(&b[0], &b[size2]);
		t.markTime();
		std::sort_heap(&b[0], &b[size2]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Heap Sort 2 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(c, size3);
		std::make_heap(&c[0], &c[size3]);
		t.markTime();
		std::sort_heap(&c[0], &c[size3]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Heap Sort 3 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	//Quick Sort
	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(a, size1);
		t.markTime();
		std::sort(&a[0], &a[size1]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Quick Sort 1 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(b, size2);
		t.markTime();
		std::sort(&b[0], &b[size2]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Quick Sort 2 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);

	avg = 0;
	for (int i = 0; i < NUM_OF_SORTS; i++)
	{
		randomFill(c, size3);
		t.markTime();
		std::sort(&c[0], &c[size3]);
		time1 = t.getTime();
		avg += time1;
	}
	std::cout << " Quick Sort 3 : " << avg / NUM_OF_SORTS << std::endl;
	myvector.push_back(avg / NUM_OF_SORTS);
	_getch();
	
	return 0;
}
void randomFill(int x[], int length)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < length; i++)
	{
		x[i] = rand();
	}
}

