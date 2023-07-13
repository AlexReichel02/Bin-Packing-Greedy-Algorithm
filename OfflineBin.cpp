/***************************************************************
  Student Name: Alex Reichel
  File Name: OfflineBin.cpp
  Assignment number Project 04

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "OfflineBin.hpp"

OfflineBin::OfflineBin() {
	// TODO Auto-generated constructor stub

}

void OfflineBin::readFile(){
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


}

void OfflineBin::swap(float *a,float *b){
	float temp = *a;
	*a = *b;
	*b = temp;
}

int OfflineBin::getNumFirstFitBins(){
	return numFirstFitBins;

}

int OfflineBin::getNumBestFitBins(){
	return numBestFitBins;

}

void OfflineBin::firstFit(float arr[],int n){



		float c = 1.0;

		int res = 0;
		float bin_rem[n];
	    for (int i = 0; i < n; i++) {
	        int j;
	        vector<float> temp;
	        for (j = 0; j < res; j++) {
	            if (bin_rem[j] >= arr[i]) {

	            	insert2D(j,arr[i]);
	                bin_rem[j] = bin_rem[j] - arr[i];
	                break;
	            }
	        }
	        temp.push_back(arr[i]);
	        if (j == res) {
	        	firstFitBins.push_back(temp);
	            bin_rem[res] = c - arr[i];
	            res++;
	            temp.clear();
	        }

	    }



	    numFirstFitBins = res;
	}


void OfflineBin::firstFitTest(){
	 float bins[12];
	 for(int i=0;i<12;i++){
		bins[i] = binValues[i];
		}

	int n = sizeof(bins) / sizeof(bins[0]);
	sort(bins,bins + n,greater<float>());
	firstFit(bins,n);
}

void OfflineBin::bestFit(float arr[],int n){
	    int res = 0;
	    float c = 1.0;
	    float bin_rem[n];

	    for (int i = 0; i < n; i++) {
	    	vector<float>temp;
	        int j;
	        int min = c + 1, bi = 0;

	        for (j = 0; j < res; j++) {
	            if (bin_rem[j] >= arr[i] && bin_rem[j] - arr[i] < min) {
	                bi = j;
	                min = bin_rem[j] - arr[i];
	                insert2DBest(j,arr[i]);
	            }
	        }
	        temp.push_back(arr[i]);
	        if (min == c + 1) {
	        	bestFitBins.push_back(temp);
	        	temp.clear();
	        	bin_rem[res] = c - arr[i];
	        	            res++;
	        }
	        else
	            bin_rem[bi] -= arr[i];
	    }
	    numBestFitBins = res;
}

void OfflineBin::bestFitTest(){
	     float bins[12];
		 for(int i=0;i<12;i++){
			bins[i] = binValues[i];
			}

		int n = sizeof(bins) / sizeof(bins[0]);
		sort(bins,bins + n,greater<float>());

		bestFit(bins,n);
}


void OfflineBin::insert2DBest(int row,float num){
	for (int i = 0; i < bestFitBins.size(); i++)
			    {

		if(i == row){
			bestFitBins[i].push_back(num);
		}

			        for ( int j = 0; j < bestFitBins[i].size(); j++)
			        {


			        	}
			       // cout<<endl;

			        }
}

void OfflineBin::printBestFit(){
	cout<<"Offline Best Fit results"<<endl;
		for (int i = 0; i < bestFitBins.size(); i++)
					    {

					cout<<"Bin number : " << i+1 << endl;
							for ( int j = 0; j < bestFitBins[i].size(); j++)
					        {
					        	cout<<bestFitBins[i][j] << " ";

					        	}
					        cout<<endl;

					        }

}

void OfflineBin::insert2D(int row,float num){
	for (int i = 0; i < firstFitBins.size(); i++)
			    {

		if(i == row){
			firstFitBins[i].push_back(num);
		}

			        for ( int j = 0; j < firstFitBins[i].size(); j++)
			        {


			        	}
			       // cout<<endl;

			        }
			    }


void OfflineBin::printFirstFit(){
	cout<<"Offline First Fit results"<<endl;
	for (int i = 0; i < firstFitBins.size(); i++)
				    {

				cout<<"Bin number : " << i+1 << endl;
						for ( int j = 0; j < firstFitBins[i].size(); j++)
				        {
				        	cout<<firstFitBins[i][j] << " ";

				        	}
				        cout<<endl;

				        }
				    }


OfflineBin::~OfflineBin() {
	// TODO Auto-generated destructor stub
}

