// Copyright 2022 Shea Williams
// SPDX-License-Identifier: Apache-2.0

#include "keccak_utils.hpp"
#include <benchmark/benchmark.h>
#include <ethash/hash_types.h>

extern "C" {
#include "FIPS202/KeccakHash.h"
}

static auto xkcp_wrapper(const unsigned char* d, std::size_t s) {

  ethash_hash256 hash{};
  Keccak_HashInstance hashInstance;

  Keccak_HashInitialize(&hashInstance, 1088,  512, 256, 0x01);
  Keccak_HashUpdate(&hashInstance, d, s);
  Keccak_HashFinal(&hashInstance, (hash.bytes));
  return hash;
}

static void xkcp_keccak256(benchmark::State& state)
{
    const auto data_size = static_cast<size_t>(state.range(0));
    std::vector<uint8_t> data(data_size, 0xde);

    for (auto _ : state)
    {
        auto h = xkcp_wrapper(data.data(), data.size());
        benchmark::DoNotOptimize(h.bytes);
    }
}
BENCHMARK(xkcp_keccak256)->Arg(0)->Arg(32)->Arg(500)->Arg(1086)->Arg(1087)->Arg(2174)->Arg(2175);

BENCHMARK_MAIN();
