#include "Thread/Mutex.hh"

#ifdef WIN32
# include "Thread/Win/MutexImpl.hh"
#else
# include "Thread/Unix/MutexImpl.hh"
#endif

namespace LilWrapper
{
  Mutex::Mutex()
    : _impl(new MutexImpl) {}

  Mutex::~Mutex()
  {
    delete this->_impl;
  }

  void Mutex::lock()
  {
    this->_impl->lock();
  }

  void Mutex::unlock()
  {
    this->_impl->unlock();
  }

  bool Mutex::trylock()
  {
    return (this->_impl->trylock());
  }
}
