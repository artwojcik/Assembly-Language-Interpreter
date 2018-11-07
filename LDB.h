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
#include "Computer.h"
#include<string>


class LDB :
	public SAL
{
private:
	Computer * computer_; 
	std::string symbol; 
public:
	void Execute();
	void setSYmbolST(std::string);
	LDB(Computer*);
	~LDB();
};

