#include "Thread/CondVar.hh"
#include "Thread/ThreadException.hh"

namespace LilWrapper
{
  CondVar::CondVar()
  {
    if (pthread_cond_init(&this->_condvar, NULL) != 0)
      throw ThreadException("Thread Exception: "
          "Error while creating the conditional variable.");
  }

  CondVar::~CondVar()
  {
    pthread_cond_destroy(&this->_condvar);
  }
}
