#include <stdio.h>
#include <stdlib.h>

#ifndef TEST_HH_
# define TEST_HH_

void init();
void end();
void assert(bool, char *);

int assertions;
int failures;

#endif /* !TEST_HH_ */
