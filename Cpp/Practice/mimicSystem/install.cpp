#include "install.hpp"
#include <iostream>
#include <string>

using namespace std;

void Install::startInstall(){
	if(d_status == "download success"){
		cout << "started installing..." << endl;
		i_status = "install success";
		cout << "Installation Complete" << endl;
		cout << "Process " << process_name << " Complete" << endl;
	}
	else{
		 cout << "Couldn't install" << endl;
		 i_status = "install fail";
	}
};

int main(){
	Install obj;
	obj.startProcess("Game");
	obj.startDownload();
	obj.startInstall();

	return 0;
}

