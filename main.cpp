#include <iostream>
#include <variant>
#include <string>
#include <cmath>

// Define operations
struct Add {
    auto operator()(double a, double b) const { return a + b; }
    auto operator()(int a, int b) const { return a + b; }
};

struct Subtract {
    auto operator()(double a, double b) const { return a - b; }
    auto operator()(int a, int b) const { return a - b; }
};

// Add more operations: Multiply, Divide

// Operation variant
using Operation = std::variant<Add, Subtract/*, Multiply, Divide*/>;

// Apply operation
template<typename T>
T applyOperation(T a, T b, Operation op) {
    return std::visit([a, b](auto&& operation) { return operation(a, b); }, op);
}

// Example usage
int main() {
    double a = 5.5, b = 2.2;
    Operation op_add = Add{};
    Operation op_sub = Subtract{};

    auto result_add = applyOperation(a, b, op_add);
    std::cout << "Result: " << result_add << std::endl;

    auto result_sub = applyOperation(a, b, op_sub);
    std::cout << "Result: " << result_sub << std::endl;

    // Try more operations, including int operations
    // Consider implementing user input parsing and operation selection

    return 0;
}
