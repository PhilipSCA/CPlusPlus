// Unit Converter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Colours.h"

int main()
{

    float toConvert; //number from input
    int choice;

    bool keepConverting = true;
    char keepConvertingChar;

    std::cout << clrred << "Unit Converter!\n";
    

    while (keepConverting) {
        std::cout << clrgreen << "Length:\n" << white;
        std::cout << "1. Kilometres -> Miles\n";
        std::cout << "2. Miles -> Kilometres\n";
        std::cout << "3. Kilometres -> Yards\n";
        std::cout << "4. Yards -> Kilometres\n";
        std::cout << "5. Kilometres -> Feet\n";
        std::cout << "6. Feet -> Kilometres\n";
        std::cout << "7. Kilometres -> Inches\n";
        std::cout << "8. Inches -> Kilometres\n\n";

        std::cout << clrgreen << "Temperature:\n" << white;
        std::cout << "9. Celsius -> Fahrenheit\n";
        std::cout << "10. Fahrenheit -> Celsius\n\n";

        std::cout << clrgreen << "Storage:\n" << white;
        std::cout << "11. Kilobyte -> Megabyte\n";
        std::cout << "12. Megabyte -> Kilobyte\n";
        std::cout << "13. Megabyte -> Gigabyte\n";
        std::cout << "14. Gigabyte -> Megabyte\n";
        std::cout << "15. Terabyte -> Gigabyte\n";
        std::cout << "16. Gigabyte -> Terabyte\n\n";


        std::cout << "Enter the number of the conversion you would like to perform.\n";
        std::cin >> choice;
        while (std::cin.fail()) {
            std::cout << clrred << "Input Error! Must be an integer.\n" << white;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> choice;
        }

        std::cout << "Enter the amount you would like to convert: " << clrgreen;
        std::cin >> toConvert;
        std::cout << white;

        switch (choice) {
        case 1:
            std::cout << toConvert << "km" << white << "->" << toConvert / 1.609 << "miles";
            break;
        case 2:
            std::cout << toConvert << "miles" << white << "->" << toConvert * 1.609 << "km";
            break;
        case 3:
            std::cout << toConvert << "km" << white << "->" << toConvert * 1094 << "yards";
            break;
        case 4:
            std::cout << toConvert << "yards" << white << "->" << toConvert / 1094 << "km";;
            break;
            
        case 5:
            std::cout << toConvert << "km" << white << "->" << toConvert * 3281 << "ft";
            break;
        case 6:
            std::cout << toConvert << "ft" << white << "->" << toConvert / 3281 << "km";
            break;
        case 7:
            std::cout << toConvert << "km" << white << "->" << toConvert * 39370 << "inch";
            break;
        case 8:
            std::cout << toConvert << "inch" << white << "->" << toConvert / 39370 << "km";
            break;
        case 9:
            std::cout << toConvert << "°C" << white << "->" << (toConvert * 9/5) + 32 << "°F";
            break;
        case 10:
            std::cout << toConvert << "°F" << white << "->" << (toConvert - 32) * 5/9 << "°C";
            break;
        case 11:
            std::cout << toConvert << "KB" << white << "->" << toConvert / 1000 << "MB";
            break;
        case 12:
            std::cout << toConvert << "MB" << white << "->" << toConvert * 1000 << "KB";
            break;
        case 13:
            std::cout << toConvert << "MB" << white << "->" << toConvert / 1000 << "GB";
            break;
        case 14:
            std::cout << toConvert << "GB" << white << "->" << toConvert * 1000 << "MB";
            break;
        case 15:
            std::cout << toConvert << "TB" << white << "->" << toConvert * 1000 << "GB";
            break;
        case 16:
            std::cout << toConvert << "GB" << white << "->" << toConvert / 1000 << "TB";
            break;

        }


        std::cout << "\n\nWould you like to convert again? (y/n)\n";
        std::cin >> keepConvertingChar;
        if (keepConvertingChar == 'n') keepConverting = false;


    }




    return 0;
    
}
