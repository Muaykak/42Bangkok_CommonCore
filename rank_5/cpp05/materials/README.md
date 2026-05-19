_this readme was created by srussame for the purpose of education_

# CPP module 05

This project is about C++ exceptions and stuff

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

