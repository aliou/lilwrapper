#ifndef MUTEX_HH_
# define MUTEX_HH_

namespace LilWrapper
{
  class MutexImpl;

  class Mutex
  {
    private:
      MutexImpl	*_impl;

    public:
      Mutex();
      virtual ~Mutex();

      void lock();
      void unlock();
      bool trylock();
  };
}

#endif /* !MUTEX_HH_ */
