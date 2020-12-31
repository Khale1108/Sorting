#include "MergeSort.h"
#include <iostream>

void merge(vector<int>& arr, int start, int middle, int end) 
{
	//Create left and right array. Each time the merge function is call the indexes included of the array 
	//will consist of left and right subsections of respective recursive calls.
	vector<int> lArray(middle-start+1);
	vector<int> rArray(end - middle);

	//Current It will track the recombinations of the main array as things are added back as the recursive calls pop off the stack.
	int rightIt = 0;
	int leftIt = 0;
	int currentIt = start;

	//Copy over elements from called for array indexes from the recursive calls. This will get larger as items are called from popping off the stack.
	for (int i = 0; i<lArray.size(); i++) 
	{
		lArray[i] = arr[i+start];
	}

	for (int i = 0; i < rArray.size(); i++)
	{
		rArray[i] = arr[middle + i + 1];
	}

	//Merge the two arrays based on the values of each array. The left will be <= if the elements are equal to maintain stability this is needed.
	//Stability retains the position of equal value elements of the array.
	while (leftIt<lArray.size() && rightIt<rArray.size())
	{
		if (lArray[leftIt]<=rArray[rightIt]) 
		{
			arr[currentIt] = lArray[leftIt];
			leftIt++;
		}
		else 
		{
			arr[currentIt] = rArray[rightIt];
			rightIt++;
		}

		currentIt++;
	}


	//Add any remaining elments to the end of the arrya if the 2 arrays are unequal in lenght.
	while (leftIt < lArray.size())
	{
		arr[currentIt] = lArray[leftIt];
		leftIt++;
		currentIt++;
	}

	while (rightIt < rArray.size())
	{
		arr[currentIt] = rArray[rightIt];
		rightIt++;
		currentIt++;
	}
}

void mergeSort(vector<int>& arr, int start, int end) 
{
	if (start<end) 
	{
		int middle = (start+end) / 2;

		mergeSort(arr, start, middle);
		mergeSort(arr,middle+1,end);
		merge(arr, start, middle, end);
	}

}
