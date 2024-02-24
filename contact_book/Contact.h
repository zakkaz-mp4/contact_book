#include <string>

#ifndef _CONTACT_H_
#define _CONTACT_H_

class Contact {
private:
	std::string name;
	std::string number_phone;
	std::string address;

public:
	Contact(const std::string name_value, const std::string number_phone_value, const std::string address_value);
	std::string get_name();
	std::string get_number_phone();
	std::string get_address();
	
};

#endif