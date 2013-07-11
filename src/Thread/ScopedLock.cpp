#include "Thread/ScopedLock.hh"

namespace LilWrapper
{
  ScopedLock::ScopedLock(IMutex *mutex)
    : _mutex(mutex)
  {
    this->_mutex->lock();
  }

  ScopedLock::~ScopedLock()
  {
    this->_mutex->unlock();
  }
}
