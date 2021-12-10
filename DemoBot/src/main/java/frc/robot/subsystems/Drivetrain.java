// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import com.ctre.phoenix.motorcontrol.can.VictorSPX;
import com.ctre.phoenix.motorcontrol.can.WPI_VictorSPX;

import edu.wpi.first.wpilibj.SpeedControllerGroup;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;

public class Drivetrain extends SubsystemBase {
  
  private WPI_VictorSPX frontRight;
  private WPI_VictorSPX frontLeft;
  private WPI_VictorSPX backRight;
  private WPI_VictorSPX backLeft;
  
  private SpeedControllerGroup leftSide;
  private SpeedControllerGroup rightSide;
  private DifferentialDrive diffDrive;
  /** Creates a new Drivetrain. */
  public Drivetrain() {

    frontRight = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[2]);
    frontLeft = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[0]);
    backRight = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[3]);
    backLeft = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[1]);

    backRight.follow(frontRight);
    backLeft.follow(frontLeft);

    frontLeft.setInverted(true);
    backLeft.setInverted(true);

    frontRight.configFactoryDefault();
    frontLeft.configFactoryDefault();
    backRight.configFactoryDefault();
    backLeft.configFactoryDefault();

    leftSide = new SpeedControllerGroup(frontLeft, backLeft);
    rightSide = new SpeedControllerGroup(frontRight, backRight);

    diffDrive = new DifferentialDrive(leftSide, rightSide);
    
  }

  // public void arcadeDrive(double speed, double rotation){
  //  diffDrive.arcadeDrive(speed, rotation);
  // }

  public double numberLimits(double f, boolean ceiling, double highestAbs, boolean deadMan, double deadManTolerance) {  // aww yeah simple function with 5 arguments
    if (deadMan == true) {
      if (Math.abs(f) < deadManTolerance) {
        f = 0;
      }
    }
    if (ceiling == true) {
      if (f > highestAbs) {
        f = highestAbs;
      }
      else if (f < -1*highestAbs) {
        f = -1*highestAbs;
      }
    }
    return f;
  }
  public void betterArcadeDrive(double speed, double rotation) {
    speed = numberLimits(speed, true, 1, true, 0.1);
    rotation = numberLimits(speed, true, 1, true, 0.1);

    double left_throttle = (numberLimits(speed, true, 1, false, 0))+numberLimits(rotation, true, 1, false, 0);
    double right_throttle = (numberLimits(speed, true, 1, false, 0))-numberLimits(rotation, true, 1, false, 0);

    leftSide.set(left_throttle);
    rightSide.set(right_throttle);
  }
  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }
}
