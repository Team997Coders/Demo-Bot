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
            DRIVE_FRONT_LEFT = 0,
            DRIVE_FRONT_RIGHT = 1,
            DRIVE_BACK_LEFT = 2,
            DRIVE_BACK_RIGHT = 3;
    };
}