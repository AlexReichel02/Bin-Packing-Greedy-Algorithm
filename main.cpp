/***************************************************************
  Student Name: Alex Reichel
  File Name: main.cpp
  Assignment number Project 04

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include <iostream>
using namespace std;
#include"OptimalBin.hpp"
#include"OnlineBin.hpp"
#include "OfflineBin.hpp"
int main() {

	OptimalBin obj;
	obj.readFile();



	cout<<endl;
	OnlineBin obj2;

	obj2.readFile();
	obj2.firstFit();
	cout<<endl;
	obj2.nextFit();
	cout<<endl;
	obj2.bestFit();


	OfflineBin obj3;
	obj3.readFile();
	obj3.firstFitTest();
	obj3.bestFitTest();


    cout<<endl;
    cout<<endl;

	cout << "Policy                Total Bins used "<<endl;
	cout<< "Online Algorithm "<<endl;
	cout<<"First Fit               " << obj2.getNumFirstFitBins()<<endl;
	cout<<"Next Fit                " << obj2.getNumNextFitBins()<<endl;
	cout<<"Best Fit                " << obj2.getNumBestFitBins()<<endl;
	cout<< "Offline Algorithm "<<endl;
	cout<<"First Fit               " << obj3.getNumFirstFitBins()<<endl;
	cout<<"Best Fit                " << obj3.getNumBestFitBins()<<endl;

	cout<<endl;



	cout<<endl;

	obj2.printFirstFit();
	cout<<endl;
	obj2.printNextFit();
	cout<<endl;
	obj2.printBestFit();

	cout<<endl;

	obj3.printFirstFit();
	cout<<endl;
	obj3.printBestFit();

	cout<<"Now implementing brute force Optimal algorithm , this will take 2 minutes and 30 seconds"<<endl;
	obj.binPacking();
	cout<< "Total number of bins via Optimal Algorithm:       "  << obj.getNumBins() <<endl;
	obj.printOptimal();

	return 0;
}
