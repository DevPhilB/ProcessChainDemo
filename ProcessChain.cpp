#include "ProcessChain.h"

Duration ProcessChain::CalcChainDuration()
{
	Duration tmpDuration(0, 0, 0);
	for (int i = 0; i < MaxProcesses; i++)
	{
		if (i < this->processList.size() && pChain[i] != nullptr)
		{
			tmpDuration = tmpDuration + this->pChain[i]->TimeSpan();
		}
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
}

ProcessChain::ProcessChain(const ProcessChain& copy) : processList(copy.processList)
{
	this->processListIterator = copy.processListIterator;
	for (int i = 0; i < MaxProcesses; i++)
	{
		if (i < copy.processList.size() && copy.pChain[i] != nullptr)
		{
			this->pChain[i] = new Process(*copy.pChain[i]);
		}
	}
}

ProcessChain::~ProcessChain()
{
	for (int i = 0; i < MaxProcesses; i++)
	{
		if (i < this->processList.size())
		{
			delete this->pChain[i];
		}
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
			this->processList.push_back(process);
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
	int j = 0;
	int k = 0;
	for (i = 0; i < MaxProcesses; i++)
	{
		if (this->pChain[i] != nullptr)
		{
			delete this->pChain[i];
		}
	}
	this->processList.clear();
	while (j < 100)
	{
		if (this->pChain[j] != nullptr && this->pChain[j]->GetID() == id)
		{
			this->pChain[j] = &newProcess;
			while (k < 100)
			{
				if (this->pChain[k] != nullptr)
				{
					this->processList.push_back(*this->pChain[k]);
				}
				k++;
			}
		}
		j++;
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
	this->processList = rhs.processList;
	this->processListIterator = rhs.processListIterator;
	for (int i = 0; i < MaxProcesses; i++)
	{
		if (rhs.pChain[i] != nullptr)
		{
			this->pChain[i] = new Process(*rhs.pChain[i]);
		}
	}
	return *this;
}

bool CompareIDs(Process &first, Process &second)
{
	return (first.GetID() < second.GetID());
}

std::ostream& operator<<(std::ostream& os, const ProcessChain& arg)
{
	ProcessChain processChainCopy = arg;
	processChainCopy.processList.sort(CompareIDs);
	os << processChainCopy.name << " ";
	for (processChainCopy.processListIterator = processChainCopy.processList.begin(); processChainCopy.processListIterator != processChainCopy.processList.end(); ++processChainCopy.processListIterator)
	{
		os << "ID: " <<  *processChainCopy.processListIterator << " ";
	}
	os << std::endl;
	os << "Complete Duration: " << processChainCopy.CalcChainDuration();
	return os;
}
