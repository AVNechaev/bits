#include <cstddef>
#include <cstdint>

#include <benchmark/benchmark.h>
#include <cstdlib>

size_t bits_1(uint32_t data) {
    size_t count {0};
    while(data) {
        if(data & 1) {
            ++count;
        }
        data >>= 1;
    }
    return count;
}

size_t bits_2(uint32_t data) {
    size_t count {0};
    while(data) {
        count += (data & 1);
        data >>= 1;
    }
    return count;
}

size_t bits_3(uint32_t data) {
    size_t count {0};
    while(data) {
        ++count;
        data = data & (data - 1);
    }
    return count;
}

static uint32_t precomp[256];
void fill_it() {
    for(size_t i = 0; i < 256; ++i) {
        precomp[i] = bits_3(i);
    }
}

size_t bits_4(uint32_t data) {
    return precomp[data & 0xFF]
        + precomp[(data >> 8) & 0xFF]
        + precomp[(data >> 16) & 0xFF]
        + precomp[(data >> 24) & 0xFF];
}

uint32_t gen() {
    return std::rand();
}

static void BM_Bits1(benchmark::State& state) {
    auto v = gen();
    for(auto _ : state) {
        benchmark::DoNotOptimize(bits_1(v));
    }
}

static void BM_Bits2(benchmark::State& state) {
    auto v = gen();
    for(auto _ : state) {
        benchmark::DoNotOptimize(bits_2(v));
    }
}

static void BM_Bits3(benchmark::State& state) {
    auto v = gen();
    for(auto _ : state) {
        benchmark::DoNotOptimize(bits_3(v));
    }
}

static void BM_Bits4(benchmark::State& state) {
    auto v = gen();
    for(auto _ : state) {
        benchmark::DoNotOptimize(bits_4(v));
    }
}


BENCHMARK(BM_Bits1);
BENCHMARK(BM_Bits2);
BENCHMARK(BM_Bits3);
BENCHMARK(BM_Bits3)->Setup([](const benchmark::State &){ fill_it(); });


BENCHMARK_MAIN();