#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "Thread/Mutex.hh"
#include "Thread/Thread.hpp"

int increment_value;

struct mock
{
  int _data;
  LilWrapper::Mutex _access;
};

void increment(mock *m)
{
  m->_access.lock();
  for (int i = 0; i < increment_value; i++)
    m->_data++;
  m->_access.unlock();
}

int main()
{
  mock m;

  std::srand((unsigned int) std::time(0));

  int thread_count = std::rand() % 100 + 1;
  increment_value = std::rand() % 1000 + 1;
  std::vector<LilWrapper::Thread *> threads(thread_count);

  std::cout << "Increment value   ==> " << increment_value << std::endl;
  std::cout << "Number of Threads ==> " << thread_count << std::endl;

  m._data = 0;
  for (int i = 0; i < thread_count; i++)
    threads[i] = new LilWrapper::Thread(&increment, &m);

  for (int i = 0; i < thread_count; i++)
    threads[i]->launch();

  for (int i = 0; i < thread_count; i++)
    threads[i]->wait();

  assert(m._data == thread_count * increment_value);
  return (0);
}
