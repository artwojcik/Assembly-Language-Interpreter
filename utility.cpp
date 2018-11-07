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


void saveToFile(Computer *comp) {
	comp->saveToFile();
}
void printInstruction() {
	std::cout << "\ti - This command reads a SAL program from a file named input.sal. The file \n";
	std::cout << "\t    should be in the same directory as your executable ALI file. You may assume \n";
	std::cout << "\t    that the input program is syntactally correct. The program is stored in internal \n";
	std::cout << "\t    ALI memory and displayed on the user’s console.  \n\n";
	std::cout << "\t           !!! NOTE PRESSING MULTIPLE TIMES 'i' will read file from begining!!!!!\n\n";
	std::cout << "\td - Execute the program in debug mode.This command causes one line of code to be executed.\n";
	std::cout << "\t    The PC, registers, bits and the state of memory are updated as a result of the execution.\n";
	std::cout << "\t    The value of the registers, the PC, the bits and the content of memory after the instruction \n";
	std::cout << "\t    is executed are diplayed on the user’s screen.\n\n";
	std::cout << "\tr - Run the program to completion.This command causes the execution of program starting \n";
	std::cout << "\t    from the current PC instruction until the halt instruction is found or the program reaches \n";
	std::cout << "\t    its last instruction.The content of the registers, PC, bits and memory are displayed on the user’s console.\n\n";
	std::cout << "\ts - Save the program state.This command causes the content of memory, the bits and the \n";
	std::cout << "\t    registers to be saved to a file named output.txt.\n\n";
	std::cout << "\tq - Quits the ALI.\n\n";
	std::cout << "\th - Display help \n\n";
}

void processCommand(Computer * comp, std::string name, std::string number, int index) {
	if (name == "DEC") {
		SAL * val_1 = new DEC(comp);
		val_1->setVar(name);
		val_1->setAddress(index);
		comp->setSymbol(number, index);
		comp->setMemory(index, val_1);
		//val_1->Execute();
		//comp->Print();
	}
	else if (name == "ADD") {
		SAL *ad = new ADD(comp);
		comp->setMemory(index, ad);
		//ad->Execute();
		//comp->Print();
	}
	else if (name == "HLT") {
		SAL *hl = new HLT(comp);
		comp->setMemory(index, hl);

	}
	else if (name == "JVS") {
		SAL *jvs = new JVS(comp);
		std::stringstream convert(number);
		int x = 0;
		convert >> x;
		jvs->setNumber(x);
		comp->setMemory(index, jvs);
		//comp->Print();
	}
	else if (name == "JZS") {
		SAL *jzs = new JZS(comp);
		std::stringstream convert(number);
		int x = 0;
		convert >> x;
		jzs->setNumber(x);
		comp->setMemory(index, jzs);
		//comp->Print();

	}
	else if (name == "LDA") {
		SAL *lda = new LDA(comp);
		lda->setSYmbolST(number);
		comp->setMemory(index, lda);
		//comp->Print();
	}
	else if (name == "LDB") {
		SAL *ldb = new LDB(comp);
		ldb->setSYmbolST(number);
		comp->setMemory(index, ldb);
		//comp->Print();
	}
	else if (name == "LDI") {
		std::stringstream convert(number);
		int x = 0;
		convert >> x;
		SAL * val2 = new LDI(comp);

		val2->setNumber(x);
		comp->setMemory(index, val2);
		//val2->Execute();
		//comp->Print();
	}
	else if (name == "ST") {
		SAL * st = new ST(comp);
		st->setSYmbolST(number);
		comp->setMemory(index, st);
		//st->Execute();
		//comp->Print();
	}
	else if (name == "XCH") {
		SAL * xc = new XCH(comp);
		comp->setMemory(index, xc);
		//xc->Execute();
		//comp->Print();
	}
	else if (name == "JMP") {
		SAL *jmp = new JMP(comp);
		std::stringstream convert(number);
		int x = 0;
		convert >> x;
		jmp->setNumber(x);
		comp->setMemory(index, jmp);
		//comp->Print();
	}
}

void readFile(Computer *comp) {
	std::string name, number, line;
	std::string xch = "XCH";
	std::string add = "ADD";
	std::string hlt = "HLT";
	int index = 0;

	std::ifstream file("input.sal", std::ifstream::in);
	if (!file.good()) {
		std::cerr << "  ERROR FILE\n\n";
		exit(-1);
	}
	while (std::getline(file, line)) {
		auto tempPos = line.find(' ');
		auto isXch = line.find(xch);
		auto isAdd = line.find(add);
		auto isHlt = line.find(hlt);

		if (isAdd != std::string::npos || isXch != std::string::npos || isHlt != std::string::npos) {
			name = line.substr(0, 3);
			number = "NONE";
		}
		else {
			name = line.substr(0, tempPos);
			if (tempPos != std::string::npos) {
				number = line.substr(tempPos + 1, line.length());
			}
		}
		processCommand(comp, name, number, index);
		index++;
	}
	comp->Print();
}
void warning() {
	std::cout << "\n\t\t* * * No computer created... press 'i' to initilaize simulation...\n\n";
}

void executeProgram(Computer * comp) {
	
	for (int i = comp->getProgramCounter(); i < 256; ) {
		
		if (comp->getMemory(i) != NULL) {
			comp->perform();
			
			i = comp->getProgramCounter();
		}
		if (comp->getMemory(i) == NULL)
			break;
	}
	comp->Print();
}
void info()
{
	std::cout << "\t  _______________________\n\n";
	std::cout << "\t |   Artur Wojcik        |\n";
	std::cout << "\t |   NetID: awojci5      |\n";
	std::cout << "\t |   CS 474              |\n";
	std::cout << "\t |   UIC SPRING 2018     |\n";
	std::cout << "\t |_______________________|\n\n\n";
}
