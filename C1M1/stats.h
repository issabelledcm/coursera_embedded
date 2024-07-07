#ifndef __STATS_H__
#define __STATS_H__

typedef struct stats{
    uint8_t *numArray;
    uint8_t arrayLength;
    uint8_t median;
    uint8_t mean;
    uint8_t max;
    uint8_t min;
} stat;

void print_statistics(stat ArrayStats);
void print_array(uint8_t *arrayPrt, uint8_t arrayLength);
void sort_array(uint8_t *arrayPrt, uint8_t arrayLength);
uint8_t find_min(uint8_t *arrayPrt, uint8_t arrayLength);
uint8_t find_max(uint8_t *arrayPrt, uint8_t arrayLength);
uint8_t find_mean(uint8_t *arrayPrt, uint8_t arrayLength);
uint8_t find_median(uint8_t *arrayPrt, uint8_t arrayLength);


#endif /* __STATS_H__ */