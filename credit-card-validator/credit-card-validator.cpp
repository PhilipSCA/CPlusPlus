#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../Colours.h"
//Colours header file, allows me to use colours on the console.

int main()
{   
    // Will store the users card number input.
    long long cardNumber;
    std::cout << "Enter a card number: \n";
    std::cin >> cardNumber;
    
    // Validates the input is an integer - cardNumber type is integer so cin will fail.
    while (std::cin.fail()) {
        std::cout << clrred << "Input Error! Must be an integer.\nPlease try again!\n" << white;
        //Clear failure error
        std::cin.clear();
        //Ignore previous user input
        std::cin.ignore(256, '\n');
        //Request user input again
        std::cin >> cardNumber;
    }

    // long long Card Number converting to a string for easier manipulation
    std::string cardNumberString = std::to_string(cardNumber);
    // Get the length of the card number for later use
    int cardNumberLength = cardNumberString.length();
    // Remove the last digit off the card number.
    std::cout << "card number:" << cardNumberString << "\n";
    // Get the last digit of the card number.
    // cardNumberString[length-1] <- returns a char of the last digit. Leaving it at a char would work, however
    // in the future we want to use this check digit as an integer, converting from char to int gives ASCII so we need to convert string to int
    std::string checkDigitString(1, cardNumberString[cardNumberLength - 1]);
    // Since it's a string, we can now use std::stoi to convert the string to an int - we wouldn't be able to do this as a char which is why we converted above.
    int checkDigit = std::stoi(checkDigitString);

   /* cardNumberString.pop_back();
    cardNumberLength = cardNumberString.length();*/

    //This will store all the numbers in the even positions when counted from the right
    //eg. 12345 -> store 5,3,1
    std::vector<int> evenNumbers;
    //This will store all the numbers in the odd positions when counted from the right
    //eg. 12345 -> 4,2
    std::vector<int> oddNumbers;

    //Counters
    //i will reset when reaches 10, since I only want 1 digit values, however this must be separate from y otherwise if the card number is longer than 10 , it will endelessly reset to 1 and endelessly loop.
    int i = 1;
    //y is counting to loop over each letter in the string/card number
    int y = 1;
    while (y <= cardNumberLength) {
        if (i >= 10) {
            i = 1;
        }
        if (i % 2 == 0) {
            oddNumbers.push_back(i);
        }
        else {
            evenNumbers.push_back(i);
        }
        i++;
        y++;
    }

    //Will store the doubled number of each element in evenNumbers vector
    int evenNumberDoubled = 0;
    //Convert the doubled number to a string for easier manipulation
    std::string evenNumberDoubledStr = "";
    //Stores the total of all the numbers doubled

    std::vector<std::string> toAdd;

    //Loop through each evenly positioned number in the credit card
    for (int i = 0; i < evenNumbers.size(); i++) {
        //Double each evenly positioned number
        evenNumberDoubled = evenNumbers[i] * 2;
        //Convert the doubled number to a string (we need to check if it has more than 1 digit, if it does we need to split the 2 digits into singular digits then add them together...
        evenNumberDoubledStr = std::to_string(evenNumberDoubled);
        //If number is more than 1 digit
        if (evenNumberDoubledStr.length() > 1) {
            //Loop through each digit
            for (int i = 0; i < evenNumberDoubledStr.length(); i++) {
                //Converting the char to a string to add to the toAdd vector
                std::string s;
                s.push_back(evenNumberDoubledStr[i]);
                //Push each digit to the toAdd vector
                toAdd.push_back(s);
            }
        }
        else {
            //Push whole number to the toAdd vector without looping through digits if length is only 1 digit
            toAdd.push_back(evenNumberDoubledStr);
        }
    }

    //Total of even numbers
    int evenTotal = 0;
    //Loop through evenNumbers vector (after doubled), add all to a oddTotal variable.
    for (int i = 0; i < toAdd.size(); i++) {
        //Converting string to int to add to evenTotal (int) variuable.
        evenTotal += std::stoi(toAdd[i]);
    }
    //Total of odd numbers
    int oddTotal = 0;
    //Loop through oddNumbers vector, add all to a oddTotal variable.
    for (int i = 0; i < oddNumbers.size(); i++) {
        oddTotal += oddNumbers[i];
    }



    int completeTotal = evenTotal + oddTotal;
    //CORRECT UP TO THIS POINT!
    std::cout << "Total: " << completeTotal << "\n";

    //find check digit
    int calculatedCheckDigit = 0;
    for (int i = 0; i < 10; i++) {
        if ((completeTotal + i) % 10 == 0){
            calculatedCheckDigit = i;
            break;
        }
    }
    std::cout << "Initial Check Digit: " << checkDigit << "Calculated Check Digit: "<< calculatedCheckDigit;
    std::cin >> cardNumber;
    

    return 0;
}



