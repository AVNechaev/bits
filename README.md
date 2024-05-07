Benchmarking various bit counting algos

# Build
```bash
mkdir build
conan install . --output-folder=build --build=missing
cd build
cmake .. --preset conan-release
cmake --build .
```

# Benchmarks
