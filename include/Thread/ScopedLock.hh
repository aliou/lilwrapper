#include "Thread/IMutex.hh"

#ifndef SCOPEDLOCK_HH_
# define SCOPEDLOCK_HH_

namespace LilWrapper
{
  class ScopedLock
  {
    private:
      IMutex	*_mutex;

    public:
      ScopedLock(IMutex *);
      ~ScopedLock();
  };
}

#endif /* SCOPEDLOCK_HH_ */
