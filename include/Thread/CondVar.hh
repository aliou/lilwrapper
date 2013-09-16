#include <pthread.h>
#include "Thread/Mutex.hh"

#ifndef CONDVAR_HH_
# define CONDVAR_HH_

namespace LilWrapper
{
  class CondVar
  {
    private:
      pthread_cond_t  _condvar;

    public:
      CondVar();
      ~CondVar();
  };
}

#endif /* !CONDVAR_HH_ */
