// Secret Log In

#include <iostream>
#include <string>

int main()
{
	std::cout << "\tSuper Secret Portal\n" << std::endl;
	
	std::string username, password;
	bool success;
	
	do
	{
		std::cout << "Username: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;
		
		if (username == "guest" || password == "guest")
		{
			std::cout << "\nWelcome, guest.\n" << std::endl;
			success = true;
		}
		else if (username == "William.C" && password == "conkers2")
		{
			std::cout << "\nWelcome, William.\n" << std::endl;
			success = true;
		}
		else
		{
			std::cout << "\nIncorrect username/password combination.\n" << std::endl;
			success = false;
		}
	} while (!success);
	
	
	return 0;
}