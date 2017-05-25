#include "ProcessChain.h"

Duration ProcessChain::CalcChainDuration()
{
	Duration tmpDuration(0, 0, 0);
	for (int i = 0; i < this->pChainCounter; i++)
	{
		tmpDuration = tmpDuration + this->pChain[i]->TimeSpan();
	}
	Duration returnDuration = tmpDuration;
	return returnDuration;
}

ProcessChain::ProcessChain(const std::string name) : name(name)
{
	for (int i = 0; i < MaxProcesses; i++)
	{
		this->pChain[i] = nullptr;
	}
	this->pChainCounter = 0;
}

ProcessChain::ProcessChain(const ProcessChain& copy) : name(copy.name)
{
	this->pChainCounter = copy.pChainCounter;
	for (int i = 0; i < copy.MaxProcesses; i++)
	{
		if (copy.pChain[i] == nullptr)
		{
			this->pChain[i] = nullptr;
		}
		else
		{
			this->pChain[i] = new Process(*copy.pChain[i]);
		}
	}
}

ProcessChain::~ProcessChain()
{
	for (int i = 0; i < this->MaxProcesses; i++)
	{
		delete this->pChain[i];
	}
}

bool ProcessChain::Insert(Process& arg)
{
	int i = 0;
	Process *pProcess = new Process(arg);
	Process process(arg);
	while (i < 100)
	{
		if (this->pChain[i] == nullptr)
		{
			this->pChain[i] = pProcess;
			pChainCounter++;
			return true;
		}
		else if (this->pChain[i]->GetID() == arg.GetID())
		{
			return false;
		}
		i++;
	}
	return false;
}

void ProcessChain::ChangeProcess(int id, Process& newProcess)
{
	int i = 0;
	for (i = 0; i < MaxProcesses; i++)
	{
		if (this->pChain[i] != nullptr)
		{
			if (this->pChain[i]->GetID() == id)
			{
				delete this->pChain[i];
				this->pChain[i] = &newProcess;
				break;
			}
		}
	}
}

ProcessChain& ProcessChain::operator=(const ProcessChain & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	for (int i = 0; i < MaxProcesses; i++)
	{
		delete pChain[i];
	}
	this->name = rhs.name;
	for (int i = 0; i < pChainCounter; i++)
	{
		this->pChain[i] = new Process(*rhs.pChain[i]);
	}
	return *this;
}

/// <summary>
/// Method to compare two processes
/// </summary>
/// <param name="first">First process</param>
/// <param name="second">Second process</param>
/// <returns>True=First has higher ID | False=Second has higher ID</returns>
bool CompareID(Process *first, Process *second)
{
	return (first->GetID() < second->GetID());
}

std::ostream& operator<<(std::ostream& os, const ProcessChain& arg)
{
	ProcessChain processChainCopy = arg;
	os << processChainCopy.name << ":" << std::endl;
	std::sort(processChainCopy.pChain, processChainCopy.pChain+arg.pChainCounter, CompareID);
	for (int i = 0; i < processChainCopy.pChainCounter; i++)
	{
		os << "ID: " << *processChainCopy.pChain[i] << " ";
	}
	os << std::endl;
	os << "Complete Duration: " << processChainCopy.CalcChainDuration();
	return os;
}
