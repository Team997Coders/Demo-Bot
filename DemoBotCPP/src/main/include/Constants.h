// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace constants {
    struct Ports {
        static const int
            // motor controller CAN ids
            DRIVE_FRONT_LEFT = 0,
            DRIVE_FRONT_RIGHT = 1,
            DRIVE_BACK_LEFT = 2,
            DRIVE_BACK_RIGHT = 3,

            // joystick ports
            JOYSTICK_1 = 0,
            JOYSTICK_2 = 1;
        static const frc::SerialPort::Port
            // gyro
            GYRO = frc::SerialPort::Port::kUSB; 
    };
    struct Measurements {
        static constexpr double
            // drive motor controller limits informed by: https://motors.vex.com/vexpro-motors/cim-motor?q=&locale.name=English#d8wg1gv (12V)
            PEAK_CURRENT = 120.0, // stall current: 131 Amps
            PEAK_CURRENT_DURATION = 500.0, // milliseconds
            CONTINUOUS_CURRENT = 66.9, // current at peak power: 66.9 Amps
            NOMINAL_OUTPUT = 4637.1 / 5330.0; // percent output for max efficiency: (max efficiency RPM) / (max RPM) = 0.87
    };
}