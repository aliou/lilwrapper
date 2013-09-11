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
    pthread_mutex_destroy(&this->_mutex);
  }

  void MutexImpl::lock()
  {
    pthread_mutex_lock(&this->_mutex);
  }

  void MutexImpl::unlock()
  {
    pthread_mutex_unlock(&this->_mutex);
  }

  bool MutexImpl::trylock()
  {
    return (pthread_mutex_trylock(&this->_mutex) == 0);
  }
}
