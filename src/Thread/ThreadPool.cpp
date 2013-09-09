#include "Thread/ThreadPool.hh"

namespace LilWrapper
{
  ThreadPool::ThreadPool(int nb)
  {
    for (int i = 0; i < nb; i++)
      this->_thread.push_back(
          std::make_pair(new Thread(), ThreadStatusUnused));
  }

  ThreadPool::~ThreadPool()
  {
    std::for_each(this->_thread.begin(), this->_thread.end(),
        ThreadPool::removeTask);
    this->_thread.clear();
  }

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

  void ThreadPool::removeTask(std::pair<IThread *, Status> pair)
  {
    delete pair.first;
  }
}
