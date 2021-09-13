// Demonstrating Continue and Break

#include <iostream>

int main()
{
	int count = 0;
	while (true)
	{
		count +=1;
		
		if (count > 10)
			break; // end when count is more than 10
		
		if (count == 5)
			continue; // skip printing number 5
		
		std::cout << count << std::endl;
	}
	
	return 0;
}