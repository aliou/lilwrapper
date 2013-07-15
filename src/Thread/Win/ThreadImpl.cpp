#include "Thread/Win/ThreadImpl.hh"
#include "Thread/ThreadException.hh"

namespace LilWrapper
{
  ThreadImpl::ThreadImpl(Thread *owner)
  {
    this->_handle = reinterpret_cast<HANDLE>(_beginthreadex(NULL, 0,
	  &ThreadImpl::entryPoint, owner, 0, &this->_id));
    if (this->_handle == (HANDLE) -1L || this->_handle == (HANDLE) -1)
      throw ThreadException("Thread Exception: "
	  "Error while creating the Thread.");
  }

  ThreadImpl::~ThreadImpl()
  {
    if (this->_handle)
      terminate();
  }

  void ThreadImpl::wait()
  {
    if (this->_handle)
    {
      if (this->_id == GetCurrentThreadId())
	throw ThreadException("Thread Exception: "
	    "A thread cannot wait for itself.");
      WaitForSingleObject(this->_handle, INFINITE);
    }
  }

  void ThreadImpl::terminate()
  {
    if (this->_handle)
      TerminateThread(this->_handle, 0);
  }

  unsigned int __stdcall ThreadImpl::entryPoint(void* data)
  {
    Thread* self = static_cast<Thread*>(data);

    self->run();
    _endthreadex(0);
    return (0);
  }

}
