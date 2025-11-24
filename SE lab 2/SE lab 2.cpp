#include <iostream>
#include <cmath>
#include <sstream>
#include <conio.h>
using namespace std;

int one();
int range();
double formula(int n, double x);
void main_menu();

//testing
//test


int main() {
	cout << "------------------------------\n";
	cout << "|     Software engineering   |\n";
	cout << "|      Laboratory work 2     |\n";
	cout << "|     Function calculator    |\n";
	cout << "------------------------------\n";
	cout << "Welcome to Function calculator.\n";
	cout << "Press any button to continue\n";
	_getch();
	cout << "\n";
	main_menu();
	return 0;
}
void main_menu() {
	char choice;
	while (1) {
		cout << "------------------------------------------\n";
		cout << "|                Main menu               |\n";
		cout << "------------------------------------------\n";
		cout << "Choose an option:\n";
		cout << "1. Calculate for a singular x.\n";
		cout << "2. Calculate for a range of x.\n";
		cout << "3. Exit program.\n";

		choice = _getch();
		cout << "\n";
		switch (choice) {
		case'1':
			one();
			break;
		case'2':
			range();
			break;
		case'3':
			cout << "exiting program...\n";
			cout << "goodbye!\n";
			return;
		default:
			cout << "incorect input!\n";
			break;

		}
	}
}

int clean_input(int& n);
int clean_input(double& n);

double formula(int n, double x) { // Function that calculates the formula
	if (x < 0) {
		double mlt = 1;
		for (int i = 1; i <= n; i++) {
			mlt *= 1 / (i - x);
		}
		return mlt;
	}
	double sum = 0;
	for (int j = 0; j <= n - 2; j++) {
		double mlt = 1;
		for (int i = 0; i <= n + 1; i++) {
			mlt *= (x + i + pow(j, 2) / (i + 1));
		}
		sum += mlt;
	}
	return 4 * x + sum;

}
int one() { // getting n, x from user
	cout << "calculating for singlar x\n";
	double x, y;
	int n;

	while (1) {
		cout << "Input n>=3, n=";
		if (!clean_input(n) || n < 3) {

			cout << "Incorrect input!\n";
			continue;
		}
		break;
	}
	cout << "input x, x =";
	if (!clean_input(x)) {
		cout << "incorect input! x must be a double!\ninput x, x=";
	}
	cout << "\n";
	y = formula(n, x); // calculation
	cout << "y = " << y << "\n";
	cout << "\nPress any button to return to main menu.\n";
	_getch();
	cout << "\n";
	return 0;
}
int range() { // getting n, min, max, step from user
	cout << "calculating for range of x\n";
	double x, y, min, max, step;
	int n;
	while (1) {

		cout << "Input n>=3, n=";
		if (!clean_input(n) || n < 3) {

			cout << "Incorrect input!\n";
			continue;
		}
		break;
	}

	while (1) {

		cout << "Input min, min=";
		while (!clean_input(min)) {
			cout << "Incorrect input! min must be a double!\nInput min, min=";
		}
		cout << "Input max, max=";
		while (!clean_input(max)) {
			cout << "Incorrect input! max must be a double! \nInput max, max=";
		}
		if (min < max) {

			break;
		}
		cout << "Error: max must be bigger than min. \n";
	}
	x = min;
	while (1) {

		cout << "Input step>0, step=";
		if (!clean_input(step) || step <= 0) {

			cout << "Incorrect input\n";
			continue;
		}
		break;
	}



	cout << "-----------------------------\n"; // calculating
	cout << "|           Results         |\n";
	cout << "-----------------------------\n";
	for (int i = 1; x <= max; x += step, i++) {
		y = formula(n, x);
		if (i == 1) {
			cout << "1. x = " << x << "\t\ty = " << y << endl;
		}
		else {
			cout << i << ". x = " << min << "+" << (i - 1) * step << "\t\ty = " << y << endl;
		}
	}
	cout << "\nPress any button to return to main menu.\n";
	_getch();
	cout << "\n";
	return 0;
}

string inpStr, compStr;
stringstream ss;

int clean_input(int& n) { // checking user input
	getline(cin, inpStr);
	stringstream(inpStr) >> n;
	ss << n;
	ss >> compStr;
	ss.clear();
	if (inpStr != compStr) {
		return 0;
	}
	return 1;
}

int clean_input(double& n) {
	getline(cin, inpStr);
	stringstream(inpStr) >> n;
	ss << n;
	ss >> compStr;
	ss.clear();
	if (inpStr != compStr) {
		return 0;
	}
	return 1;
}