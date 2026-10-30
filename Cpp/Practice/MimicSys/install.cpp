#include "install.hpp"
#include "download.hpp"
#include <iostream>


void Install::startInstall(Download& dp){
			if(dp.download_status == "download success"){
				install_status = "install success";
				std::cout << "started installing...\n";
				std::cout << "Install Complete\n";

			}
			else{
				install_status = "install failed";
				std::cout << "Couldn't install\n";
			}
		}
