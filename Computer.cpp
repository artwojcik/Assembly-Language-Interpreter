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

#include "Computer.h"
#include <iostream>
#include <fstream>
#include <typeinfo>




Computer::Computer()
	:registerA_(0), registerB_(0), zeroBit_(0), overflowBit_(0), programCounter_(0)
{
	for (int i = 0; i < 256; i++) {
		this->memory_[i] = nullptr;
	}
}


Computer::~Computer()
{
	for (int i = 0; i < 256; i++) {
		if (this->memory_[i] != NULL) {
			delete this->memory_[i];
		}
	}
}

void Computer::Print()
{
	std::string nextOP = "NULL"; 

	if (memory_[this->getProgramCounter()] != nullptr) {
		nextOP = typeid(*memory_[this->getProgramCounter()]).name();
		auto convertName = nextOP.find("INT");
		if (convertName != std::string::npos) {
			nextOP = memory_[this->getProgramCounter()]->getNumberFromINT(); // << " ";
		}
		else {
			nextOP = typeid(*memory_[this->getProgramCounter()]).name(); // << " ";
		}
	}


	std::cout << "\n\n   * * *   All information about you computer * * * \n\n";
	std::cout << "\tRegister A: " << registerA_ << std::endl; 
	std::cout << "\tRegister B: " << registerB_ << std::endl;
	std::cout << "\tZeroBit " << zeroBit_ << std::endl;
	std::cout << "\tOverflowBit: " << overflowBit_ << std::endl;
	std::cout << "\tPC: " << programCounter_ << std::endl;
	std::cout << "\tNEXT OP wil be: " << nextOP << std::endl<<std::endl; 
	std::cout << "\tMemory state: -> ";
	for (int i = 0; i < 256; i++) {
		//std::cout << std::typ
		if (memory_[i] == nullptr) {
			//std::cout << "NULL "; 
		}
		else {
			std::string temp = typeid(*memory_[i]).name(); 
			//std::cout<< temp<<"\n\n"; 

			auto str = temp.find("INT"); 

			if (str != std::string::npos) {
				std::cout << memory_[i]->getNumberFromINT() << " "; 
			}
			else {
				std::cout << typeid(*memory_[i]).name() << " ";
			}
		}

	}
	std::cout << std::endl <<"\n";
}

int Computer::getRegisterA() const
{
	return this->registerA_;
}

int Computer::getRegisterB() const
{
	return this->registerB_;
}

int Computer::getZeroBit() const
{
	return this->zeroBit_;
}

int Computer::getOverflowBit() const
{
	return this->overflowBit_;
}

int Computer::getProgramCounter() const
{
	return this->programCounter_;
}

SAL *Computer::getMemory(int index)
{
	return this->memory_[index];
}

int Computer::getSymbol(std::string symbol)
{
	return this->dictionary[symbol];
}

std::map<std::string, int>* Computer::getMap()
{
	return &dictionary;
}

void Computer::setRegisterA(const int & num)
{
	this->registerA_ = num; 
}

void Computer::setRegisterB(const int & num)
{
	this->registerB_ = num; 
}

void Computer::setZeroBit(const int & num)
{
	this->zeroBit_ = num; 
}

void Computer::setOverflowBit(const int & num)
{
	this->overflowBit_ = num; 
}

void Computer::setProgramCounter(const int & num)
{
	this->programCounter_ = num; 
}

void Computer::setMemory(const int & index, SAL *object)
{
	this->memory_[index] = object; 
}

void Computer::setSymbol(std::string symbol, int adress)
{
	if (this->dictionary.find(symbol) == this->dictionary.end()) {
		// not found
		this->dictionary.insert(std::make_pair(symbol, adress));
	}
	else {
		// found
		this->dictionary[symbol] = adress; 

	}
	//this->dictionary.insert(std::make_pair(symbol, adress)); 
}

void Computer::perform()
{

	if(this->memory_[this->programCounter_ ] != nullptr)
		this->memory_[this->programCounter_ ]->Execute();
	
}

void Computer::saveToFile()
{
	std::string nextOP = "NULL";

	if (memory_[this->getProgramCounter()] != nullptr) {
		nextOP = typeid(*memory_[this->getProgramCounter()]).name();
		auto convertName = nextOP.find("INT");
		if (convertName != std::string::npos) {
			nextOP = memory_[this->getProgramCounter()]->getNumberFromINT(); // << " ";
		}
		else {
			nextOP = typeid(*memory_[this->getProgramCounter()]).name(); // << " ";
		}
	}


		std::ofstream file("output.txt");
		if (!file.good()) {
			std::cout << "ERROR FILE while saving ";
			return; 
		}
		file << "   * * *   All information about you computer * * * \n\n";
		file << "\tRegister A: " << registerA_ << std::endl;
		file << "\tRegister B: " << registerB_ << std::endl;
		file << "\tZeroBit " << zeroBit_ << std::endl;
		file << "\tOverflowBit: " << overflowBit_ << std::endl;
		file << "\tPC: " << programCounter_ << std::endl;
		file << "\tNEXT OP wil be: " << nextOP << std::endl<<std::endl;
		file << "\tMemory state: -> ";
		for (int i = 0; i < 256; i++) {
			//std::cout << std::typ
			if (memory_[i] == nullptr) {
				//std::cout << "NULL "; 
			}
			else {
				std::string temp = typeid(*memory_[i]).name();
				//std::cout<< temp<<"\n\n"; 

				auto str = temp.find("INT");

				if (str != std::string::npos) {
					file << memory_[i]->getNumberFromINT() << " ";
				}
				else {
					file << typeid(*memory_[i]).name() << " ";
				}
			}

		}
		file << std::endl << "\n\n";
	
}



