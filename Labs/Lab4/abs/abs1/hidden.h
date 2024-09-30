#include <iostream>
#include <stdexcept>
//stack
using namespace std;

// Unit test (1 point)
bool testDefaultConstructorAndGetSize() {
    ABS<int> stack;
    if(stack.getSize() != 0) {
        cout << "Default size is not 0!\n";
        return false;
    }

    if(stack.getMaxCapacity() != 1) {
        cout << "Default capacity is not 1!\n";
        return false;
    }
    return true;
}

// Unit test (2 points)
bool testParameterizedConstructor() {
    ABS<int> stack(10);
    if(stack.getSize() != 0) {
        cout << "Size incorrect!\n";
        return false;
    }

    if(stack.getMaxCapacity() != 10) {
        cout << "Capacity not the same as constructor parameter!\n";
        return false;
    }
    return true;
}

// Unit test (2 points)
bool testResizingOnPush() {
    ABS<int> stack;
    stack.push(1);
    if(stack.getSize() != 1) {
        cout << "Size incorrect! Expected: 1 Actual: " << stack.getSize() << "\n";
        return false;
    }
    if(stack.getMaxCapacity() != 1) {
        cout << "Capacity incorrect! Expected: 1 Actual: " << stack.getMaxCapacity() << "\n";
        return false;
    }

    stack.push(2);
    if(stack.getSize() != 2) {
        cout << "Size incorrect! Expected: 2 Actual: " << stack.getSize() << "\n";
        return false;
    }
    if(stack.getMaxCapacity() != 2) {
        cout << "Capacity incorrect! Expected: 2 Actual: " << stack.getMaxCapacity() << "\n";
        return false;
    }

    stack.push(3);
    if(stack.getSize() != 3) {
        cout << "Size incorrect! Expected: 3 Actual: " << stack.getSize() << "\n";
        return false;
    }
    if(stack.getMaxCapacity() != 4) {
        cout << "Capacity incorrect! Expected: 4 Actual: " << stack.getMaxCapacity() << "\n";
        return false;
    }

    return true;
}

// Unit test (2 points)
bool testPoppingFromABS() {
    ABS<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    int result = stack.pop();
    if(result != 3) {
        cout << "Item not popped properly! Expected: 3 Actual: " << result << "\n";
        return false;
    }
    result = stack.pop();
    if(result != 2) {
        cout << "Item not popped properly! Expected: 2 Actual: " << result << "\n";
        return false;
    }
    result = stack.pop();
    if(result != 1) {
        cout << "Item not popped properly! Expected: 1 Actual: " << result << "\n";
        return false;
    }

    return true;
}

// Unit test (1 point)
bool testPoppingFromEmptyABS() {
    ABS<int> stack;

    try {
        stack.pop();
    } catch(runtime_error& ex) {
        return true;
    }
    cout << "No error thrown!\n";
    return false;
}

// Unit test (1 point)
bool testPeekingAtEmptyABS() {
    ABS<int> stack;

    try {
        stack.peek();
    } catch(runtime_error& ex) {
        return true;
    }
    cout << "No error thrown!\n";
    return false;
}

// Unit test (2 points)
bool testPeekingAtContents() {
    ABS<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    if(stack.peek() != 3) {
        cout << "Item not peeked at properly! Expected: 3 Actual: " << stack.peek() << "\n";
        return false;
    }
    stack.pop();
    if(stack.peek() != 2) {
        cout << "Item not peeked at properly! Expected: 2 Actual: " << stack.peek() << "\n";
        return false;
    }
    stack.pop();
    if(stack.peek() != 1) {
        cout << "Item not peeked at properly! Expected: 1 Actual: " << stack.peek() << "\n";
        return false;
    }

    return true;
}

// Unit test (2 points)
bool testProperResizingAfterPopping() {
    ABS<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.pop();
    if(stack.getSize() != 2) {
        cout << "Size incorrect! Expected: 2 Actual: " << stack.getSize() << "\n";
        return false;
    }
    if(stack.getMaxCapacity() != 4) {
        cout << "Capacity incorrect! Expected: 4 Actual: " << stack.getMaxCapacity() << "\n";
        return false;
    }

    stack.pop();
    if(stack.getSize() != 1) {
        cout << "Size incorrect! Expected: 1 Actual: " << stack.getSize() << "\n";
        return false;
    }
    if(stack.getMaxCapacity() != 2) {
        cout << "Capacity incorrect! Expected: 2 Actual: " << stack.getMaxCapacity() << "\n";
        return false;
    }

    stack.pop();
    if(stack.getSize() != 0) {
        cout << "Size incorrect! Expected: 0 Actual: " << stack.getSize() << "\n";
        return false;
    }
    if(stack.getMaxCapacity() != 1) {
        cout << "Capacity incorrect! Expected: 1 Actual: " << stack.getMaxCapacity() << "\n";
        return false;
    }

    return true;
}