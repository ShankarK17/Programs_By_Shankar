#include <iostream>
#include <cstring>

class Data{
	private:
		char *name;
		int age;
	public:
		Data(const char *input){
			int len = std::strlen(input);
			name = new char[len+1];//new allocates dynamic memory in heap
					       // of size 1 more than len of string from command line args
					       // and return the address of the first byte.
			std::strcpy(name, input);
		}
		void destroy(){
			delete[] name; // free the allocated memory 
		}
		void display(){
			std::cout << "Name: " << name << std::endl;
		}
};

int main(int argc, char *argv[]){
	int n = argc - 1;
	Data **d = new Data*[n]; //Array of pointer to create multiple pointers to object of type Data. 
	for(int i = 0; i<n; i++){
		d[i] = new Data(argv[i+1]);
	}

	for(int j = 0; j<n; j++){
		d[j]->display();
	}
	for(int k = 0; k<n; k++){
		d[k]->destroy();
		delete d[k];
	}
	delete[] d;

	return 0;	
}


