
# Container Methods Explanation

A brief explanation and demonstration of some methods used by containers in C++98

## Sequence Containers (vector, deque, list, forward_list)

We are going to assume that the base container will be this:

```c
int arr[] = {1, 2, 3, 4, 5};
std::vector<int> vec;
```
### .empty()
Returns ``true`` if the vector is empty and ``false`` otherwise
```c
vec.empty()
    ? std::cout << "Vector is empty" << std::endl
    : std::cout << "Vector is not empty" << std::endl;
//output:
    Vector is empty
```

### .assign()
To ``assign values`` from a array to the vector
```c
vec.assign(arr, arr + sizeof(arr) / sizeof(int));
vec.empty()
    ? std::cout << "Vector is empty" << std::endl
    : std::cout << "Vector is not empty" << std::endl;
//output:
    Vector is not empty
```

### .size()
Returns the ``number`` of elements in the vector
```c
std::cout << "Vector size: " << vec.size() << std::endl;
//output:
    Vector size: 5
```

### .at(i)
Returns a ``reference`` to the element at the position ``n`` in the vector with bounds checking

Throws ``std::out_of_range`` expection if ``n`` is out of bounds
```c
std::cout << "Element at index 2: " << vec.at(2) << std::endl;
//output:
    Element at index 2: 3
```

### .front()  && .back()
Returns a ``reference`` to the ``first`` element in the vector and to the ``last`` respectively

```c
std::cout << "First element: " << vec.front() << std::endl;
std::cout << "Last element: " << vec.back() << std::endl;
//output:
    First element: 1
    Last element: 5 
```

### .capacity()  && .reserve(x)
The ``capacity()`` returns the ``size`` of the storage space currently allocated for the vector

The ``reserve(x)`` requests that the vector capacity be at least enough to contain ``n`` elements

```c
std::cout << "Capacity: " << vec.capacity() << std::endl;
vec.reserve(10);
std::cout << "Capacity after reserve: " << vec.capacity() << std::endl;
std::cout << "Size after reserve: " << vec.size() << std::endl;
//output:
    Capacity: 5
    Capacity after reserve: 10
    Size after reserve: 5
```

### .clear()
Removes ``all`` elements from the vector
```c
vec.clear();
vec.empty()
    ? std::cout << "Vector is empty" << std::endl
    : std::cout << "Vector is not empty" << std::endl;
//output:
    Vector is empty
```

### .insert(i, val)  && .erase(i)
Inserts ``val`` before the element at position ``i`` and removes the element at position ``i`` respectively
```c
std::cout << "First element: " << vec.front() << std::endl;
vec.insert(vec.begin(), 0);
std::cout << "First element after insert: " << vec.front() << std::endl;
std::cout << "Vector size: " << vec.size() << std::endl;
vec.erase(vec.begin());
std::cout << "First element after erase: " << vec.front() << std::endl;
std::cout << "Vector size: " << vec.size() << std::endl;
//output:
    First element: 1
    First element after insert: 0
    Vector size: 6
    First element after erase: 1
    Vector size: 5
```

### .push_back(val); .pop_back()
Adds a new element ``val`` at the ``end`` of the vector, increasing its size by one and removes the ``last`` element from the vector reducing its size by one respectively
```c
std::cout << "Last element: " << vec.back() << std::endl;
vec.push_back(6);
std::cout << "Last element before push_back: " << vec.back() << std::endl;
std::cout << "Vector size: " << vec.size() << std::endl;
vec.pop_back();
std::cout << "Last element after pop_back: " << vec.back() << std::endl;
std::cout << "Vector size: " << vec.size() << std::endl;
//output:
    Last element: 5
    Last element before push_back: 6
    Vector size: 6
    Last element after pop_back: 5
    Vector size: 5
```

### .resize(x)
Resizes the container to contain ``n`` elements
```c
std::cout << "Last element: " << vec.back() << std::endl;
vec.resize(4);
std::cout << "Last element after resize smaller: " << vec.back() << std::endl;
std::cout << "Vector size: " << vec.size() << std::endl;
vec.push_back(5);
vec.resize(6);
std::cout << "Last element after resize bigger: " << vec.back() << std::endl;
std::cout << "Vector size: " << vec.size() << std::endl;
vec.pop_back();
//output:
    Last element: 5
    Last element after resize smaller: 4
    Vector size: 4
    Last element after resize bigger: 0
    Vector size: 6
```

### .swap(cpy)
Swaps the contents of the vector with those of cpy
```c
int arr2[] = {5, 4, 3, 2, 1};
std::vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
std::cout << "Last element: " << vec.back() << std::endl;
vec.swap(vec2);
std::cout << "Last element after swap: " << vec.back() << std::endl;
//output:
    Last element: 5
    Last element after swap: 1
```

### std::find(begin, end, val)
Takes two iterators that ``define the range`` to search in the container

If the value is ``found`` within the range, std::find() retuns an iterator pointing to the first occurence of the ``value``

If the value is ``not found`` it returns the iterator ``end``, allowing us to compare the it to the vec.end() to understand if the value was found
```c
std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), vec.at(2));
it != vec.end()
    ? std::cout << "Found: " << *it << std::endl
    : std::cout << "Value not found" << std::endl;
//output:
    Found: 3
```
