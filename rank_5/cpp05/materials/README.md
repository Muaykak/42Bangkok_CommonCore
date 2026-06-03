_this readme was created by srussame for the purpose of education_

# CPP module 05

This project is about C++ exceptions and stuff

[> ex00](./README.md#ex00-mommy-when-i-grow-up-i-want-to-be-a-bureaucrat)

## What is c++ exceptions?
 > this is from cplusplus.com

 Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring control to special functions called **handlers**.

## How to work with exceptions in C++?

Normally, some functions in C++ may **throw** exceptions and the only way possible to handle with exceptions is with **try-catch** block

```cpp
try {
	/* you code here */
}
catch (...)
{
	/* this is where you will be after some exceptions inside try block were thrown */
}
```

### What happens when we **throw()** something out?

> this is from [cppreference](https://en.cppreference.com/cpp/language/throw)

Throwing an exception initializes as object with dynamic storage duration, called the *exception* object.

Once the exception object is constructed, the control flow works **backwards** (up the call stack) until it reaches the start of a try block. The process is called **stack unwinding**. at which point the parameters of all associated handlers are compared, in order of appearance, with the type of the exception object to find a *match*. If no match is found, the control flow continues to unwind the stack until the next try block and so on. If a match is found, the control flow jumps to the matching handler.

While the stack is unwinding and bubbling up, when each stack is destroyed, objects that are constructed in that scope will automatically called its destructor. however those that we manually allocate with **new** that we don't wrapp it in class implementation for cleanup may result in memory leaks.

## ex00: Mommy, when I grow up, I want to be a bureaucrat

This exercise wants you to throw a custom object out. that means we need to build a custom Exception class

this Exeception class define inside Bereaucrat class in ex00/Bureaucrat.hpp

```cpp
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
```

### Why we need these custom exception classes to derived from <u>std::exception</u> ?

To answer this question, we need to look at the excercise's subject what they want the exception class to be like

"The thrown exceptions must be catchable using try and catch blocks"

```cpp

try
{

}
catch (std::exception & e)
{

}

```

BUUTTT we can also catch like this:

```cpp

try
{
	/* you do something with the Bureaucrat class and it might throw something out in case of errors */
}
catch (Bureaucrat::GradeToHighException & e)
{
}
catch (Bureaucrat::GradeToLowException & e)
{
}

```


It is just because the subject's example catches the exception from the class with **std::exception**. The only to make it work is to make our custom exception classes derived from **std::exception**

I think the reason behind is for **general error handling**. Because of all other c++ standard libraries (c++98, mostly, i assumed, sorry lmao), their exception objects are also derived from **std::exception** class. When any errors happens at anywhere, because all their classes are derived from **std::exception**, we can just simply have one catch block that catch it all. And for me i think it is a good practice for our custom exception classes to derived from **std::exception** as well to make it easy for general error handling.

### What about <u>std::exception</u> ?

We derived our classes from it. so we need to know about this base classe as well yeah?

> the following information is from [here](https://en.cppreference.com/cpp/error/exception)

the **std::exception** class has **four** member functions

| function | definition |
| :-------: | :---------: |
| (constructor) | constructs the exception object (public member function) |
| (destructor)[virtual] | destroys the exception object (virtual public member function) |
| operator= | copies exception object (public member function)|
|what [virtual]| returns an explanatory string (virtual public member function) |

that means when we derived from **std::exception** with *public* inherit, we will automatically get these member functions in public space. **what** is the member function that we need to modify in our custom exception classes to let's take a look

```cpp
virtual const char* what() const throw();
```

the **throw()** keyword is new here. let's see the definition: It is a exception specifier. I read it and it has many use cases in the past but this **throw()**, when you put it to a function, it tells the compiler that this particular function does not throw any exceptions. It just promise to compiler that it will never throw any exception. but if it throws, undefined behavior might occurs.

