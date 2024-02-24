#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include "Telephone.h"
#include "Contact.h"

Telephone::Telephone() : turned_on{ true } {
	std::cout << "The smartphone is loading..." << std::endl;
	Sleep(4000);
	std::cout << "The smartphone has turned on." << std::endl << std::endl;
};

void Telephone::display_menu() {
	std::cout << std::endl;
	std::cout << "Choose an option from menu:" << std::endl
		<< "1) Show contacts list" << std::endl
		<< "2) Add Contact" << std::endl
		<< "3) Delete contact" << std::endl
		<< "4) Turn off the smarthone" << std::endl;
}

void Telephone::handle_menu_selection() {
	int selected{0};

	std::cin >> selected;
	std::cout << std::endl;

	switch (selected) {
	case 1:
		show_contacts_list();
		break;
	case 2:
		add_contact();
		break;
	case 3:
		break;
	case 4:
		turn_off();
		break;
	default:
		std::cout << "Not a valid value" << std::endl << std::endl;
	}
}

void Telephone::show_contacts_list() {
	std::cout << "Your contacts list:" << std::endl;
	std::cout << "----------------------------:" << std::endl;
	 
	if (contacts.size() < 1) {
		std::cout << "No contacts in the list, get some friends..." << std::endl;
	}
	else {
		size_t index = 0;
		for (Contact &contact : contacts) {
			index++;
			std::cout << index << ") Name: " << contact.get_name() << " - " << "Number: " << contact.get_number_phone() << std::endl;
		}
	}
	
	std::cout << "----------------------------:" << std::endl << std::endl;
}


bool Telephone::contact_exists(std::string name) {

	for (auto& contact : contacts) {
		if (contact.get_name() == name) return true;
	}
	
	return false;
}

bool Telephone::check_valid_number(std::string number) {

	const size_t min_digits{ 9 };

	if (number.size() < min_digits) {
		std::cout << "Min digits: " << min_digits << std::endl;
		return false;
	}
	
	for (char digit : number) {
		if (!std::isdigit(digit)) {
			std::cout << "You entered wrong values" << std::endl;
			return false;
		}
	}

	return true;
}

void Telephone::add_contact() {
	std::string name{};
	std::string number{};
	std::string address{};
	std::cout << "You wanna add a new contact, nice!\nWe are gonna ask you some basics infos." << std::endl;

	do {
		std::cout << "Enter contact's name:" << std::endl;
		std::getline(std::cin >> std::ws, name);
	}
	while (contact_exists(name));


	do {
		std::cout << "Enter contact's number:" << std::endl;
		std::getline(std::cin >> std::ws, number);
	} while (!check_valid_number(number));

	std::cout << "Enter contact's address:" << std::endl;
	std::getline(std::cin >> std::ws, address);


	Contact new_contact{ name, number, address};
	contacts.push_back(new_contact);
	std::cout << "Wow! You entered a new contact to the list!" << std::endl;
}

bool Telephone::get_turned_on() {
	return turned_on;
}

void Telephone::turn_off() {
	std::cout << "Turning off the smartphone..." << std::endl;
	Sleep(4);
	std::cout << "You turned off your smartphone!" << std::endl;
	turned_on = false;
}