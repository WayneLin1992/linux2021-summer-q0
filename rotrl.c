#include <stdint.h>
#include <stdint.h>
#include <stdio.h>  
#define __DECLARE_ROTATE(bits, type)                   \
    static inline type rotl##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v << c) | (v >> (-c & mask));          \
    }                                                  \
                                                       \
    static inline type rotr##bits(const type v, int c) \
    {                                                  \
        const int mask = (bits) - (1);                 \
        c &= mask;                                     \
                                                       \
        return (v >> c) | (v << (-c & mask));          \
    }
#define DECLARE_ROTATE(bits) __DECLARE_ROTATE(bits, uint##bits##_t)
static inline uint8_t rotl8(const uint8_t v, int c) {
    const int mask = (8) - (1);
    c &= mask;
    return (v << c) | (v >> (-c & mask));
}
static inline uint8_t rotr8(const uint8_t v, int c) {
    const int mask = (8) - (1);
    c &= mask;
    return (v >> c) | (v << (-c & mask));
};
int main(){
//    DECLARE_ROTATE(64);
//    DECLARE_ROTATE(32);
//    DECLARE_ROTATE(16);
//    DECLARE_ROTATE(8);
printf("rotl8 %d \n", rotl8(16, 1));
printf("rotr8 %d \n", rotr8(16, 1));
}
