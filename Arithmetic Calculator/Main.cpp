#include <IOstream> // Allows the use of cin and cout to get inputs and outputs 
#include <conio.h> // Allows the use of _getch() to allow the program to wait for user input 


//Main method is were the computer will look to start the program 
int main() {
	std::cout << "Welcome to the Arithmatic Calculator" << "\n";
	std::cout << "Press any key to continue..." << "\n" << "\n";

	_getch();


	//printing out the menu
	std::cout << "Press 1 for Additon" << "\n";
	std::cout << "Press 2 for Subtration" << "\n";
	std::cout << "Press 3 for Divison" << "\n";
	std::cout << "Press 4 for Multiplication" << "\n";
	std::cout << "Press 5 for Area of a Rectangle " << "\n";
	std::cout << "Press 6 for Area of a Triangle " << "\n";
	std::cout << "Press 7 to Calculate the unknown side of a Right Angle Triangle  " << "\n";
	std::cout << "Press E to Exit the program " << "\n";

	char cUserInput; //variable to holde the users in put 
	cUserInput = _getch(); // getting the users input 

	switch (cUserInput) {
	case '1':
		std::cout << "ADD" << "\n";
		break;
	case '2':
		std::cout << "SUB" << "\n";
		break;
	case '3':
		std::cout << "DIV" << "\n";
		break;
	case '4':
		std::cout << "MUL" << "\n";
		break;
	case '5':
		std::cout << "ARE REC" << "\n";
		break;
	case '6':
		std::cout << "ARE TRI" << "\n";
		break;
	case '7':
		std::cout << "PAG" << "\n";
		break;
	case 'e':
	case 'E':
		std::cout << "EXIT" << "\n";
		break;
	}

	return 0; // if every thing works fine the comuter will return a 0 at the end of the program 
}