## Thread

The class `Thread` represents a single thread of execution. Threads allow multiple
pieces of code to run asynchronously and simultaneously.

### Instantiating Threads

The Thread class can be instantiated from three constructors:

* [`Thread(F function)`][1]:

This constructor takes as a parameter the function to execute in the new
thread. It can be used like this:

```cpp
void long_computation()
{
  sleep(5);
}

int main()
{
  LilWrapper::Thread t1(&long_computation);
  LilWrapper::Thread t2(&long_computation);

  t1.launch();
  t2.launch();
  return (0);
}
```

* [`Thread(F function, A Argument)`][2]:

This constructor, like the previous one, takes the function to execute in the
new thread, and also a argument to pass to this function. It can be used like
this:

```cpp
void long_computation(int length)
{
  sleep(length);
}

int main()
{
  LilWrapper::Thread t1(&long_computation, 5);
  LilWrapper::Thread t2(&long_computation, 3);

  t1.launch();
  t2.launch();
  return (0);
}
```

* [`Thread(void (C::*)(), C *)`][3]:

This constructor takes a pointer to a member function from a class C and a
pointer to object from the class C. A call to the member function from the
object will be executed in the new thread. It can be used like this:

```cpp
class Sleeper {
  public:
    void long_computation()
    {
      sleep(5);
    }
};

int main()
{
  Sleeper s;
  LilWrapper::Thread t1(&Sleeper::long_computation, &s);
  LilWrapper::Thread t2(&Sleeper::long_computation, &s);

  t1.launch();
  t2.launch();
  return (0);
}
```

### Using the Threads.

Your thread object can now be used with the following methods:

* `void Thread::launch()`:

The `launch` method actually creates the thread and runs the associated functor in
the thread.

* `void Thread::wait()`:

The `wait` method waits for the thread to terminate. If it as already terminated,
then it return immediately.

* `void Thread::terminate()`:

The `terminate` method immediately terminates the thread.

<!---
### Notes

The `Thread::run()` method is used by the `ThreadImpl` class, the class that calls
the function from the C library depending on the operating system. It is not for
public use and will probably become private soon.

The `Thread::run()` should probably be private and the `ThreadImpl` class should
be a friend class of `Thread`.
-->


[1]: https://github.com/aliou/lilwrapper/blob/da84c6b8aff82e19a14b3349fe9bd473ad1e060d/include/Thread/Thread.hpp#L77
[2]: https://github.com/aliou/lilwrapper/blob/da84c6b8aff82e19a14b3349fe9bd473ad1e060d/include/Thread/Thread.hpp#L85
[3]: https://github.com/aliou/lilwrapper/blob/da84c6b8aff82e19a14b3349fe9bd473ad1e060d/include/Thread/Thread.hpp#L94
