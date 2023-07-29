#include <iostream>
#include <vector>
using namespace std;

// Iterators:
// begin() – Returns an iterator pointing to the first element in the vector
// end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
// rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
// rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
// cbegin() – Returns a constant iterator pointing to the first element in the vector.
// cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
// crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
// crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

// Capacity:
//  size() – Returns the number of elements in the vector.
//  max_size() – Returns the maximum number of elements that the vector can hold.
//  capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
//  resize(n) – Resizes the container so that it contains ‘n’ elements.
//  empty() – Returns whether the container is empty.
//  shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
//  reserve() – Requests that the vector capacity be at least enough to contain n elements.

// Element access:
// reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
// at(g) – Returns a reference to the element at position ‘g’ in the vector
// front() – Returns a reference to the first element in the vector
// back() – Returns a reference to the last element in the vector
// data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

// Modifiers:
// assign() – It assigns new value to the vector elements by replacing old ones
// push_back() – It push the elements into a vector from the back
// pop_back() – It is used to pop or remove elements from a vector from the back.
// insert() – It inserts new elements before the element at the specified position
// erase() – It is used to remove elements from a container from the specified position or range.
// swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
// clear() – It is used to remove all the elements of the vector container
// emplace() – It extends the container by inserting new element at position
// emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector

int main()
{
    vector<int> v;

    // 1st method to enter values in a vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.pop_back();
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    // 2nd method for enter values in a vector

    vector<int> v2(3, 67);

    // methods for printng vector by different approches

    cout << "First method of display a vector\n";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }

    cout << "Second method of display a vector\n";

    vector<int>::iterator it;

    cout << "Different types of iterarors are as follows\n";

    cout << "Type: 1\n";
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "\n";
    }

    cout << "Type: 2\n";
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << "\n";
    }

    cout << "Type: 3\n";
    for (auto it = v.cbegin(); it != v.cend(); it++)
    {
        cout << *it << "\n";
    }

    cout << "Type: 4\n";
    for (auto it = v.crbegin(); it != v.crend(); it++)
    {
        cout << *it << "\n";
    }

    cout << "Third method of display a vector\n";

    for (auto element : v)
    {
        cout << element << "\n";
    }

    cout << "Size of Vector: " << v.size();
    cout << "\nMaximum Size of vector: " << v.max_size();
    cout << "\nCapacity of Vector: " << v.capacity();

    cout << "Vector V Befor Swap\n";
    for (auto element : v)
    {
        cout << element << "\n";
    }

    cout << "Vector V2 Befor Swap\n";
    for (auto element : v2)
    {
        cout << element << "\n";
    }

    cout << "Func to Swap data of two vectors\n";

    swap(v, v2);

    cout << "Vector V After Swap\n";
    for (auto element : v)
    {
        cout << element << "\n";
    }

    cout << "Vector V2 After Swap\n";
    for (auto element : v2)
    {
        cout << element << "\n";
    }
}