#include <iostream>
#include <stdexcept>

using namespace std;

int DefaultConstructor()
{
    ABQ<int> queue;
    std::string error = "";

    if(queue.getSize() != 0)
    {
        error += "Default size is not 0! ";
    }

    if(queue.getMaxCapacity() != 1)
    {
        error += "Default capacity is not 1! ";
    }

    if(error.empty())
    {
        std::cout << "DefaultConstructor: PASS\n";
        return 2; // Return 2 points directly.
    }
    else
    {
        std::cout << "DefaultConstructor: FAIL\n" << error << "\n\n";
        return 0; // Return 0 for failure.
    }
}


int ConstructorWithCapacity()
{
    ABQ<int> queue(5);
    std::string error = "";

    if (queue.getMaxCapacity() != 5) {
        error += "Specified capacity is not 5!";
    }

    if (queue.getSize() != 0) {
        error += "Size incorrect! Expected: 0 Actual: " + std::to_string(queue.getSize());
    }

    if (error.empty()) {
        std::cout << "ConstructorWithCapacity: PASS\n";
        return 2;
    } else {
        std::cout << "ConstructorWithCapacity: FAIL\n" << error << "\n\n";
        return 0;
    }
}

int DequeueEmpty()
{
    ABQ<int> queue;
    std::string error = "";

    try
    {
        queue.dequeue();
        error = "Dequeue didn't throw exception on empty queue!";
    }
    catch(const std::runtime_error& e)
    {
        // Expected exception
    }

    if (error.empty()) {
        std::cout << "DequeueEmpty: PASS\n";
        return 1;
    } else {
        std::cout << "DequeueEmpty: FAIL\n" << error << "\n\n";
        return 0;
    }
}


int DequeueOrder()
{
    ABQ<int> queue;
    std::string error = "";

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    if (queue.dequeue() != 1 || queue.dequeue() != 2 || queue.dequeue() != 3) {
        error = "Dequeue order is incorrect!";
    }

    if (error.empty()) {
        std::cout << "DequeueOrder: PASS\n";
        return 2;
    } else {
        std::cout << "DequeueOrder: FAIL\n" << error << "\n\n";
        return 0;
    }
}

int DequeueResize()
{
    ABQ<int> queue;
    std::string error = "";

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.dequeue();
    if (queue.getSize() != 2) {
        error += "\nSize incorrect! Size should be 2, actual size: " + std::to_string(queue.getSize());
    }
    if (queue.getMaxCapacity() != 4) {
        error += "\nCapacity incorrect! Capacity should be 4, actual capacity: " + std::to_string(queue.getMaxCapacity());
    }

    queue.dequeue();
    if (queue.getSize() != 1) {
        error += "\nSize incorrect! Size should be 1, actual size: " + std::to_string(queue.getSize());
    }
    if (queue.getMaxCapacity() != 2) {
        error += "\nCapacity incorrect! Capacity should be 2, actual capacity: " + std::to_string(queue.getMaxCapacity());
    }

    int val = queue.peek();
    if (val != 3) {
        error += "\nFront value incorrect! Expected: 3, Actual: " + std::to_string(val);
    }

    queue.dequeue();
    if (queue.getSize() != 0) {
        error += "\nSize incorrect! Size should be 0, actual size: " + std::to_string(queue.getSize());
    }
    if (queue.getMaxCapacity() != 1) {
        error += "\nCapacity incorrect! Capacity should be 1, actual capacity: " + std::to_string(queue.getMaxCapacity());
    }

    if (error.empty()) {
        std::cout << "DequeueResize: PASS\n";
        return 2;
    } else {
        std::cout << "DequeueResize: FAIL" << error << "\n";
        return 0;
    }
}

int EnqueueResize()
{
    ABQ<int> queue;
    bool test_passed = true;


    std::string error = "";

    queue.enqueue(1);
    if (queue.getSize() != 1) {
        error += "\nSize incorrect! Size should be 1, actual size: " + std::to_string(queue.getSize());
        test_passed = false;
    }



    queue.enqueue(2);
    if (queue.getSize() != 2) {
        error += "\nSize incorrect! Size should be 2, actual size: " + std::to_string(queue.getSize());
        test_passed = false;
    }
    queue.enqueue(3);

    if (queue.getSize() != 3) {
        error += "\nSize incorrect! Size should be 3, actual size: " + std::to_string(queue.getSize());
        test_passed = false;
    }
    if (queue.getMaxCapacity() != 4) {
        error += "\nCapacity incorrect! Capacity should be 4, actual capacity: " + std::to_string(queue.getMaxCapacity());
        test_passed = false;
    }


    if(test_passed)
    {
        std::cout << "EnqueueResize: PASS\n";
        return 2;
    }
    else
    {
        std::cout << "EnqueueResize: FAIL\n";
        return 0;
    }
}

int PeekEmpty() 
{
    ABQ<int> queue;
    std::string error = "";

    try {
        queue.peek();
        error = "No error thrown when peeking at an empty ABQ.";
    } catch (const runtime_error& ex) {
        // Expected exception
    }

    if (error.empty()) {
        std::cout << "PeekEmpty: PASS - Proper error thrown when peeking at an empty ABQ.\n";
        return 1;
    } else {
        std::cout << "PeekEmpty: FAIL\n" << error << "\n";
        return 0;
    }
}

int PeekMultiple() {
    ABQ<int> queue;
    std::string error = "";

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    if (queue.peek() != 1) {
        error += "Expected: 1, Actual: " + std::to_string(queue.peek()) + ".\n";
    }
    queue.dequeue();

    if (queue.peek() != 2) {
        error += "Expected: 2, Actual: " + std::to_string(queue.peek()) + ".\n";
    }
    queue.dequeue();

    if (queue.peek() != 3) {
        error += "Expected: 3, Actual: " + std::to_string(queue.peek()) + ".\n";
    }

    if (error.empty()) {
        std::cout << "PeekMultiple: PASS - Items peeked at properly in sequence.\n";
        return 2;
    } else {
        std::cout << "PeekMultiple: FAIL\n" << error << "\n";
        return 0;
    }
}
