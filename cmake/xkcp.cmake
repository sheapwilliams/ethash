
enable_language(ASM)
add_library(xkcp-avx2 STATIC vendor/xkcp/lib/low/KeccakP-1600/AVX2/KeccakP-1600-AVX2.s vendor/xkcp/lib/high/Keccak/FIPS202/KeccakHash.c vendor/xkcp/lib/high/Keccak/KeccakSponge.c)
target_include_directories(xkcp-avx2 PUBLIC vendor/xkcp/lib/low/KeccakP-1600/AVX2 vendor/xkcp/lib/high/Keccak test/benchmarks vendor/xkcp/lib/common)

