#ifndef USE_CASES_H
#define USE_CASES_H

#include <repository.h>

void use_case_check_in(repository_base *repository);
void use_case_check_in_m(repository_base *repository);
void use_case_check_out(repository_base *repository);
void use_case_check_out_m(repository_base *repository);
void use_case_check_list(repository_base *repository);
check_t use_case_last_type(repository_base *repository);
void use_case_check_quit(repository_base *repository);

#endif /* USE_CASES_H */
