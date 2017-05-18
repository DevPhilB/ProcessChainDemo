#include "Process.h"

Process::Process(int id, const std::string name) : name(name)
{
	this->id = id;
	this->name = name;
	this->pDuration = nullptr;
}

Process::Process(const Process& copy) : name(copy.name)
{
	this->pDuration = nullptr;
	delete this->pDuration;
	this->id = copy.id;
	this->pDuration = new Duration(*copy.pDuration);
}

int Process::GetID()
{
	return this->id;
}

Process::~Process()
{
	this->pDuration = nullptr;
	delete this->pDuration;
}

Process & Process::operator=(const Process& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	this->pDuration = nullptr;
	delete this->pDuration;
	this->id = rhs.id;
	this->name = rhs.name;
	this->pDuration = new Duration(*rhs.pDuration);
	return *this;
}

const Duration& Process::TimeSpan()
{
	return *this->pDuration;
}

void Process::TimeSpan(Duration& arg)
{
	this->pDuration = &arg;
}

std::ostream& operator<<(std::ostream& os, const Process& arg)
{
	os << arg.id << " " << arg.name << " " << *arg.pDuration;
	return os;
}
