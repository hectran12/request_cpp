# REQUEST_CPP (In development...)

Simple request library in c++

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

## License

[MIT](https://choosealicense.com/licenses/mit/)
