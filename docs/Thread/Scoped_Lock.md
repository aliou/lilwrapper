## Scoped Lock

### Using Scoped Locks

The Scoped lock class is a wrapper around a Mutex that provides a way to own a
mutex for the duration of a scoped block.

When a Scoped lock object is created, it locks the provided mutex. When the
control leaves the scope in which the scoped lock object was created, the object
is destroyed and the mutex is released.

It can be used like this:

  ```c
int g_i;
LilWrapper::Mutex g_i_mutex;

void safe_increment()
{
  LilWrapper::ScopedLock lock(g_i_mutex);
  ++g_i;

  // g_i_mutex is automatically released when lock goes out of scope
}

int main()
{
  LilWrapper::Thread t1(safe_increment);
  LilWrapper::Thread t2(safe_increment);

  t1.wait();
  t2.wait();
}
```
### Notes

This class is non-copyable.
