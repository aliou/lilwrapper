#include <iostream>
#include "Thread/Mutex.hh"

#ifndef MOCKCLASS_HH_
# define MOCKCLASS_HH_

class Mock
{
  private:
    int _data;
    LilWrapper::Mutex *_m;
  public:
    Mock();
    ~Mock() {}

    void increment_without_mutex();
    void increment_with_mutex();
    int getData() const;
};

#endif /* !MOCKCLASS_HH_ */
