/***************************************************************
  Student Name: Alex Reichel
  File Name: OptimalBin.cpp
  Assignment number Project 04

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "OptimalBin.hpp"

OptimalBin::OptimalBin() {
	// TODO Auto-generated constructor stub

}


void OptimalBin::readFile(){
	    ifstream inFile;
	    int numBins1;
	    float tempBinValues=0.0;
		inFile.open("items.txt");

		if(!inFile){
		  cout<<"unable to open"<<endl;
	     }else{


		while(inFile >> numBins1 >> tempBinValues){

			if(numBins1 > 0){
				numBins = numBins1;
			}
			binValues.push_back(tempBinValues);

			}
		inFile.close();
		}

		test.push_back(10);


}
void OptimalBin::printTour(float arr[], int size)
{
	vector<vector<float> > allBins;
	vector<float> bin;
	    int binCount=1;
		float sum=0.0;

		for(int i=0;i<size;i++){

			sum += arr[i];
			if(sum <= 1.0){
				bin.push_back(arr[i]);
				
			}else{
				allBins.push_back(bin);
				bin.clear();
				binCount++;
				bin.push_back(arr[i]);
				sum = 0.0 + arr[i];
				
			}


			if(i==size-1){
				allBins.push_back(bin);
				
				}

		}


		if(test[0] < binCount){

					optimalBins = test[0];
				}else{
					optimalBins = binCount;
					test[0] = binCount;
					allTours = allBins;
					setNumBins(binCount);
				}


}

void OptimalBin::setNumBins(int temp){
	optimalBins = temp;
}

void OptimalBin::printOptimal(){

	cout<<"Optimal Fit Results " << getNumBins() <<endl;
	for (int i = 0; i < allTours.size(); i++)
		    {
		       cout<< "Bucket num: " << i+1 <<endl;
		        for (long int j = 0; j < allTours[i].size(); j++)
		        {

		        		cout << allTours[i][j] << " ";

		        	}
		        cout<<endl;

		        }
		    }


void OptimalBin::permutation(float *arr,int start,int end){


	if(start==end)
		    {
		        printTour(arr, end+1);
		        return;
		    }
		    int i;
		    for(i=start;i<=end;i++)
		    {
		        swap((arr+i), (arr+start));
		        permutation(arr, start+1, end);
		        swap((arr+i), (arr+start));
		    }

}

void OptimalBin::swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void OptimalBin::binPacking(){
	float bins[12];
	for(int i=0;i<12;i++){
		bins[i] = binValues[i];
	}

	permutation(bins,0,11);

}

int OptimalBin::getNumBins(){
	return allTours.size();
}

void OptimalBin::printBinValues(){

}

OptimalBin::~OptimalBin() {
	// TODO Auto-generated destructor stub
}

