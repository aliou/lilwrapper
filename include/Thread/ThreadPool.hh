#include <algorithm>
#include <list>
#include <utility>
#include <queue>
#include "Thread/Thread.hpp"

#ifndef THREADPOOL_HH_
# define THREADPOOL_HH_

namespace LilWrapper
{
  typedef enum
  {
    ThreadStatusError = -1,
    ThreadStatusUnused,
    ThreadStatusUsed,
  } Status;

  class ThreadPool
  {
    private:
      std::queue<ThreadStarter *>		_tasks;
      std::list<std::pair<IThread *, Status> >	_thread;

      static void removeTask(std::pair<IThread *, Status>);
    public:
      ThreadPool(int);
      ~ThreadPool();

      template <typename F>
        void schedule(F);

      template <typename F, typename A>
        void schedule(F, A);

      template <typename O>
        void schedule(void (O::*)(), O *obj);
  };
}

#endif /* !THREADPOOL_HH_ */
