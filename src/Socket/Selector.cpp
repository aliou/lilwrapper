#include "Socket/Selector.hh"

namespace LilWrapper
{
  Selector::Selector()
    : _timeout(NULL) {}

  Selector::Selector(struct timeval *ts)
    : _timeout(ts) {}

  void Selector::initSet()
  {
    std::list<ISocket *>::iterator it = _sockets.begin();

    clearSet();
    for (; it != _sockets.end(); ++it)
      FD_SET((*it)->getFD(), &_readfds);
  }

  void Selector::addToSet(ISocket *sock)
  {
    FD_SET(sock->getFD(), &_readfds);
  }

  void Selector::removeFromSet(ISocket *sock)
  {
    FD_CLR(sock->getFD(), &_readfds);
  }

  void Selector::clearSet()
  {
    FD_ZERO(&_readfds);
  }

  int Selector::getMaxFD() const
  {
    std::list<ISocket *>::const_iterator it = _sockets.begin();
    int maxfd = (*it)->getFD();

    for (; it != _sockets.end(); ++it)
      maxfd = (*it)->getFD() > maxfd ? (*it)->getFD() : maxfd;

    return (maxfd);
  }

  bool Selector::select()
  {
    return (::select(getMaxFD() + 1, &_readfds, NULL, NULL, _timeout) == -1);
  }

  void Selector::setTimeout(struct timeval *timeout)
  {
    this->_timeout = timeout;
  }

  void Selector::addSocket(ISocket *sock)
  {
    if (std::find(_sockets.begin(), _sockets.end(), sock) == _sockets.end())
    {
      _sockets.push_back(sock);
      addToSet(sock);
    }
  }

  void Selector::removeSocket(ISocket *sock)
  {
    _sockets.remove(sock);
    removeFromSet(sock);
  }

  bool Selector::hasChanged(ISocket *sock) const
  {
    return (FD_ISSET(sock->getFD(), &_readfds) == 1);
  }

}
