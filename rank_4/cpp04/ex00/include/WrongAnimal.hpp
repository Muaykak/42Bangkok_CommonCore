#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal(); // Default Constructor
		WrongAnimal(const WrongAnimal& obj); // Copy constructor
		WrongAnimal& operator=(const WrongAnimal &obj); // Copy assignment operator
		virtual ~WrongAnimal(); // Destructor

		void	makeSound() const; // is not a virtual member function on Base Class
		const std::string& getType() const;
	protected:
		std::string type;
};

#endif