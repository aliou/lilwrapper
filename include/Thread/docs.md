So far, there are four classes abstracted from the C Thread Library.

## Thread

### Instantiation

The Thread class can be instantiated from three constructors:

* `Thread(F function)`:

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

  t1.run();
  t2.run();
  return (0);
}
```

* `Thread(F function, A Argument)`:

This constructor, like the previous one, takes the function to execute in the
new thread, and also a argument to pass to this function.

* `Thread(void (C::*)(), C *)`:

This constructor takes a pointer to a member function from a class C and a
pointer to object from the class C. A call to the member function from the
object will be executed in the new thread.
