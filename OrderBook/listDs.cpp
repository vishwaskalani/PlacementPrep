// Understanding and documenting about the list data structure in C++
// It is prefered when frequent insertions and deletions are required, especially in the middle of the sequence.

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class ListDeque {
private:
    list<T> container; 

public:
    ListDeque() = default; 

    ~ListDeque() = default; 

    bool isEmpty() const {
        return container.empty();
    }

    int size() const {
        return static_cast<int>(container.size()); 
    }

    void push_front(T value) {
        container.push_front(value);
    }

    void push_back(T value) {
        container.push_back(value);
    }

    const T& front() const {
        if (isEmpty()) {
            throw out_of_range("Deque is empty: cannot access front.");
        }
        return container.front();
    }


    const T& back() const {
        if (isEmpty()) {
            throw out_of_range("Deque is empty: cannot access back.");
        }
        return container.back();
    }

    T pop_front() {
        if (isEmpty()) {
            throw out_of_range("Deque is empty: cannot pop front.");
        }
        T value = container.front(); // Get value
        container.pop_front();       // Remove element
        return value;
    }

    // Remove and return the back element
    T pop_back() {
        if (isEmpty()) {
            throw out_of_range("Deque is empty: cannot pop back.");
        }
        T value = container.back(); // Get value
        container.pop_back();      // Remove element
        return value;
    }
};



int main(){

	ListDeque<string> job_queue;

    cout << "Is empty: " << job_queue.isEmpty() << endl; // Output: 1 (true)

    // Add elements
    job_queue.push_back("Task B");
    job_queue.push_front("Task A (High Priority)");
    job_queue.push_back("Task C");

    cout << "Size: " << job_queue.size() << endl; // Output: 3
    cout << "Front: " << job_queue.front() << endl; // Output: Task A (High Priority)
    cout << "Back: " << job_queue.back() << endl;   // Output: Task C

    cout << "\nProcessing Queue:" << endl;
    while (!job_queue.isEmpty()) {
        string job = job_queue.pop_front();
        cout << "  Popped: " << job << endl;
    }

    cout << "Is empty after processing: " << job_queue.isEmpty() << endl; // Output: 1 (true)


	return 0;
}