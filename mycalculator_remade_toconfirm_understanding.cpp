#include <iostream>
#include <limits>


void clearlines()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Need ) After '\n' to properly work.
}

double input()
{

	while (true)
	{

		double value;
		std::cout << "Enter a number. Decimals numbers are supported!: ";
		std::cin >> value;

		if (!std::cin) // if user input errors beginning
		{
			if (std::cin.eof()) // if input line is ended some how by user
			{
				exit(0); // close progm
			}

			std::cin.clear(); // clears error, and puts the user back to input
			clearlines();

		}
		else
		{
			clearlines();
			return value;
		} // complete end of if branch
	} // while statement end
}

char useroperator()
{

	char operinput;
	std::cout << "\nHello! Please enter your operator now!: ";
	while (true) {
		std::cin >> operinput;
		std::cout << "\n";
		if (!std::cin) // if user input fails for operation input
		{
			if (std::cin.eof()) // user some how ends input stream
			{
				exit(0); // close progm
			}

			std::cin.clear(); // clears the "fail mode" user input is put into
			clearlines(); // flushes variables
		}
		else
		{
			clearlines(); // flushes extra variables input past first user variable input
			return operinput; // returns users operator
		}

		switch (operinput) // makes these operators the only valid ones
		{
		case '+':
		case '-':
		case '*':
		case '/':

		default:
			std::cout << "Error! Your input was not valid or was not accepted. Please try again!\n";
		}

	}
}

void mathematics(double x, char oper, double y) { 

	std::cout << "\n";
	switch (oper) // depending on operator input outputs whatever
	{
	case '+':
		std::cout << x << "+" << y << "=" << x + y;
		break;
	case '-':
		std::cout << x << "-" << y << "=" << x - y;
		break;
	case '*':
		std::cout << x << "*" << y << "=" << x * y;
		break;
	case '/':
		std::cout << x << "/" << y << "=" << x / y;
		break;
	}


}


int main()
{
	while (true) // keep program running constantly
	{

		double x{ input() };
		char oper{ useroperator() };
		double y{ input() };

		mathematics(x, oper, y);
		std::cout << "\n\n";
	}

}
