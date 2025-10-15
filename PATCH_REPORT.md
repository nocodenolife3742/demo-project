
## Patch ID
f0625785-abfa-4593-97a5-30c80715a232

## Crash Input
```
cidu
```

## Crash Report
```
main.c:24:14: runtime error: index 10 out of bounds for type 'char [10]'
main.c:24:19: runtime error: store to address 0x7ffe1b74f33a with insufficient space for an object of type 'char'
0x7ffe1b74f33a: note: pointer points here
 00 00  79 7c 68 ef 9e 7f 00 00  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  80 f3 74 1b fe 7f
              ^ 
=================================================================
==57==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffe1b74f33a at pc 0x55763307567f bp 0x7ffe1b74f300 sp 0x7ffe1b74f2f0
WRITE of size 1 at 0x7ffe1b74f33a thread T0
    #0 0x55763307567e in asan_stack_overflow /src/main.c:24
    #1 0x557633075a26 in example_snippet /src/main.c:71
    #2 0x557633075fd3 in main /src/main.c:112
    #3 0x7f9eef623d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)
    #4 0x7f9eef623e3f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x29e3f)
    #5 0x5576330753a4 in _start (/exe/example+0x33a4)

Address 0x7ffe1b74f33a is located in stack of thread T0 at offset 42 in frame
    #0 0x5576330755a1 in asan_stack_overflow /src/main.c:22

  This frame has 1 object(s):
    [32, 42) 'stack_buf' (line 23) <== Memory access at offset 42 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow /src/main.c:24 in asan_stack_overflow
Shadow bytes around the buggy address:
  0x1000436e1e10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000436e1e20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000436e1e30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000436e1e40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000436e1e50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x1000436e1e60: 00 00 f1 f1 f1 f1 00[02]f3 f3 00 00 00 00 00 00
  0x1000436e1e70: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 f1 f1
  0x1000436e1e80: f1 f1 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000436e1e90: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000436e1ea0: 00 00 f3 f3 f3 f3 f3 f3 f3 f3 00 00 00 00 00 00
  0x1000436e1eb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==57==ABORTING

```

## Fix Description
The crash report indicates a stack buffer overflow in the `asan_stack_overflow` function at line 24 of `/src/main.c`. The `stack_buf` is declared as `char stack_buf[10]`, meaning it has indices 0-9. The code attempts to write to `stack_buf[10]`, which is one byte beyond the allocated buffer. To fix this, the index should be within the bounds of the array, such as `stack_buf[9] = 'a';` or the buffer size can be increased. I will modify the code to write to the last valid index `stack_buf[9]`.

## Notes
- Some characters in the crash input and report may not render properly due to encoding issues. Please refer to the raw files for accurate representation.
