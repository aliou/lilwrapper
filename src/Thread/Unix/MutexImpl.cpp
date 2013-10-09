#include "Thread/Unix/MutexImpl.hh"
#include "Thread/ThreadException.hh"

namespace LilWrapper
{
  MutexImpl::MutexImpl()
  {
    if (pthread_mutex_init(&this->_mutex, NULL) != 0)
      throw ThreadException("Mutex Exception: "
          "Error while creating the Mutex.");
  }

  MutexImpl::~MutexImpl()
  {
    if (pthread_mutex_destroy(&this->_mutex) != 0)
      throw ThreadException("Mutex Exception: "
          "Error while destroying the Mutex.");
  }

  void MutexImpl::lock()
  {
    if (pthread_mutex_lock(&this->_mutex) != 0)
      throw ThreadException("Mutex Exception: "
          "Error while locking the Mutex.");
  }

  void MutexImpl::unlock()
  {
    if (pthread_mutex_unlock(&this->_mutex) != 0)
      throw ThreadException("Mutex Exception: "
          "Error while unlocking the Mutex.");
  }

  bool MutexImpl::trylock()
  {
    return (pthread_mutex_trylock(&this->_mutex) == 0);
  }
}
