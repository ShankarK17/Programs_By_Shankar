#include "base.hpp"
#include "download.hpp"
#include "install.hpp"
#include <iostream>

void Base::endProcess(Install& ip){
	if(ip.install_status == "install success"){
		status = "Complete";
		std::cout << "Process Status: " << status << std::endl;
	}
	else{
		status = "incomplete";
		std::cout << "Status: " << status << std::endl;
	}
}

int main(){
	Base base_obj;
	Download download_obj;
	download_obj.startDownload(base_obj);
	Install install_obj;
	install_obj.startInstall(download_obj);
	base_obj.endProcess(install_obj);

	return 0;
}


















