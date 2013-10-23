#include "Socket/SocketType.hh"

#ifndef SOCKET_HH_
# define SOCKET_HH_

namespace LilWrapper
{
  class SocketImpl;

  class Socket
  {
    private:
      SocketImpl  *_impl;
    public:
      Socket();
      ~Socket() {}

      t_socket getNativeHandle() const;
  };
}

#endif /* !SOCKET_HH_ */
