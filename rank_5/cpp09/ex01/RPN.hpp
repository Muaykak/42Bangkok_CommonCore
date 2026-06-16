#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <cstdlib>
# include <exception>
# include <limits>

class RPN
{
	/* this is just perform so no need to instantiate */
	private:
		/* still need orthodox canonical ? */
		RPN();
		RPN(const RPN& obj);
		RPN& operator=(const RPN& obj);
		~RPN();

		static void performRPN(std::stack<double>& performStack, char input);

	public:

		static double calculate(const std::string& rpn_string);

};


#endif
