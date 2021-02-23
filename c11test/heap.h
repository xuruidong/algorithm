#ifndef HEAP_H_INCLUDE
#define HEAP_H_INCLUDE

class heap
{
public:
    int insert(int n);
    int pop();
    int top();
    int heapify(int index);

private:
    int current_size;
    std::vector<int> array;
};

int heap_sort(std::vector<int> &array, int current_size);
#endif // HEAP_H_INCLUDE
