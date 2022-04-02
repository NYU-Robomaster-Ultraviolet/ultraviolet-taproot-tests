#ifndef CHASSIS_TANK_DRIVE_COMMAND_HPP_
#define CHASSIS_TANK_DRIVE_COMMAND_HPP_

#include "tap/control/command.hpp"
#include "chassis_subsystem.hpp"

namespace src::chassis
{
class ChassisTankDriveCommand : public tap::control::Command
{
    public:

        ChassisTankDriveCommand(src::Chassis::ChassisSubsystem *const chassis, tap::Drivers *drivers);

        ChassisTankDriveCommand(const ChassisTankDriveCommand &other) = delete;

        ChassisTankDriveCommand &operator = (const ChassisTankDriveCommand &other) = delete;

        void initialize() override;

        const char *getName() const { return "chassis tank drive command"; }

        void execute() override;

        void end(bool) override;

        bool isFinished() const override;

    private:
        src::Chassis::ChassisSubsystem *const chassis;

        tap::Drivers *drivers;
};
}

#endif