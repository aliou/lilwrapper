#include "Thread/ThreadPool.hpp"

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

  void ThreadPool::removeTask(std::pair<IThread *, Status> pair)
  {
    delete pair.first;
  }
}
