#include <iostream>
#include <stdlib.h> 
#include <time.h>



int main(int argc, char** argv)
{
    srand(time(NULL));

    int rand1 = rand() % 100;
    int guess;


    while (true)
    {
        std::cout << " Guess a Number \n";
        std::cin >> guess;

        if (guess < rand1)
        {
            std::cout << "Higher Enter a New number\n";
        }
        else if (guess > rand1)
        {
            std::cout << "Lower Enter a New number\n";
        }
        else
        {
            std::cout << "Correct";
            break;
        }
    }

    return 0;
}