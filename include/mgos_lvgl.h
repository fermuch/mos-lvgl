#pragma once

#include "mgos_event.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MGOS_LVGL_BASE MGOS_EVENT_BASE('L', 'V', 'G')

enum mgos_pppos_event {
  MGOS_LVGL_EARLY = MGOS_LVGL_BASE,   // ev_data: NULL
  MGOS_LVGL_AFTER_INIT,               // ev_data: NULL
};

#ifdef __cplusplus
}
#endif