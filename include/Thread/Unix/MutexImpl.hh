#include <pthread.h>

#ifndef MUTEXIMPL_HH_
# define MUTEXIMPL_HH_

namespace LilWrapper
{
  class MutexImpl
  {
    private:
      pthread_mutex_t	_mutex;

    public:
      MutexImpl();
      ~MutexImpl();

      void lock();
      void unlock();
      bool trylock();
  };
}

#endif /* !MUTEXIMPL_HH_ */
