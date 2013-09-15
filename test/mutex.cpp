#include <iostream>
#include <assert.h>
#include "mockclass.hh"
#include "Thread/Mutex.hh"
#include "Thread/Thread.hpp"

int without_mutex()
{
  Mock m;
  LilWrapper::IThread *t1 = new LilWrapper::Thread(&Mock::increment_without_mutex, &m);
  LilWrapper::IThread *t2 = new LilWrapper::Thread(&Mock::increment_without_mutex, &m);

  t1->launch();
  t2->launch();

  delete t1;
  delete t2;
  return (m.getData());
}

int with_mutex()
{
  Mock m;
  LilWrapper::IThread *t1 = new LilWrapper::Thread(&Mock::increment_with_mutex, &m);
  LilWrapper::IThread *t2 = new LilWrapper::Thread(&Mock::increment_with_mutex, &m);

  t1->launch();
  t2->launch();

  delete t1;
  delete t2;
  return (m.getData());
}

int main()
{
  return (0);
}
