#ifndef WT901_H
#define WT901_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

void set_rsv_buf(uint8_t *, uint8_t, uint8_t *, uint8_t);
uint8_t get_rsv_size1();
uint8_t get_rsv_size2();
void clear_rsv_size();
void WT901_rsv_int();


#endif	//WT901_H
/**
 End of File
*/