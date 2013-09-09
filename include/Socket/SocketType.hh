
#ifndef SOCKETTYPE_HH_
# define SOCKETTYPE_HH_

namespace LilWrapper
{
# ifdef WIND32
  typedef SOCKET t_socket;
# else
  typedef int t_socket;
# endif
}


#endif /* !SOCKETTYPE_HH_ */
