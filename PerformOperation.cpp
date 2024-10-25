#include "PerformOperation.hpp"

template <typename T>
void PerformOperation (T *px)
{
	++*px;
}

template void PerformOperation <uint32_t>               (uint32_t               *px);
template void PerformOperation <volatile uint32_t>      (volatile uint32_t      *px);
template void PerformOperation <std::atomic <uint32_t>> (std::atomic <uint32_t> *px);

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
