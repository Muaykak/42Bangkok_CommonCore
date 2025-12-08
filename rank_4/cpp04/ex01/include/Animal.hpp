#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	public:
		Animal(); // Default Constructor
		Animal(const Animal& obj); // Copy constructor
		Animal& operator=(const Animal &obj); // Copy assignment operator
		virtual ~Animal(); // Destructor

		virtual void	makeSound() const;
		const std::string& getType() const;
	protected:
		std::string type;
};

#endif