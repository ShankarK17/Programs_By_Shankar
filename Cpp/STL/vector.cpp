#include <iostream>
#include <vector> // vector is a class template we can create vector of any datatype

using namespace std;

int main(){
	vector<int> vec1; // vector (dynamic Array) of type integer
	vec1.push_back(10); // inserts element in vector from back
	
	cout << "Capacity: " <<  vec1.capacity() << endl; // tells the actual size of vector in memory	
	cout << "Size: " << vec1.size() << endl; // gives the size of vector
	
	vec1.push_back(20);
	//cout << "Capacity: " <<  vec1.capacity() << endl; // increases the size of vector dynamically	
	
	vec1.push_back(30);
	vec1.push_back(40);
	//cout << "Capacity: " <<  vec1.capacity() << endl; // it increases size 2x of the previous size to hold more elements	
	
	cout << "At front: " << vec1.front() << endl; // gives the element at begining
	cout << "At Back: " << vec1.back() << endl; //gives the element at last/end
	cout << "At index 1: " << vec1[1] << endl; // works like array with [] doesn't perform bound checks
	cout << "At index 3: " << vec1.at(3) << endl; //provides function at() to get element at specific position with bound checks 
						      //will try an exception out of range of the position is invalid
	
	vec1.insert(vec1.begin(), 70); //inserts value at beginning
	vec1.insert(vec1.end(), 90);	
	cout << '{';
	for(int value: vec1){
		cout << value << ' ';
	}
	cout << "}\n";
	vec1.erase(vec1.begin()); //will remove the first element
	//vec1.clear(); //will delete the entire vector
	cout << "After erase\n";
	cout << '{';
	for(int value: vec1){
		cout << value << ' ';
	}
	cout << "}\n";
	return 0;
}



















