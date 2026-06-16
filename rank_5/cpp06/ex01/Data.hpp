#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

class Data
{
	public:
		Data();
		Data(const Data &obj);
		Data& operator=(const Data& obj);
		~Data();

		Data(const std::string& newname);
		Data(const std::string& newname, int newValue);

		std::string name;
		int value;
};

std::ostream& operator<<(std::ostream& os, const Data& obj);

#endif
