#include <pthread.h>

#ifndef CONDVARIMPL_HH_
# define CONDVARIMPL_HH_

namespace LilWrapper
{
  class CondVarImpl
  {
    private:
      pthread_cond_t  _condvar;

    public:
      CondVarImpl();
      ~CondVarImpl();

      void notify_one();
      void notify_all();

      void wait(pthread_mutex_t *);
  };
}
#endif /* !CONDVARIMPL_HH_ */
