[系统接口 GetExitCodeThread][1]

```cpp
BOOL GetExitCodeThread(
  HANDLE  hThread,
  LPDWORD lpExitCode
);
```

If the thread has terminated and the function succeeds, the status returned is one of the following values:

- The exit value specified in the ExitThread or TerminateThread function.
- The return value from the thread function.
- The **exit value** of the thread's process.


[系统函数 WaitForSingleObject][2]

> Waits until the specified object is in the signaled state or the time-out interval elapses.

[How Threads are Terminated][3]

Terminating a thread has the following results:

- Any resources owned by the thread, such as windows and hooks, are freed.
- The thread exit code is set.
- The thread object is **signaled**.
- If the thread is the only active thread in the process, the process is terminated. For more information, see Terminating a Process.

A thread executes until one of the following events occurs:

- The thread calls the `ExitThread` function.
- Any thread of the process calls the `ExitProcess` function.
- The thread function returns.
- Any thread calls the `TerminateThread` function with a handle to the thread.
- Any thread calls the `TerminateProcess` function with a handle to the process.

[Terminating a Process][4]

[1]:https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread
[2]:https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject
[3]:https://docs.microsoft.com/en-us/windows/win32/procthread/terminating-a-thread#how-threads-are-terminated
[4]:https://docs.microsoft.com/en-us/windows/win32/procthread/terminating-a-process