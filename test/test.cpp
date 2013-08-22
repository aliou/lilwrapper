#include "test.hh"

void init()
{
  assertions = 0;
  failures = 0;
}

void end()
{
  fprintf(stdout, "%d assertions, %d failures\n", assertions, failures);
  exit (failures != 0);
}

void assert(bool exp, char *message)
{
  assertions++;
  if (exp)
    fprintf(stderr, "✓ %s\n", message);
  else
  {
    fprintf(stderr, "✗ %s\n", message);
    failures++;
  }
}
