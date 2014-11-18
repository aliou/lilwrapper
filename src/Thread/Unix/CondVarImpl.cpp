#include "Thread/Unix/CondVarImpl.hh"
#include "Thread/ThreadException.hh"

namespace LilWrapper
{
  CondVarImpl::CondVarImpl()
  {
    if (pthread_cond_init(&this->_condvar, NULL) != 0)
      throw ThreadException("CondVar Exception: "
          "Error while creating the Conditional Variable.");
  }

  CondVarImpl::~CondVarImpl()
  {
    pthread_cond_destroy(&this->_condvar);
  }

  void CondVarImpl::notify_one()
  {
    if (pthread_cond_signal(&this->_condvar) != 0)
      throw ThreadException("CondVar Exception: "
          "Error while notifying a waiting thread.");
  }

  void CondVarImpl::notify_all()
  {
    if (pthread_cond_broadcast(&this->_condvar) != 0)
      throw ThreadException("CondVar Exception: "
          "Error while notifying the waiting threads.");
  }

  void CondVarImpl::wait(pthread_mutex_t *mutex)
  {
  }
};
