#include <iostream>
#include <vector>

using std::cout, std::endl;

std::ostream& operator<<(std::ostream& output, const std::vector<int>& v) {
    for (auto& n:v) {
        output << n << ' ';
    }
    return output;
}

void operator<<(std::vector<int>& v, const std::vector<int>& in_vec) {
    for (auto& n: in_vec) {
        v.push_back(n);
    }
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    cout << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    v.push_back(6);
    cout << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    v << std::vector({7, 8, 9, 10, 11});
    cout << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    v << std::vector({12, 13, 14, 15, 16, 17, 18, 19, 20, 21});
    cout << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    v.shrink_to_fit();
    cout << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    v.reserve(500);
    cout << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    return 0;
}