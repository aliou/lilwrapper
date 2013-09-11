CXX	= clang++

RM	= rm -rf

CXXFLAGS	+= -Wall -Wextra -Werror
CXXFLAGS	+= -I include

SRCTHREAD	= src/Thread/Mutex.cpp				\
		  src/Thread/ScopedLock.cpp			\
		  src/Thread/Thread.cpp				\
		  src/Thread/ThreadException.cpp	\
		  src/Thread/ThreadPool.cpp			\
		  src/Thread/Unix/ThreadImpl.cpp	\
		  src/Thread/Unix/MutexImpl.cpp		\

OBJTHREAD	= $(SRCTHREAD:.cpp=.o)

SRCTESTMUTEX	= test/mutex.cpp
OBJTESTMUTEX	= $(SRCTESTMUTEX:.cpp=.o)

SRCTESTTHREAD	= test/thread.cpp
OBJTESTTHREAD	= $(SRCTESTTHREAD:.cpp=.o)

###############################################################################

all: test_mutex test_thread

test_mutex: $(OBJTHREAD) $(OBJTESTMUTEX)
	$(CXX) $(OBJTHREAD) $(OBJTESTMUTEX) -o test_mutex

test_thread: $(OBJTHREAD) $(OBJTESTTHREAD)
	$(CXX) $(OBJTHREAD) $(OBJTESTTHREAD) -o test_thread

clean:
	$(RM) $(OBJTHREAD) $(OBJTESTMUTEX) $(OBJTESTTHREAD)

fclean: clean
	$(RM) test_mutex test_thread

re: fclean all
