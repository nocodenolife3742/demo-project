
## Patch ID
fab2b2c5-13fc-4c43-b039-dd1303b51ffa

## Crash Input
```
beve
```

## Crash Report
```
=================================================================
==69==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x50200000001a at pc 0x557b59a9e57c bp 0x7ffda38e0690 sp 0x7ffda38e0680
WRITE of size 1 at 0x50200000001a thread T0
    #0 0x557b59a9e57b in asan_heap_overflow /src/main.c:16
    #1 0x557b59a9e996 in example_snippet /src/main.c:67
    #2 0x557b59a9efd3 in main /src/main.c:112
    #3 0x7f632f52dd8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)
    #4 0x7f632f52de3f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x29e3f)
    #5 0x557b59a9e3a4 in _start (/exe/example+0x33a4)

0x50200000001a is located 0 bytes to the right of 10-byte region [0x502000000010,0x50200000001a)
allocated by thread T0 here:
    #0 0x7f632fe16887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x557b59a9e4ff in asan_heap_overflow /src/main.c:15
    #2 0x557b59a9e996 in example_snippet /src/main.c:67
    #3 0x557b59a9efd3 in main /src/main.c:112
    #4 0x7f632f52dd8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

SUMMARY: AddressSanitizer: heap-buffer-overflow /src/main.c:16 in asan_heap_overflow
Shadow bytes around the buggy address:
  0x0a047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0a047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0a047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0a047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0a047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0a047fff8000: fa fa 00[02]fa fa fa fa fa fa fa fa fa fa fa fa
  0x0a047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0a047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0a047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0a047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0a047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
==69==ABORTING

```

## Fix Description
The heap-buffer-overflow in `asan_heap_overflow` is caused by writing to `heap_buf[10]`, which is one byte beyond the allocated size of 10 bytes. The fix is to allocate 11 bytes instead of 10, to accommodate the null terminator.

## Notes
- Some characters in the crash input and report may not render properly due to encoding issues. Please refer to the raw files for accurate representation.
