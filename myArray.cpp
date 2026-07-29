#include <stdexcept>
namespace myLibrary{
    template <typename type, long long int setSize> class array{
        private:
            type* elements;
            long long int size;
        public:
            array();
            array(type x);
            ~array();
            type& operator[](long long int pos);
            type& at(long long int pos);
            long long int getSize();
    };
    template <typename type, long long int setSize> array<type,setSize>::array(){
        size = setSize;
        elements = new type[size];
    }
    template <typename type, long long int setSize> array<type,setSize>::array(type x){
        size = setSize;
        elements = new type[size];
        for (int i = 0; i <size; i++){
            elements[i] = x;
        }
    }
    template <typename type, long long int setSize> array<type,setSize>::~array(){
        delete [] elements;
    }
    template <typename type, long long int setSize> type& array<type,setSize>::operator[](long long int pos){
        return elements[pos];
    }
    template <typename type, long long int setSize> type& array<type,setSize>::at(long long int pos){
        if (pos >= size){
            throw std::out_of_range("Position in at method >= size");
        }else{
            return elements[pos];
        }
    }
    template <typename type, long long int setSize> long long int array<type,setSize>::getSize(){
        return size;
    }
}
