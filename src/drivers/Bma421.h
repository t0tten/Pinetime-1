#pragma once

#include <drivers/Bma421_C/bma4_defs.h>

namespace Pinetime {
  namespace Drivers {
    class TwiMaster;
    class Bma421 {
      public:
        Bma421(TwiMaster& twiMaster, uint8_t twiAddress);
        Bma421(const Bma421&) = delete;
        Bma421& operator=(const Bma421&) = delete;
        Bma421(Bma421&&) = delete;
        Bma421& operator=(Bma421&&) = delete;

        void Init();
        void Reset();
        void Process();

        void Read(uint8_t registerAddress, uint8_t *buffer, size_t size);
        void Write(uint8_t registerAddress, const uint8_t *data, size_t size);

      private:
        TwiMaster& twiMaster;
        uint8_t twiAddress;

        struct bma4_dev bma;
        struct bma4_accel_config accel_conf;
        static constexpr uint8_t deviceAddress = 0x18;
    };
  }
}