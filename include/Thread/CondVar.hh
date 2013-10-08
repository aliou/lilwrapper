#include <list>
#include "Thread/Mutex.hh"
#include "Thread/Thread.hpp"

#ifndef CONDVAR_HH_
# define CONDVAR_HH_

namespace LilWrapper
{
  class CondVarImpl;

  class CondVar
  {
    private:
      CondVarImpl *_impl;

    public:
      CondVar();
      ~CondVar();

      void notify_one();
      void notify_all();

      void wait(Mutex &);
      template <class P>
        void wait(Mutex *, P);
  };
}

#endif /* !CONDVAR_HH_ */
