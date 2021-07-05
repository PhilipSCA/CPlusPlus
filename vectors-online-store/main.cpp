#include <iostream>
#include <vector>
#include "Colours.h"



std::vector<float> orderPrices;
std::vector<std::string> orderItems;

void addToOrder(std::string item, float price) {

	orderPrices.push_back(price);
	orderItems.push_back(item);

	float total = 0;
	for (int i = 0; i < orderPrices.size(); i++) {
		total = total + orderPrices[i];
	}

	std::cout << clrgreen << item << white << " added to order!\n";
	std::cout << "Your basket contains:\n";
	for (int i = 0; i < orderItems.size(); i++) {
		std::cout << i << ". " << orderItems[i] << "\n";
	}
	std::cout << clrred << "\n========================\nOrder Total: " << clrgreen << "$" << total << clrred << "\n========================\n";
}



int main() {
	bool keepConverting = true;
	char keepConvertingChar;
	int choice;


	std::cout << clrred << "Welcome to Philip's store!\n" << white << "What would you like to purchase?\n";
	while (keepConverting) {
		
		std::cout << clrred << "Menu:" << white << "\n";
		std::cout << "1. Doughnut" << clrgreen << " - $1.99\n" << white;
		std::cout << "2. Sugar" << clrgreen << " - $1.50\n" << white;
		std::cout << "3. Milk" << clrgreen << " - $1.29\n" << white;
		std::cout << "4. Butter" << clrgreen << " - $1.00\n" << white;
		std::cout << "5. Chocolate" << clrgreen << " - £4.00\n" << white;
		std::cout << "6. Ketchup" << clrgreen << " - £2.40\n\n" << white;

		std::cout << "Enter the ID number of what you would like to buy.\n";
		std::cin >> choice;
		while (std::cin.fail()) {
			std::cout << clrred << "Input Error! Must be an integer.\n" << white;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		switch (choice) {
		case 1:
			addToOrder("Doughnut", 1.99);
			break;
		case 2:
			addToOrder("Sugar", 1.50);
			break;
		case 3:
			addToOrder("Milk", 1.29);
			break;


		default:
			std::cout << "That isn't an option!";

		}

		std::cout << "\n\nWould you like to buy more? (y/n)\n";
		std::cin >> keepConvertingChar;
		if (keepConvertingChar == 'n') keepConverting = false;
	}

	std::cout << "Done!\n";


	return 0;
}


