#ifndef REQUEST_CPP_H
#define REQUEST_CPP_H


#include <string>
#include <iostream>
#include <vector>

using namespace std;


struct header {
	string name;
	string value;
};

class validationException : public exception
{
public:
	const char* what() const throw()
	{
		return "Invalid URL -> url must startwith http:// or https://";
	}

};

class execException : public exception
{
public:
	const char* what() const throw()
	{
		return "Error when execute command";
	}
};


class needMoreInfoException : public exception
{
public:
	const char* what() const throw()
	{
		return "Need more information (maybe lost url or method)";
	}

};


class request {
public:
	string url; // define url as a string
	string method; // define method request as a string (includes get, post, put, delete, etc...)
	bool silent; // define silent as a boolean (true or false)
	vector<header> headers; // define headers as a vector of header struct

	int timeout = 60; // define timeout as an integer (default is 60s)


	// main constructor (initialize url and method, ...)
	request(string url, string method);

	// exec to cmd
	string execToCMD(const string& command);

	// check url is valid
	bool checkValidUrl(string url);

	// set url to the request
	void setUrl(string url);

	// set method to the request
	void setMethod(string method);

	// set silent to the exec command
	void setSilent(bool silent);


	// set header to the request (headers - argument is a vector of header struct)
	void setHeaders(vector<header> headers);
	
	// set header to the request (header - argument name and value)
	void setHeader(string name, string value);

	// set timeout to the request 
	void setTimeout(int timeout);


	// action simple_get 
	string simple_get();
};


#endif
