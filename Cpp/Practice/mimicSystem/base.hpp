#pragma once
#include <iostream>
#include <string>

using namespace std;

class Base{
	protected:
		string process_name;
		string b_status;
	public:
		void startProcess(string);
		virtual void startDownload() = 0;
};
