#include <iostream>
#include <vector>

template<typename T>
void maxHeapify(std::vector<T>&, std::size_t, int);

template <typename T>
void buildMaxHeap(std::vector<T>&);

template <typename T>
void heapSort(std::vector<T>&);


int main(){
    const size_t size{10};
    std::vector<int> integers(10);
    std::cout<<"Enter 10 integers:\n";
    for(size_t i{0};i < size;++i){
        std::cin>>integers[i];
    }

    std::cout<<"\nArray integers after sorting contains:\n";
    heapSort(integers);
    for(size_t i{0};i < size;++i){
        std::cout<<integers[i]<<' ';
    }
    return 0;
}

template <typename T>
void maxHeapify(std::vector<T>& arr,std::size_t heapSize, int index){
    int indexOfLeft{ 2 * index + 1};
    int indexOfRight{2 * (index + 1)};
    int indexOfLargest{index};
    if((indexOfLeft < heapSize) && (arr[indexOfLeft] > arr[indexOfLargest])){
        indexOfLargest = indexOfLeft;
    }
    if((indexOfRight < heapSize) && (arr[indexOfRight] > arr[indexOfLargest])){
        indexOfLargest = indexOfRight;
    }
    if(indexOfLargest != index){
        std::swap(arr[indexOfLargest], arr[index]);
        maxHeapify(arr, heapSize, indexOfLargest);
    }
}

template <typename T>
void buildMaxHeap(std::vector<T>& arr){
    int size = arr.size() - 1;
    for(int i = size / 2; i >= 0; --i){
        maxHeapify(arr, size, i);
    }
}

template <typename T>
void heapSort(std::vector<T>& arr){
    buildMaxHeap(arr);
    std::size_t size{arr.size()};
    std::size_t heapSize{size};
    for(std::size_t i{size - 1}; i > 0; --i){
        std::swap(arr[0], arr[i]);
        --heapSize;
        maxHeapify(arr, heapSize, 0);
    }
}
