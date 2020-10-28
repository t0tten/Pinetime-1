#include "Modal.h"

#include <cstdint>
#include <chrono>

#include "Screen.h"
#include "components/ble/NotificationManager.h"
#include "displayapp/DisplayApp.h"

#include <bits/unique_ptr.h>
#include <libs/lvgl/src/lv_core/lv_style.h>
#include <libs/lvgl/src/lv_core/lv_obj.h>
#include <libs/lvgl/lvgl.h>

using namespace Pinetime::Applications::Screens;
extern lv_font_t jetbrains_mono_extrabold_compressed;
extern lv_font_t jetbrains_mono_bold_20;

Modal::Modal(Pinetime::Applications::DisplayApp *app) : Screen(app) {}

Modal::~Modal() {
  lv_obj_clean(lv_scr_act());
}

bool Modal::Refresh() {

  return running;
}

bool Modal::OnButtonPushed() {
  running = false;
  return true;
}

void Modal::Hide() {
  /* Delete the parent modal background */
  lv_obj_del_async(lv_obj_get_parent(mbox));
  mbox = NULL; /* happens before object is actually deleted! */
  isVisible = false;
}

void Modal::mbox_event_cb(lv_obj_t *obj, lv_event_t evt) {
  auto* m = static_cast<Modal *>(obj->user_data);
  m->OnEvent(obj, evt);
}