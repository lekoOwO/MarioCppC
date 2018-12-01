#ifndef _CSTDINT_
#define _CSTDINT_
#include <cstdint>
#endif

#ifndef _STRING_
#define _STRING_
#include <string>
#endif

typedef std::uint64_t hash_t;  
   
constexpr hash_t prime = 0x100000001B3ull;  
constexpr hash_t basis = 0xCBF29CE484222325ull;  
  
hash_t hash_(char const* str)  
{  
    hash_t ret{basis};  
   
    while(*str){  
        ret ^= *str;  
        ret *= prime;  
        str++;  
    }  
   
    return ret;  
}  

hash_t hash_(std::string str)  
{
    auto x = str.c_str();
    hash_t ret{basis};  
   
    while(*x){  
        ret ^= *x;  
        ret *= prime;  
        x++;  
    }  
   
    return ret;  
}  

constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)  
{  
    return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;  
}  

constexpr unsigned long long operator "" _hash(char const* p, size_t)  
{  
    return hash_compile_time(p);  
}  