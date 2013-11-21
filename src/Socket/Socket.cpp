#include "Socket/Socket.hh"

#ifdef WIN32
# include "Socket/Win/SocketImpl.hh"
#else
# include "Socket/Unix/SocketImpl.hh"
#endif

namespace LilWrapper
{
  Socket::Socket()
    : _impl(new SocketImpl)
  {
  }

  t_socket Socket::getNativeHandle() const
  {
    return (this->_impl->getNativeHandle());
  }
}
