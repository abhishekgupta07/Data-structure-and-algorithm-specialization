#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HeapBuilder 
{
	
 private:
 		
  vector<int> data_;                       //declaring a dynamic array for storing elements from the user
  vector< pair<int, int> > swaps_;		   //declaring dynamic array for storing the swaps


//writing output or response
  void WriteResponse() const 
  {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) 
	{
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }



  
//reading data from user
  void ReadData() 
  {
    int n;
    cin >> n;
    data_.resize(n);  					 //resizing the vector
    for(int i = 0; i < n; ++i)
    cin >> data_[i];					//giving input to vector
  }

/*
  void GenerateSwaps() 
  {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) 
	  {
        if (data_[i] > data_[j]) 
		{
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }
  
 */
 
 
 //swap function
  
  void FastGenerateSwaps() 
  {
	swaps_.clear();
	for (int i = data_.size()/2; i >= 0; i--) 
	{
		SiftDown(i);
	}
  }
  
  
 
  
  void SiftDown(int i) 
  {
  	
	int minIndex = i;
	//getting left child
	int l = 2*i + 1;
	if(l < data_.size() && data_[l] < data_[minIndex])
		minIndex = l;
	//getting right child
	int r = 2*i + 2;
	if(r < data_.size() && data_[r] < data_[minIndex])
		minIndex = r;
	if(i!=minIndex)  //if i isn't equal to the minIndex then do swap opeartion
	{
		swap(data_[i], data_[minIndex]);
		swaps_.push_back(make_pair(i, minIndex));
		SiftDown(minIndex);
	}
  }




 public:
 //common public function for all private functions	
  void Solve() 
  {
    ReadData();
    // GenerateSwaps();
	FastGenerateSwaps();
    WriteResponse();
  }
  
};




int main() 
{
  //std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;  //declaring class object i.e., heap_builder
  heap_builder.Solve();		 //calling public function ( solve() )using class object i.e., heap_builder
  return 0;
}
