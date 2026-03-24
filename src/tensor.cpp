#include "tensor.hpp"
#include <iostream>
#include <iomanip>

Tensor::Tensor(std::vector<uint32_t> shape)
    :shape(shape)
{
    // Total element 
    size_t total = numel();
    data.resize(total, 0.0f);  // initializing everything with zero
}

Tensor::Tensor(std::vector<u_int32_t> shape, std::vector<float>data)
        :shape(shape), data(std::move(data))
{
    // verify the data and shape
    assert(this->data.size() == numel() && "Data size and shape mismatched!");
}

size_t Tensor::numel() const {
    if (shape.empty()) return 0;
    return std::accumulate(shape.begin(), shape.end(), (size_t)1, std::multiplies<size_t>());
}

std::string Tensor::shape_str() const {
    std::string s = "(";
    for (size_t i = 0; i < shape.size(); i++) {
        s += std::to_string(shape[i]);
        if (i + 1 < shape.size()) s += ", ";
    }
    s += ")";
    return s;
}

void Tensor::print(const std::string& name) const {
    std::cout << name << " | shape: " << shape_str()
              << " | numel: " << numel() << std::endl;
    std::cout << "[";
    size_t n = std::min(data.size(), (size_t)10);
    for (size_t i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(4) << data[i];
        if (i + 1 < n) std::cout << ", ";
    }
    if (data.size() > 10) std::cout << ", ...";
    std::cout << "]" << std::endl;
}