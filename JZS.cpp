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

#include "JZS.h"



void JZS::Execute()
{
	int temp = this->computer_->getZeroBit();
	if (temp > 0) {
		this->computer_->setProgramCounter(this->number_);
	}
	else {
		this->computer_->setProgramCounter(this->computer_->getProgramCounter() + 1);
	}
}

void JZS::setNumber(int num)
{
	this->number_ = num;
}

JZS::JZS(Computer* comp)
	: computer_(comp)
{
}


JZS::~JZS()
{
}
