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
//		� 2018 Artur Wojcik *** ALL RIGHTS RESERVED ***
//

#include "INT.h"



INT::INT(Computer* computer, int num)
	:computer_(computer), number_(num)
{
}

int INT::getNumberFromINT()
{
	return this->number_;
}


INT::~INT()
{
}
