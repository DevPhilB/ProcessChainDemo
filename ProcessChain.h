#pragma once

#include <string>
#include <iostream>
#include <list>

#include "Process.h"

/// <summary>
/// Process chain class
/// </summary>
class ProcessChain
{
	static const int MaxProcesses = 100;
	std::string name;
	Process *pChain[MaxProcesses];
	std::list<Process> processList;
	std::list<Process>::iterator processListIterator;
	Duration CalcChainDuration();
public:
	ProcessChain(std::string name);
	ProcessChain(const ProcessChain& copy);
	virtual ~ProcessChain();
	bool Insert(Process& arg);
	void ChangeProcess(int id, Process& newProcess);
	ProcessChain& operator= (const ProcessChain& rhs);
	friend std::ostream& operator<<(std::ostream& os, const ProcessChain& arg);
};