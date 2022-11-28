
enable_language(ASM)
add_library(xkcp-avx2 STATIC vendor/xkcp/lib/low/KeccakP-1600/AVX2/KeccakP-1600-AVX2.s vendor/xkcp/lib/high/Keccak/FIPS202/KeccakHash.c vendor/xkcp/lib/high/Keccak/KeccakSponge.c)
target_include_directories(xkcp-avx2 PUBLIC vendor/xkcp/lib/low/KeccakP-1600/AVX2 vendor/xkcp/lib/high/Keccak test/benchmarks vendor/xkcp/lib/common)

add_library(xkcp-x86-64 STATIC vendor/xkcp/lib/low/KeccakP-1600/x86-64/KeccakP-1600-x86-64-gas.s vendor/xkcp/lib/high/Keccak/FIPS202/KeccakHash.c vendor/xkcp/lib/high/Keccak/KeccakSponge.c)
target_include_directories(xkcp-x86-64 PUBLIC vendor/xkcp/lib/low/KeccakP-1600/x86-64 vendor/xkcp/lib/high/Keccak test/benchmarks vendor/xkcp/lib/common)

