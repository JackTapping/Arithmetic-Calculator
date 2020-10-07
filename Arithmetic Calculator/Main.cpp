#include <IOstream> // Allows the use of cin and cout to get inputs and outputs 
#include <conio.h> // Allows the use of _getch() to allow the program to wait for user input 
#include <cmath> // Allows the use of sqrt to to get the squer root of a number 
#include<Windows.h> // Allows me to change the console window size and text color  


//Function 

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
	system("cls");
}

// printing out the main menu to the user 
void Menu()
{
	ChangeConsoleWindowSize(500, 225);
	//printing out the menu
	std::cout << "Press 1: for Additon" << "\n";
	std::cout << "Press 2: for Subtration" << "\n";
	std::cout << "Press 3: for Divison" << "\n";
	std::cout << "Press 4: for Multiplication" << "\n";
	std::cout << "Press 5: for Area of a Rectangle " << "\n";
	std::cout << "Press 6: for Area of a Triangle " << "\n";
	std::cout << "Press 7: to Calculate the unknown side of a Right Angle Triangle  " << "\n";

	ChangeTextColour(5);
	std::cout << "Press E: to Exit the program " << "\n";
}

// will aske the use for 2 numbers then add them togeather 
void Addition() {
	float fNumOne, fNumTwo; // two ints to hold the users numbers

	system("cls"); // usind this to clear the console window to make the program less clutered 

	//getting numbers
	std::cout << "Please enter in your first Number: ";
	std::cin >> fNumOne;

	std::cout << "Please enter in your second Number: ";
	std::cin >> fNumTwo;
	std::cout << std::endl;

	//outputing result 
	std::cout << fNumOne << "+" <<fNumTwo << "=" <<fNumOne + fNumTwo;
}

// subtract the second number from the first
void Subtraction() {
	float fNumOne, fNumTwo; // two ints to hold the users numbers

	system("cls"); // usind this to clear the console window to make the program less clutered 

	//getting numbers
	std::cout << "Please enter in your first Number: ";
	std::cin >> fNumOne;

	std::cout << "Please enter in your second Number: ";
	std::cin >> fNumTwo;
	std::cout << std::endl;

	//outputing result 
	std::cout << fNumOne << "-" << fNumTwo << "=" << fNumOne - fNumTwo;
}
// will devied the first number by the second  
void Devison() {
	float fNumOne, fNumTwo; // two ints to hold the users numbers

	system("cls"); 

	//getting numbers
	std::cout << "Please enter in your Numerator: ";
	std::cin >> fNumOne;

	std::cout << "Please enter in your Denumerator: ";
	std::cin >> fNumTwo;
	std::cout << std::endl;

	//outputing result 
	std::cout << fNumOne << "/" << fNumTwo << "=" << fNumOne / fNumTwo;
}
// will multiply two numbers
void Multiplication() {
	float fNumOne, fNumTwo; // two ints to hold the users numbers

	system("cls"); 

	//getting numbers
	std::cout << "Please enter in your first Number: ";
	std::cin >> fNumOne;

	std::cout << "Please enter in your second Number: ";
	std::cin >> fNumTwo;
	std::cout << std::endl;

	//outputing result 
	std::cout << fNumOne << "*" << fNumTwo << "=" << fNumOne * fNumTwo;
}
// will give the user the area of thier rectangle
void RectangleArea() {
	float fNumOne, fNumTwo; // two ints to hold the users numbers

	system("cls");  

	//getting numbers
	std::cout << "Please enter in the Legnth of the Rectanlge: ";
	std::cin >> fNumOne;

	std::cout << "Please enter in the width of the Rectangle: ";
	std::cin >> fNumTwo;
	std::cout << std::endl;

	//outputing result 
	std::cout << fNumOne << "*" << fNumTwo << "=" << fNumOne * fNumTwo;
}
// will give the user the are fo their triangle
void TriangleArea() {
	float fNumOne, fNumTwo; // two ints to hold the users numbers

	system("cls"); 

	//getting numbers
	std::cout << "Please enter in the Legnth of the Base: ";
	std::cin >> fNumOne;

	std::cout << "Please enter in the Hight of the triangle: "; 
	std::cin >> fNumTwo;
	std::cout << std::endl;

	//outputing result 
	std::cout << "0.5*" << "(" <<fNumOne << "*" << fNumTwo << ")" << "=" << 0.5 * (fNumOne * fNumTwo);
}

// will give the user the are fo their triangle
void Pythagorean() {
	float fNumOne, fNumTwo; // two ints to hold the users numbers

	system("cls");  

	//getting numbers
	std::cout << "Please enter in the Legnth of the first side of the Triangle: ";
	std::cin >> fNumOne;

	std::cout << "Please enter in the Legnth of the Second side of the Triangle: ";  
		std::cin >> fNumTwo;
	std::cout << std::endl;

	//outputing result 
	std::cout << fNumOne << "^2" << " +" << fNumTwo << "^2" << " "<< "=" << sqrt((fNumOne * fNumOne) + (fNumTwo * fNumTwo));
}
//Main method is were the computer will look to start the program 
int main() {

	Intro();
	Menu();

	

	char cUserInput; //variable to holde the users in put 
	cUserInput = _getch(); // getting the users input 

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
		std::cout << "EXIT" << "\n";
		break;
	}

	return 0; // if every thing works fine the comuter will return a 0 at the end of the program 
}