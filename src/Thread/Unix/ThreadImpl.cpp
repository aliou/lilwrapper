#include "Thread/Unix/ThreadImpl.hh"
#include "Thread/ThreadException.hh"

namespace LilWrapper
{
  ThreadImpl::ThreadImpl(Thread *thread)
  {
    this->_isActive = pthread_create(&this->_thread, NULL,
        &ThreadImpl::entryPoint, thread) == 0;
    if (!this->_isActive)
      throw ThreadException("Thread Exception: "
          "Error while creating the Thread.");
  }

  ThreadImpl::~ThreadImpl()
  {
    if (this->_isActive)
      terminate();
  }

  void ThreadImpl::wait()
  {
    if (this->_isActive)
    {
      if (pthread_equal(pthread_self(), this->_thread) != 0)
        throw ThreadException("Thread Exception: "
            "A thread cannot wait for itself.");
      if (pthread_join(this->_thread, NULL) != 0)
        throw ThreadException("Thread Exception: "
            "Error while waiting for the thread to finish.");
    }
    this->_isActive = false;
  }

  void ThreadImpl::terminate()
  {
    if (this->_isActive)
      if (pthread_cancel(this->_thread) != 0)
        throw ThreadException("Thread Exception: "
            "Error while canceling the thread.");
    this->_isActive = false;
  }

  void *ThreadImpl::entryPoint(void *data)
  {
    Thread *self = static_cast<Thread *>(data);

    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    self->run();
    return (NULL);
  }
}
