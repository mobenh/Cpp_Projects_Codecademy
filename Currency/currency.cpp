#include <iostream>
#include <cstdio>
using namespace std;

int main() {

	double p, q, c, dollars;

	cout << "Enter number of Pesos: ";
	cin >> p;

	cout << "Enter number of Guatemalan Quetzals: ";
	cin >> q;

	cout << "Enter number of Salvadoran Colons: ";
	cin >> c;

	dollars = 0.049 * p + 0.1305 * q + 0.1144 * c;

	cout << "Total USD = $" << dollars << "\n";

	cout << " \n";
	system("pause");
}