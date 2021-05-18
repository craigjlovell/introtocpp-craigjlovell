#include <iostream>

// Note:

int find_Power(int baseNumber, int toPoweOf);
int main()
{
	int baseNumber = 2;
	int toPoweOf = 5;
	int answer = find_Power(baseNumber, toPoweOf);

	std::cout << baseNumber << "^" << toPoweOf << " is " << answer;
	return 0;
}
int find_Power(int baseNumber, int toPoweOf)
{
	if (toPoweOf == 0)
	{
		return 1;
	}

	int value = (baseNumber * find_Power(baseNumber, toPoweOf - 1));
	return value;

}