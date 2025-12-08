#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
	public:
		WrongDog();
		WrongDog(const WrongDog& obj);
		WrongDog& operator=(const WrongDog& obj);
		~WrongDog();

		void	makeSound() const ;
};

#endif