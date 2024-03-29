#include <iostream>
#include <variant>
#include <string>
#include <cmath>
#include <optional>

// Define operations
struct Add {
    std::optional<double> operator()(double a, double b) const { return a + b; }
    std::optional<int> operator()(int a, int b) const { return a + b; }
};

struct Subtract {
    std::optional<double> operator()(double a, double b) const { return a - b; }
    std::optional<int> operator()(int a, int b) const { return a - b; }
};

struct Multiply {
    std::optional<double> operator()(double a, double b) const { return a * b; }
    std::optional<int> operator()(int a, int b) const { return a * b; }
};

struct Divide {
    std::optional<double> operator()(double a, double b) const {
        if (b == 0) return std::nullopt;
        return a / b;
    };

    std::optional<int> operator()(int a, int b) const {
        if (b == 0) return std::nullopt;
        return a / b;
    }
};

// Operation variant
using Operation = std::variant<Add, Subtract, Multiply, Divide>;

// Apply operation
template<typename T>
std::optional<T> applyOperation(T a, T b, Operation op) {
    return std::visit([a, b](auto&& operation) { return operation(a, b); }, op);
}

// Print optional
template<typename T>
std::string printOptional(const std::optional<T>& opt) {
    if (opt) {
        return std::to_string(*opt);
    } else {
        return "No value";
    }
}

// Example usage
int main() {
    double a = 5, b = 2;

    Operation op_add = Add{};
    Operation op_sub = Subtract{};
    Operation op_mul = Multiply{};
    Operation op_div = Divide{};

    auto result_add = applyOperation(a, b, op_add);
    std::cout << "Result: " << printOptional(result_add) << std::endl;

    auto result_sub = applyOperation(a, b, op_sub);
    std::cout << "Result: " << printOptional(result_sub) << std::endl;

    auto result_mul = applyOperation(a, b, op_mul);
    std::cout << "Result: " << printOptional(result_mul) << std::endl;

    auto result_div = applyOperation(a, b, op_div);
    std::cout << "Result: " << printOptional(result_div) << std::endl;

    // Consider implementing user input parsing and operation selection

    return 0;
}
