///////////////////////////////////////////////////////////////////////////////
///////////////////////ONLY WORK IN THIS FILE//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

template <typename T>

class ABS{
  private:
    T* array;
    int capacity;
    int curr_size;

  public:
    ABS(){
      capacity = 1;
      curr_size = 0;
      array = new T[1]; // need for memory leak, array of size capacity
    }

    ABS(int new_capacity){
      capacity = new_capacity;
      curr_size = 0;
      array = new T[capacity];
    }

    ABS(const ABS &d){}

    ABS &operator=(const ABS &d){}

    ~ABS() {
      delete[] array;   
    }

    int getSize(){
      return curr_size;
    }

    int getMaxCapacity(){
      return capacity;
    }
  
    void push(T data){
      if (capacity == curr_size){
        capacity *= 2;

        T* new_array = new T[capacity];
        for (int i = 0; i < curr_size; ++i) {
          new_array[i] = array[i];            
        }
        delete[] array;
        array = new_array;
      }
      
      array[curr_size] = data;
      curr_size+=1; // after cause im dum
    }

    T pop() {
      if (curr_size <= 0) {
          throw runtime_error("Cannot pop from an empty array."); // Handle empty case
      }

      T data = array[curr_size - 1]; // Get the last element
      curr_size--; // Decrease the size

      // Resize if necessary
      if (curr_size * 2 < capacity ) {
          capacity /= 2; // Correctly divide the capacity

          // Only resize if the new capacity is greater than 0
          if (capacity > 0) {
              T* new_array = new T[capacity];
              for (int i = 0; i < curr_size; ++i) {
                  new_array[i] = array[i]; // Copy existing elements
              }

              delete[] array; // Free the old array's memory
              array = new_array; // Update to the new array
          }
      }

      return data; // Return the popped data
    }

    T peek(){
      if (curr_size == 0){
        throw runtime_error("Cannot peek at a stack of size 0");
      }else{
        return array[curr_size - 1];
      }
    }

    T* getData(){
      return array;
    }
};