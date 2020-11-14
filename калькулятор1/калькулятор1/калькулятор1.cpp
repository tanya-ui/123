#include <iostream>
//+ , - , / , * , ** ,!

char* getNumber() {
	char number[255];
	std::cout << "Введите число" << std::endl;
	std::cin.getline(number, 255);
	while (std::cin.fail()) {
		std::cout << "Введите правильное число" << std::endl;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cin.getline(number, 255);
	} 
	std::cin.ignore(32767, '\n');
	return number;

}
char getOperand() {
	char operand;
	while (true) {
		std::cout << "Ввeдите операцию" << std::endl;
		std::cin >> operand;
		if (operand == '+' || operand == '/' || operand == '-' || operand == '*' || operand == '**' || operand == '!') {
			return operand;
		}
		std::cout << "Введите правильный знак операции" << std::endl;
	}
	return operand;
}
double factorial(double num) {
	double result = num;
	if (num == 0) {
		return 1;
	}
	return num * factorial(num - 1);
}

int i;
int j;
char * calc(char * num1, char op, char* num2) {
	char result[255];
	for (int i = 0; i < 255; i++) {
		result[i] = '0';
	}
	if (op == '+') {
		for ( i = strlen(num1),  j = strlen(num2); i > 0 && j > 0, i--, j++;);
		if (i > j) {
			if (num1[i] + num2[j] >= 10) {
				result[i + 1] = num1[i] + num2[j] % 10;
				result[i] += 1;
			}
			result[i + 1] = num1[i] + num2[j];
		}
		else {
			if (num1[i] + num2[j] >= 10) {
				result[j + 1] = num1[i] + num2[j] % 10;
				result[j] += 1;
			}
			result[j + 1] = num1[i] + num2[j];
		}
	}
		return result;
	}
/*
	if (op == '/') {
		return num1 / num2;
	}
	if (op == '-') {
		return num1 - num2;
	}
	if (op == '*') {
		return num1 * num2;
	}
	if (op == '**') {
		return pow(num1, num2);
	}
	if (op == '!') {
		return factorial(num1);
	}
	*/

int main() {
	setlocale(0, "");
	char* result = calc(getNumber(), getOperand(), getNumber());

	std::cout.precision(40);
	for (int i = 0; i < sizeof(result); i++) {
		std::cout << result[i];
	}
		return 0;
}

