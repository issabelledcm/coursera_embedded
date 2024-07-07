#include <stdio.h>
#include <stdint.h>
#include "stats.h"


#define SIZE (40)

void main() {

      unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90,};

    stat Array;


  Array.numArray = test;
  Array.arrayLength = SIZE;
  Array.max = 0;
  Array.min = 0xFF;
  Array.mean = 0;
  Array.median = 0;

  sort_array(Array.numArray, Array.arrayLength);
  Array.min = find_min(Array.numArray, Array.arrayLength);
  Array.max = find_max(Array.numArray, Array.arrayLength);
  Array.mean = find_mean(Array.numArray, Array.arrayLength);
  Array.median = find_median(Array.numArray, Array.arrayLength);
  print_array(Array.numArray, Array.arrayLength);
  print_statistics(Array);
}

void print_statistics(stat ArrayStat){
  printf("Array Min: %u\n", ArrayStat.min);
  printf("Array Max: %u\n", ArrayStat.max);
  printf("Array Mean: %u\n", ArrayStat.mean);
  printf("Array Median: %u\n", ArrayStat.median);
  printf("Array Size: %u\n", ArrayStat.arrayLength);
}

void print_array(uint8_t *arrayPrt, uint8_t arrayLength){

  for(uint8_t i=0; i<arrayLength; i++){
    printf("array[%u]: %u\n", i, *(arrayPrt + sizeof(char)*i));
  }
  printf("\n");
  return;
}
void sort_array(uint8_t *arrayPrt, uint8_t arrayLength){
  uint8_t i, j = 0;
  uint8_t temp;

  for(i=0; i<arrayLength; i++){
    for(j=i+1; j<arrayLength; j++){
      if(arrayPrt[i]<arrayPrt[j]){
        temp = arrayPrt[i];
        arrayPrt[i]=arrayPrt[j];
        arrayPrt[j]=temp;
      }
    }
  }
}

uint8_t find_min(uint8_t *arrayPrt, uint8_t arrayLength){
  uint8_t minValue=0xFF;

  for (uint8_t i=0; i<arrayLength; i++){
    if (arrayPrt[i] < minValue){
      minValue = arrayPrt[i];
    }
  }

  return minValue;
}

uint8_t find_max(uint8_t *arrayPrt, uint8_t arrayLength){
  uint8_t maxValue=0;

  for (uint8_t i=0; i<arrayLength; i++){
    if (arrayPrt[i] > maxValue){
      maxValue = arrayPrt[i];
    }
  }

  return maxValue;
}

uint8_t find_mean(uint8_t *arrayPrt, uint8_t arrayLength){
  uint32_t avg=0;


  for(uint8_t i=0; i<arrayLength; i++){
    avg+= arrayPrt[i];
  }
  

  return (avg/arrayLength);
}

uint8_t find_median(uint8_t *arrayPrt, uint8_t arrayLength){

  sort_array(arrayPtr, arrayLength);


  if (arrayLength%2){
    return arrayPrt[arrayLength/2];
  }


  uint8_t avg = (arrayPrt[arrayLength/2 - 1]+arrayPrt[arrayLength/2])/2;
  return avg;
}

