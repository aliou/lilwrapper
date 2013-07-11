#ifndef IMUTEX_HH_
# define IMUTEX_HH_

namespace LilWrapper
{
  class IMutex
  {
    public:
      virtual ~IMutex() {}

      virtual void lock() = 0;
      virtual void unlock() = 0;
      virtual bool trylock() = 0;
  };
}

#endif /* IMUTEX_HH_ */
