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

#pragma once
#include "SAL.h"
#include"Computer.h"

class JZS :
	public SAL
{
private:
	Computer * computer_; 
	int number_; 
public:
	void Execute();
	void setNumber(int);
	JZS(Computer *);
	~JZS();
};

