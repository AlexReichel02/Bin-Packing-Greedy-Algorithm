/***************************************************************
  Student Name: Alex Reichel
  File Name: OnlineBin.cpp
  Assignment number Project 04

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "OnlineBin.hpp"

OnlineBin::OnlineBin() {
	// TODO Auto-generated constructor stub

}

void OnlineBin::readFile(){
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

void OnlineBin::firstFit(){
	   float bins[12];
		for(int i=0;i<12;i++){
			bins[i] = binValues[i];
		}

		int n = sizeof(bins) / sizeof(bins[0]);

		float c = 1.0;
	    int res = 0;
	    float bin_rem[n];
	    for (int i = 0; i < n; i++) {
	            
	            int j;
	            vector<float> temp;
	            for (j = 0; j < res; j++) {

	                if (bin_rem[j] >= bins[i]) {


	                	insert2D(j,bins[i]);

	                	//cout<<j<< " " << bins[i]<< " ";

	                    bin_rem[j] = bin_rem[j] - bins[i];


	                    break;
	                }
	            }
	            temp.push_back(bins[i]);
	           
	            if (j == res) {
	            	firstFitBins.push_back(temp);
	            	bin_rem[res] = c - bins[i];

	                res++;
	                temp.clear();

	        }

	    }

	  
	    numFirstFitBins = res;
	}



void OnlineBin::insert2D(int row,float num){
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


void OnlineBin::printFirstFit(){
	cout<<"Online First Fit results"<<endl;
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



void OnlineBin::nextFit(){
	        float bins[12];
			for(int i=0;i<12;i++){
				bins[i] = binValues[i];
			}

			int n = sizeof(bins) / sizeof(bins[0]);


	        int res = 0;
	        float c =1.0;
	        float bin_rem = c;
	        vector<float> temp;
	            for (int i = 0; i < n; i++) {

	            			if (bins[i] > bin_rem) {

	            					nextFitBins.push_back(temp);
	            					temp.clear();
	            					res++;

	            					bin_rem = c - bins[i];

	        } else{
	            bin_rem -= bins[i];

	        }

	        temp.push_back(bins[i]);

	     
	        numNextFitBins = res;

	    }

	    cout<<endl;

}

	void OnlineBin::printNextFit(){
		cout<<"Online next Fit results"<<endl;
			for (int i = 0; i < nextFitBins.size(); i++)
				    {

				cout<<"Bin number : " << i+1 << endl;
						for ( int j = 0; j < nextFitBins[i].size(); j++)
				        {
				        	cout<<nextFitBins[i][j] << " ";

				        	}
				        cout<<endl;

				        }
				    }

	void OnlineBin::bestFit(){
	            float bins[12];
				for(int i=0;i<12;i++){
					bins[i] = binValues[i];
				}

				int n = sizeof(bins) / sizeof(bins[0]);

				float c = 1.0;

				int res = 0;
				float bin_rem[n];

				    for (int i = 0; i < n; i++) {
				    	vector<float>temp;
				        int j;
				        int min = c + 1, bi = 0;


				        for (j = 0; j < res; j++) {

				            if (bin_rem[j] >= bins[i] && bin_rem[j] - bins[i] < min) {
				                bi = j;
				                min = bin_rem[j] - bins[i];
				              
				                insert2DBest(j,bins[i]);
				            }
				        }


				        temp.push_back(bins[i]);

				        if (min == c + 1) {
				        	bestFitBins.push_back(temp);
				        	temp.clear();
				            bin_rem[res] = c - bins[i];
				            res++;
				           // cout<<endl;
				        }else{
				            bin_rem[bi] -= bins[i];
				        }

				    


				    }
				    
				    numBestFitBins = res;
}

void OnlineBin::insert2DBest(int row,float num){
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

void OnlineBin::printBestFit(){
	cout<<"Online Best Fit results"<<endl;
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

int OnlineBin::getNumBestFitBins(){
	return numBestFitBins;

}

int OnlineBin::getNumNextFitBins(){
	return numNextFitBins;

}

int OnlineBin::getNumFirstFitBins(){
	return numFirstFitBins;

}


OnlineBin::~OnlineBin() {
	// TODO Auto-generated destructor stub
}

