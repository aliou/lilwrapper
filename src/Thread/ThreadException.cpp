#include "Thread/ThreadException.hh"

namespace LilWrapper
{
  ThreadException::ThreadException(const char *message)
    : _message(message)
  {}

  const char *ThreadException::what() const throw()
  {
    return (this->_message);
  }
}
