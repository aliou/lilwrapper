#include "Thread/Thread.hh"

#ifdef WIN32
# include "Thread/Win/ThreadImpl.hh"
#else
# include "Thread/Unix/ThreadImpl.hh"
#endif

namespace LilWrapper
{
  template <typename F>
  Thread::Thread(F function)
    : _impl(0), _starter(new ThreadFunctor<F>(function)) {}

  template<typename F>
  ThreadFunctor<F>::ThreadFunctor(F f)
    : functor(f) {}

  template <typename F, typename A>
  Thread::Thread(F function, A argument)
    : _impl(0),
    _starter(new ThreadFunctorWithArg<F,A>(function, argument)) {}

  template <typename F, typename A>
  ThreadFunctorWithArg<F, A>::ThreadFunctorWithArg(F f, A a)
    : functor(f), argument(a) {}

  template <typename C>
  Thread::Thread(void (C::*function)(), C *object)
    : _impl(0),
    _starter(new ThreadMemberFunction<C>(function, object)) {}

  template <typename C>
  ThreadMemberFunction<C>::ThreadMemberFunction(void (C::*f)(), C *o)
    : member_function(f), object(o) {}

  Thread::~Thread()
  {
    wait();
    delete this->_starter;
  }

  void Thread::launch()
  {
    wait();
    this->_impl = new ThreadImpl(this);
  }

  void Thread::wait()
  {
    if (this->_impl)
    {
      this->_impl->wait();
      delete this->_impl;
      this->_impl = NULL;
    }
  }

  void Thread::terminate()
  {
    if (this->_impl)
    {
      this->_impl->terminate();
      delete this->_impl;
      this->_impl = NULL;
    }
  }

  void Thread::run()
  {
    this->_starter->run();
  }

  template <typename F>
  void ThreadFunctor<F>::run()
  {
    (this->functor)();
  }

  template <typename F, typename A>
  void ThreadFunctorWithArg<F, A>::run()
  {
    (this->functor)(this->argument);
  }

  template <typename O>
  void ThreadMemberFunction<O>::run()
  {
    (object->*member_function)();
  }
}
