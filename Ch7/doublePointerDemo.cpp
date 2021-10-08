#include <iostream>
#include <string>

int main()
{
	std::string aString = "Hello there";
	
	std::string* pString = &aString;
	
	std::string** ppString = &pString;
	
	std::cout << **ppString << std::endl;
	
	std::cout << (*ppString)->size() << std::endl;
	
	return 0;
}