#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include <stdint.h>

#define BMS_NUM_CELLS 8

typedef struct {
    float cell_voltages_mv[BMS_NUM_CELLS];
    float pack_current_a;
    float pack_temp_c;
    bool comms_ok;
    uint32_t last_update_ms;
} BmsData;

typedef struct {
    float temp_c;
    bool valid;
} BatteryTempData;

typedef struct {
    bool running;
    uint8_t fault_code;
    bool comms_ok;
    uint32_t last_update_ms;
} InverterData;

typedef struct {
    float voltage_v;
    float current_a;
} PvData;

typedef struct {
    float voltage_v;
    float frequency_hz;
    bool present;
} GridData;

typedef struct {
    bool commanded_closed;
    bool feedback_closed;
} RelayState;

typedef struct {
    bool triggered;
    uint32_t timestamp_ms;
} DoorSwitchData;

typedef enum {
    SYSTEM_OFF = 0,
    SYSTEM_ON = 1,
} SystemState;

typedef struct {
    SystemState state;
    bool buzzer_on;
    bool notification_flag;
} SystemOutputs;

#endif // TYPES_H
