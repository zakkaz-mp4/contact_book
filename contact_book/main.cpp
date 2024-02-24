#include "Telephone.h"

int main() {

	Telephone telephone;

	while (telephone.get_turned_on()) {
		telephone.display_menu();
		telephone.handle_menu_selection();
	}

	return 0;
}