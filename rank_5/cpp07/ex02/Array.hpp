#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>

template<typename T>
class Array
{
	private:
		T* _array;
		unsigned int _array_size;
	public:
		/* need orthodox canonical form ?*/
		Array();
		Array(const Array& obj);
		Array& operator=(const Array& obj);
		~Array();

		Array(unsigned int n);
		const T &operator[](unsigned int index) const;
		T &operator[](unsigned int index);
		unsigned int size() const;

		class IndexOutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

# include "Array.tpp"

#endif
