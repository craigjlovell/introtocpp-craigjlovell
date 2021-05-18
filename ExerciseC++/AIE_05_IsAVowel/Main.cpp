#include <iostream>

bool IsAVowel(char letter)
{
	letter = tolower(letter);

	//if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')//       return true;

	//return false;

	switch (letter)
	{
	case 'a':
		return true;
		break;
	case 'e':
		return true;
		break;
	case 'i':
		return true;
		break;
	case 'o':
		return true;
		break;
	case 'u':
		return true;
		break;
	default:
		break;
	}
	return false;
}

int main(int argc, char** argv)
{
	while (true)
	{
		char imput;
		std::cin >> imput;
		if (IsAVowel(imput))
		{
			std::cout << imput << " Is a Vowel\n";
		}
		else
		{
			std::cout << imput << " Is a not a Vowel" << std::endl;;
		}
	}
	return 0;
}
