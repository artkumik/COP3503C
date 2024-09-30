///////////////////////////////////////////////////////////////////////////////
///////////////////////ONLY WORK IN THIS FILE//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

using namespace std;

template<typename T>

class ABQ{
  private:
    T* array;
    int capacity;
    int curr_size;
  
  public:
    ABQ(){
      capacity = 1;
      curr_size = 0;
      array = new T[1];
    }

    ABQ(int new_capacity){
      capacity = new_capacity;
      curr_size = 0;
      array = new T[capacity];
    }

    ABQ(const ABQ &d){}

    ABQ &operator=(const ABQ &d){}

    ~ABQ(){
      delete[] array;
    }

    void enqueue(T data){
      if (curr_size == capacity){
        capacity *= 2;
        T* new_array = new T[capacity];
        for(int i = 0; i < curr_size; i+=1){
          new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
      }

      array[curr_size] = data;
      curr_size ++;
    }

    T dequeue(){
      if(curr_size== 0){
        throw runtime_error("Cannot dequeue from empty queue");
      }

      T first = array[0];
        for (int i = 1; i < curr_size; ++i) {
            array[i - 1] = array[i];
        }
        curr_size--;

        if (curr_size*2 < capacity){
            capacity /= 2;
            T* new_array = new T[capacity];
            for (int i = 0; i < curr_size; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }

        return first;
    }

    T peek(){
      if (curr_size == 0) {
        throw runtime_error("Cannot peek at empty queue");
      }
      return array[0];
    }

    unsigned int getSize(){
      return curr_size;
    }

    unsigned int getMaxCapacity() {
      return capacity;
    }

    T* getData(){
      return array;
    }



};