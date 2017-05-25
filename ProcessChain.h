#pragma once

#include <string>
#include <iostream>
#include <algorithm>

#include "Process.h"

/// <summary>
/// Process chain class
/// </summary>
class ProcessChain
{
	/// <summary>
	/// Maximum amount of processes for the chain
	/// </summary>
	static const int MaxProcesses = 100;

	/// <summary>
	/// Process chain name
	/// </summary>
	std::string name;

	/// <summary>
	/// Array of processes as pointer (Max 100 elements)
	/// </summary>
	Process *pChain[MaxProcesses];

	/// <summary>
	/// Counter for array to increase performance and error-avoidance
	/// </summary>
	int pChainCounter;

	/// <summary>
	/// Method to calculate complete process chain duration
	/// </summary>
	/// <returns>Complete duration</returns>
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
	/// Method to change process
	/// </summary>
	/// <param name="id">Old Process ID</param>
	/// <param name="newProcess">New process reference</param>
	void ChangeProcess(int id, Process& newProcess);

	/// <summary>
	/// Overloaded assignment operator
	/// </summary>
	/// <param name="rhs">Process chain to assign</param>
	ProcessChain& operator= (const ProcessChain& rhs);

	/// <summary>
	/// Overloaded leftshift operator for ostream
	/// </summary>
	/// <param name="os">Current ostream</param>
	/// <param name="arg">Process chain reference</param>
	friend std::ostream& operator<<(std::ostream& os, const ProcessChain& arg);
};