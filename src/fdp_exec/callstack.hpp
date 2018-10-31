#pragma once

#include "enums.hpp"
#include "types.hpp"
#include "core.hpp"
#include "utils/pe.hpp"

#include <functional>

namespace callstack
{
    struct ICallstack
    {
        virtual ~ICallstack() = default;

        using on_callstep_fn = std::function<walk_e(sym::Cursor)>;

        virtual bool    get_callstack        (proc_t proc, uint64_t rip, uint64_t rsp, uint64_t rbp,
                                              const on_callstep_fn& on_callstep) = 0;
    };

    std::unique_ptr<ICallstack> make_callstack_nt (core::Core& core, pe::Pe& pe);
}