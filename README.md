# z64hdr
 
Zelda 64 header files and function/symbol addresses. For compiling code to be
linked to OoT or MM, including custom actors and other generic romhack code.

Currently supports OoT MQ Debug (the Debug ROM) and OoT 1.0 J/U.

## Feature comparison

| [z64hdr (this repo)](https://github.com/turpaan64/z64hdr) | [z64ovl new ("z64poevl")](https://github.com/CrookedPoe/z64ovl/) | [libzelda64](https://github.com/hylian-modding/libzelda64) | [z64ovl_archived](https://github.com/z64me/z64ovl_archived) |
| --- | --- | --- | --- |
| Does not contain Gigaleak content | | | Does not contain Gigaleak content |
| Debug && 1.0 | Debug && 1.0 | 1.0 only? | Debug && 1.0 |
| Decomp names | Decomp names | Decomp names | `z64_snake_case` names |
| Sane typedef structs | Sane typedef structs | `struct blah` required everywhere | Sane typedef structs |
| Addresses in linker scripts | Addresses in inline asm | Addresses in inline asm | Addresses in inline asm |

## How to Use

- `#include "oot_debug.h"` or `#include "oot_10.h"`.
- In your link step, use a linker script like `mips64-ld -T LINKER_SCRIPT.ld --emit-relocs -o something.elf something.o`. If you are building a custom actor, use `oot_debug.ld` or `oot_10.ld` as appropriate; these will include `oot_X_syms.ld` and `z64hdr_actor.ld`. If you are writing other custom code which requires a different ELF layout than provided in `z64hdr_actor.ld`, provide your own linker script, and within that `INCLUDE oot_X_syms.ld` or provide `-T oot_X_syms.ld` in addition to your own script to the linker.

## Other info

z64hdr can / will be updated to match the current state of decomp headers. When
the decomp updates a function name, e.g. from `func_800XXXXX` to 
`Something_DoSomething`, it will be updated in `z64hdr` and you will have to
update your project code.

## Missing 1.0 addresses

For most functions, a 1.0 address is provided. Only a few important symbol addresses are provided for either Debug or 1.0.

If you need to use a function for which a Debug address is provided but a 1.0 address is not, please check that this function exists in 1.0. Debugging functions like `Graph_OpenDisps`, `Graph_CloseDisps`, and `LogUtils_LogThreadId` for example do not exist in 1.0. You should never need to use these functions; if you copied code from the decomp, you should remove these functions.

If the function really is in 1.0 but `z64hdr` is missing its address, please open a GitHub issue.

## Credits

Addresses from:
- [The decomp](https://github.com/zeldaret/oot)
- [z64ovl_archived](https://github.com/z64me/z64ovl_archived)
- [CrookedPoe's spreadsheet](https://docs.google.com/spreadsheets/d/1PqqbENJRmxj0iWDexm-6J3LWJ5lAWZpWQJM8_sRhMQU/edit#gid=0)
- Manual asm comparison by z64me, rankaisija, Sauraen, Skawo, Dragorn421 

## Internal documentation: what to change when copying new decomp headers

- z64actor.h, in `Actor`:
    ```
    #ifndef _Z64OVL_10_
    /* 0x13C */ char dbgPad[0x10]; // Padding that only exists in the debug rom
    #endif
    ```
- z64actor.h, in `ActorInit`:
    ```
    /* 0x0A */ u16 padding; // Padding exists, but must be named for DEAD BEEF algorithm for zzrtl and friends
    ```
- functions.h: Replace three functions at the top which have `#pragma intrinsic` with them, with
    ```
    #include "../intrinsics.h"
    ```    
- functions.h: add `const` to `bcopy`:
    ```
    void* bcopy(const void* __src, void* __dest, u32 __n);
    ```
- functions.h: add `#ifdef _Z64HDR_DEBUG_` around `, const char* file, s32 line` in
    ```
    DmaMgr_SendRequest2
    DmaMgr_SendRequest1
    ```
