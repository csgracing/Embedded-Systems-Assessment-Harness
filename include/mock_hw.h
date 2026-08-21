#ifndef MOCK_HW_H
#define MOCK_HW_H

#include <stdint.h>

#include "types.h"

typedef struct {
    BmsData bms;
    BatteryTempData batt_temp;
    InverterData inverter;
    PvData pv;
    GridData grid;
    RelayState relay;
    DoorSwitchData door;
    uint32_t sim_time_ms;
} WorldState;

void load_world_state(const WorldState *world);

BmsData read_bms(void);
BatteryTempData read_batt_temp(void);
InverterData read_inverter(void);
PvData read_pv(void);
GridData read_grid(void);
RelayState read_relay(void);
DoorSwitchData read_door_switch(void);
uint32_t read_system_time_ms(void);

void write_relay(bool closed);
void write_buzzer(bool on);
void write_notification(bool on);

#endif // MOCK_HW_H
