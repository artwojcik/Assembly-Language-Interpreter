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

#include "XCH.h"



void XCH::Execute()
{
	int temp = this->computer_->getRegisterA(); 
	this->computer_->setProgramCounter(this->computer_->getProgramCounter() + 1); 
	this->computer_->setRegisterA(this->computer_->getRegisterB());
	this->computer_->setRegisterB(temp); 
}

void XCH::Print()
{
}

XCH::XCH(Computer* comput)
	:computer_(comput)
{
}




XCH::~XCH()
{
	this->computer_ = nullptr;
}
