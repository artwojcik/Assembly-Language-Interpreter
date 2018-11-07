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
#include<iostream>
#include"SAL.h"
#include<string>
#include<map>
class Computer
{
private:
	int registerA_; 
	int registerB_; 
	int zeroBit_; 
	int overflowBit_;
	int programCounter_; 
	SAL *memory_[256]; 
	std::map<std::string, int> dictionary; 
public:
	int getRegisterA()const; 
	int getRegisterB()const; 
	int getZeroBit()const; 
	int getOverflowBit()const; 
	int getProgramCounter()const; 
	SAL* getMemory(int);
	int getSymbol(std::string symbol); 
	std::map<std::string, int> *getMap();

	void setRegisterA(const int& num);
	void setRegisterB(const int& num);
	void setZeroBit(const int& num);
	void setOverflowBit(const int& num);
	void setProgramCounter(const int& num);
	void setMemory(const int& index, SAL *object); 
	void setSymbol(std::string symbol, int adress); 
	void perform(); 
	void saveToFile(); 

	

	Computer();
	~Computer();
	void Print(); 
};

