#pragma once

#include <string>
#include <iostream>

#include "Duration.h"

/// <summary>
/// Process class
/// </summary>
class Process
{
	int id;
	std::string name;
	Duration* pDuration = nullptr;
public:
	Process(int id, std::string name);
	Process(const Process& copy);
	int GetID();
	virtual ~Process();
	friend std::ostream& operator<<(std::ostream& os, const Process& arg);
	Process& operator= (const Process& rhs);
	const Duration& TimeSpan();
	void TimeSpan(Duration& arg);
};