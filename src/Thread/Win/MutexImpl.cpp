#include "Thread/Win/MutexImpl.hh"
#include "Thread/ThreadException.hh"

namespace LilWrapper
{
  MutexImpl::MutexImpl()
  {
    InitializeCriticalSection(&this->_mutex);
  }

  MutexImpl::~MutexImpl()
  {
    DeleteCriticalSection(&this->_mutex);
  }

  void MutexImpl::lock()
  {
    EnterCriticalSection(&this->_mutex);
  }

  void MutexImpl::unlock()
  {
    LeaveCriticalSection(&this->_mutex);
  }

  bool MutexImpl::trylock()
  {

  }
}
