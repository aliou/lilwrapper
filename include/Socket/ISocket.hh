#include "Socket/SocketType.hh"

#ifndef ISOCKET_HH_
# define ISOCKET_HH_

namespace LilWrapper
{
  class ISocket
  {
    public:
      virtual ~ISocket() {}

      virtual t_socket getNativeSocket() const;
  };
}

#endif /* !ISOCKET_HH_ */
