#include "Thread/Mutex.hh"

#ifndef SCOPEDLOCK_HH_
# define SCOPEDLOCK_HH_

namespace LilWrapper
{
  class ScopedLock
  {
    private:
      Mutex	*_mutex;

    public:
      ScopedLock(Mutex *);
      ~ScopedLock();
  };
}

#endif /* SCOPEDLOCK_HH_ */
