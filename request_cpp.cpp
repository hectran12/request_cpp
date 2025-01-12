#include "request_cpp.h"
#include <iostream>
#include <cstdio>
#include <memory>



using namespace std;

request::request(string url, string method)
{

	// set properties
	this->url = url; 
	this->method = method;

	this->silent = false; // disable show information when execute command

	/*
		If u want to enable silent mode, just call setSilent(true)
	*/

	if (!this->checkValidUrl(this->url))
	{
		throw validationException();
	}
}

void request::setUrl(string url)
{
	this->url = url;
	if (!this->checkValidUrl(this->url))
	{
		throw validationException();
	}
}

void request::setMethod(string method)
{
	this->method = method;
}


bool request::checkValidUrl(string url)
{
	// valid url must start with http:// or https://
	string validStart[2] = {"http://", "https://"}; 
	int sizeValid = sizeof(validStart) / sizeof(validStart[0]); 
	// check if url starts with http:// or https://
	for (int i = 0; i < sizeValid; i++)
	{
		if (url.find(validStart[i]) == 0)
		{
			return true;
		}
	}

	return false;
}


void request::setSilent(bool silent)
{
	this->silent = silent;
}


string request::execToCMD(const string& command) {
	unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(command.c_str(), "r"), _pclose);
	if (!pipe) {
		throw execException();
	}
	char buffer[128];
	string result;
	while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
		result += buffer;
	}
	return result; 
}

string request::simple_get()
{
	if (this->url.empty())
	{
		throw needMoreInfoException();
	}

	string command = "curl ";
	if (this->silent) command += "-s "; // added silent mode
	command += "-X GET " + this->url;


	return this->execToCMD(command);
}
