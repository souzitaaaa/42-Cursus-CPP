#include "easyfind.hpp"

void study()
{
    std::cout << YELLOW << "------------------STUDY------------------" << RESET << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec;

    std::cout << GREEN << "[ .empty(); .assign(); .size() ]" << RESET << std::endl;
    vec.empty()
        ? std::cout << "Vector is empty" << std::endl
        : std::cout << "Vector is not empty" << std::endl;
    vec.assign(arr, arr + sizeof(arr) / sizeof(int));
    vec.empty()
        ? std::cout << "Vector is empty" << std::endl
        : std::cout << "Vector is not empty" << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;

    std::cout << GREEN << "[ .at(i) ]" << RESET << std::endl;
    std::cout << "Element at index 2: " << vec.at(2) << std::endl;

    std::cout << GREEN << "[ .front(); .back() ]" << RESET << std::endl;
    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    std::cout << GREEN << "[ .capacity(); .reserve(x) ]" << RESET << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    vec.reserve(10);
    std::cout << "Capacity after reserve: " << vec.capacity() << std::endl;
    std::cout << "Size after reserve: " << vec.size() << std::endl;

    std::cout << GREEN << "[ .clear() ]" << RESET << std::endl;
    vec.clear();
    vec.empty()
        ? std::cout << "Vector is empty" << std::endl
        : std::cout << "Vector is not empty" << std::endl;
    vec.assign(arr, arr + sizeof(arr) / sizeof(int));
    std::cout << GREEN << "[ .insert(i, val); .erase(i) ]" << RESET << std::endl;
    std::cout << "First element: " << vec.front() << std::endl;
    vec.insert(vec.begin(), 0);
    std::cout << "First element after insert: " << vec.front() << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    vec.erase(vec.begin());
    std::cout << "First element after erase: " << vec.front() << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;

    std::cout << GREEN << "[ .push_back(val); .pop_back() ]" << RESET << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;
    vec.push_back(6);
    std::cout << "Last element before push_back: " << vec.back() << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    vec.pop_back();
    std::cout << "Last element after pop_back: " << vec.back() << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;

    std::cout << GREEN << "[ .resize(x) ]" << RESET << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;
    vec.resize(4);
    std::cout << "Last element after resize smaller: " << vec.back() << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    vec.push_back(5);
    vec.resize(6);
    std::cout << "Last element after resize bigger: " << vec.back() << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    vec.pop_back();

    std::cout << GREEN << "[ .swap(vector) ]" << RESET << std::endl;
    int arr2[] = {5, 4, 3, 2, 1};
    std::vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    std::cout << "Last element: " << vec.back() << std::endl;
    vec.swap(vec2);
    std::cout << "Last element after swap: " << vec.back() << std::endl;
    vec.assign(arr, arr + sizeof(arr) / sizeof(int));

    std::cout << GREEN << "[ std::find() ]" << RESET << std::endl;
    // Takes two iterators that define the range to search in the container
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), vec.at(2));
    // If the value is found within the range, std::find() retuns an iterator pointing
    //      to the first occurence of the value
    // If the value is not found it returns the iterator end
    // Allowing us to compare the it to the vec.end() to understand if the value was found

    std::cout << "it: " << *it << std::endl;
    it != vec.end()
        ? std::cout << "Found: " << *it << std::endl
        : std::cout << "Value not found" << std::endl;
};

int main()
{
    // study();
    std::cout << YELLOW << "------------------EASY FINDS------------------" << RESET << std::endl;
    {
        std::cout << GREEN << "[ Vector ]" << RESET << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
        printC(vec);
        try
        {
            std::vector<int>::iterator it = easyfind(vec, 5);
            VECTOR_VAL_INDEX(*it, vec)
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << GREEN << "[ List (Double linked list) ]" << RESET << std::endl;
        int arr[] = {5, 4, 3, 2, 1};
        std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
        printC(lst);
        try
        {
            std::list<int>::iterator it = easyfind(lst, 5);
            LIST_VAL_INDEX(*it, lst)
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    {
        std::cout << GREEN << "[ Vector not INT ]" << RESET << std::endl;
        char arr[] = {'a', 'b', 'c', 'd', 'e'};
        std::vector<char> vec(arr, arr + sizeof(arr) / sizeof(char));
        printC(vec);
        try
        {
            std::vector<char>::iterator it = easyfind(vec, 'c');
            VECTOR_VAL_INDEX(*it, vec)
        }
        catch (const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}