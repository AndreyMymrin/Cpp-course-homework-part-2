#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	// units of length measurement m yard mile arshin
	std::string a, b;
	double x;
	std::cout << "Enter the initial value with units of measurement and the resulting units separated by a space, for example 10 m mile\nChoose from: m verst mile arshin\nEnter 0 0 0 to close\n";
	std::cin >> x >> a >> b;
	double x0 = x;
	while (a != "0")
	{
		
		if (a == "verst") {
			x *= 1066.8;
		}
		if (a == "mile") {
			x *= 1609.34;
		}
		if (a == "arshin") {
			x *= 0.7112;
		}

		if (b == "verst") {
			x *= 0.00094;
		}
		if (b == "mile") {
			x *= 0.00062;
		}
		if (b == "arshin") {
			x *= 1.41;
		}
		std::cout.setf(std::ios::fixed);
		//std::cout.width(5);
		std::cout <<right<<setw(10) << setprecision(1) << x0 << ' ' <<left<<setw(5) << a << " = " << left<< setw(13)<< setprecision(3) << x << ' ' << b << std::endl;

		std::cin >> x >> a >> b;
		x0 = x;
	}
	return 1;
}