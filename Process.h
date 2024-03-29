#pragma once

#include <string>
#include <iostream>

#include "Duration.h"

/// <summary>
/// Process class
/// </summary>
class Process
{
	/// <summary>
	/// Process ID
	/// </summary>
	int id;

	/// <summary>
	/// Process name
	/// </summary>
	std::string name;

	/// <summary>
	/// Process duration as pointer
	/// </summary>
	Duration* pDuration = nullptr;

public:
	/// <summary>
	/// Constructor with ID and name
	/// </summary>
	/// <param name="id">ID</param>
	/// <param name="name">Process name</param>
	Process(int id, std::string name);

	/// <summary>
	/// Copy constructor
	/// </summary>
	Process(const Process& copy);

	/// <summary>
	/// Method to get process ID
	/// </summary>
	/// <returns>Process ID</returns>
	int GetID();

	/// <summary>
	/// Virtual destructor
	/// </summary>
	virtual ~Process();

	/// <summary>
	/// Overloaded leftshift operator for ostream
	/// </summary>
	/// <param name="os">Current ostream</param>
	/// <param name="arg">Process reference</param>
	friend std::ostream& operator<<(std::ostream& os, const Process& arg);

	/// <summary>
	/// Overloaded assignment operator
	/// </summary>
	/// <param name="rhs">Process to assign</param>
	Process& operator= (const Process& rhs);

	/// <summary>
	/// Get process duration reference
	/// </summary>
	const Duration& TimeSpan();

	/// <summary>
	/// Method to set process duration
	/// </summary>
	/// <param name="arg">Duration reference</param>
	void TimeSpan(Duration& arg);
};