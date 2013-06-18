#include <exception>

#ifndef THREADEXCEPTION_HH_
# define THREADEXCEPTION_HH_

namespace LilWrapper
{
  class ThreadException : public std::exception
  {
    private:
      const char	*_message;
    public:
      ThreadException(const char *message);
      virtual ~ThreadException() throw() {}

      virtual const char *what() const throw();
  };
}

#endif /* THREADEXCEPTION_HH_ */
