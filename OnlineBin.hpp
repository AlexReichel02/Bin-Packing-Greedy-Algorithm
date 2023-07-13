/***************************************************************
  Student Name: Alex Reichel
  File Name: OnlineBin.hpp
  Assignment number Project 04

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef ONLINEBIN_HPP_
#define ONLINEBIN_HPP_
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class OnlineBin {
public:

	/**
		Basic empty constructor
		*/
	OnlineBin();


	/**
			Function that implements the first fit alogirthm
			*/
	void firstFit();

	/**
			Function that implements the next fit alogirthm
			*/
	void nextFit();

	/**
			Function that implements the best fit alogirthm
			*/
	void bestFit();

	/**
		Function that reads the file with bin values
		*/
	void readFile();

	/**
			Function that inserts extra values into bin
			@param int representing row of vector
			@param float representing the value to be added
			*/
	void insert2D(int row,float num);

	/**
		Function that inserts extra values into bin
		@param int representing row of vector
		@param float representing the value to be added
		*/
	void insert2DBest(int row,float num);

	/**
		Function that prints first fit  bins
		*/
	void printFirstFit();

	/**
		Function that prints best fit  bins
		*/
	void printBestFit();

	/**
		Function that prints next fit  bins
		*/
	void printNextFit();

	/**
		Function that returns an int representing number  first fit  bins
		*/
	int getNumFirstFitBins();

	/**
		Function that returns an int representing number of  best fit bins
		*/
	int getNumBestFitBins();

	/**
		Function that returns an int representing number of next fit bins
	*/
	int getNumNextFitBins();

	/**
	function that prints the bin values
	*/
	void printBinValues();

	/**
	Function that returns an int representing number of bins
	*/
	int getNumBins();



	virtual ~OnlineBin();


	/**
	int representing number of bins
	*/
	int numBins;

	/**
	int representing number of first fit bin values
	*/
	int numFirstFitBins;

	/**
	int representing number of next fit bin values
	*/
	int numNextFitBins;

	/**
	int representing number of best fit bins
	*/
	int numBestFitBins;

	/**
	float vector representing first fit bin values
	*/
	vector<vector<float> > firstFitBins;

	/**
	float vector representing best fit bin values
	*/
	vector<vector<float> > bestFitBins;

	/**
	float vector representing next fit bin values
	*/
	vector<vector<float> > nextFitBins;

	/**
	float vector representing bin values
		*/
	vector<float> binValues;


};

#endif /* ONLINEBIN_HPP_ */
