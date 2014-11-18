#ifndef THREAD_HH_
# define THREAD_HH_

namespace LilWrapper
{
  class ThreadImpl;

  class ThreadStarter
  {
    public:
      virtual ~ThreadStarter() {}
      virtual void run() = 0;
  };

  class Thread
  {
    friend class ThreadImpl;
    private:
      ThreadImpl	*_impl;
      ThreadStarter	*_starter;

      void run();
    public:
      Thread() : _impl(0), _starter(0) {}

      template <typename F>
        Thread(F);

      template <typename F, typename A>
        Thread(F, A);

      template <typename C>
        Thread(void (C::*)(), C *);

      virtual ~Thread();

      void launch();
      void wait();
      void terminate();
  };

  template <typename F>
    class ThreadFunctor : public ThreadStarter
  {
    private:
      F functor;

    public:
      ThreadFunctor(F);
      virtual ~ThreadFunctor() {}
      void run();
  };

  template <typename F, typename A>
    class ThreadFunctorWithArg : public ThreadStarter
  {
    private:
      F functor;
      A argument;

    public:
      ThreadFunctorWithArg(F, A);
      virtual ~ThreadFunctorWithArg() {}
      void run();
  };

  template <typename C>
    class ThreadMemberFunction : public ThreadStarter
  {
    private:
      void (C::*member_function)();
      C *object;

    public:
      ThreadMemberFunction(void (C::*)(), C *);
      virtual ~ThreadMemberFunction() {}
      void run();
  };

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

#endif /* !THREAD_HH_ */
