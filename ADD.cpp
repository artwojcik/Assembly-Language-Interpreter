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

#include "ADD.h"
#include <cmath>




void ADD::Execute()
{
	int32_t tempA, tempB, temp, postiviOverflow, negativeOverflow, num;
	this->computer_->setProgramCounter(this->computer_->getProgramCounter() + 1);
	tempA = this->computer_->getRegisterA();
	tempB = this->computer_->getRegisterB();
	this->computer_->setRegisterA(tempA + tempB);
	postiviOverflow = (int)pow(2, 31) - 1;
	negativeOverflow = (int)pow(2, 31)*(-1);
	num = this->computer_->getRegisterA();

	if (tempA > 0 && tempB > postiviOverflow - tempA) {
		num = tempA + tempB; 
		this->computer_->setOverflowBit(1);
		this->computer_->setRegisterA(num); 
	}
	else if (tempA < 0 && tempB < negativeOverflow - tempA) {
		num = tempA + tempB; 
		this->computer_->setRegisterA(num); 
		this->computer_->setOverflowBit(1);
	}
	else {
		this->computer_->setOverflowBit(0);
	}

	temp = this->computer_->getRegisterA();

	if (temp == 0) {
		this->computer_->setZeroBit(1);
	}
	else {
		this->computer_->setZeroBit(0);
	}
}

ADD::ADD(Computer* comp)
	: computer_(comp)
{
}


ADD::~ADD()
{
}
