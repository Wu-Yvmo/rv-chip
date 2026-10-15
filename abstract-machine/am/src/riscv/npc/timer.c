#include <am.h>

#define TIMER_ADDR_HI 0x20000004ul
#define TIMER_ADDR_LO 0x20000000ul

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t timer_hi = *(volatile uint32_t*)TIMER_ADDR_HI;
  uint32_t timer_lo = *(volatile uint32_t*)TIMER_ADDR_LO;
  uptime->us = (uint64_t)timer_hi << 32 | timer_lo;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
