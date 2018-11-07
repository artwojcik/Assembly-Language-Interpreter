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

#include "LDA.h"



void LDA::Execute()
{
	//std::string temp; 
	int temp; 
	this->computer_->setProgramCounter(this->computer_->getProgramCounter() + 1); 
	temp = this->computer_->getSymbol(this->symbol); 
	int k = this->computer_->getMemory(temp)->getNumberFromINT();

	this->computer_->setRegisterA(k);


	//SAL* mem = this->computer_->getMemory(); 
	//this->computer_->setRegisterA()
}

void LDA::setSYmbolST(std::string sym)
{
	this->symbol = sym; 
}

LDA::LDA(Computer* comp)
	:computer_(comp) 
{
}


LDA::~LDA()
{
}
