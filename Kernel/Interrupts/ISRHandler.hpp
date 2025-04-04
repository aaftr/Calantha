/*
* Copyright (c) 2025 Diago Lima
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef CALANTHA_IHANDLER_HPP
#define CALANTHA_IHANDLER_HPP
#include <Kernel/KCore/Types.hpp>
#include <Kernel/KCore/Result.hpp>
BEGIN_NAMESPACE(interrupt);

struct PACKED_ Frame {
  uint64 r15; /// Registers pushed by the ISR
  uint64 r14; /// dispatch stub in ISR.S
  uint64 r13; ///
  uint64 r12;
  uint64 r11;
  uint64 r10;
  uint64 r9;
  uint64 r8;
  uint64 rbp;
  uint64 rdi;
  uint64 rsi;
  uint64 rdx;
  uint64 rcx;
  uint64 rbx;
  uint64 rax;
  uint64 vec;
  uint64 err;
  uint64 rip; ///
  uint64 cs;  /// Special purpose regs:
  uint64 rflags;
  uint64 rsp;
  uint64 ss;
};

class Handler {
public:
  NODISCARD_ static auto get()  -> Handler&;
  NODISCARD_ static auto init() -> kcore::Result<void>;
  constexpr Handler()  = default;
private:
  uintptr* stub_begin_ = nullptr;
  uintptr* stub_end_   = nullptr;
};

static_assert(sizeof(Frame) == 176);
extern constinit const char* g_exception_msgs[32];

END_NAMESPACE(interrupt);
#endif //CALANTHA_IHANDLER_HPP
