#include <iostream>
#include <array>

template <typename T,size_t size>
void insertion_sort(std::array<T,size>& items){
    for(size_t next{1};next < items.size();++next){
        T insertValue{items[next]};
        size_t index{next};

        while((index > 0) && items[index - 1] > insertValue){
            items[index] = items[index - 1];
            --index;
        }

        items[index] = insertValue;
    }
}

int main(){
    const size_t size{10};
    std::array<int,size> integers;
    std::cout<<"ENter 10 numbers:\n";
    for(size_t i{0};i < size;++i){
        std::cin>>integers[i];
    }

    std::cout<<"\nArray integers after sorting contains:\n";
    insertion_sort(integers);
    for(size_t i{0};i < size;++i){
        std::cout<<integers[i]<<' ';
    }
}