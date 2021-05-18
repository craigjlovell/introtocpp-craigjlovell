#include <iostream>


int main(int argc, char** argv)
{
    int numberOfChildren = 0;
    char partnerName[20] = "";
    char location[20] = "";
    char job[20] = "";

    std::cout << "Enter a Number\n";
    std::cin >> numberOfChildren;
    std::cin.ignore();

    std::cout << "Enter a JobTitle\n";
    std::cin.getline(job, 32);
    //std::cin.ignore();

    std::cout << "Enter a Location\n";
    std::cin.getline(location, 32);

    std::cout << "Enter a Name\n";
    std::cin.getline(partnerName, 32);


    std::cout << "you will be a " << job << " Living in " << location << " and your Partners name will be " << partnerName << " and you will have " << numberOfChildren << " kids";

    return 0;
}
