//Creator:	Justin Blakeman - Oct 26, 2018
//Class:	COSC 2030 - Data Structures
//Name:		"Project01" - "Blood Sugar Project"

//This Code Implements the LinkedList Class and the Node Classes To Keep Track Of Blood Sugar Readings

#include "pch.h"
#include "LinkedList.h"
#include <iostream>
#include <String>
#include <list>
#include <array>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------A Function That Returns a String With Day and Time Info-------------------------------------->>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string theDayWeek(int dayOfWeek, int onWeek) {

	string day, week, dayWeek;

	if (dayOfWeek == 0) { day = "Monday"; }			///////	
	if (dayOfWeek == 1) { day = "Tuesday"; }		//
	if (dayOfWeek == 2) { day = "Wednesday"; }		//
	if (dayOfWeek == 3) { day = "Thursday"; }		////This Block of if- statements use the index of our list of days to determine the day. 
	if (dayOfWeek == 4) { day = "Friday"; }			//
	if (dayOfWeek == 5) { day = "Saturday"; }		//
	if (dayOfWeek == 6) { day = "Sunday"; }			///////

	week = " Week " + std::to_string(onWeek + 1);  // unions the string " Week " to the index of the current week+1, +1 because our index is zero based --- and humans are not

	dayWeek = day + week;			//unions the two strings containing info about the day and week
	return dayWeek;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------------------------------------------<<<
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	bool TruthBool = true;
	string input;
	int dayOfWeek = 0;			//To keep track (for refrencing values in our arrays) of the current day of the week user is on
	int onWeek = 0;				//Keeps track of week (for refrencing the correct linked list based on what week is currently selected)

	List mon1, tues1, wed1, thur1, fri1, sat1, sun1, mon2, tues2, wed2, thur2, fri2, sat2, sun2;		//14 Linked Lists, each representing a different day of the week for two seperate weeks

	std::list<List> week1 = { mon1, tues1, wed1, thur1, fri1, sat1, sun1 };								//a list array of size 7, that stores the linked lists  initial nodes for each day of the week
	std::list<List> week2 = { mon2, tues2, wed2, thur2, fri2, sat2, sun2 };								//a list array of size 7, that stores the linked lists  initial nodes for each day of the week

	std::array<std::list<List>, 2> theWeeks = { week1, week2 };						//An array of lists containing linked-lists, stores 2 lists of Lists, spots for week1 and week2

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////------------------------This is the start menu, the main screen for the user to select options on, will loop until given valid command to execute----------------------------------------->>>
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (TruthBool == true) {

		float value = 0.0;					//Blood Sugar Value is reset every iteration of the loop to zero, an invalid input purposefully, dont want old values triggering current menus
		cout << "*********************************************************************************************" << endl;
		cout << "*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*" << endl;
		cout << "*********************************************************************************************" << endl;
		cout << "_____________________________________________________________________________________________" << endl;
		cout << "\n\t\t\t\tToday is - ";
		cout << theDayWeek(dayOfWeek, onWeek) << endl;							//Calls a function that prints out appropriate day and week
		cout << "_____________________________________________________________________________________________" << endl;

		cout << "\n\tInput a Valid Blood Sugar Level\t\t-\t(All Values >0.0 Are Valid)\n\t\t-OR-\n\tInput an Option From the Following List of Commands:\n\n";

		cout << "\tList of Commands: \n";
		cout << "\t-----------------\n\t";
		cout << "'D' OR 'Day'\t- Summary of the Daily Readings Thus Far\n\t";
		cout << "'W' OR 'Week'\t- Summary of this Weeks Readings Thus Far\n\t";
		cout << "'N' OR 'Next'\t- Goto Next Day\n\t";
		cout << "'E' OR 'Exit'\t- To Exit\n\n";
		cout << "_____________________________________________________________________________________________" << endl;
		cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);	//this makes any user input where applicable lowercase, used later to more simply compare strings without worrying about case

		
		
		if ((input.compare("e") != 0) && (input.compare("exit") != 0) && (input.compare("d") != 0) && (input.compare("day") != 0) && (input.compare("w") != 0) && (input.compare("week") != 0) && (input.compare("n") != 0) && (input.compare("next") != 0)) {
			try {								//Try to convert the users input from string to float.
				value = std::stof(input);		//But only IF that input was a menu command. 
			}
			catch (...) {						//Catch any errors (i.e. string cannot convert to float)
				//cout << "INPUT ERROR" << endl;
				continue;						//If exception occurs skip the rest of this garbage and go back to the menu
			}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//----------------------This is The input new value logic, It accepts a valid BGL input from the user (int or float > 0) and inserts the value in the front of the selected list------------------------------------>>>
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			if (value > 0.0) {					//Since string "0" and negative value strings can sucessfully convert into floats, ensure here we only accept VALID input i.e. Floats > 0.0
				std::list<List>::iterator it = theWeeks[onWeek].begin();		//set our iterator at the begininng of the current week which is in an array of all theWeeks
				std::advance(it, dayOfWeek);		//Now advance to the current day of the week we are on
				List tmp = *it;								//create temp linked list that is a copy of the current days values
				tmp.insertAsFirst(value);			//Insert the users value  in the front of the temp list
				theWeeks[onWeek].insert(it, tmp);		//Insert at the currents days index in the week this temp list
				theWeeks[onWeek].erase(it);			//Erase the original day which was replaced

				continue;						//That is all we want to do.
			}
			else { continue; }					//If the string is of value 0 or a negative we don't do anything and skip the rest of this garbage below and go back to the main menu

		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------<<<
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//----------------------------------This If Statement Tests For User Exit, Then If True, Exits the Program--------------------------------------->>>
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		if ((input.compare("e") == 0) || (input.compare("exit") == 0)) {
			TruthBool = false;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//-----------------------------------------------------------------------------------------------------------------------------------------------<<<
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//----------------------Gives a Summary of the current day by iterating through the current weeks array to the current day and prinitng out the linked list in that position------------->>>
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		float sum = 0.0;			//initial value of sum set to zero. Why? Isn't it obvious?

		if ((input.compare("d") == 0) || (input.compare("day") == 0)) {
				std::list<List>::iterator it = theWeeks[onWeek].begin();
				std::advance(it, dayOfWeek);

				cout << "_____________________________________________________________________________________________" << endl;
				cout << "\n\tHere is A Summary of The Values Entered Today, " << theDayWeek(dayOfWeek, onWeek) << " :\n";		//Calls a function that prints out appropriate day and week
				cout << "\t-----------------------------------------------------------\n";

				cout << "\n\t" << *it;																			//*it points to the whole list on some day in the weeks array... Prints it out

				List tmp = *it;
				cout << "\n\n    Sum of Todays Values: " << tmp.sum(tmp) << endl;
				cout << "    Max Value of Todays Values: " << tmp.max(tmp) << endl;
				cout << "    Min Value of Todays Values: " << tmp.min(tmp) << endl;
				cout << "    There are '" << tmp.count(tmp) << "' entries on this day\n\n" << endl;

				system("pause");
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------<<<
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//------------------------Gives a Summary of the week by iterating through the current weeks array and prinitng out the linked lists--------------------->>>
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if ((input.compare("w") == 0) || (input.compare("week") == 0)) {


			//float deltaDay;
			int countDay = 0;					//Stores the entries on the day being interated through
			int countWk = 0;					//Stores the total entries in the week
			float sumWk = 0.0;				//Stores the sum of all entries in the week
			float deltaDayAmount = 0.0;			//Stores the highest deltacount
			int deltaDayNumber = -9;					//Stores the day of the week the highest delta was found -- Set to impossible day bcuz if there is no deltaDay we can't print out that there is...
			float deltaDayMin = 0.0;			//Stores the max entry on the highest delta day
			float deltaDayMax = 0.0;			//Stores the min entry on the highest delta day
			float maxWk;					//Stores the max value recorded in the week
			float minWk;					//Stores the min value recorded in the week
			List weekMaxList, weekMinList, deltaDayList;

			cout << "_____________________________________________________________________________________________" << endl;
			cout << "\n\n\tHere is A Summary of The Values Entered So Far In Week " << onWeek+1 << ":" << endl;
			cout << "\t--------------------------------------------------------\n\n";

			std::list<List>::iterator it = theWeeks[onWeek].begin();		//Start at the first day of the week we are on. Then iterate through from there.
			for (int i = 0; i <= 6; i++) {

				std::advance(it, i);				//'it' points to the element at index i, 'it' will keep its index through the loop, so at the end of this loop we need to reset it

				if (i == 0) { cout << "    Monday:\t" << *it << endl; }			//FROM HERE
				if (i == 1) { cout << "    Tuesday:\t" << *it << endl; }		//
				if (i == 2) { cout << "    Wednesday:\t" << *it << endl; }		//
				if (i == 3) { cout << "    Thursday:\t" << *it << endl; }		//This just prints out the day which the values being shown belong to (for use to help user know where values come from)
				if (i == 4) { cout << "    Friday:\t" << *it << endl; }			//
				if (i == 5) { cout << "    Saturday:\t" << *it << endl; }		//
				if (i == 6) { cout << "    Sunday:\t" << *it << endl; }			//TO HERE

				List tmp = *it;				//Creates a Linked-List tmp, who's first node data contains the position of a different day of the week each iteration of the for-loop (7 times == 7)
				List deltaDayList;			//Stores all the deltas from each day in the week

				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////COUNTS # OF ENTRIES
				countDay = tmp.count(tmp);
				if (countDay != 0.0) {
					countWk = countWk + countDay;
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////SUM OF WEEKS ENTRIES
				sumWk = sumWk + tmp.sum(tmp);			//sumWk + the sum of the current day currently iterated on
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////MAX OF WEEK ENTRIES
				maxWk = tmp.max(tmp);					//maxWk should be set to whatever the maximum of the current day being looked at is
				if (maxWk != 0.0) {	
					weekMaxList.insertAsFirst(maxWk);	//Inserts the maximum of the current day its on into a linked list
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////MIN WEEK STUFF
				minWk = tmp.min(tmp);
				if (minWk != 0.0) {
					weekMinList.insertAsFirst(minWk);	//Inserts the maximum of the current day its on into a linked list
				}
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////DELTA STUFF
				if ((minWk != 0.0) && (maxWk != 0.0)) {				//our min() and max() functions return a zero if the list if empty so no need to do anything for an empty list
					deltaDayList.insertAsFirst(maxWk - minWk);		//insterts the delta of the day into a linked list of deltas for the week
					if ((maxWk - minWk) > deltaDayAmount) {		//if this delta is bigger than all the others before it then it is our highest delta
						deltaDayAmount = maxWk - minWk;			//so we change this variable to represent that
						deltaDayNumber = i;						//This stores which day of the week the highest delta was found on
						deltaDayMax = maxWk;					//This stores the max value from the delta
						deltaDayMin = minWk;					//This stores the min value from the delta
					}
				}
				else {
					deltaDayList.insertAsFirst(0.0);		//If minWk or maxWk were zero then insert a dummy value into the linked list, to keep order of days with the index.
				}

	
				std::advance(it, (i * -1));						//Sets iterator back to element index 0, thus now the indexing it i amount of times will result in the correct positioning
			}
			
			maxWk = weekMaxList.max(weekMaxList);				//Now finds the true max from our list of possible max's from each day by calling max() on our temporary list
			minWk = weekMinList.min(weekMinList);				//Now finds the true min from our list of possible min's from each day by calling max() on our temporary list

			cout << "\n\n\tSum of This Weeks Values: " << sumWk << endl;					//FROM HERE ----->>>
			cout << "\tMax Value of This Weeks Values: " << maxWk << endl;					//		This prints out all the values we found above: min(), max(), sum(), count()
			cout << "\tMinimum Value of This Weeks Values: " << minWk << endl;				//
			cout << "\tThere are '" << countWk << "' Entries From This Week" << endl;		//TO HERE <<<-----

																							//THAT LONG COUPLE BELOW PRINTS OUT : HIGHEST DELTA INFO
			if (deltaDayNumber != -9) {
				cout << "\n\tYou Recorded Your Largest Delta Difference in Blood Sugar Levels on " << theDayWeek(deltaDayNumber, onWeek + 1) << "\n\tThe Delta Value is: " << deltaDayAmount << "\n\tThe Low and High Values On This Day Are: '" << deltaDayMin << "' and '" << deltaDayMax << "' Respectively\n\n" << endl;

			}
			else {
				cout << "\n\tWhoops! I Did Not Have Enough Information To Generate a Highest Delta Value For This Week!!!\n" << endl;
			}

			system("pause");

		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------<<<
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//------------------------This keeps track of what day and week it is and stores that info so later we can easily access the current day/weeks info------------------------->>>
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if ((input.compare("n") == 0) || (input.compare("next") == 0)) {

			cout << "*********************************************************************************************" << endl;
			cout << "*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*" << endl;
			cout << "*********************************************************************************************" << endl;

			if ((dayOfWeek == 6) && (onWeek + 1 == theWeeks.size())) { //If the day is sunday and the current week is the last week in memory then:
				onWeek = 0;
				dayOfWeek = -1;
			}
			if (dayOfWeek == 6) {	//If the day is sunday but we arent on the last week in memory then:
				onWeek++;
				dayOfWeek = -1;
			}
			dayOfWeek++;				//The user entered N for a reason. Increment the day no matter what
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------<<<
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}

	return 0;
}