#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	map<int, string> stdData;
	stdData[1] = "Ajay"; //One-way of defining key-value pair for map;
	stdData.insert({2, "Raghav"});
	stdData.insert(make_pair(3,"Sourav"));
	stdData.emplace(4,"Manesh");

	for(const auto &[roll,name]: stdData){
		cout << "Student Roll: " << roll << "\tName: " << name << endl;
	}

	auto it = stdData.begin();
	for(int i = 1; i <= 4 ; i++){
		if(it->first == 3)
		{
			cout<<it->first<<" : "<<it->second<<endl;
			break;
		}

		it++;
	}

	return 0;
}







