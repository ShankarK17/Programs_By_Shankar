#include "install.hpp"
#include <iostream>
#include <string>

using namespace std;

void Install::startInstall(){
	if(i_status){
		cout << "started installing..." << endl;
		cout << "Installtion Complete" << endl;
		d_status = 0;
		i_status = 0;
	}
	else{
		 cout << "Couldn't install" << endl;
		 cout << "Installation Fail" << endl;
	}
};

int Base::d_status = 0;
int Base::i_status = 0;

int Install::getDstatus(){
	return d_status;
}

int Install::getIstatus(){
	return i_status;
}


int main(){
	Install obj;
	obj.startProcess("Game");
	obj.startDownload();
	obj.startInstall();

	return 0;
}

