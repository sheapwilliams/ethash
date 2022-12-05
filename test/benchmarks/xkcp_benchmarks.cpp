// Copyright 2022 Shea Williams
// SPDX-License-Identifier: Apache-2.0

#include "keccak_utils.hpp"
#include <benchmark/benchmark.h>
#include <ethash/hash_types.h>

extern "C" {
#include "FIPS202/KeccakHash.h"
}

static auto xkcp_keccak256(Keccak_HashInstance& h, const unsigned char * c, std::size_t s) {
		ethash_hash256 hash{};

		KeccakP1600_OverwriteWithZeroes(h.sponge.state, 200);
		h.sponge.squeezing = 0;
		h.sponge.byteIOIndex = 0;
		Keccak_HashUpdate(&h, c, s*8);
		Keccak_HashFinal(&h, (hash.bytes));
		return hash;
}


static void xkcp_keccak256(benchmark::State& state)
{
    const auto data_size = static_cast<size_t>(state.range(0));
    std::vector<uint8_t> data(data_size, 0xde);
    Keccak_HashInstance hashInstance;

    Keccak_HashInitialize(&hashInstance, 1088,  512, 256, 0x01);
 
    for (auto _ : state)
    {
        auto h = xkcp_keccak256(hashInstance, data.data(), data.size());
        benchmark::DoNotOptimize(h.bytes);
    }
}
BENCHMARK(xkcp_keccak256)->Arg(0)->Arg(32)->Arg(135)->Arg(136)->Arg(271)->Arg(272)->Arg(407)->Arg(408)->Arg(500);

BENCHMARK_MAIN();
