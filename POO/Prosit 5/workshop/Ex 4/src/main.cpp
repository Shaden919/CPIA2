#include <iostream>

using namespace std;

template<typename T> class DynamicArray {
private:
  int count;
  int size;

  T **els;

  const float REFIT_THRESHOLD = 0.8;
  const float RESIZE_THRESHOLD = 0.8;

private:
  void resize(int size) {
    try {
      T **temp;

      this->size = size;
      temp = new T *[size];
      for (int i = 0; i < count; i++) {
        temp[i] = els[i];
      }

      delete[] els;
      els = temp;
    } catch (std::bad_alloc e) {
      size = size / 2;
    }
  }
  void fit() { resize(count); }

public:
  DynamicArray(int size = 1) {
    count = 0;
    els = new T *[size];
  }
  int add(T *el) {
    if (count >= RESIZE_THRESHOLD * size) {
      resize(size * 2);
    }

    els[count] = el;

    return count++;
  }
  T *remove(int i) {
    T *ptr = nullptr;

    if(0 <= i < count) {
      ptr = els[i];
      els[i] = els[--count];

      if (count < REFIT_THRESHOLD * size) {
        fit();
      }
    }
    
    return ptr;
  }
  T *get(int i) { return els[i]; }
  void print() {
    cout << "[";
    if(count > 0) {
      for(int i = 0; i < count - 1; i++) {
        cout << *els[i] << ",";
      }
      cout << *els[count - 1];
      
    }
    cout << "]" << endl;
  }
};

int main() {
  DynamicArray<int> arr;

  int a = 2, b = 3, c = 5;

  arr.add(&a);
  arr.add(&b);
  arr.add(&c);

  arr.remove(1);

  arr.print();

  DynamicArray<string> arr2;

  string d = "hello", e = "poop", f = " world";

  arr2.add(&d);
  arr2.add(&e);
  arr2.add(&f);

  arr2.remove(1);

  arr2.print();

  return 0;
}