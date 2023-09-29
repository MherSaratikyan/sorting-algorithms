#include <iostream>
#include <array>

template <typename T,size_t  size>
int partition(std::array<T,size>& items,size_t low,size_t high){
    size_t index{low - 1};
    T pivot{items[high]};
    for(size_t j{low};j <= high;++j){
        if(items[j] <= pivot){
            ++index;
            T hold{items[j]};
            items[j] = items[index];
            items[index] = hold;
        }
    }

    return index;
}

template <typename T,size_t size>
void quick_sort(std::array<T,size>& items,size_t low,size_t high){
    if(high - low >= 1){
        int index = partition(items,low,high);

        if(index > low){
            quick_sort(items,low,index - 1);
        }

        if(index < high){
            quick_sort(items,index + 1,high);
        }
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