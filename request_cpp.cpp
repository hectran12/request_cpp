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



// TO DO: Set some properites headers
void request::setAcceptHeader(string acceptType)
{
	header h;
	h.name = "accept";
	h.value = acceptType;
	this->headers.push_back(h); // add header to the headers vector
}


void request::setContentTypeHeader(string contentType)
{
	header h;
	h.name = "content-type";
	h.value = contentType;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setAuthorizationHeader(string authorization)
{
	header h;
	h.name = "authorization";
	h.value = authorization;
}

void request::setAcceptLanguageHeader(string acceptLanguage)
{
	header h;
	h.name = "accept-language";
	h.value = acceptLanguage;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setUserAgentHeader(string userAgent)
{
	header h;
	h.name = "user-agent";
	h.value = userAgent;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setOriginHeader(string origin)
{
	header h;
	h.name = "origin";
	h.value = origin;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setRefererHeader(string referer)
{
	header h;
	h.name = "referer";
	h.value = referer;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setCookieHeader(string cookie)
{
	header h;
	h.name = "cookie";
	h.value = cookie;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setCacheControlHeader(string cacheControl)
{
	header h;
	h.name = "cache-control";
	h.value = cacheControl;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setPragmaHeader(string pragma)
{
	header h;
	h.name = "pragma";
	h.value = pragma;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setConnectionHeader(string connection)
{
	header h;
	h.name = "connection";
	h.value = connection;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setHostHeader(string host)
{
	header h;
	h.name = "host";
	h.value = host;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setUpgradeInsecureRequestsHeader(string upgradeInsecureRequests)
{
	header h;
	h.name = "upgrade-insecure-requests";
	h.value = upgradeInsecureRequests;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setAcceptEncodingHeader(string acceptEncoding)
{
	header h;
	h.name = "accept-encoding";
	h.value = acceptEncoding;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setDntHeader(string dnt)
{
	header h;
	h.name = "dnt";
	h.value = dnt;
	this->headers.push_back(h); // add header to the headers vector
}


void request::setTeHeader(string te)
{
	header h;
	h.name = "te";
	h.value = te;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setRangeHeader(string range)
{
	header h;
	h.name = "range";
	h.value = range;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setIfModifiedSinceHeader(string ifModifiedSince)
{
	header h;
	h.name = "if-modified-since";
	h.value = ifModifiedSince;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setIfNoneMatchHeader(string ifNoneMatch)
{
	header h;
	h.name = "if-none-match";
	h.value = ifNoneMatch;
	this->headers.push_back(h); // add header to the headers vector
}


void request::setIfRangeHeader(string ifRange)
{
	header h;
	h.name = "if-range";
	h.value = ifRange;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setIfUnmodifiedSinceHeader(string ifUnmodifiedSince)
{
	header h;
	h.name = "if-unmodified-since";
	h.value = ifUnmodifiedSince;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setMaxForwardsHeader(string maxForwards)
{
	header h;
	h.name = "max-forwards";
	h.value = maxForwards;
	this->headers.push_back(h); // add header to the headers vector
}


void request::setProxyAuthorizationHeader(string proxyAuthorization)
{
	header h;
	h.name = "proxy-authorization";
	h.value = proxyAuthorization;
	this->headers.push_back(h); // add header to the headers vector
}


void request::setAcceptCharsetHeader(string acceptCharset)
{
	header h;
	h.name = "accept-charset";
	h.value = acceptCharset;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setAcceptDatetimeHeader(string acceptDatetime)
{
	header h;
	h.name = "accept-datetime";
	h.value = acceptDatetime;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setAccessControlRequestMethodHeader(string accessControlRequestMethod)
{
	header h;
	h.name = "access-control-request-method";
	h.value = accessControlRequestMethod;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setAccessControlRequestHeadersHeader(string accessControlRequestHeaders)
{
	header h;
	h.name = "access-control-request-headers";
	h.value = accessControlRequestHeaders;
	this->headers.push_back(h); // add header to the headers vector
}

void request::setPriorityHeader(string priority)
{
	header h;
	h.name = "priority";
	h.value = priority;
	this->headers.push_back(h); // add header to the headers vector
}


void request::setSecChUaHeader(string secChUa)
{
	header h;
	h.name = "sec-ch-ua";
	h.value = secChUa;
	this->headers.push_back(h);
}

void request::setSecChUaMobileHeader(string secChUaMobile)
{
	header h;
	h.name = "sec-ch-ua-mobile";
	h.value = secChUaMobile;
	this->headers.push_back(h);
}

void request::setSecChUaPlatformHeader(string secChUaPlatform)
{
	header h;
	h.name = "sec-ch-ua-platform";
	h.value = secChUaPlatform;
	this->headers.push_back(h);
}


void request::setSecFetchDestHeader(string secFetchDest)
{
	header h;
	h.name = "sec-fetch-dest";
	h.value = secFetchDest;
	this->headers.push_back(h);
}


void request::setSecFetchModeHeader(string secFetchMode)
{
	header h;
	h.name = "sec-fetch-mode";
	h.value = secFetchMode;
	this->headers.push_back(h);
}

void request::setSecFetchSiteHeader(string secFetchSite)
{
	header h;
	h.name = "sec-fetch-site";
	h.value = secFetchSite;
	this->headers.push_back(h);
}

void request::setSecFetchUserHeader(string secFetchUser)
{
	header h;
	h.name = "sec-fetch-user";
	h.value = secFetchUser;
	this->headers.push_back(h);
}

// TO DO: Remove header by name
/*
	name: string
	return: true (if removed), false (if not removed)
	what?: remove header by name
*/
bool request::removeHeader(string name)
{
	for (int i = 0; i < this->headers.size(); i++)
	{
		if (this->headers[i].name == name)
		{
			this->headers.erase(this->headers.begin() + i);
			return true;
		}
	}

	return false;
}


// TO DO: Remove headers by vector of names
/*
	names: vector of string
	fall_count_return: boolean (true - return countRemoveFail, false - return countRemoveSuccess)
	return: int
	what?: remove headers by vector of names
*/ 
int request::removeHeaders(vector<string> names, bool fall_count_return)
{
	int countRemoveSuccess = 0, countRemoveFail = 0;

	for (int i = 0; i < names.size(); i++)
	{
		if (this->removeHeader(names[i]))
		{
			countRemoveSuccess++;
		}
		else
		{
			countRemoveFail++;
		}
	}

	if (fall_count_return) return countRemoveFail; // if fall_count_return is true, return countRemoveFail
	else return countRemoveSuccess;
}

// TO DO: View headers
void request::viewHeaders()
{
	cout << "Total headers: " << this->headers.size() << endl;

	for (header h : this->headers)
	{
		cout << h.name << ": " << h.value << endl;
	}
}


// TO DO: Build headers
string request::buildHeaders()
{
	string headers = "";
	for (header h : this->headers)
	{
		headers += "-H \"" + h.name + ": " + h.value + "\" ";
	}
	return headers;
}


// TO DO: Get request
string request::get()
{
	if (this->url.empty())
	{
		throw needMoreInfoException();
	}
	string upperMethod = this->method;
	transform(upperMethod.begin(), upperMethod.end(), upperMethod.begin(), ::toupper);
	string command = "curl ";
	if (this->silent) command += "-s "; // added silent mode
	if (this->timeout > 0) command += "--max-time " + to_string(this->timeout) + " "; // added timeout
	command += "-X " + upperMethod + " " + this->url + " " + this->buildHeaders();
	return this->execToCMD(command); // action curl
}
