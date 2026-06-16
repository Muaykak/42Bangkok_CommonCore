# CPP 06 - all about casts in c++

> this excercise was a part of 42 coding school's curriculum (as of 2026)

as you may know that in **C** language when you want to change the type of some variable you can just

```c
int a = 40;

/* simple but some risks */
(size_t)a;
```

this excercise is to learn all about how to use each different type of casts in c++ version as they suggest you to use it

## ex00 - the most used - **static_cast**

the subject wants you to create a class that converts a string literals into commmon scalar type like this

```console
➜  ex00 > ./converter 34.12345677
char: '"'
int: 34
float: 34.1235f
double: 34.1235
```

obviously there's more what cast we should use but for this exercise we need to have explanation

### What Is `static_cast` ?
> this information is from [cppreference.com](https://en.cppreference.com/cpp/language/static_cast) and [geeksforgeeks.com](https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/)

**static_cast** is a C++ type casting operator used to perform explicit conversions between compatible types. Commonly used for numeric conversions, user-defined conversions, and etc. For me it is the most used cast type that you may need to use. these are its characteristics:
- compile-time type checking and is <u>safer than C-style casts</u>. This is because the `static_cast` will be checked during compile time and if you try to cast two completely unrelated types, `static cast` will trigger a compile-time error
- Supports conversions between related types, user defined types, and void*.
- Cannot remove const qualifiers or perform low-level memory reinterpretation. ( as those functionalities will be on another types of cast)

### Syntax
`static_cast<type>(expression)`
- **type** is the target type
- **expression** is the value to be converted

### Limitaions of `static_cast`
- Cannot remove `const` ot `volatile` qualifiers
- Cannot safely cast between unrelated pointer types.
- Does not perform runtime type checking for downcasting. Cannot perform low-level memory reinterpretation like `reinterpret_cast`

### The Main part of the excercise

I just gonna explain how each part works here

```cpp
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
	
	public:

		static void convert(const std::string& stringLiteral);
};
```

First thing is the subject states that the class must not be instantiable by user.. but still we need to design the class to have Orthodox Canonical Form. thus we need to have those constructors. By puuting it in private members. not it cannot be instatiated by anything outside of this class.

So, basically. We need to convert string literals into char, int, float, and double.

what comes to my mind first is that `double` probably has the most precision so i looked into standard functions that convert string to double and i found one

```cpp
double strtod (const char* str, char** endptr);
```

this one will easily converts string to double and then we can cast to smaller types like int, float, or char, but we need to know how to use it first

> this information is from [cplusplus.com](https://cplusplus.com/reference/cstdlib/strtod/)

*str* is the string literals that we want to convert to double value.

*endptr* - if we put the address of a `char *` here, the function will set the value of *endptr* to point to the first character after the number. Basically it returns the pointer to that position after the number that it's converted from. and we can make use of that as well.

What that needs to explain in this excercise is also this function and error handling

```cpp
	errno = 0;
	double convertNum = std::strtod(trimmedString.c_str(), &p);

	if (errno == ERANGE)
	{
		if (convertNum == HUGE_VAL || convertNum == -HUGE_VAL)
		{
			std::cerr << "Error::Overflow Detected" << std::endl;
		}
		else if (convertNum > -DBL_MIN && convertNum < DBL_MIN)
		{
			std::cerr << "Error::Underflow Detected" << std::endl;
		}
		else
			std::cerr << "Error:: Detected" << std::endl;
		return ;
	}

```

`errno = 0;` because this function may set the errno is case of error and there might be some previous function that sets the errno so we set that to 0 first to avoid any misbehaviors

as of why error handling is this way is because
> this information is from [cplusplus.com](https://cplusplus.com/reference/cstdlib/strtod/)

### Return Value
On success, the function returns the converted floating point number as a value of type double.
If no valid conversion could be performed, the function returns zero (0.0).
If the correct value is out of the range of representable values for the type, a positive or negative HUGE_VAL is returned, and errno is set to ERANGE.

If the correct value would cause underflow, the function returns a value whose magnitude is no greater than the smallest normalized positive number and sets errno to ERANGE.

`DBL_MIN` - represents the smallest value in double, if the number is smaller than this then it is underflow

```cpp
if (convertNum != convertNum)
{
	/* NaN is the only number that does not equal to itself */
	std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
	return ;
}
```

`NAN` is an acronym for **Not a Number** is an exception that usually occurs in the cases when an expression results in a number that is **undefined** ot **can't be represented**.

The easiest way to check is that the `NAN` value never equals to itself.

Next part is we gonna compare with the limit of each type by using `std::numeric_limits`

```cpp
std::ios_base::fmtflags oldflags = std::cout.flags();
std::streamsize defaultPrecis = std::cout.precision();
std::cout << std::fixed;
std::cout << std::setprecision(1) << num;
std::cout << std::setprecision(defaultPrecis);
std::cout.flags(oldflags);
std::cout.precision(defaultPrecis);

```

Last on this excercise is about this part. this needs `<iomanip>` because of we try to print out the float it would have a lot of digits. these lines set so if that the `float` value is `x.0` it would display only 1 digit.

## ex01 - `reinterpret_cast` i hope you won't use this too often

Though this exercise won't have much to explain but for the sake of the learning anyway so, this excercise wants you to create to static functions like this

```cpp
class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
		~Serializer();

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
```

### `uintptr_t` ? what is that?
> this information is from [man7.org](https://man7.org/linux/man-pages/man3/intptr_t.3type.html#:~:text=uintptr_t%20is%20an%20unsigned%20integer,in%20bits%20of%20these%20types.)

*intptr_t* is a unsigned integer type such that any valid `(void *)` value can be converted to this type and then converted back. So basically the integer version of pointer and our task is to convert back and forth in c++ and that we need to use `reinterpret_cast`

### `reinterpret_cast` Explanation
> this information is from [geeksforgeeks.org](https://www.geeksforgeeks.org/cpp/reinterpret_cast-in-c-type-casting-operators/)

reinterpret_cast is a C++ type casting operater used to reinterpret the bit pattern of an object as a different type. It provides a low-level conversion mechanism and offers very little type safety
- Can convert pointes, references, and integral types to unrelated types.
- Performs no runtime type checking and preserves the underlying bonary representation.

SIMPLEST explanation is this is the good old C type conversion brother, someone might argues but it the low-level casting as you know it is the same as C casting

## ex02 `dynamic_cast`

> this information is from [geeksforgeeks.com](https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/)

dynamic_cast is a runtime type conversion operator used in polymorphic inheritance hierarchies. It performs runtime type checking to ensure that a conversion is valid before it is applied.
- Commonly used for downcasting from a base class to a derived class.
- Requires the base class to have at least one virtual function.
- Indicates failed conversions through NULL or std::bad_cast(for references)

if we use `dynamic_cast` for pointer conversion we can check the return from it whether is NULL or not

if we use `dynamic_cast` for reference, if it fail to convert to our target type. it will throw `std::bad_cast` but the subject states that we cannot use `<typeinfo>` that have the class `std::bad_cast` so we need to use `std::exception` that it inherited from instead.

