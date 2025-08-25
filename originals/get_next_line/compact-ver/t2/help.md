# Get Next Line

## What's the problem?

The current bs-ver / compact-ver is quite fine except that the different
calls to read do not really rely on BUFFER_SIZE as it required by some
assignments...

It would interesting to improve that design so it does work as with 
variable buffer sizes at well.

## Why use a BUFFER_SIZE in the first place?

Get_next_line standard design, at least in my case since 2023:
- A `stash` with static storage duration - as long as the program lifetime -
that stores everything fetched into the `buffer` via `read`.
- A `buffer` of size `BUFFER_SIZE` which content will be copied to the stash.
- A `line` extracted from the stash.

Because it's required by the assignment? Is that all?

IF we limit the size of buffer size to 1... The problem is there will be a lot
of calls that could have been just factored in one or two. And for large
quantities, the cost of those repeated calls ballons even more.

So `read(fd, buffer, 1)` is **extremely inefficient** in practice...

## But there is a problem with adding a variable buffer size. 

A variable buffer size... make more difficult newlines '\n' detection.

The `read` syscall will read BUFFER_SIZE every time it's possible until EOF 
and won't necessary stop exactly at the newlines...

HOWEVER, with the current design, there is no memory of the bytes already 
read between each function calls. **What has been read and has not been used 
between function calls (the part after the '\n') is **lost forever**...

... unless we:
* play with `lseek` to move read offset back after the last newline, which 
may not be authorized
* or we add static storage duration to some of those vars and memory spaces.

