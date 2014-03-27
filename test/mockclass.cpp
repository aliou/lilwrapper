#include "mockclass.hh"

Mock::Mock() : _data(0)
{
  this->_m = new LilWrapper::Mutex;
}

void Mock::increment_without_mutex()
{
  for (int i = 0; i < 200; i++)
    this->_data += i;
}

void Mock::increment_with_mutex()
{
  this->_m->trylock();
  for (int i = 0; i < 200; i++)
    this->_data += i;
  this->_m->unlock();
  // data -> 20100
}

int Mock::getData() const
{
  return (this->_data);
}
