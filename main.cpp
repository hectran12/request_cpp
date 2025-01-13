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

int main()
{


	test_case_1();
	test_case_2();
	test_case_3();
	test_case_4();
	test_case_5();
	test_case_6();
	test_case_7();
	








	return 0;
}
