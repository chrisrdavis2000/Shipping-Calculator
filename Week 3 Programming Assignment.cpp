// Week 3 Programming Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

//Delcaring Constants
double const FRAGILE = 2.00;
double const USA_SHIPPING1 = 6.00; //Order Total Less Than 50 And In Usa
double const USA_SHIPPING2 = 9.00; //Order Total Greater Than 50 And Less Than 100 In Usa
double const USA_SHIPPING3 = 12.00; //Order Total Greater Than 100 And Less Than 150 In Usa
double const CAN_SHIPPING1 = 8.00; //Order Total Less Than 50 And In Can
double const CAN_SHIPPING2 = 12.00; //Order Total Greater Than 50 And Less Than 100 In Can
double const CAN_SHIPPING3 = 15.00; //Order Total Greater Than 100 And Less Than 150 In Can
double const AUS_SHIPPING1 = 10.00; //Order Total Less Than 50 And In Aus
double const AUS_SHIPPING2 = 14.00; //Order Total Greater Than 50 And Less Than 100 In Aus
double const AUS_SHIPPING3 = 17.00; //Order Total Greater Than 100 And Less Than 150 In Aus
double const NEP_SHIPPING1 = 100.00; //Order Total Less Than 50 In Neptune
double const NEP_SHIPPING2 = 150.00; //Order Total Greater Than 50 and Less Than 100 In Neptune
double const NEP_SHIPPING3 = 200.00; //Order Total Greater Than 100 And Less 150 in Neptune In Neptune
double const FREE_SHIPPING = 0.00; //Order Total Greater Than 150 In Usa/Can/Aus

int main()
{
	//Declares Variables
	ofstream outFile; //variable for output file
	string destination;
	string item_name;
	char is_fragile;
	double order_total;
	double shipping_cost = 0.00;
	double total_shipping_cost = 0.00;

	//Sets Fill For Output
	cout << setfill('*');

	//Creates Program Title
	cout << setw(50) << "*" << endl;
	cout << "ITCS 2530 - Programming Assignment For Week #3" << endl;
	cout << setw(50) << "*" << endl << endl;

	//Ask User For Items Name And Inputs The Users Data
	cout << setw(25) << left << "Please enter the item name (no spaces)" << setw(25) << right << ":";
	cin >> item_name;

	//Asks User If Item Is Fragile And Inputs The Users Data
	cout << setw(38) << left << "Is the item fragile? (y=yes/n=no)" << setw(25) << right << ":";
	cin >> is_fragile;

	//Checks For Valid Input For Fragile
	if (!(is_fragile == 'y' || is_fragile == 'n' || is_fragile == 'Y' || is_fragile == 'N'))
	{
		cout << "Invalid entry, exiting";
		return 1;
	}

	//Asks User For Order Total And Inputs The Users Data
	cout << setw(38) << left << "Please enter your order total" << setw(25) << right << ":";
	cin >> order_total;

	//Asks User For Destination And Inputs The Users Data
	cout << setw(25) << left << "Please enter destination. (usa/can/aus/neptune)" << setw(24) << right << ":";
	cin >> destination;

	//Checks For Valid Input For Destination
	if (!(destination == "usa" || destination == "can" || destination == "aus" ||
		destination == "USA" || destination == "CAN" || destination == "AUS" ||
		destination == "Usa" || destination == "Can" || destination == "Aus" ||
		destination == "neptune" || destination == "Neptune"))
	{
		cout << "Invalid entry, exiting";
		return 1;
	}

	//Determines Shipping Cost Based On Area
	if (destination == "usa" || destination == "USA" || destination == "Usa")
	{
		if (order_total <= 50.00)
			shipping_cost = USA_SHIPPING1;
		else if (order_total > 50.00 && order_total <= 100.00)
			shipping_cost = USA_SHIPPING2;
		else if (order_total > 100.00 && order_total <= 150.00)
			shipping_cost = USA_SHIPPING3;
		else if (order_total > 150.00)
			shipping_cost = FREE_SHIPPING;
	}
	else if (destination == "can" || destination == "CAN" || destination == "Can")
	{
		if (order_total <= 50.00)
			shipping_cost = CAN_SHIPPING1;
		else if (order_total > 50.00 && order_total <= 100.00)
			shipping_cost = CAN_SHIPPING2;
		else if (order_total > 100.00 && order_total <= 150.00)
			shipping_cost = CAN_SHIPPING3;
		else if (order_total > 150.00)
			shipping_cost = FREE_SHIPPING;
	}
	else if (destination == "aus" || destination == "AUS" || destination == "Aus")
	{
		if (order_total <= 50.00)
			shipping_cost = AUS_SHIPPING1;
		else if (order_total > 50.00 && order_total <= 100.00)
			shipping_cost = AUS_SHIPPING2;
		else if (order_total > 100.00 && order_total <= 150.00)
			shipping_cost = AUS_SHIPPING3;
		else if (order_total > 150.00)
			shipping_cost = FREE_SHIPPING;
	}
	else if (destination == "neptune" || destination == "Neptune")
	{
		if (order_total <= 50.00)
			shipping_cost = NEP_SHIPPING1;
		else if (order_total > 50.00 && order_total <= 100.00)
			shipping_cost = NEP_SHIPPING2;
		else if (order_total > 100.00 && order_total <= 150.00)
			shipping_cost = NEP_SHIPPING3;
		else if (order_total > 150.00)
			shipping_cost = FREE_SHIPPING;
	}

	//Determines If There Is A Fee For Fragile Item And Applies It
	if (is_fragile == 'y' || is_fragile == 'Y')
		shipping_cost += FRAGILE;

	//Opens The Output File
	outFile.open("Order.txt");
	if (outFile.fail())
	{
		return 0;
	}

	outFile << setfill('*');

	//Outputs Name Of Item
	cout << endl;
	transform(item_name.begin(), item_name.end(), item_name.begin(), std::toupper); //Turns item_name To All Caps
	cout << setw(45) << left << "Your item is" << item_name << endl;
	outFile << setw(45) << left << "Your item is" << item_name << endl;

	//Outputs Shipping Cost
	cout << showpoint << fixed << setprecision(2) << setw(45) << left << "Your shipping cost is" << "$" << shipping_cost << endl;
	outFile << showpoint << fixed << setprecision(2) << setw(45) << left << "Your shipping cost is" << "$" << shipping_cost << endl;

	//Outputs Shipping Location
	if (destination == "usa" || destination == "USA" || destination == "Usa")
	{
		cout << setw(45) << left << "You are shipping to" << "USA" << endl;
		outFile << setw(45) << left << "You are shipping to" << "USA" << endl;
	}
	else if (destination == "can" || destination == "CAN" || destination == "Can")
	{
		cout << setw(45) << left << "You are shipping to" << "CAN" << endl;
		outFile << setw(45) << left << "You are shipping to" << "CAN" << endl;
	}
	else if (destination == "aus" || destination == "AUS" || destination == "Aus")
	{
		cout << setw(45) << left << "You are shipping to" << "AUS" << endl;
		outFile << setw(45) << left << "You are shipping to" << "AUS" << endl;
	}
	else if (destination == "neptune" || destination == "Neptune")
	{
		cout << setw(45) << left << "You are shipping to" << "NEPTUNE" << endl;
		outFile << setw(45) << left << "You are shipping to" << "NEPTUNE" << endl;
	}

	//Determines And Outputs Total Shipping Cost
	total_shipping_cost = order_total + shipping_cost;
	cout << setw(45) << left << "Your total shipping costs are" << "$" << total_shipping_cost << endl;
	outFile << setw(45) << left << "Your total shipping costs are" << "$" << total_shipping_cost << endl;

	//Prints Thank You
	cout << endl;
	cout << setfill('-');
	cout << setw(55) << right << "Thank You!" << endl;
	outFile << setfill('-');
	outFile << setw(55) << right << "Thank You!";

	//Closes File Order.txt
	outFile.close();
}