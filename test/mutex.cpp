#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "Thread/Mutex.hh"
#include "Thread/Thread.hpp"

int increment_value;

struct mock
{
  int _data;
  LilWrapper::Mutex _access;
};

void increment(struct mock *m)
{
  m->_access.lock();
  for (int i = 0; i < increment_value; i++)
    m->_data++;
  m->_access.unlock();
}

int main()
{
  mock m;

  srand(time(NULL));

  int nb = random() % 30 + 1;
  increment_value = random() % 15 + 1;
  std::vector<LilWrapper::Thread *> threads(nb);

  m._data = 0;
  for (int i = 0; i < nb; i++)
    threads[i] = new LilWrapper::Thread(&increment, &m);

  for (int i = 0; i < nb; i++)
    threads[i]->launch();

  for (int i = 0; i < nb; i++)
    threads[i]->wait();

  assert(m._data == nb * increment_value);
  return (0);
}
