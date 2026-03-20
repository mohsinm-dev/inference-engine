#pragma once 

#include<vector>
#include<string>
#include<iostream>
#include<numeric>
#include<cassert>

struct Tensor{
    std::vector<float>data; //flat array
    std::vector<uint32_t> shape; //dimensions
    

    // Constructors

    // Default
    Tensor() = default;

    // With Data
    Tensor(std::vector<uint32_t> shape, std::vector<float> data);

    // Empty tensor with given shape
    Tensor(std::vector<uint32_t> shape);


    // total elements 
    // {1,28,28} -> 1 * 28 * 28 = 784 
    size_t numel() const;

    std::string shape_str() const;

    void print(const std::string& name = " ") const;

    // single index access (flat)
    float& operator[] (size_t idx) { return data[idx];}
    float operator[] (size_t idx) const {return data[idx];}
};