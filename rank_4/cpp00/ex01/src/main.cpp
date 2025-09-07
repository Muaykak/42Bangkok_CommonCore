#include "main.hpp"

static std::string userInputPromt(const std::string &str)
{
	std::string user_input;
	bool		flag;

	std::cout << std::endl << str << std::endl;
	flag = false;
	while (flag == false)
	{
		std::cout << "> ";
		std::getline(std::cin, user_input);
		if (user_input.find_first_not_of(" \t\n\v\f\r") == user_input.npos)
			flag = false;
		else
			flag = true;
	}
	return (user_input);
}

static bool	ftConvertToNumber(std::string &str, int &number)
{
	if (str.empty())
		return (false);
	
	size_t	start_trim = str.find_first_not_of(" 012345678");
	if (start_trim != str.npos)
		return (false);
	start_trim = str.find_first_of("012345678");
	size_t	end_trim = str.find_last_of("0123456789");
	if (start_trim == str.npos || end_trim == str.npos || start_trim != end_trim)
		return (false);
	number = str[start_trim] - 48;
	return (true);
}

static void searchCommand(PhoneBook &book)
{
	std::cout << "SEACH" << std::endl << std::endl;
	if (book.isEmpty())
	{
		std::cout << "The book is currently has no contact." << std::endl;
		return ;
	}
	book.displayBook();

	std::string	user_input;
	int number;
	while (true)
	{
		user_input = userInputPromt("Enter the index (1 - 8) [0 to exit to go back]");
		if (ftConvertToNumber(user_input, number) == true)
		{
			if (number == 0)
				std::cout << "Quit from search mode" << std::endl;
			else
				book.showContact(number);
			return ;
		}
		else
			std::cout << "invalid input, or the number is out of range, try again" << std::endl;
	}
}

static bool	addCommand(PhoneBook &book)
{
	std::cout << "ADD" << std::endl;

	std::string	user_input[5];

	user_input[0] = userInputPromt("Enter your firstname");
	user_input[1] = userInputPromt("Enter your lastname");
	user_input[2] = userInputPromt("Enter your nickname");
	user_input[3] = userInputPromt("Enter your phone number");
	user_input[4] = userInputPromt("Enter your Darkest Secret");

	int	contact_index = book.addContact(user_input[0], user_input[1], user_input[2], user_input[3], user_input[4]);

	if (contact_index == 0)
		return (false);	
	std::cout << std::endl;
	book.showContact(contact_index);

	std::cout << std::endl << "Contact was added successfully" << std::endl;
	return (true);
}

static void mainPrompt(PhoneBook &book)
{
	std::string	user_input;

	while (true)
	{
		user_input = userInputPromt("type ('ADD', 'SEARCH', or 'EXIT')");
		if (user_input == "ADD")
		{
			if (addCommand(book) == false)
				return ;
		}
		else if (user_input == "SEARCH")	
			searchCommand(book);
		else if (user_input == "EXIT")
		{
			std::cout << "EXIT the program" << std::endl;
			return ;
		}
	}
}

int	main(void)
{
	PhoneBook Book;

	std::cout << "Wellcome to " << PROGRAM_NAME << std::endl;
	mainPrompt(Book);
	return (0);
}