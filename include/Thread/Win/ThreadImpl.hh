#include <windows.h>
#include <process.h>
#include "Thread/Thread.hh"

#ifndef THREADIMPL_HH_
# define THREADIMPL_HH_

namespace LilWrapper
{
  class ThreadImpl
  {
    private:
      HANDLE _handle;
      unsigned int _id;

      static unsigned int __stdcall entryPoint(void* userData);
    public:
      ThreadImpl(Thread *);
      ~ThreadImpl();

      void wait();
      void terminate();
  };
}

#endif /* !THREADIMPL_HH_ */
