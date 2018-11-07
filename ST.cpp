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

#include "ST.h"
#include"INT.h"


void ST::Execute()
{
	this->computer_->setProgramCounter(this->computer_->getProgramCounter() + 1); 
	int temp = this->computer_->getSymbol(this->symbol); 
	delete this->computer_->getMemory(temp);
	//this->computer_->setSymbol(this->symbol, this->computer_->getRegisterA());
	SAL *value = new INT(this->computer_, this->computer_->getRegisterA());
	this->computer_->setMemory(temp, value);

	

}

void ST::Print()
{

}

int ST::getSymbolST(std::string symbol)
{
	return this->computer_->getSymbol(symbol);
	//return this->computer_->getSymbol(this->symbol);
}

void ST::setSYmbolST(std::string symb)
{
	this->symbol = symb; 
}

void ST::storeSymbolAt(int index, SAL*object)
{
	this->computer_->setMemory(index, object); 
}

ST::ST(Computer* comp)
	:computer_(comp)
{
	//std::cout << a << std::endl; 
}


ST::~ST()
{
}
