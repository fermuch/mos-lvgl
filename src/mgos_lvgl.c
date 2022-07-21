#include "mgos_lvgl.h"

#include "mgos.h"
#include "mgos_event.h"

#include "lvgl.h"

/**
 * @brief LVGL timer task (callback) that informs lvgl of time passing.
 * @param arg NULL
 */
static void lvgl_inc_timer_cb(void *arg) {
    lv_tick_inc(mgos_sys_config_get_lvgl_time_ms());
    (void) arg;
}

/**
 * @brief LVGL timer task (callback) that is called periodically to inform lvgl of time passing.
 * @param arg NULL
 */
static void lvgl_task_handler_cb(void *arg) {
    lv_task_handler();
    (void) arg;
}

bool mgos_mos_lvgl_init(void) {
  mgos_event_register_base(MGOS_LVGL_BASE, "lvgl");

  mgos_event_trigger(MGOS_LVGL_EARLY, NULL);

  lv_mem_init();
  lv_init();

  mgos_event_trigger(MGOS_LVGL_AFTER_INIT, NULL);

  mgos_set_timer(mgos_sys_config_get_lvgl_time_ms(), MGOS_TIMER_REPEAT, lvgl_inc_timer_cb, NULL);
  mgos_set_timer(mgos_sys_config_get_lvgl_time_ms(), MGOS_TIMER_REPEAT, lvgl_task_handler_cb, NULL);

  return MGOS_APP_INIT_SUCCESS;
}
