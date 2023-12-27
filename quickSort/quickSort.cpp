#include <iostream>
#include <array>

template <typename T,size_t  size>
int partition(std::array<T,size>& items,int low,int high){
    int index{low - 1};
    T pivot{items[high]};
    for(int j{low};j < high;++j){
        if(items[j] <= pivot){
            index = index + 1;
            std::swap(items[index], items[j]);
        }
    }

    std::swap(items[index + 1], items[high]);
    return index + 1;
}

template <typename T,size_t size>
void quick_sort(std::array<T,size>& items, int low, int high){
    while(low < high){
        int index = partition(items,low,high);
        quick_sort(items,low,index - 1);
        low = index + 1;  
    }
}

int main(){
    const size_t size{10};
    std::array<int,size> integers;
    std::cout<<"Enter 10 integers:\n";
    for(size_t i{0};i < size;++i){
        std::cin>>integers[i];
    }

    std::cout<<"\nAfter sorting,array integers contains:\n";
    quick_sort(integers,0,integers.size() - 1);
    for(size_t i{0};i < size;++i){
        std::cout<<integers[i]<<' ';
    }
    
}