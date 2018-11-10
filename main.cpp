// 
//  Artur Wojcik
//  NetID: awojci5
//  CS 474 UIC Spring 2018
//  Project 4 
//  Date:   5/5/2018
//
//  SAL interpreter using multiple classes and using COMMAND PATTERN  
//  Read file "input.sal" and stores into memory size 256 
//  Execution can be performed line by line using - "d" command 
//  Or all instraction at once using command - "r" 
//  To load file use "l" command and file must be in same folder 
//  
//
//  
//		© 2018 Artur Wojcik *** ALL RIGHTS RESERVED ***
//

#include"utility.h"



int main() {
	
	info(); 
	Computer *comp = nullptr;// = new Computer();

	std::string input;
	bool alreadyComputer = false; 
	std::cout << "\t\t  * * * Welcome to SAL Emulator * * * \n\n\n";

	printInstruction();

	while (true) {

		std::cout << "\tEnter command:  ->  ";
		std::cin >> input;
		if (input == "q") {
			break;
		}
		else if (input == "h") {
			std::cout << "\t\t  * * * Available commands * * * \n\n";
			printInstruction(); 
		}
		else if (input == "i") {
			//read file 
			if (alreadyComputer == true) {
				delete comp; 
			}

			comp = new Computer();
			alreadyComputer = true; 
			std::cout << "\n\n\t\tYour Computer has been created: \n\n";
			readFile(comp);
		}
		else if (input == "r") {
			if (comp != nullptr) {
				executeProgram(comp); 
				//comp->perform();
			}
			else {
				warning(); 
			}
		}
		else if (input == "d") {
			if (comp != nullptr) {
				comp->perform(); 
				comp->Print(); 
			}
			else {
				warning();
			}
		}
		else if (input == "s") {
			if (comp != nullptr) {
				std::cout << "\n\n\t\t*** SAVING TO FILE ***     \n\t\tFile name:    ->     output.txt\n\n";
				saveToFile(comp);

			}
			else {
				warning();
			}
		}
		else {
			std::cout << "\t* * * Invalid input * * *\n\n";
		}
	}

	std::cout << "\n\n\tExiting program !!!!\n\n\n";

	if (comp != nullptr) {
		delete comp;
		comp = nullptr; 
	}

	return 0;
}
