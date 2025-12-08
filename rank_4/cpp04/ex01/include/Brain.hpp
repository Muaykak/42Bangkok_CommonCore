#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain& obj);
		Brain&	operator=(const Brain& obj);
		~Brain();

		void	setIdea(const std::string& newIdea, const int& index);
		std::string getIdea(const int& index) const;

	private:
		std::string	idea[100];
};

#endif