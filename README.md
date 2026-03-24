# Inference Engine

A lightweight C++ inference engine built from scratch, starting with a tensor library foundation.

## Building

```bash
mkdir -p build && cd build
cmake ..
make
```

## Project Structure

```
src/
  tensor.hpp   - Tensor class declaration
  tensor.cpp   - Tensor implementation
  main.cpp     - Entry point
models/        - Model weight files
inputs/        - Input data files
```

## Requirements

- C++17 or later
- CMake 3.20+
