#include <IOstream> // Allows the use of cin and cout to get inputs and outputs 
#include <conio.h> // Allows the use of _getch() to allow the program to wait for user input 
#include <cmath> // Allows the use of sqrt to to get the squer root of a number 
#include<Windows.h> // Allows me to change the console window size and text color  
#include <stdlib.h> // gives access to the sleep fucntion 





// changing the colour of the text based on an int paramneter 
void ChangeTextColour(int iCoulorValue)

//0 = Black 
//1 = Blue 
//2 = Green 
//3 = Aqua 
//4 = Red 
//5 = Purple
//6 = Yellow 
//7 = White 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iCoulorValue);
}

// changes the size of the consloe windows X and Y cordinates 
void ChangeConsoleWindowSize(int iXValue, int iYvalue)
{
	// changeing the size of the console window 
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, iXValue, iYvalue, TRUE);

}

void PrtinErrorMesage()
{

	system("cls");
	ChangeConsoleWindowSize(200, 75);
	ChangeTextColour(4);
	std::cout << "Invalid Input";
	Sleep(1000);
	system("cls");

	//clearing cin
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

// displlaying the intro to the user
void Intro ()
{
	
	ChangeConsoleWindowSize(400, 150);
	ChangeTextColour(7);

	std::cout << "##################################################\n\n";
	ChangeTextColour(1);
	std::cout << "\tWelcome to the Arithmatic Calculator" << "\n";
	std::cout << " \t   Press any key to continue..." << "\n" << "\n";
	ChangeTextColour(7);
	std::cout << "##################################################";

	_getch();
	system("cls"); // clears the console window
}

// printing out the main menu to the user 
void Menu()
{
	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "##############################";
	ChangeTextColour(7);
	std::cout << " MENU ";
	ChangeTextColour(1);
	std::cout << "############################\n\n";

	ChangeTextColour(7);
	//printing out the menu
	std::cout << "Press 1: for Additon" << "\n";
	std::cout << "Press 2: for Subtration" << "\n";
	std::cout << "Press 3: for Divison" << "\n";
	std::cout << "Press 4: for Multiplication" << "\n";
	std::cout << "Press 5: for Area of a Rectangle " << "\n";
	std::cout << "Press 6: for Area of a Triangle " << "\n";
	std::cout << "Press 7: to Calculate the unknown side of a Right Angle Triangle  " << "\n";

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 225);
	std::cout << "##########################";
	ChangeTextColour(7);
	std::cout << " E to Exit ";
	ChangeTextColour(1);
	std::cout << "############################";	
}

bool MenuInputChecker(char cInput)
{

	system("cls"); 
	bool bValid = false;

	//holds all the vaild in puts for the menu 
	char acValidInputs [9] = { '1', '2', '3','4','5','6','7','e','E'};

	// cheking user input to the values in the array
	for(int i  = 0; i < 9; i++)
	{
		if (cInput == acValidInputs[i]) bValid = true;
	}

	if (bValid)
	{
		return true;
	}
	else
	{
		PrtinErrorMesage();
		return false;
	}
}

// will hold a float and a bool so the function below can return both
struct InputValues
{
	float fNumber;
	bool bTrueOrFalse;
};

InputValues NumberInputChecker()
{
	// get users input
	float fNumber;
	std::cin >> fNumber;

	// if the useres input is bad show error 
	while (!std::cin.good())
	{
		PrtinErrorMesage();
		return InputValues{ 0,false };
	}

	// if the useres input is good return input
	return InputValues{fNumber,true };
}

// will aske the use for 2 numbers then add them togeather 
void Addition() {
	
	bool bInput = false;
	float fNumOne = 0, fNumTwo = 0;
	InputValues NumberInput;

	do {
		do
		{
			system("cls");

			ChangeTextColour(1);
			ChangeConsoleWindowSize(500, 250);
			std::cout << "#############################";
			ChangeTextColour(7);
			std::cout << " INPUTS ";
			ChangeTextColour(1);
			std::cout << "###########################\n\n";
			ChangeTextColour(7);

			std::cout << "Please enter in your First Number: ";
			NumberInput = NumberInputChecker();
			bInput = NumberInput.bTrueOrFalse;
			fNumOne = NumberInput.fNumber;
		} while (!bInput);

		std::cout << "Please enter in your second Number: ";
		NumberInput = NumberInputChecker();
		bInput = NumberInput.bTrueOrFalse;
		fNumTwo = NumberInput.fNumber;
		std::cout << std::endl;

	} while (!bInput);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#############################";
	ChangeTextColour(7);
	std::cout << " Result ";
	ChangeTextColour(1);
	std::cout << "###########################\n\n";
	ChangeTextColour(7);
	
	//outputing result 
	std::cout <<fNumOne << "+" << fNumTwo << "=" << fNumOne + fNumTwo << "\n\n";

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#########################";
	ChangeTextColour(7);
	std::cout << " Any Key For Menu ";
	ChangeTextColour(1);
	std::cout << "######################";
	_getch();
	ChangeTextColour(7);

	
}
// subtract the second number from the first
void Subtraction() {

	bool bInput = false;
	float fNumOne = 0, fNumTwo = 0;
	InputValues NumberInput;

	do {
		do
		{
			system("cls");

			ChangeTextColour(1);
			ChangeConsoleWindowSize(500, 250);
			std::cout << "#############################";
			ChangeTextColour(7);
			std::cout << " INPUTS ";
			ChangeTextColour(1);
			std::cout << "###########################\n\n";
			ChangeTextColour(7);

			std::cout << "Please enter in your First Number: ";
			NumberInput = NumberInputChecker();
			bInput = NumberInput.bTrueOrFalse;
			fNumOne = NumberInput.fNumber;
		} while (!bInput);

		std::cout << "Please enter in your second Number: ";
		NumberInput = NumberInputChecker();
		bInput = NumberInput.bTrueOrFalse;
		fNumTwo = NumberInput.fNumber;
		std::cout << std::endl;

	} while (!bInput);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#############################";
	ChangeTextColour(7);
	std::cout << " Result ";
	ChangeTextColour(1);
	std::cout << "###########################\n\n";
	ChangeTextColour(7);

	//outputing result 
	std::cout << fNumOne << "-" << fNumTwo << "=" << fNumOne - fNumTwo<< "\n\n";

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#########################";
	ChangeTextColour(7);
	std::cout << " Any Key For Menu ";
	ChangeTextColour(1);
	std::cout << "######################";
	_getch();
	ChangeTextColour(7);


	
}
// will devied the first number by the second  
void Devison() {
	bool bInput = false;
	float fNumOne = 0, fNumTwo = 0;
	InputValues NumberInput;

	do {
		do
		{
			system("cls");

			ChangeTextColour(1);
			ChangeConsoleWindowSize(500, 250);
			std::cout << "#############################";
			ChangeTextColour(7);
			std::cout << " INPUTS ";
			ChangeTextColour(1);
			std::cout << "###########################\n\n";
			ChangeTextColour(7);

			std::cout << "Please enter in your Numerator: ";
			NumberInput = NumberInputChecker();
			bInput = NumberInput.bTrueOrFalse;
			fNumOne = NumberInput.fNumber;
		} while (!bInput);

		std::cout << "Please enter in your Denumerator: ";
		NumberInput = NumberInputChecker();
		bInput = NumberInput.bTrueOrFalse;
		fNumTwo = NumberInput.fNumber;
		std::cout << std::endl;

		if(fNumOne == 0|| fNumTwo == 0)
		{
			PrtinErrorMesage();
			bInput = false;
		}
	} while (!bInput);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#############################";
	ChangeTextColour(7);
	std::cout << " Result ";
	ChangeTextColour(1);
	std::cout << "###########################\n\n";
	ChangeTextColour(7);

	//outputing result 
	std::cout << fNumOne << "/" << fNumTwo << "=" << fNumOne / fNumTwo << "\n\n";

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#########################";
	ChangeTextColour(7);
	std::cout << " Any Key For Menu ";
	ChangeTextColour(1);
	std::cout << "######################";
	_getch();
	ChangeTextColour(7);
	
}
// will multiply two numbers
void Multiplication() {
	bool bInput = false;
	float fNumOne = 0, fNumTwo = 0;
	InputValues NumberInput;

	do {
		do
		{
			system("cls");

			ChangeTextColour(1);
			ChangeConsoleWindowSize(500, 250);
			std::cout << "#############################";
			ChangeTextColour(7);
			std::cout << " INPUTS ";
			ChangeTextColour(1);
			std::cout << "###########################\n\n";
			ChangeTextColour(7);

			std::cout << "Please enter in your First Number: ";
			NumberInput = NumberInputChecker();
			bInput = NumberInput.bTrueOrFalse;
			fNumOne = NumberInput.fNumber;
		} while (!bInput);

		std::cout << "Please enter in your Second Number: ";
		NumberInput = NumberInputChecker();
		bInput = NumberInput.bTrueOrFalse;
		fNumTwo = NumberInput.fNumber;
		std::cout << std::endl;

	} while (!bInput);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#############################";
	ChangeTextColour(7);
	std::cout << " Result ";
	ChangeTextColour(1);
	std::cout << "###########################\n\n";
	ChangeTextColour(7);

	//outputing result 
	std::cout << fNumOne << "*" << fNumTwo << "=" << fNumOne * fNumTwo << "\n\n";

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#########################";
	ChangeTextColour(7);
	std::cout << " Any Key For Menu ";
	ChangeTextColour(1);
	std::cout << "######################";
	_getch();
	ChangeTextColour(7);
	
}
// will give the user the area of thier rectangle
void RectangleArea() {
	bool bInput = false;
	float fNumOne = 0, fNumTwo = 0;
	InputValues NumberInput;

	do {
		do
		{
			system("cls");

			ChangeTextColour(1);
			ChangeConsoleWindowSize(500, 250);
			std::cout << "#############################";
			ChangeTextColour(7);
			std::cout << " INPUTS ";
			ChangeTextColour(1);
			std::cout << "###########################\n\n";
			ChangeTextColour(7);

			std::cout << "Please enter in the Lenght of the Rectangle: ";
			NumberInput = NumberInputChecker();
			bInput = NumberInput.bTrueOrFalse;
			fNumOne = NumberInput.fNumber;
		} while (!bInput);

		std::cout << "Please enter in the Width of the Rectangle: ";
		NumberInput = NumberInputChecker();
		bInput = NumberInput.bTrueOrFalse;
		fNumTwo = NumberInput.fNumber;
		std::cout << std::endl;

	} while (!bInput);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#############################";
	ChangeTextColour(7);
	std::cout << " Result ";
	ChangeTextColour(1);
	std::cout << "###########################\n\n";
	ChangeTextColour(7);

	//outputing result 
	std::cout << fNumOne << "*" << fNumTwo << "=" << fNumOne * fNumTwo << "\n\n";

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#########################";
	ChangeTextColour(7);
	std::cout << " Any Key For Menu ";
	ChangeTextColour(1);
	std::cout << "######################";
	_getch();
	ChangeTextColour(7);
}
// will give the user the are fo their triangle
void TriangleArea() {
	bool bInput = false;
	float fNumOne = 0, fNumTwo = 0;
	InputValues NumberInput;

	do {
		do
		{
			system("cls");

			ChangeTextColour(1);
			ChangeConsoleWindowSize(500, 250);
			std::cout << "#############################";
			ChangeTextColour(7);
			std::cout << " INPUTS ";
			ChangeTextColour(1);
			std::cout << "###########################\n\n";
			ChangeTextColour(7);

			std::cout << "Please enter in the Lenght of the base: ";
			NumberInput = NumberInputChecker();
			bInput = NumberInput.bTrueOrFalse;
			fNumOne = NumberInput.fNumber;
		} while (!bInput);

		std::cout << "Please enter in the Hight of the triangle: ";
		NumberInput = NumberInputChecker();
		bInput = NumberInput.bTrueOrFalse;
		fNumTwo = NumberInput.fNumber;
		std::cout << std::endl;

	} while (!bInput);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#############################";
	ChangeTextColour(7);
	std::cout << " Result ";
	ChangeTextColour(1);
	std::cout << "###########################\n\n";
	ChangeTextColour(7);

	//outputing result 
	std::cout << "0.5*" << "(" << fNumOne << "*" << fNumTwo << ")" << "=" << 0.5 * (fNumOne * fNumTwo);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#########################";
	ChangeTextColour(7);
	std::cout << " Any Key For Menu ";
	ChangeTextColour(1);
	std::cout << "######################";
	_getch();
	ChangeTextColour(7);

	
}

// will give the user the are fo their triangle
void Pythagorean() {
	bool bInput = false;
	float fNumOne = 0, fNumTwo = 0;
	InputValues NumberInput;

	do {
		do
		{
			system("cls");

			ChangeTextColour(1);
			ChangeConsoleWindowSize(500, 250);
			std::cout << "#############################";
			ChangeTextColour(7);
			std::cout << " INPUTS ";
			ChangeTextColour(1);
			std::cout << "###########################\n\n";
			ChangeTextColour(7);

			std::cout << "Please enter in the Lenght of the First side: ";
			NumberInput = NumberInputChecker();
			bInput = NumberInput.bTrueOrFalse;
			fNumOne = NumberInput.fNumber;
		} while (!bInput);

		std::cout << "Please enter in the Length of the Second side: ";
		NumberInput = NumberInputChecker();
		bInput = NumberInput.bTrueOrFalse;
		fNumTwo = NumberInput.fNumber;
		std::cout << std::endl;

	} while (!bInput);

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#############################";
	ChangeTextColour(7);
	std::cout << " Result ";
	ChangeTextColour(1);
	std::cout << "###########################\n\n";
	ChangeTextColour(7);

	//outputing result 
	std::cout << fNumOne << "^2" << " +" << fNumTwo << "^2" << " " << "=" << sqrt((fNumOne * fNumOne) + (fNumTwo * fNumTwo));

	ChangeTextColour(1);
	ChangeConsoleWindowSize(500, 250);
	std::cout << "#########################";
	ChangeTextColour(7);
	std::cout << " Any Key For Menu ";
	ChangeTextColour(1);
	std::cout << "######################";
	_getch();
	ChangeTextColour(7);
	
}

//Main method is were the computer will look to start the program 
int main() {

	Intro();
	
	char cUserInput; //variable to holde the users in put 
	bool bCorrectInput = false;

	do
	{

		do
		{
			//Re printing the menu untill the user selects a valid input
			Menu();
			cUserInput = _getch(); // getting the users input 
			bCorrectInput = MenuInputChecker(cUserInput);
		} while (!bCorrectInput);

		// calling fucntion based on user input 
		switch (cUserInput) {
		case '1':
			Addition();
			break;
		case '2':
			Subtraction();
			break;
		case '3':
			Devison();
			break;
		case '4':
			Multiplication();
			break;
		case '5':
			RectangleArea();
			break;
		case '6':
			TriangleArea();
			break;
		case '7':
			Pythagorean();
			break;
		case 'e':
		case 'E':
			system("cls");
			ChangeConsoleWindowSize(400, 150);
			ChangeTextColour(7);

			std::cout << "##################################################\n\n";
			ChangeTextColour(1);
			std::cout << "   Thank you for using  the Arithmatic Calculator" << "\n";
			std::cout << " \t     Press any key to continue..." << "\n" << "\n";
			ChangeTextColour(7);
			std::cout << "##################################################";

			_getch();
			system("cls"); 
			return 0; // if every thing works fine the comuter will return a 0 at the end of the program 
			break;
		}
	} while (true);
	
	
	

	

	
}