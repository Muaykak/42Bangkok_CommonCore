template<typename T>
Array<T>::Array()
:
_array(NULL),
_array_size(0)
{
	_array = new T[_array_size];
}

template<typename T>
Array<T>::Array(const Array& obj)
:
_array(NULL),
_array_size(obj.size())
{
	operator=(obj);
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	/* perform deep copy */
	if (this != &obj)
	{
		/* if the size is not match then must reallocate */
		if (_array == NULL || _array_size != obj.size())
		{
			if (_array)
				delete[] _array;
			_array_size = obj.size();
			_array = new T[_array_size];
		}

		for (unsigned int i = 0; i < _array_size; i++)
			_array[i] = obj[i];

	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}


template<typename T>
Array<T>::Array(unsigned int n)
:
_array_size(n)
{
	_array = new T[_array_size];
}


template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _array_size)
		throw IndexOutOfRangeException();
	return (_array[index]);
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _array_size)
		throw IndexOutOfRangeException();
	return (_array[index]);
}

template<typename T>
const char* Array<T>::IndexOutOfRangeException::what() const throw()
{
	return ("Array::IndexOutOfRange");
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (_array_size);
}