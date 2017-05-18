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
	/// <summary>
	/// Explicit constructor
	/// </summary>
	explicit ProcessChain(std::string name);
	/// <summary>
	/// Copy constructor
	/// </summary>
	ProcessChain(const ProcessChain& copy);
	/// <summary>
	/// Virtual destructor
	/// </summary>
	virtual ~ProcessChain();
	/// <summary>
	/// Method to insert process into the chain
	/// </summary>
	/// <param name="arg">New process</param>
	/// <returns>True=success|False=failure</returns>
	bool Insert(Process& arg);
	/// <summary>
	/// Method to change specific process
	/// </summary>
	/// <param name="id">Old process ID</param>
	/// <param name="newProcess">New process</param>
	void ChangeProcess(int id, Process& newProcess);
	/// <summary>
	/// Overloaded assignment operator
	/// </summary>
	/// <param name="rhs">Process to assign</param>
	ProcessChain& operator= (const ProcessChain& rhs);
	/// <summary>
	/// Overloaded leftshift operator for ostream
	/// </summary>
	/// <param name="os">Current ostream</param>
	/// <param name="arg">Process chain reference</param>
	friend std::ostream& operator<<(std::ostream& os, const ProcessChain& arg);
};