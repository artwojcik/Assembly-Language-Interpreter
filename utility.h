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
#include<string>
#include<sstream>
#include"SAL.h"
#include"JZS.h"
#include"Computer.h"
#include"ST.h"
#include"LDI.h"
#include"XCH.h"
#include<map>
#include"DEC.h"
#include"ADD.h"
#include"HLT.h"
#include"JVS.h"
#include"JMP.h"
#include"LDA.h"
#include"LDB.h"
#include<fstream>
#include <cmath>
#include"State.h"
#include <typeinfo>



void saveToFile(Computer *comp); 
void printInstruction();
void processCommand(Computer * comp, std::string name, std::string number, int index); 

void readFile(Computer *comp);
void warning(); 

void executeProgram(Computer * comp); 
void info();