/***************************************************************
  Student Name: Alex Reichel
  File Name: OptimalBin.hpp
  Assignment number Project 04

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#ifndef OPTIMALBIN_HPP_
#define OPTIMALBIN_HPP_
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
class OptimalBin {
public:

	/**
	Basic empty constructor
	*/
	OptimalBin();

	/**
	Function that reads the file with bin values
	*/
	void readFile();

	/**
	Function prints all of the bin values
	*/
	void printBinValues();

	/**
	Function that permuates all of the diferent bin values
	*/
	void binPacking();

	/**
		Function that permuates all of the different bin values
		@param float * representing pointer array
		@param int representing start of permutation
		@param int representing end of permutation
	*/
	void permutation(float *arr,int start,int end);

	/**
			Function that permuates all of the different bin values
			@param float * representing pointer array
			@param int representing size of array

		*/
	void printTour(float arr[], int size);


	/**
			Function that swaps the float values
			@param float * representing float value to be swapped
			@param float * representing float value to be swapped

		*/
	void swap(float *a, float *b);

	/**
			Function that returns the number of bins
		*/
	int getNumBins();

	/**
			Function that sets the number of bins
			@param int representing variable to set number of bins
		*/
	void setNumBins(int temp);

	/**
	Function that prints the optimal bin values
		*/
	void printOptimal();

	/**
	Integer representing number of bins
	*/
	int numBins;

	/**
	Float vector representing bin values
	*/
	vector<float> binValues;

	/**
	Integer vector representing a test vector
	*/
	vector<int> test;

	/**
	Integer representing optimal number of bins
	*/
	int optimalBins;

	/**
	2D vector representing the optimal solution
	*/
	vector<vector<float> > allTours;

	virtual ~OptimalBin();
};

#endif /* OPTIMALBIN_HPP_ */
