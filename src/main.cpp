#include "tensor.hpp"

int main() {
    Tensor t1({1, 28, 28});
    t1.print("zeros");

    Tensor t2({2, 3}, {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
    t2.print("manual");

    return 0;
}
