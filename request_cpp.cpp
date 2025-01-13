#include "request_cpp.h"
#include <iostream>
#include <cstdio>
#include <memory>



using namespace std;


//TO DO: Implement the request class here
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


// TO DO: Set url to the request
void request::setUrl(string url)
{
	this->url = url;
	if (!this->checkValidUrl(this->url))
	{
		throw validationException();
	}
}


// TO DO: Set method to the request
void request::setMethod(string method)
{
	this->method = method;
}

// TO DO: Check valid url
/*
	url: string
	return: boolean (true - if alid, false - if invalid)
*/
bool request::checkValidUrl(string url)
{
	// valid url must start with http:// or https://
	string validStart[2] = { "http://", "https://" };
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

// TO DO: Set silent to the exec command (curl)
/*
	silent: boolean
	Meaning: true - silent mode, false - show information when execute command
*/
void request::setSilent(bool silent)
{
	this->silent = silent;
}



// TO DO: Execute command to the cmd
/*
	command: string
	return: string

	What?: Execute command to the cmd and return the result
*/
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


// TO DO: Simple get request
/*
	return: string

	What?: Simple get request to the url
*/
string request::simple_get()
{
	if (this->url.empty())
	{
		throw needMoreInfoException();
	}

	string command = "curl ";
	if (this->silent) command += "-s "; // added silent mode
	if (this->timeout > 0) command += "--max-time " + to_string(this->timeout) + " "; // added timeout
	command += "-X GET " + this->url;


	return this->execToCMD(command); // action curl
}


// TO DO: Set headers to the request
/*
	headers: vector of header struct
	what?: set headers to the request (headers - argument is a vector of header struct)
*/
void request::setHeaders(vector<header> headers)
{
	for (header h : headers)
	{
		this->headers.push_back(h); // add header to the headers vector
	}
}


// TO DO: Set header to the request 
/*
	name: string
	value: string
	what?: set header to the request (header - argument name and value)
*/
void request::setHeader(string name, string value)
{
	header h;
	h.name = name;
	h.value = value;
	this->headers.push_back(h); // add header to the headers vector
}


// TO DO: Set timeout to the request
void request::setTimeout(int timeout)
{
	this->timeout = timeout;
}
