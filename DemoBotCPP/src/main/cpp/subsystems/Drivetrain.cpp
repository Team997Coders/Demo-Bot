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

    // set motors to factory settings
    frontLeft->ConfigFactoryDefault();
    frontRight->ConfigFactoryDefault();
    backLeft->ConfigFactoryDefault();
    backRight->ConfigFactoryDefault();
    
    // enable current limiting for drive motors
    frontLeft->EnableCurrentLimit(true);
    frontRight->EnableCurrentLimit(true);
    backLeft->EnableCurrentLimit(true);
    backRight->EnableCurrentLimit(true);

    // set peak current limits
    frontLeft->ConfigPeakCurrentLimit(constants::Measurements::PEAK_CURRENT);
    frontRight->ConfigPeakCurrentLimit(constants::Measurements::PEAK_CURRENT);
    backLeft->ConfigPeakCurrentLimit(constants::Measurements::PEAK_CURRENT);
    backRight->ConfigPeakCurrentLimit(constants::Measurements::PEAK_CURRENT);

    // set peak current limit duration
    frontLeft->ConfigPeakCurrentDuration(constants::Measurements::PEAK_CURRENT_DURATION);
    frontRight->ConfigPeakCurrentDuration(constants::Measurements::PEAK_CURRENT_DURATION);
    backLeft->ConfigPeakCurrentDuration(constants::Measurements::PEAK_CURRENT_DURATION);
    backRight->ConfigPeakCurrentDuration(constants::Measurements::PEAK_CURRENT_DURATION);

    // set continous current limit
    frontLeft->ConfigContinuousCurrentLimit(constants::Measurements::CONTINUOUS_CURRENT);
    frontRight->ConfigContinuousCurrentLimit(constants::Measurements::CONTINUOUS_CURRENT);
    backLeft->ConfigContinuousCurrentLimit(constants::Measurements::CONTINUOUS_CURRENT);
    backRight->ConfigContinuousCurrentLimit(constants::Measurements::CONTINUOUS_CURRENT);

    // set nominal motor outout (for maximum efficiency)
    frontLeft->ConfigNominalOutputForward(constants::Measurements::NOMINAL_OUTPUT);
    frontRight->ConfigNominalOutputForward(constants::Measurements::NOMINAL_OUTPUT);
    backLeft->ConfigNominalOutputForward(constants::Measurements::NOMINAL_OUTPUT);
    backRight->ConfigNominalOutputForward(constants::Measurements::NOMINAL_OUTPUT);

    frontLeft->ConfigNominalOutputReverse(constants::Measurements::NOMINAL_OUTPUT);
    frontRight->ConfigNominalOutputReverse(constants::Measurements::NOMINAL_OUTPUT);
    backLeft->ConfigNominalOutputReverse(constants::Measurements::NOMINAL_OUTPUT);
    backRight->ConfigNominalOutputReverse(constants::Measurements::NOMINAL_OUTPUT);

    // set encoders (probably not all motor controllers have talons)
    frontLeft->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 50);
    frontRight->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 50);
    backLeft->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 50);
    backRight->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::CTRE_MagEncoder_Relative, 0, 50);

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
