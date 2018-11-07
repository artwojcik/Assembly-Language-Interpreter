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

#include "LDI.h"



void LDI::Print()
{
	
}

void LDI::Execute()
{
	this->computer_->setProgramCounter(this->computer_->getProgramCounter() + 1); 
	this->computer_->setRegisterA(this->number_); 
}

void LDI::setNumber(int num)
{
	this->number_ = num; 
}

int LDI::getNumber() const
{
	return this->number_;
}

LDI::LDI(Computer* comp)
	:computer_(comp)
{
}

LDI::LDI(int num)
	:computer_(new Computer()), number_(num)
{
}


LDI::~LDI()
{
}
