#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	_oldest_index = 0;
}

int	PhoneBook::addContact(const std::string &firstname,
			const std::string &lastname,
			const std::string &nickname,
			const std::string &phone_num,
			const std::string &secret)
{
	Contact	*target = NULL;

	if (firstname.empty() || lastname.empty() || nickname.empty() || phone_num.empty() || secret.empty())
	{
		std::cout << "you should not add emptystring to Contact" << std::endl;
		return (0);
	}
	for (int i = 0; i < 8; i++)
	{
		if (_contact_list[i].isEmpty() == true)
		{
			target = &(_contact_list[i]);
			_newest_index = i + 1;
			break;
		}
	}
	if (target == NULL)
	{
		target = &(_contact_list[_oldest_index]);
		_newest_index = _oldest_index + 1;
		_oldest_index = (_oldest_index + 1) % 7;
	}
	target->setInfo(firstname, lastname, nickname, phone_num, secret);
	std::cout << "_newest_index: " << _newest_index << std::endl;
	return (_newest_index);
}

bool	PhoneBook::isEmpty(void)
{
	for (int i = 0; i < 8; i++)
	{
		if (this->_contact_list[i].isEmpty() == false)
			return (false);
	}
	return (true);
}

static void	displayEachBlock(std::string &str)
{
	std::cout << '|';
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::right << std::setfill(' ') << std::setw(10) << str;
}

static void	displayEachRow(int index, std::string firstname,
			std::string lastname, std::string nickname)
{
	std::cout << '|';
	std::cout << std::right << std::setfill(' ') << std::setw(10) << index;
	displayEachBlock(firstname);
	displayEachBlock(lastname);
	displayEachBlock(nickname);
	std::cout << '|' << std::endl;
}

void	PhoneBook::displayBook(void)
{
	if (this->isEmpty() == true)
		return ;
	std::cout << std::setfill('-') << std::setw(45) << "" << std::endl;
	std::cout << '|';
	std::cout << std::right << std::setfill(' ') << std::setw(11) << "Index|";
	std::cout << std::right << std::setfill(' ') << std::setw(11) << "Firstname|";
	std::cout << std::right << std::setfill(' ') << std::setw(11) << "Lastname|";
	std::cout << std::right << std::setfill(' ') << std::setw(11) << "Nickname|";
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contact_list[i].isEmpty() == false)
			displayEachRow(i + 1, this->_contact_list[i].getFirstName(),
				this->_contact_list[i].getLastName(),
				this->_contact_list[i].getNickName());
	}
	std::cout << std::setfill('-') << std::setw(45) << "" << std::endl;
}

bool	PhoneBook::showContact(int index)
{
	if (index > 8 || index < 0)
	{
		std::cout << "Index number is out of range" << std::endl;
		return (false);
	}
	if (this->_contact_list[index - 1].isEmpty() == true)
	{
		std::cout << "Contact[" << index << "] has no info" << std::endl;
		return (false);
	}
	std::cout << "Contact[" << index << "]" << std::endl;
	this->_contact_list[index - 1].showInfo();
	return (true);
}
