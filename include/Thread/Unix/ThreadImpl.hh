#include <pthread.h>
#include "Thread/Thread.hh"

#ifndef THREADIMPL_HH_
# define THREADIMPL_HH_

namespace LilWrapper
{
  class ThreadImpl
  {
    private:
      pthread_t _thread;
      bool _isActive;

      static void *entryPoint(void *);
    public:
      ThreadImpl(Thread *);
      ~ThreadImpl();

      void wait();
      void terminate();
  };
};

#endif /* !THREADIMPL_HH_ */
