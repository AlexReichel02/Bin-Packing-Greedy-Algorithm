/***************************************************************
  Student Name: Alex Reichel
  File Name: OfflineBin.hpp
  Assignment number Project 04

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef OFFLINEBIN_HPP_
#define OFFLINEBIN_HPP_
#include<iostream>
#include <vector>
#include<algorithm>
#include <fstream>
using namespace std;
class OfflineBin {
public:

	/**
	Basic empty constructor
			*/
	OfflineBin();

	/**
	Function that reads the file with bin values
			*/
	void readFile();

	/**
				Function that swaps the float values
				@param float * representing float value to be swapped
				@param float * representing float value to be swapped

			*/
	void swap(float *a,float *b);



	/**
	Function that implements the first fit algorithm
	@param float array representing array to be used
	@param int n representing size of array
				*/
	void firstFit(float arr[],int n);


	/**
		Function that implements the best fit algorithm
		@param float array representing array to be used
		@param int n representing size of array
					*/
	void bestFit(float arr[],int n);


	/**
	Function that returns an int representing number of first fit bins
		*/
	int getNumFirstFitBins();

	/**
	Function that returns an int representing number of best fit bins
		*/
	int getNumBestFitBins();

	/**
	Function that implements the first fit algorithm with correctly sorted vector
		*/
	void firstFitTest();

	/**
		Function that implements the best fit algorithm with correctly sorted vector
	*/
	void bestFitTest();

	/**
	Function that prints first fit  bins
		*/
	void printFirstFit();

	/**
	Function that prints best fit  bins
			*/
	void printBestFit();

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
		int representing number of bins
		*/
	int numBins;

	/**
	2D vector representing all first fit bins
		*/
	vector<vector<float> > firstFitBins;

	/**
   2D vector representing all best fit bins
			*/
	vector<vector<float> > bestFitBins;


	/**
  float vector representing all bin values
			*/
	vector<float> binValues;

	/**
		int representing number of first fit bins
	*/
	int numFirstFitBins;

	/**
	int representing number of best fit bins
			*/
	int numBestFitBins;


	virtual ~OfflineBin();
};

#endif /* OFFLINEBIN_HPP_ */
