#include <iostream>
#include <string.h>
#include <exception>

int Calculate(int num1, int num2, const std::string& operation)
{
    if (operation == "Add")
    {
        int answer = num1 + num2;
        return answer;
    }
    if (operation == "Sub")
    {
        int answer = num1 - num2;
        return answer;
    }
    if (operation == "Mul")
    {
        int answer = num1 * num2;
        return answer;
    }
    if (operation == "Div")
    {
        int answer = num1 / num2;
        return answer;
    }


}

int main(int argc, char** argv)
{
    int num1 = 0;
    int num2 = 0;
    std::string operation;

    std::cout << "Please Enter 2 Numbers and a Operation\n";

    std::cin >> num1;
    std::cin >> num2;
    std::cin >> operation;

    std::cout << Calculate(num1, num2, operation);

    //std::cout << "Add: " << Calculate(num1, num2, "Add") << std::endl;
    //std::cout << "Sub: " << Calculate(num1, num2, "Sub") << std::endl;
    //std::cout << "Mult: " << Calculate(num1, num2, "Mul") << std::endl;
    //std::cout << "Div: " << Calculate(100, 20, "Div") << std::endl;
    return 0;
}