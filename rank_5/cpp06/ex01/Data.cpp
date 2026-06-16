#include "Data.hpp"

Data::Data()
: value(0)
{
}
Data::Data(const Data& obj)
{
	operator=(obj);
}
Data& Data::operator=(const Data& obj)
{
	if (this != &obj)
	{
		name = obj.name;
		value = obj.value;
	}
	return (*this);
}
Data::~Data()
{

}

Data::Data(const std::string& newname)
:
name(newname),
value(0)
{

}

Data::Data(const std::string& newname, int newValue)
:
name(newname),
value(newValue)
{
}

std::ostream& operator<<(std::ostream& os, const Data& obj)
{
	os << "Data{\"" << obj.name << "\", " << obj.value << "}";
	return (os);
}
