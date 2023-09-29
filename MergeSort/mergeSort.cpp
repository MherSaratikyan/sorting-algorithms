#include <iostream>
#include <array>

template <typename T,size_t size>
void merge(std::array<T,size>& items,size_t left,size_t middle1,size_t middle2,size_t right){
    size_t leftIndex{left};
    size_t rightIndex{middle2};
    size_t combinedIndex{left};
    std::array<T,size> combined;

    while((leftIndex <= middle1) && (rightIndex <= right)){
        if(items[leftIndex] <= items[rightIndex]){
            combined[combinedIndex++] = items[leftIndex++];
        }else{
            combined[combinedIndex++] = items[rightIndex++];
        }
    }

    if(leftIndex == middle2){
        while(rightIndex <= right){
            combined[combinedIndex++] = items[rightIndex++];
        }
    }else{
        while(leftIndex <= middle1){
            combined[combinedIndex++] = items[leftIndex++];
        }
    }

    for(size_t i{left};i <= right;++i){
        items[i] = combined[i];
    }
}

template <typename T,size_t size>
void merge_sort(std::array<T,size>& items,size_t low,size_t high){
    if(high - low >= 1){
        size_t middle1{(low + high) / 2};
        size_t middle2{middle1 + 1};

        merge_sort(items,low,middle1);
        merge_sort(items,middle2,high);

        merge(items,low,middle1,middle2,high);
    }
}

int main(){
    const size_t size{10};
    std::array<int,size> integers;
    std::cout<<"Enter 10 integers:\n";
    for(size_t i{0};i < size;++i){
        std::cin>>integers[i];
    }

    std::cout<<"\nArray integers after sorting contains:\n";
    merge_sort(integers,0,size - 1);
    for(size_t i{0};i < size;++i){
        std::cout<<integers[i]<<' ';
    }
    return 0;
}