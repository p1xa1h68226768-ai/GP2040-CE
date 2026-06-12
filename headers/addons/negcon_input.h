#ifndef NEGCON_INPUT_H_
#define NEGCON_INPUT_H_

#include <string>
#include <stdint.h>
#include "gpaddon.h"
#include "gamepad.h"

// ネジコンのピン設定
#define NEGCON_PIN_DAT 0
#define NEGCON_PIN_CMD 1
#define NEGCON_PIN_ATT 2
#define NEGCON_PIN_CLK 3

class NeGconInput : public GPAddon {
public:
    virtual bool available();
    virtual void setup();
    virtual void process();
    virtual void preprocess() {}
    virtual void postprocess(bool sent) {}
    virtual void reinit() {}
    virtual std::string name() { return "NeGconInput"; }

private:
    uint8_t spi_transfer(uint8_t data);
};

#endif // NEGCON_INPUT_H_
