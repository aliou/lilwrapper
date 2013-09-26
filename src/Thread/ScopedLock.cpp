#include "Thread/ScopedLock.hh"

namespace LilWrapper
{
  ScopedLock::ScopedLock(Mutex *mutex)
    : _mutex(mutex)
  {
    if (this->_mutex)
      this->_mutex->lock();
  }

  ScopedLock::~ScopedLock()
  {
    if (this->_mutex)
      this->_mutex->unlock();
  }
}
