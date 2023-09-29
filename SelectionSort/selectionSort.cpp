#include <iostream>
#include <array>


template <typename T,size_t size>
void selection_sort(std::array<T,size>& items){
    for(size_t start{0};start < items.size() - 1;++start){
        size_t indexOfMinimum{start};
        for(size_t i{start + 1};i < items.size();++i){
            if(items[indexOfMinimum] > items[i]){
                indexOfMinimum = i;
            }
        }

        T hold=items[start];
        items[start] = items[indexOfMinimum];
        items[indexOfMinimum] = hold;
    }
}


int main(){
    
    const size_t size{10};
    std::array<int,size> integers;
    std::cout<<"Enter 10 numbers:\n";
    for(size_t i{0};i < size;++i){
        std::cin>>integers[i];
    }

    std::cout<<"\nAfter sorting,array integers contains:\n";
    selection_sort(integers);

    for(size_t i{0};i < size;++i){
        std::cout<<integers[i]<<' ';
    }
}