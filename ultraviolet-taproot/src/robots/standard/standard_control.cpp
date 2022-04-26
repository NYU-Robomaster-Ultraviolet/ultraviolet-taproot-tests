#ifdef TARGET_STANDARD

#include "drivers.hpp"
#include "drivers_singleton.hpp"
//
#include "tap/control/command_mapper.hpp"
#include "tap/control/hold_command_mapping.hpp"
#include "tap/control/hold_repeat_command_mapping.hpp"
#include "tap/control/press_command_mapping.hpp"
#include "tap/control/setpoint/commands/calibrate_command.hpp"
#include "tap/control/toggle_command_mapping.hpp"
//
#include "control/chassis/chassis_subsystem.hpp"
#include "control/chassis/chassis_tank_drive_command.hpp"

using namespace src::Chassis;

/*
 * NOTE: We are using the DoNotUse_getDrivers() function here
 *      because this file defines all subsystems and command
 *      and thus we must pass in the single statically allocated
 *      Drivers class to all of these objects.
 */
src::driversFunc drivers = src::DoNotUse_getDrivers;

using namespace tap;
using namespace tap::control;

namespace StandardControl {

// Define subsystems here ------------------------------------------------
ChassisSubsystem chassis(drivers());

// Define commands here ---------------------------------------------------
ChassisTankDriveCommand chassisDriveCommand(drivers(), &chassis);

// Define command mappings here -------------------------------------------
/*HoldCommandMapping leftSwitchUp(
    drivers(),
    {&chassisDriveCommand},
    RemoteMapState(Remote::Switch::LEFT_SWITCH, Remote::SwitchState::UP));*/

// Register subsystems here -----------------------------------------------
void registerSubsystems(src::Drivers *drivers) {
    drivers->commandScheduler.registerSubsystem(&chassis);
}

// Initialize subsystems here ---------------------------------------------
void initializeSubsystems() {
    chassis.initialize();
}

// Set default command here -----------------------------------------------
void setDefaultCommands(src::Drivers *) {
    chassis.setDefaultCommand(&chassisDriveCommand);
}

// Set commands scheduled on startup
void startupCommands(src::Drivers *drivers) {
    
}

// Register IO mappings here -----------------------------------------------
void registerIOMappings(src::Drivers *drivers) {
    //drivers->commandMapper.addMap(&leftSwitchUp);
}

}  // namespace StandardControl

namespace src::Control {
    // Initialize subsystems ---------------------------------------------------
    void initializeSubsystemCommands(src::Drivers * drivers) {
        StandardControl::initializeSubsystems();
        StandardControl::registerSubsystems(drivers);
        StandardControl::setDefaultCommands(drivers);
        StandardControl::startupCommands(drivers);
        StandardControl::registerIOMappings(drivers);
    }
}  // namespace src::Control

#endif