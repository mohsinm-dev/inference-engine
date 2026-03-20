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