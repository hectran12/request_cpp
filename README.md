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

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

Note: Maybe I don't care, because this is my study project. I write for fun, so I have no intention of developing... :D

## License

[MIT](https://choosealicense.com/licenses/mit/)
