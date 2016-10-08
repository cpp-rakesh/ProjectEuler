#include "common/Integer.h"
#include <ctime>
#include <cstdio>

int main() {
    int N = 1000;
    std::clock_t start = clock();
    PROJECT_EULER::COMMON::Integer A(2);
    for (int i = 0; i < N - 1; ++i)
	A *= 2;

    int sum = 0;
    std::string number = A.GetReverse();
    for (std::size_t i = 0; i < number.size(); ++i)
	sum += number[i] - '0';

    printf("sum == [%d]\n", sum);
    printf("Execution time == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));
}