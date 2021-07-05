#include <iostream>
#include <vector>
#include "Colours.h"
#include <string>

std::vector<std::vector<std::string>> products = {
	{"Doughnut","1.99"},
	{"Sugar","1.50"},
	{"Milk","1.29"},
	{"Butter","1.00"},
	{"Chocolate","4.00"},
	{"Ketchup","2.40"}
};


std::vector<float> orderPrices;
std::vector<std::string> orderItems;

void addToOrder(std::string item) {

	float priceToAdd;
	for (int i = 0; i < products.size(); i++) {
		if (products[i][0] == item) {
			priceToAdd = std::stof(products[i][1]);
			break;
		}
	}

	orderPrices.push_back(priceToAdd);
	orderItems.push_back(item);

	float total = 0;
	for (int i = 0; i < orderPrices.size(); i++) {
		total = total + orderPrices[i];
	}

	std::cout << clrgreen << item << white << " added to order!\n";
	std::cout << clrred << "\n========================\nOrder Total: " << clrgreen << "$" << total << clrred << "\n========================\n" << white;
	return;
}



int main() {
	bool keepConverting = true;
	char keepConvertingChar;
	int choice;
	float total = 0;

	std::cout << blue << "Welcome to the store!\n" << white << "What would you like to purchase?\n";
	while (keepConverting) {

		std::cout << clrred << "========================\nMENU\n" << white << "\n";
		for (int x = 0; x < products.size(); x++) {
			std::cout << x + 1 << ". " << products[x][0] << clrgreen << " - $" << products[x][1] << "\n" << white;
		}
		std::cout << clrred << "========================" << white << "\n\n";

		std::cout << "Enter the ID number of what you would like to buy.\n";
		std::cin >> choice;
		while (std::cin.fail() || choice > (int)products.size() || choice <= 0) {
			std::cout << clrred << "Input Error! Must be an integer and on the menu.\n" << white;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		addToOrder(products[choice - 1][0]);

		std::cout << white << "\n\nWould you like to buy anything else? (y/n)\n";
		std::cin >> keepConvertingChar;
		if (keepConvertingChar == 'n') keepConverting = false;
		system("cls");
	}


	std::cout << "Your basket contains:\n";
	for (int i = 0; i < orderItems.size(); i++) {
		std::cout << i+1 << ". " << orderItems[i] << "\n";
	}
	for (int i = 0; i < orderPrices.size(); i++) {
		total = total + orderPrices[i];
	}
	std::cout << clrred << "\n========================\nOrder Total: " << clrgreen << "$" << total << clrred << "\n========================\n";
	
	if (total == 0) {
		std::cout << clrred << "Order is empty!\n";
		Sleep(2000);
		return 0;
	}
	
	
	for (int j = 0; j < 100; j++) {
		std::cout << yellow << "\rAwaiting Payment   \rAwaiting Payment";
		for (int i = 0; i < 3; i++) {
			std::cout << ".";
			Sleep(300);
		}
	}
	

	return 0;
}
