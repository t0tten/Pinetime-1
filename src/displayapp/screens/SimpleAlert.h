#pragma once

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

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Modal;
        class SimpleAlert : public Modal {
          public:
            SimpleAlert(DisplayApp* app);
            ~SimpleAlert();

            virtual void Show(Pinetime::Controllers::NotificationManager::Notification notification);
          private:
            const std::string BTN_OK = "Ok";
            
            virtual void OnEvent(lv_obj_t *event_obj, lv_event_t evt);
        };
    }
  }
}
