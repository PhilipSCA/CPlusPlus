#include <iostream>
#include <vector>
#include <string>
#include "../Colours.h"


int main()
{
    //Constants
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 100;
    const int totalQuestions = 10;
    const std::vector<std::string> students{ "Charles","TJ","Nathan","Jaydan" };

    //Variables
    int number_1;
    int number_2;
    char math_op;
    int expectedAnswer;
    int enteredAnswer;
    int finalScore;
    int correctAnswers = 0;
    /*Get the System Time*/
    unsigned seed = time(0);




    std::cout << blue << "========================================\n\n" << white;
    std::cout << "Welcome " << students[rand() % students.size()] << ", to the arithmetic test!\n";
    std::cout << "Get ready to add, subtract, and multiply!\n\n";
    std::cout << blue << "========================================\n" << white;



    for (int i = 0; i < totalQuestions; i++) {
        /*Seed the Random Number Generator*/
        srand(seed);
        int random = rand() % 3;

        /*Generates Random Numbers for the Math Problems*/
        number_1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        number_2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

        switch (random) {
        case 0:
            math_op = '+';
            expectedAnswer = number_1 + number_2;
            break;
        case 1:
            math_op = '-';
            expectedAnswer = number_1 - number_2;
            break;
        default:
            math_op = '*';
            expectedAnswer = number_1 * number_2;
            break;
        }
        std::cout << "How much is " << clrgreen << number_1 << math_op << number_2 << white << "?\n";
        std::cin >> enteredAnswer;
        
        std::string result;
        if (enteredAnswer == expectedAnswer) {
            result = "Correct\n ";
            correctAnswers++;
        }
        else {
            result = "Incorrect\n";
        }
        std::cout << result;
        
    }
    float average = (correctAnswers / static_cast<float>(totalQuestions)) * 100;
    std::cout << "\nTotal Average: " << round(average) << "%\n";
    
    
    getchar();
    return 0;
    
}

