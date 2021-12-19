// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>

#include "subsystems/Drivetrain.h"
#include "Constants.h"

Drivetrain::Drivetrain() {
    frontLeft = new ctre::phoenix::motorcontrol::can::TalonSRX(constants::Ports::DRIVE_FRONT_LEFT);
    frontRight = new ctre::phoenix::motorcontrol::can::TalonSRX(constants::Ports::DRIVE_FRONT_RIGHT);
    backLeft = new ctre::phoenix::motorcontrol::can::TalonSRX(constants::Ports::DRIVE_BACK_LEFT);
    backRight = new ctre::phoenix::motorcontrol::can::TalonSRX(constants::Ports::DRIVE_BACK_RIGHT);

    gyro = new AHRS(constants::Ports::GYRO);

    // TODO: Check motor specifications for current limit 0.87

    frontLeft->ConfigFactoryDefault();
    frontRight->ConfigFactoryDefault();
    backLeft->ConfigFactoryDefault();
    backRight->ConfigFactoryDefault();

    backLeft->Follow(*frontLeft);
    backRight->Follow(*frontRight);
    
}

Drivetrain::~Drivetrain() {
    // motor controllers
    delete frontLeft;
    delete frontRight;
    delete backLeft;
    delete backRight;

    // gyro
    delete gyro;
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}

void Drivetrain::SetSpeed(double left, double right) {
    
    frontLeft->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, left);
    frontRight->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, right);
}
