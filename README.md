# REQUEST_CPP (In development...)

Simple request library in c++

## Important (MUST READ BEFORE USING IN YOUR PROJECT)
This library uses curl - a feature available on windows (or some other platforms that support it) to make requests. So it may not work on some operating systems. Consider before using.

## Installation
Add the files (request_cpp.h, request_cpp.cpp) to your project
```cpp
#include <iostream>
#include "request_cpp.h"
```

## Usage
1. simple_get : perform a simple get request
```cpp
request obj2("https://google.com", "get");
try {
	obj2.setSilent(true); // This is to hide the download bar when executing exec curl
	cout << "Content: " << obj2.simple_get() << endl;
}
catch (exception& e) {
	cout << e.what() << endl;
}
```
2. setTimeout : Increase request execution time
```cpp
try
{
	request req("https://google.com", "get");

	cout << "Timeout of request: " << req.timeout << endl;

	req.setTimeout(120); // increasing timeout to 120s

	cout << "Timeout of request (after set): " << req.timeout << endl;

}
catch (exception& e)
{
	cout << e.what() << endl;
}
```
3. Some methods to add headers
```cpp
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

```
4. get : perform get request, including set headers (different from simple_get)
```cpp
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
``


## TO DO Today
1. Optimize url for utf8 (15/01/2025) - unfinished
2. Update post method (15/01/2025) - unfinished


## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

Note: Maybe I don't care, because this is my study project. I write for fun, so I have no intention of developing... :D

## License

[MIT](https://choosealicense.com/licenses/mit/)
