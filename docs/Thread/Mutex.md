## Mutex

### Instantiating Mutexes

The Mutex class can be instantiated with its simple constructor: [`Mutex()`][1].
The constructor initialize the mutex native handle.

### Using the Mutexes

Your Mutex object can now be used with the following methods:

* `void Mutex::lock()`:

The `lock` method locks the mutex. If the mutex is already locked, the calling
thread is blocked until the mutex is unlocked.

* `void Mutex::unlock()`:

The `unlock()` method releases the mutex.

* `bool Mutex::trylock()`:

The `trylock()` method is equivalent to the `lock` method except that if the
mutex is already locked, the method returns the `false`.

[1]: https://github.com/aliou/lilwrapper/blob/da84c6b8aff82e19a14b3349fe9bd473ad1e060d/src/Thread/Mutex.cpp#L11
