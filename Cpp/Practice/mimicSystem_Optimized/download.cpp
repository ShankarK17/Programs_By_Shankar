#include <iostream>
#include <string>
#include "download.hpp"

void Download::startDownload(){
	if(d_status){
		cout << "started downloading..." << endl;
		cout << "Download complete" << endl;
		i_status = 1;
	}
	else{
		cout << "couldn't download" << endl;
	}
};

