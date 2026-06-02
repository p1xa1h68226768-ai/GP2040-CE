#ifndef _NEGCON_INPUT_H
#define _NEGCON_INPUT_H

#include "gpaddon.h"
#include "GamepadState.h"
#include "pico/stdlib.h"

// ネジコン接続用のピン設定 (RP2040-Zeroの 0, 1, 2, 3 ピンを使用)
#define NEGCON_PIN_DAT 0 // Data (PS1端子の1番ピン/茶)
#define NEGCON_PIN_CMD 1 // Command (PS1端子の2番ピン/橙)
#define NEGCON_PIN_ATT 2 // Attention (PS1端子の6番ピン/黄)
#define NEGCON_PIN_CLK 3 // Clock (PS1端子の7番ピン/青)

class NeGconInput : public GPAddon {
public:
    virtual bool available();
    virtual void setup();
    virtual void process();
    virtual std::string name() { return "NeGcon Input"; }
private:
    uint8_t spi_transfer(uint8_t data);
    void read_negcon();
};

#endif
