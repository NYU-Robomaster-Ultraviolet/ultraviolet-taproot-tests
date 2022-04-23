/*
General Way to Define a Subsystem, example through the chassis
*/

#ifndef CHASSIS_SUBSYSTEM_HPP_
#define CHASSIS_SUBSYSTEM_HPP_

#include "tap/control/subsystem.hpp" //control folder has subsystem.hpp as a base to build all subsystems from
#include "tap/motor/dji_motor.hpp" //different motors in the motor folder
#include "tap/util_macros.hpp"

namespace src::Chassis
{
    /**
     * Subsystem skeleton for 4 wheel chassis
     */
class ChassisSubsystem : public tap::control::Subsystem
{
    public:
        //A current constant that we can modify as seen fit.
        static constexpr float MAX_CURRENT_OUTPUT = 8000.0f;

    //constructor intializes default values
        ChassisSubsystem(tap::Drivers *drivers) : 
            tap::control::Subsystem(drivers),
            leftFrontMotor(drivers, LEFT_FRONT_MOTOR_ID, MOTOR_CAN_BUS, false, "left front drive motor"),
            leftBackMotor(drivers, LEFT_BACK_MOTOR_ID, MOTOR_CAN_BUS, false, "left back drive motor"),
            rightFrontMotor(drivers, RIGHT_BACK_MOTOR_ID, MOTOR_CAN_BUS, false, "right front drive motor"),
            rightBackMotor(drivers, RIGHT_BACK_MOTOR_ID, MOTOR_CAN_BUS, false, "right back drive motor"),
            leftFrontOutput(0),
            leftBackOutput(0),
            rightFrontOutput(0),
            rightBackOutput(0)
        {}

        //needed for all subsystems: virtual functions in tap::control::Subsystem so must be overriden
        void initialize() override;
        
        void refresh() override;

        mockable void setDesiredOutput(int16_t leftSideOutput, int16_t rightSideOutput);

        const tap::motor::DjiMotor &getLeftFrontMotor() const
        {
            return leftFrontMotor;
        }
        const tap::motor::DjiMotor &getRightFrontMotor() const
        {
            return rightFrontMotor;
        }
        const tap::motor::DjiMotor &getLeftBackMotor() const
        {
            return leftBackMotor;
        }
        const tap::motor::DjiMotor &getRightBackMotor() const
        {
            return rightBackMotor;
        }

    private:
        //Hardware constants
        static constexpr tap::motor::MotorId RIGHT_FRONT_MOTOR_ID = tap::motor::MOTOR1;
        static constexpr tap::motor::MotorId LEFT_FRONT_MOTOR_ID = tap::motor::MOTOR2;
        static constexpr tap::motor::MotorId LEFT_BACK_MOTOR_ID = tap::motor::MOTOR3;
        static constexpr tap::motor::MotorId RIGHT_BACK_MOTOR_ID = tap::motor::MOTOR4;
        static constexpr tap::can::CanBus MOTOR_CAN_BUS = tap::can::CanBus::CAN_BUS2;

        //Software objects of physical things
        tap::motor::DjiMotor leftFrontMotor;
        tap::motor::DjiMotor leftBackMotor;
        tap::motor::DjiMotor rightFrontMotor;
        tap::motor::DjiMotor rightBackMotor;   

        //User input variables
        uint16_t leftFrontOutput;
        uint16_t leftBackOutput;
        uint16_t rightFrontOutput;
        uint16_t rightBackOutput;

};
}

#endif // CHASSIS_SUBSYSTEM_HPP_