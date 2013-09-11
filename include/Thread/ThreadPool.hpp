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
      std::list<std::pair<IThread *, Status> >	_workers;

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

  template <typename F>
    void ThreadPool::schedule(F function)
    {
      ThreadStarter *starter = new ThreadFunctor<F>(function);
      this->_tasks.push(starter);
    }

  template <typename F, typename A>
    void ThreadPool::schedule(F func, A arg)
    {
      ThreadStarter *starter = new ThreadFunctorWithArg<F, A>(func, arg);
      this->_tasks.push(starter);
    }

  template <typename O>
    void ThreadPool::schedule(void (O::*func)(), O *object)
    {
      ThreadStarter *starter = new ThreadMemberFunction<O>(func, object);
      this->_tasks.push(starter);
    }
}

#endif /* !THREADPOOL_HH_ */
