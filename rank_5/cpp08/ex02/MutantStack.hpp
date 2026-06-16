#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	/* it has underlying protected member c */
	/* which is */
	// Container c; /* which is the underlying container that stack uses */

	public:
		MutantStack()
		:
		std::stack<T>()
		{}

		MutantStack(const MutantStack& obj)
		:
		std::stack<T>(obj)
		{}

		MutantStack& operator=(const MutantStack& obj)
		{
			if (this != &obj)
			{
				std::stack<T>::operator=(obj);
			}
			return (*this);
		}
		~MutantStack()
		{}

		typedef	typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return (std::stack<T>::c.begin());
		}
		iterator end()
		{
			return (std::stack<T>::c.end());
		}
};


#endif
