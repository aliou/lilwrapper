#include <list>
#include <algorithm>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "Socket/ISocket.hh"

#ifndef SELECTOR_HH_
# define SELECTOR_HH_

namespace LilWrapper
{
  class Selector
  {
    private:
      std::list<ISocket *>	_sockets;
      fd_set			_readfds;
      // fd_set			_writefds;
      // fd_set			_exceptfds;
      struct timeval		*_timeout;

      void initSet();
      void addToSet(ISocket *);
      void removeFromSet(ISocket *);
      void clearSet();
      int getMaxFD() const;
    public:
      Selector();
      Selector(struct timeval *);
      ~Selector();

      void setTimeout(struct timeval *timeout);
      void addSocket(ISocket *);
      void removeSocket(ISocket *);
      bool select();
      bool hasChanged(ISocket *) const;
  };
}

#endif /* !SELECTOR_HH_ */
