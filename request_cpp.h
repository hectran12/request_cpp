#ifndef REQUEST_CPP_H
#define REQUEST_CPP_H


#include <string>
#include <iostream>
#include <vector>
#include <algorithm> // std::transform
#include <string>    // std::string


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


	// set accept
	void setAcceptHeader(string acceptType);

	// set content type
	void setContentTypeHeader(string contentType);

	// set authorization
	void setAuthorizationHeader(string authorization);


	// set accept_language
	void setAcceptLanguageHeader(string acceptLanguage);

	// set user_agent
	void setUserAgentHeader(string userAgent);

	// set orgin
	void setOriginHeader(string origin);

	// set referer
	void setRefererHeader(string referer);

	// set cookie
	void setCookieHeader(string cookie);

	// set cache_control
	void setCacheControlHeader(string cacheControl);

	// set pragma
	void setPragmaHeader(string pragma);

	// set connection
	void setConnectionHeader(string connection);

	// set host
	void setHostHeader(string host);

	// set upgrade_insecure_requests
	void setUpgradeInsecureRequestsHeader(string upgradeInsecureRequests);

	// set accept_encoding
	void setAcceptEncodingHeader(string acceptEncoding);

	// set dnt
	void setDntHeader(string dnt);

	// set te
	void setTeHeader(string te);

	// set range
	void setRangeHeader(string range);

	// set if_modified_since
	void setIfModifiedSinceHeader(string ifModifiedSince);

	// set if_none_match
	void setIfNoneMatchHeader(string ifNoneMatch);

	// set if_range
	void setIfRangeHeader(string ifRange);

	// set if_unmodified_since
	void setIfUnmodifiedSinceHeader(string ifUnmodifiedSince);

	// set max_forwards
	void setMaxForwardsHeader(string maxForwards);

	// set proxy_authorization
	void setProxyAuthorizationHeader(string proxyAuthorization);

	// set accept_charset
	void setAcceptCharsetHeader(string acceptCharset);

	// set accept_datetime
	void setAcceptDatetimeHeader(string acceptDatetime);

	// set access_control_request_method
	void setAccessControlRequestMethodHeader(string accessControlRequestMethod);

	// set access_control_request_headers
	void setAccessControlRequestHeadersHeader(string accessControlRequestHeaders);

	// set priority
	void setPriorityHeader(string priority);

	// set sec-ch-ua
	void setSecChUaHeader(string secChUa);

	// set sec_ch_ua_mobile	
	void setSecChUaMobileHeader(string secChUaMobile);

	// set sec_ch_ua_platform
	void setSecChUaPlatformHeader(string secChUaPlatform);

	// set sec_fetch_dest
	void setSecFetchDestHeader(string secFetchDest);

	// set sec_fetch_mode
	void setSecFetchModeHeader(string secFetchMode);

	// set sec_fetch_site
	void setSecFetchSiteHeader(string secFetchSite);

	// set sec_fetch_user
	void setSecFetchUserHeader(string secFetchUser);

	// remove header
	bool removeHeader(string name);

	// remove headers
	int removeHeaders(vector<string> names, bool fall_count_return);

	// view headers
	void viewHeaders();


	// build header string
	string buildHeaders();

	// action get method
	string get();

	// action simple_get 
	string simple_get();
};


#endif
