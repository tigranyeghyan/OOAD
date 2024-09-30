#include <iostream>
#include <utility>

#include "Shared_ptr.hpp"

int main() {
    Shared_ptr<int> sp1(new int(42));
    Shared_ptr<int> sp2 = sp1;
    Shared_ptr<int> sp3 = std::move(sp1);
    Shared_ptr<int> sp4;
    sp4 = std::move(sp2);

    return 0;
}
