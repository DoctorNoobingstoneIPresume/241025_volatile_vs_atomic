#include "PerformOperation.hpp"

template <typename T>
void PerformOperation (T *px)
{
	++*px;
}

template void PerformOperation <uint64_t>               (uint64_t               *px);
template void PerformOperation <volatile uint64_t>      (volatile uint64_t      *px);
template void PerformOperation <std::atomic <uint64_t>> (std::atomic <uint64_t> *px);

//void PerformOperation (uint64_t *px)
//{
//	++*px;
//}
//
//void PerformOperation (volatile uint64_t *px)
//{
//	++*px;
//}
//
//void PerformOperation (std::atomic <uint64_t> *px)
//{
//	++*px;
//}
