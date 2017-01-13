#pragma once
#include <cstddef>
#include <cstdint>

namespace coreutil {

// minimum alignment for memory allocators on most machines
static constexpr unsigned standard_alignment = 2 * sizeof(void *);

//------------------------------------------------------------------------------
// pointer bump allocator
//------------------------------------------------------------------------------
// note: not thread-safe
// note: the memory buffer must be preallocated and aligned, eg.
//   alignas(coreutil::standard_alignment) char my_memory[my_size];

void pbinit(void *mem, size_t memsize);
[[gnu::malloc]] void *pbmalloc(void *mem, size_t size) noexcept;
void pbclear(void *mem) noexcept;

}  // namespace coreutil
