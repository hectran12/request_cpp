#include <iostream>
#include "request_cpp.h"

using namespace std;

void outBar(int amount)
{
	for (int i = 0; i < amount; i++) cout << "=";
	cout << endl;
}


void test_case_1()
{
	cout << "Test case 1: valid url" << endl;
	try {
		request obj("hello", "get");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	outBar(100);
}


void test_case_2()
{
	cout << "Test case 2: show properties" << endl;
	request req("https://kiemtraip.com", "get");
	cout << "url: " << req.url << endl;
	cout << "method: " << req.method << endl;

	outBar(100);
}

void test_case_3()
{
	request req("https://kiemtraip.com", "get");
	cout << "Test case 3: test set properties (url)" << endl;
	try {
		req.setUrl("hello");
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	outBar(100);
}

void test_case_4()
{
	request req("https://kiemtraip.com", "get");
	cout << "Test case 4: test set properties" << endl;
	req.setUrl("https://google.com");
	req.setMethod("get");
	cout << "url: " << req.url << endl;
	cout << "method: " << req.method << endl;
	outBar(100);
}

void test_case_5()
{
	/*
		cout << "Test case 5: test execToCMD" << endl;
		string command = "curl -X GET https://kiemtraip.com";
		try {
			cout << req.execToCMD(command) << endl;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}

	*/
}


void test_case_6()
{
	cout << "Test case 6: test simple_get" << endl;
	request obj2("https://kiemtraip.com/raw.php", "get");

	try {
		obj2.setSilent(true);
		cout << "Simple fetching ip: " << obj2.simple_get() << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}


	outBar(100);
}


void test_case_7()
{
	try
	{
		request req("https://kiemtraip.com", "get");

		cout << "Timeout of request: " << req.timeout << endl;

		req.setTimeout(120); // increasing timeout to 120s

		cout << "Timeout of request (after set): " << req.timeout << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	outBar(100);
}


void test_case_8()
{
	cout << "Test case 8: test headers" << endl;
	request req("https://google.com", "get");
	

	// set header with set method

	// type 1 (set header with some set method has been defined)
	req.setAcceptCharsetHeader("utf-8");
	req.setAcceptEncodingHeader("gzip, deflate, br");
	req.setAcceptLanguageHeader("en-US,en;q=0.9,vi;q=0.8");
	req.setConnectionHeader("keep-alive");
	req.setHostHeader("google.com");
	req.setUpgradeInsecureRequestsHeader("1");
	

	// type 2 (set multi headers with vector<header>)
	header h;
	h.name = "priority";
	h.value = "1";

	header h2;
	h2.name = "user-agent";
	h2.value = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0";

	vector<header> headers;
	headers.push_back(h);
	headers.push_back(h2);

	req.setHeaders(headers);


	// type 3 (set one header)
	req.setHeader("pragma", "no-cache");



	// view header method

	cout << "Header beforce remove called" << endl;
	req.viewHeaders();

	// remove header
	req.removeHeader("pragma"); // remove pragma header
	vector<string> names_to_remove = { "priority", "user-agent" };
	// set false if you want return the count of removed headers (success)
	// set true if you want return the count of removed headers (fall) 
	cout << "Total count remove success: " << req.removeHeaders(names_to_remove, false) << endl;

	cout << "Header after remove called" << endl;
	req.viewHeaders();


}


void test_case_9()
{
	cout << "Test case 9: test build headers";
	request req("https://google.com", "get");
	req.setAcceptCharsetHeader("utf-8");
	req.setAcceptEncodingHeader("gzip, deflate, br");
	req.setAcceptLanguageHeader("en-US,en;q=0.9,vi;q=0.8");
	req.setConnectionHeader("keep-alive");
	req.setHostHeader("google.com");
	req.setUpgradeInsecureRequestsHeader("1");

	cout << req.buildHeaders() << endl;
}


void test_case_10()
{
	cout << "Test case 10: test request (get method)" << endl;

	try
	{
		request req("https://parseapi.com/useragent", "get");

		req.setUserAgentHeader("Mozilla/5.0 (iPhone; CPU iPhone OS 17_7_2 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/17.4.1 Mobile/15E148 Safari/604.1");

		req.setSilent(true);

		cout << req.get() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	
}

int main()
{


	/*
		test_case_1();
		test_case_2();
		test_case_3();
		test_case_4();
		test_case_5();
		test_case_6();
		test_case_7();
	*/

	//test_case_8();
	//test_case_9();

	test_case_10();







	return 0;
}
