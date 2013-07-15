#include <windows.h>

#ifndef MUTEXIMPL_HH_
# define MUTEXIMPL_HH_

namespace LilWrapper
{
  class MutexImpl
  {
    private:
      CRITICAL_SECTION _mutex;

    public:
      MutexImpl();
      ~MutexImpl();

      void lock();
      void unlock();
      bool trylock();
  };
}

#endif /* !MUTEXIMPL_HH_ */

