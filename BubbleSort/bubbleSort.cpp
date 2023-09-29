#include <iostream>
#include <array>

template <typename T,size_t size>
void bubble_sort(std::array<T,size>& items){
    size_t i{0};
    bool permutations;
    do{
        permutations = false;
        for(size_t j{0};j < items.size() - i - 1;++j){
            if(items[j] >= items[j + 1]){
                T hold{items[j]};
                items[j] = items[j + 1];
                items[j + 1] = hold;
                permutations = true;
            }
        }
        ++i;
    }while(permutations);
}

int main(){
    const size_t size{10};
    std::array<int,size> integers;
    std::cout<<"\nEnter 10 integers:\n";
    for(size_t i{0};i < size;++i){
        std::cin>>integers[i];
    }

    std::cout<<"\nAfter sorting,array integers contains:\n";
    bubble_sort(integers);
    for(size_t i{0};i < size;++i){
        std::cout<<integers[i]<<' ';
    }
}