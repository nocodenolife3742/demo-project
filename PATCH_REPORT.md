
## Patch ID
6461dcf5-cdb8-4cde-8b42-4efd116858d1

## Crash Input
```
aeveaeve
```

## Crash Report
```
main.c:9:8: runtime error: store to null pointer of type 'int'
AddressSanitizer:DEADLYSIGNAL
=================================================================
==57==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x55fae87a94e0 bp 0x7ffe20a56760 sp 0x7ffe20a56750 T0)
==57==The signal is caused by a WRITE memory access.
==57==Hint: address points to the zero page.
    #0 0x55fae87a94e0 in asan_null_deref /src/main.c:9
    #1 0x55fae87a9906 in example_snippet /src/main.c:63
    #2 0x55fae87a9fd3 in main /src/main.c:112
    #3 0x7f9c76c2cd8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)
    #4 0x7f9c76c2ce3f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x29e3f)
    #5 0x55fae87a93a4 in _start (/exe/example+0x33a4)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV /src/main.c:9 in asan_null_deref
==57==ABORTING

```

## Fix Description
The crash occurs because `asan_null_deref` dereferences a null pointer. The fix is to check if the pointer is NULL before dereferencing it.

## Notes
- Some characters in the crash input and report may not render properly due to encoding issues. Please refer to the raw files for accurate representation.
