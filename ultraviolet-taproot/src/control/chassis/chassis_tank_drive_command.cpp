#include "chassis_tank_drive_command.hpp"

#include "tap/algorithms/math_user_utils.hpp"
#include "tap/drivers.hpp"
#include "tap/errors/create_errors.hpp"

namespace src::Chassis
{

ChassisTankDriveCommand()

void ChassisTankDriveCommand::initialize() {}

void ChassisTankDriveCommand::execute()
{   
    int16_t leftInput = drivers->remote.getChannel(tap::Remote::Channel::LEFT_VERTICAL) * ChassisSubsystem::MAX_CURRENT_OUTPUT;
    int16_t rightInput = drivers->remote.getChannel(tap::Remote::Channel::RIGHT_VERTICAL) * ChassisSubsystem::MAX_CURRENT_OUTPUT;
    chassis->setDesiredOutput(leftInput, rightInput);
}

void ChassisTankDriveCommand::end(bool)
{
    chassis-> setDesiredOutput(0,0);
}

bool ChassisTankDriveCommand::isFinished() const
{
    return false;
}

}