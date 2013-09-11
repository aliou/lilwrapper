#include "Thread/Thread.hpp"

#ifdef WIN32
# include "Thread/Win/ThreadImpl.hh"
#else
# include "Thread/Unix/ThreadImpl.hh"
#endif

namespace LilWrapper
{
  Thread::~Thread()
  {
    wait();
    delete this->_starter;
  }

  void Thread::launch()
  {
    wait();
    this->_impl = new ThreadImpl(this);
  }

  void Thread::wait()
  {
    if (this->_impl)
    {
      this->_impl->wait();
      delete this->_impl;
      this->_impl = NULL;
    }
  }

  void Thread::terminate()
  {
    if (this->_impl)
    {
      this->_impl->terminate();
      delete this->_impl;
      this->_impl = NULL;
    }
  }

  void Thread::run()
  {
    this->_starter->run();
  }
}
