#include "TestSuite.h"
#include "AllProblemHeaders.h"
#include <cstdio>

namespace pt = project_euler::test;
namespace pp = project_euler::problems;

pt::TestSuite::TestSuite() {}

pt::TestSuite::~TestSuite() {}

void pt::TestSuite::run(int test_case) const {
}

void pt::TestSuite::run_all() const {
}

void pt::TestSuite::m_initialize_test_cases_dictionary() {
    m_test_cases_dictionary[1] = &TestSuite::m_test_case_for_problem_1;
    m_test_cases_dictionary[2] = &TestSuite::m_test_case_for_problem_2;    
}

void pt::TestSuite::m_execute(ptrFunc function) {
    
}

void pt::TestSuite::m_test_case_for_problem_1() {
    m_start_timer();
    
    pp::Problem_1 problem;
    const int N = 999;
    printf("Sum == [%d]\n", (problem.sum(3, N) + problem.sum(5, N)) - problem.sum(15, N));

    m_end_timer();
}

void pt::TestSuite::m_test_case_for_problem_2() {
    m_start_timer();
    
    pp::Problem_2 problem;
    printf("Sum of even fibbonacci numbers == [%d]\n", problem.sum());

    m_end_timer();
}

void pt::TestSuite::m_start_timer() {
    m_start_time = clock();
}

void pt::TestSuite::m_end_timer() const {
    printf("----------------------------------------------------------------------------------------\n");
    printf("Execution time == [%.8f] seconds\n", (clock() - m_start_time) / static_cast<double>(CLOCKS_PER_SEC));
    printf("----------------------------------------------------------------------------------------\n");    
}
