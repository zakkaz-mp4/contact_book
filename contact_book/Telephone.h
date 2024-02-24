#include <vector>
#include <string>
#include "Contact.h"

#ifndef _TELEPHONE_H_
#define _TELEPHONE_H_
class Telephone {
private:
	std::vector<Contact> contacts;
	bool turned_on;
	void show_contacts_list();
	void add_contact();
	void delete_contact();
	bool contact_exists(std::string name);
	bool check_valid_number(std::string number);
	void turn_off();

public:
	Telephone();

	// menu stuff
	bool get_turned_on();
	void display_menu();
	void handle_menu_selection();
};
#endif