#include <sys/socket.h>

#ifndef SOCKETIMPL_HH_
# define SOCKETIMPL_HH_

namespace LilWrapper
{
  class SocketImpl
  {
    private:
      int _socket;
    public:
      SocketImpl();
      ~SocketImpl();

      int getNativeHandle() const;
  };
}

#endif /* !SOCKETIMPL_HH_ */
