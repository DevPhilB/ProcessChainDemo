#pragma once

#include <iostream>

/// <summary>
/// Duration class
/// </summary>
class Duration
{
	unsigned int h = 0;
	unsigned int m = 0;
	unsigned int s = 0;
	bool isDirty = false;
public:
	Duration();
	Duration(const Duration& copy);
	Duration(unsigned int h, unsigned int m, unsigned int s);
	virtual ~Duration() {};
	void SetDirty();
	Duration operator+ (const Duration & rhs);
	friend std::ostream& operator<< (std::ostream& os, const Duration& arg);
	Duration& operator= (const Duration& rhs);
	static Duration Add(const Duration & arg1, const Duration & arg2);
};