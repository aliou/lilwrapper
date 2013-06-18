#include "IMutex.hh"

#ifndef SCOPEDLOCK_HH_
# define SCOPEDLOCK_HH_

class ScopedLock
{
  private:
    ThreadWrapper::IMutex	*_mutex;

    ScopedLock(const ScopedLock &);
    ScopedLock &operator=(const ScopedLock &);
  public:
    ScopedLock(ThreadWrapper::IMutex *mutex);
}

#endif /* SCOPEDLOCK_HH_ */
