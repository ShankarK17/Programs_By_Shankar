#include "download.hpp"
#include "base.hpp"
#include <iostream>

class Base;

void Download::startDownload(Base& bp){
			 if(bp.status == "In progress"){
				download_status = "download success";
				std::cout << "started downloading.....\n";
				std::cout << "Download Complete\n";
			 }
			 else{
				 download_status = "downlaod failed";
				 std::cout << "couldn't download\n";
			 }
		 }
