#include <string>
#include "Contact.h"

Contact::Contact(std::string name_value, std::string number_phone_value, std::string address_value) : name{ name_value }, number_phone{ number_phone_value }, address{ address_value } {}

std::string Contact::get_name() {
	return name;
}

std::string Contact::get_number_phone() {
	return number_phone;
}

std::string Contact::get_address() {
	return address;
}