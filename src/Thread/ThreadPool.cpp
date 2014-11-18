#include "Thread/ThreadPool.hpp"

namespace LilWrapper
{
  ThreadPool::ThreadPool(int nb)
  {
    for (int i = 0; i < nb; i++)
      this->_workers.push_back(
          std::make_pair(new Thread(), ThreadStatusUnused));
  }

  ThreadPool::~ThreadPool()
  {
    std::for_each(this->_workers.begin(), this->_workers.end(),
        ThreadPool::removeTask);
    this->_workers.clear();
  }

  void ThreadPool::removeTask(std::pair<IThread *, Status> pair)
  {
    delete pair.first;
  }
}
