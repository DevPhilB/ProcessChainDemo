#include "Duration.h"
#include "Process.h"
#include "ProcessChain.h"

/// <summary>
/// Use case for process chain.
/// </summary>
int main()
{
	Duration testDuration(10, 20, 10);
	std::cout << "Test duration: " << testDuration << std::endl;
	Process testProcess1(3, "Vektorisieren");
	testProcess1.TimeSpan(testDuration);
	std::cout << "Test process 1: " << testProcess1 << std::endl;
	Process testProcess2(16, "Ableiten");
	Duration testDuration2 = testDuration + testDuration;
	testProcess2.TimeSpan(testDuration2);
	std::cout << "Test process 2: " << testProcess2 << std::endl;
	Process testProcess3(1, "Normalisieren");
	Duration testDuration3 = testDuration.Add(testDuration2, testDuration);
	testProcess3.TimeSpan(testDuration3);
	std::cout << "Test process 3: " << testProcess3 << std::endl;
	ProcessChain testProcessChain("Test process chain");
	testProcessChain.Insert(testProcess1);
	testProcessChain.Insert(testProcess2);
	std::cout << std::endl;
	// Try adding process again to process chain
	std::cout << "Try adding process with ID " << testProcess1.GetID() << " again..." << std::endl;
	if (!testProcessChain.Insert(testProcess1))
	{
		std::cout << "Process with ID " << testProcess1.GetID() << " already exists!" << std::endl;
	}
	testProcessChain.Insert(testProcess3);
	std::cout << std::endl;
	std::cout << testProcessChain << std::endl;
	std::cout << std::endl;

	// Deep copy
	ProcessChain deepCopyProcessChain = testProcessChain;
	std::cout << "Deep Copy" << std::endl;
	std::cout << deepCopyProcessChain << std::endl;
	std::cout << std::endl;

	Process testProcess4(20, "Umleiten");
	Duration testDuration4(127, 0, 1);
	testProcess4.TimeSpan(testDuration4);
	std::cout << "Test process 4: " << testProcess4 << std::endl;
	// Replace process in process chain
	std::cout << "Replace process with ID 16 with 20 in process chain" << std::endl;
	testProcessChain.ChangeProcess(16, testProcess4);
	std::cout << std::endl;
	std::cout << testProcessChain << std::endl;
	std::cout << std::endl;

	// Deep copy
	std::cout << "Deep Copy again" << std::endl;
	std::cout << deepCopyProcessChain << std::endl;
	std::cin.get();
	return 0;
}