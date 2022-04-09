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

        ChassisTankDriveCommand(ChassisSubsystem *chassis, src::Drivers *drivers);

        ChassisTankDriveCommand(const ChassisTankDriveCommand &other) = delete;

        ChassisTankDriveCommand &operator = (const ChassisTankDriveCommand &other) = delete;

        void initialize() override;

        const char *getName() const { return "chassis tank drive command"; }

        void execute() override;

        void end(bool interrupted) override;

        bool isFinished() const override;

    private:
        ChassisSubsystem *const chassis;
        src::Drivers *drivers;
};
}

#endif