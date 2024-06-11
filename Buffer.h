#ifndef ___BUFFER_H___
#define ___BUFFER_H___

#include <iterator>
#include <string>

template <int SIZE>
class Buffer {
  char buffer[SIZE]; // circular array
  size_t head; // index/position of the most recent character in the buffer
  size_t size; // number of elements in the buffer

public:
  Buffer() : head(0), size(0) {}

  void Add(char ch) {
    buffer[head] = ch;
    head = (head+1) % SIZE;
    size = size+1 < SIZE
      ? size+1
      : SIZE; 
  }

  void Add(const std::string& s) {
    const size_t cs = s.size();
    for (size_t i = 0; i < cs; ++i) {
      Add(s[i]);
    }
  }

  bool IsEmpty() const {
    return size == 0;
  }

  std::string GetBuffer() const {
    std::string res;
    res.reserve(size+1);

    if (size < SIZE) {
      for (size_t i = 0; i < head; ++i) {
        res += buffer[i];
      }
    } else {
      size_t ph = head;
      for (size_t i = 0; i < SIZE; ++i) {
        res += buffer[ph];
        ph = (ph + 1) % SIZE;
      }
    }

    return res;
  }
};

#endif // ___BUFFER_H___
