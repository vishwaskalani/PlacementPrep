#include <memory>
using namespace std;

int main() {
    unique_ptr<int> uniquePtr = make_unique<int>(42);
    // Memory is automatically deallocated when uniquePtr goes out of scope.

	shared_ptr<int> sharedPtr1 = make_shared<int>(42);
    shared_ptr<int> sharedPtr2 = sharedPtr1; // Shared ownership

    return 0;
}
