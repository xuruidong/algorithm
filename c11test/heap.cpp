#include <vector>
#include <iostream>

#include "heap.h"
#include "utils.h"


int heap::insert(int n)
{
    if(current_size >= array.size()){
        //
    }
    int ind = ++current_size;
    while(ind>1){
        if(array[ind] > array[(ind-1)>>1]){
            std::swap(array[ind], array[(ind-1)>>1]);
            ind = (ind-1)>>1;
        }
        else{
            break;
        }
    }
    return 0;
}

int heap::top()
{
    if(current_size){

    }
}
int heap::pop()
{

}

int heap::heapify(int index)
{
    if(index >= current_size){
        return -1;
    }
    do{
        int left = index*2+1;
        int large = left+1<current_size && array[left] < array[left+1]?left+1:left;
        std::swap(array[large], array[index]);
        index = large;
    }while(index<current_size);
    return 0;
}


int heap_insert(std::vector<int> &array, int index)
{
    while(array[index] >array[(index-1)/2]){
        std::swap(array[index], array[(index-1)/2]);
        index = (index-1)/2;
    }

}

int heapify(std::vector<int> &array, int index, int current_size)
{
    if(index >= current_size){
        return -1;
    }
    /*
    int left = index*2+1;
    int large = ((left+1<=current_size) && (array[left] < array[left+1]))?left+1:left;
    while(large <= current_size){

        std::swap(array[large], array[index]);
        index = large;
        left = index*2+1;
        large = ((left+1<=current_size) && (array[left] < array[left+1]))?left+1:left;
        if(array[large]<=array[index]){
            break;
        }
    }
    */
    int tmp = array[index];
    int left = index*2+1;
    int large;
    for(;left<current_size;){
        large = ((left+1 < current_size) && (array[left]<array[left+1]))?left+1:left;
        //std::cout<<"index="<<index<<" large="<<large<<std::endl;
        if(array[large] > array[index]){
            //array[index] = array[large];
            std::swap(array[large], array[index]);
        }
        else{
            //array[large] = tmp;
            break;
        }
        //vector_print(array);
        index = large;
        left = index*2+1;
    }
    /*
    while(left <= current_size){
        large = ((left+1 <= current_size) && (array[left]<array[left+1]))?left+1:left;
        if(array[large] > array[index]){
            std::swap(array[large], array[index]);
        }
        else{
            break;
        }
        index = large;
        left = index*2+1;
    }
    */
    return 0;
}

int heap_sort(std::vector<int> &array, int current_size)
{
    //std::cout<<"------"<<std::endl;
    //vector_print(array);
    if(current_size < 2){
        return 0;
    }
    for(int i=0; i<current_size; ++i){
        heap_insert(array, i);
    }
    //vector_print(array);
    int i=0;
    while(current_size>0){
        std::swap(array[0], array[current_size-1]);
        //std::cout<<"after swap  ";
        //vector_print(array);
        //std::cout<<"size: "<<current_size-1<<std::endl;
        heapify(array, 0, --current_size);
        //std::cout<<"after modify ";
        //vector_print(array);

    }
}

