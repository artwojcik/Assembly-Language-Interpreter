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

#include "DEC.h"



void DEC::Execute()
{
	this->computer_->setProgramCounter(this->computer_->getProgramCounter() + 1); 
	this->computer_->setSymbol(this->var, this->address); 
}

void DEC::setVar(std::string myVar)
{
	this->var = myVar; 
}

void DEC::setAddress(int num)
{
	this->address = num; 
}

std::string DEC::getVar()
{
	return this->var;
}

DEC::DEC(Computer* comp)
	:computer_(comp)
{
}


DEC::~DEC()
{
}
