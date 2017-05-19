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
	/// <summary>
	/// Default constructor
	/// </summary>
	Duration();

	/// <summary>
	/// Copy constructor
	/// </summary>
	Duration(const Duration& copy);

	/// <summary>
	/// Constructor with time
	/// </summary>
	/// <param name="h">Hours</param>
	/// <param name="m">Minutes</param>
	/// <param name="s">Seconds</param>
	Duration(unsigned int h, unsigned int m, unsigned int s);

	/// <summary>
	/// Deconstructor
	/// </summary>
	virtual ~Duration() {};

	/// <summary>
	/// Method to set dirty flag
	/// </summary>
	void SetDirty();

	/// <summary>
	/// Overloaded plus operator
	/// </summary>
	/// <param name="rhs">Duration reference</param>
	Duration operator+ (const Duration& rhs);

	/// <summary>
	/// Friendly overloaded leftshift operator for ostream
	/// </summary>
	/// <param name="os">Current ostream</param>
	/// <param name="arg">Duration reference</param>
	friend std::ostream& operator<< (std::ostream& os, const Duration& arg);

	/// <summary>
	/// Overloaded assignment operator
	/// </summary>
	/// <param name="rhs">Duration to assign</param>
	Duration& operator= (const Duration& rhs);

	/// <summary>
	/// Method to add two durations
	/// </summary>
	/// <param name="arg1">Duration 1</param>
	/// <param name="arg2">Duration 2</param>
	static Duration Add(const Duration & arg1, const Duration & arg2);
};