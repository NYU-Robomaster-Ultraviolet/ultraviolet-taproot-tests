#ifndef CHASSIS_TANK_DRIVE_COMMAND_HPP_
#define CHASSIS_TANK_DRIVE_COMMAND_HPP_

#include "tap/control/command.hpp"
#include "chassis_subsystem.hpp"
#include "drivers.hpp"

namespace src::Chassis
{
class ChassisTankDriveCommand : public tap::control::Command
{
    public:

        ChassisTankDriveCommand(src::Drivers *drivers, ChassisSubsystem *chassis);

        void initialize() override;

        void execute() override;

        void end(bool interrupted) override;

        bool isReady() override;

        bool isFinished() const override;

        const char *getName() const { return "chassis tank drive command"; }

    private:
        ChassisSubsystem * chassis;
        src::Drivers *drivers;
};
}

#endif