#include <iostream>
#include <string>
#include "download.hpp"

void Download::startDownload(){
	if(b_status == "In progress"){
		d_status = "download success";
		cout << "started downloading..." << endl;
		cout << "Download complete" << endl;
	}
	else{
		d_status = "download fail";
		cout << "couldn't download" << endl;
	}
};

