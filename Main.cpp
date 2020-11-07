#include <iostream> //std::cout
#include <fstream> //std::ifstream, std::ostream
#include <string> //std::string
#include <vector> //std::vector
#include <chrono> //std::start, std::stop, std::duration
#include <iterator> //std::ostream_iterator
#include <cstdlib> //std::rand()
#include <ctime> //std::time
#include "ErrorSwitch.h"
#include "List.h""


using namespace std;
using namespace std::chrono;

//Swaps two elements on list
void swapFunc(vector<int>& vec, int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

//BubbleSort Function (Worst Case Complexity)
void bubbleSort(vector<int>& arr, int vectorSize, int ascDec) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < vectorSize - 1; i++) {
			switch (ascDec) {
			case 0:
				if (arr[i] > arr[i + 1]) {
					swapFunc(arr, i, i + 1);
					sorted = false;
				}
				break;
			case 1:
				if (arr[i] < arr[i + 1]) {
					swapFunc(arr, i, i + 1);
					sorted = false;
				}
				break;
			}
		}
	}
}

//Insertion Sort Function (Best Case Complexity)
void insertionSort(vector<int>& arr, int vectorSize, int ascDec){
	int i, key, j;
	for (i = 1; i < vectorSize; i++)
	{
		key = arr[i];
		j = i - 1;
		switch (ascDec){
		case 0:
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			break;
		case 1:
			while (j >= 0 && arr[j] < key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			break;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int inputData;
	vector<int> inputVector;
	//Open file
	ifstream file("input-a1q1.txt");
	//Error Handling
	if (!file) {
		cout << "There was an error opening the file." << endl;
		return 0;
	}
	//Fail if string is given instead of int
	if (file.fail()) {
		cout << "invalid data type" << endl;
		return 0;
	}

	//store file in vector
	while (file >> inputData) {
		inputVector.push_back(inputData);
	}
	if (inputVector.size() < 4) {
		cout << "Error, file format invalid" << endl;
		return 0;
	}

	//Initialize Object of ErrorSwitch
	ErrorSwitch errorCheck;

	//Error first two lines
	for (int i = 0; i < 2; i++) {
		//Convert input string to int
		errorCheck.lineCheck = inputVector[i];
		//Store result of check
		bool checkResult = errorCheck.errorCheck();
		//Exit if input invalid
		if (!checkResult) {
			cout << "Error on line " << i + 1 << " of file. '"<< inputVector[i]<<"' is not a valid input"<< endl;
			return 0;
		}
	}

	//Line three and four checks
	errorCheck.lineCheck = inputVector[2];
	bool checkResult = errorCheck.errorCheck2();
	if (!checkResult) {
		cout << "Error on line 3 of file." << endl;
		return 0;
	}

	errorCheck.listSize = inputVector.size() - 3;
	checkResult = errorCheck.errorCheck3();
	//Specifies error location for debugging
	if (!checkResult) {
		cout << "Error list size '"<< inputVector[2] <<"' does not match expected input '" << errorCheck.listSize << "'" << endl;
		return 0;
	}

	//Create Vector for Sorting
	vector<int> sortingVector;
	for (int i = 3; i <= inputVector.size()-1; i++) {
		sortingVector.push_back(inputVector[i]);
	} 
	
	//Time Taken to sort
	auto start = high_resolution_clock::now();
	//Switch for which sorting method to use
	switch (inputVector[1]) {
	//Insertion Sort
	case 0:
		for (int i = 0; i <= 1; i++) {
			insertionSort(sortingVector, sortingVector.size(), inputVector[0]);
		}
		break;
	//Bubble Sort
	case 1:
		for (int i = 0; i <= 1; i++){
		bubbleSort(sortingVector, sortingVector.size(), inputVector[0]);
		}
		break;
	}

	//End time of function
	auto stop = high_resolution_clock::now();
	//Find total time required
	duration<double, milli> duration = stop - start;

	// Create and open a text file
	ofstream myFile("output-a1q1.txt");
	// Write time to the file then loop through and display sorted vector
	myFile << duration.count() <<endl;
	for (vector<int>::const_iterator i = sortingVector.begin(); i != sortingVector.end(); ++i) {
		myFile << *i << ' ';
	}
	// Close the file
	myFile.close();

	//Question 2
	list myList;

	//Open file
	ifstream file2("input-a1q2.txt");
	//Error Handling
	if (!file2) {
		cout << "There was an error opening the file." << endl;
		return 0;
	}
	//Fail if string is given instead of int
	if (file2.fail()) {
		cout << "invalid data type" << endl;
		return 0;
	}

	//Write size to variable
	file2 >> inputData;

	// Create and open a text file
	ofstream myFile2("output-a1q2.txt");

	//Insert at beginning with random values
	auto start1 = high_resolution_clock::now();
	for (int i = 0; i < inputData; i++) {
		int j = rand();
		myList.insertAtBeginning(j);
	}

	auto stop1 = high_resolution_clock::now();
	//Find total time required
	auto duration1 = duration_cast<milliseconds>(stop1 - start1);
	myFile2 << duration1.count() << endl;

	auto start2 = high_resolution_clock::now();
	//Delete from start of list 
	for (int i = 0; i < inputData; i++) {;
		myList.deleteFromBeginning();
	}
	auto stop2 = high_resolution_clock::now();
	//Find total time required
	auto duration2 = duration_cast<milliseconds>(stop2 - start2);
	myFile2 << duration2.count() << endl;

	auto start3 = high_resolution_clock::now();
	//Insert at end with random values
	for (int i = 0; i < inputData; i++) {
		int j = rand();
		myList.insertAtEnd(j);
	}
	auto stop3 = high_resolution_clock::now();
	//Find total time required
	auto duration3 = duration_cast<milliseconds>(stop3 - start3);
	myFile2 << duration3.count() << endl;

	auto start4 = high_resolution_clock::now();
	//Delete from end of list 
	for (int i = 0; i < inputData; i++) {
		;
		myList.deleteFromEnd();
	}
	auto stop4 = high_resolution_clock::now();
	//Find total time required
	auto duration4 = duration_cast<milliseconds>(stop4 - start4);
	myFile2 << duration4.count() << endl;

	return 0;
	
}
