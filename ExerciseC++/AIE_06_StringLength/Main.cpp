#include <iostream>
#include <cstring>

int StringLength(const char* szString)
{
	// TODO: Calculate the length of the string
	// your result should be the same as strlen(szString)	
	int i = 0;

	while (szString[i] != '\0')
		i++;

	return i;
}

int main(int argc, char** argv)
{
	std::cout << "Length: " << StringLength("Bannana") << std::endl;
	std::cout << "Length: " << StringLength("Apple") << std::endl;
	std::cout << "Length: " << StringLength("Mangow") << std::endl;
	std::cout << "Length: " << StringLength("Orange") << std::endl;

	return 0;
}
