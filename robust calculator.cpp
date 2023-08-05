#include <iostream>
#include <limits> // streamsize && natural limits


void clearline()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getdoubleval()
{
	while (true)
	{
		std::cout << "Enter your decimal value: ";
		double val;
		std::cin >> val;

		if (!std::cin)
		{
			if (std::cin.eof()) // stream is closed
			{
				exit(0);
			}


			std::cin.clear(); // puts back into normal op mode
			clearline(); // clears bad input;
			std::cout << "That input is not valid! Try again! ";
		}
		else
		{
			clearline(); // gets rid of variables input past the first variable
			return val; // returns number user input for further use.
		}

	}
}

char getoper()
{
	std::cout << "Enter your operator! ";
	char oper;
	std::cin >> oper;

	// Protocol for incorrect application usage.
	while (true) {
		if (!std::cin) // If user input fails (user enters incorrect input)
		{
			if (std::cin.eof()) // If application stream is cancelled (I.E. pressing CTRL D)
			{
				exit(0);
			}

			std::cin.clear(); // Puts user back into normal operation mode :P
		}
		
		clearline(); // Clears extranous output - Non Intellectual Version -> Gets rid of variables past the first entered one.

		switch (oper)
		{
		case '+':
		case '-':
		case '/':
		case '*':
			return oper; // returns CORRECT operator.

		default: // if operator incorrect, will produce this line of test
			std::cout << "This input is invalid. Please try again :) \n";


		}
	}
}

void calcmath(double x, char ope, double y)
{
		
	switch (ope)
	{
	case '+':
		std::cout << x << "+" << y << "=" << x + y;
	case '-':
		std::cout << x << "-" << y << "=" << x - y;
	case '*':
		std::cout << x << "*" << y << "=" << x * y;
	case '/':
		std::cout << x << "/" << y << "=" << x / y;
	}

}



int main()
{
	double foo{ getdoubleval() };
	char opz{ getoper() };
	double goo{ getdoubleval() };


	calcmath(foo, opz, goo);

}
