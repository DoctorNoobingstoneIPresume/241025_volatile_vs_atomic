#include "PerformOperation.hpp"

#include <thread>
#include <atomic>
#include <vector>

#include <iostream>
#include <sstream>
#include <iomanip>

#include <typeinfo>

#include <stdint.h>

unsigned SetValue_V (volatile unsigned *p, unsigned x)
{
	const unsigned rv {*p};
	*p = x;
	return rv;
}

unsigned SetValue_A (std::atomic <unsigned> *p, unsigned x)
{
	const unsigned rv {*p};
	*p = x;
	return rv;
}

template <typename T>
bool Do_Main ()
{
	T x {0};
	
	const std::size_t nThreads             {0x80};
	const uint64_t    nOperationsPerThread {0x10000};
	
	std::vector <std::thread> vThreads;
	{
		vThreads.reserve (nThreads);
		
		const auto f
		{
			[=, &x] () -> void
			{
				for (uint64_t i {0}; i < nOperationsPerThread; ++i)
					PerformOperation (&x);
			}
		};
		
		for (std::size_t iThread {0}; iThread < nThreads; ++iThread)
			vThreads.push_back (std::thread (f));
	}
	
	// [2024-10-25] TODO: RAII...
	for (auto &thread: vThreads)
		thread.join ();
	
	bool bResult {x == nThreads * nOperationsPerThread};
	
	std::ostringstream os;
	{
		os
			<< "Pointer-to-T is " << std::left << std::setw (40) << typeid (&x).name () << ", "
			<< "x is " << std::hex << std::uppercase << std::right << std::setw (16) << x << "h" << ", "
			<< "verdict is " << (bResult ? "PASS" : "FAIL") << ".";
	}
	
	std::cout << os.str () << "\n";
	
	return bResult;
}

int main ()
{
	const bool b0 {Do_Main <uint32_t>               ()};
	const bool b1 {Do_Main <volatile uint32_t>      ()};
	const bool b2 {Do_Main <std::atomic <uint32_t>> ()};
	
	return b0 && b1 && b2 ? EXIT_SUCCESS : EXIT_FAILURE;
}
