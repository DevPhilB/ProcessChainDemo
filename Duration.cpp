#include "Duration.h"

Duration::Duration()
{
	this->h = 0;
	this->m = 0;
	this->s = 0;
}

Duration::Duration(const Duration& copy)
{
	Duration durationCopy(copy.h, copy.m, copy.s);
	while (durationCopy.s >= 60)
	{
		durationCopy.s -= 60;
		this->m++;
	}
	this->s = durationCopy.s;
	while (durationCopy.m >= 60)
	{
		durationCopy.m -= 60;
		this->h++;
	}
	this->m += durationCopy.m;
	this->h += durationCopy.h;
	this->isDirty = durationCopy.isDirty;
}

Duration::Duration(unsigned int h, unsigned int m, unsigned int s)
{
	while (s >= 60)
	{
		s -= 60;
		this->m++;
	}
	this->s = s;
	while (m >= 60)
	{
		m -= 60;
		this->h++;
	}
	this->m += m;
	this->h += h;
}

void Duration::SetDirty()
{
	this->isDirty = true;
}

Duration Duration::operator+(const Duration& rhs)
{
	Duration tmpDuration;
	tmpDuration.h = this->h + rhs.h;
	tmpDuration.m = this->m + rhs.m;
	tmpDuration.s = this->s + rhs.s;
	return Duration(tmpDuration.h, tmpDuration.m, tmpDuration.s);
}

Duration& Duration::operator=(const Duration& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	this->h = rhs.h;
	this->m = rhs.m;
	this->s = rhs.s;
	this->isDirty = rhs.isDirty;
	return *this;
}

Duration Duration::Add(const Duration& arg1, const Duration& arg2)
{
	Duration tmpDuration;
	tmpDuration.h = arg1.h + arg2.h;
	tmpDuration.m = arg1.m + arg2.m;
	tmpDuration.s = arg1.s + arg2.s;
	while (tmpDuration.s >= 60)
	{
		tmpDuration.s -= 60;
		tmpDuration.m++;
	}
	while (tmpDuration.m >= 60)
	{
		tmpDuration.m -= 60;
		tmpDuration.h++;
	}
	return tmpDuration;
}

std::ostream& operator<<(std::ostream& os, const Duration& arg)
{
	os << "[" << arg.h << "|" << arg.m << "|" << arg.s << "]";
	return os;
}
