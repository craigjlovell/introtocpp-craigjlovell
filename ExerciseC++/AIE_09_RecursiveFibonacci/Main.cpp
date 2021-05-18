#include <iostream>

void CountDownFrom(int num1, int num2, int number)
{
	if (number <= 0)
	{
		return;
	}

	std::cout << num1 << std::endl;
	CountDownFrom(num2, num1 + num2, number - 1);
}

int main(int argc, char** argv)
{
	CountDownFrom(0, 1, 15);
	return 0;
}