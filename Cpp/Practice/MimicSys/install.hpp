#pragma once
#include <iostream>
#include <string>

class Download;

class Install{
	public:
		std::string install_status;
		void startInstall(Download& dp);
};

