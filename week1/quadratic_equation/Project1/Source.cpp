#include <iostream>
int main()
{
	double a, b, c;

	std::cout << "Please, enter the values a, b and c" << std::endl;
	std::cin >> a >> b >> c;
	if (a == 0)
	{
		std::cout << "Error, this is not a quadratic equation";
	}
	else
	{
		if (b * b - 4 * a * c < 0)  std::cout << "The discriminant is less than zero, there are no solutions";
		if (b * b - 4 * a * c == 0) std::cout << "The only solution: " << -b / 2 / a;
		if (b * b - 4 * a * c > 0)  std::cout << "Two solutions:\n1) " << (-b + sqrt(b * b - 4 * a * c)) / 2 / a << "\n2) " << (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
	}
	return 1;
};