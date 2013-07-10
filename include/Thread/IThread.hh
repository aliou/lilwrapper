#ifndef ITHREAD_HH_
# define ITHREAD_HH_

namespace LilWrapper
{
  class IThread
  {
    public:
      virtual ~IThread() {}

      virtual void launch() = 0;
      virtual void wait() = 0;
      virtual void terminate() = 0;
  };
}

#endif /* ITHREAD_HH_ */
