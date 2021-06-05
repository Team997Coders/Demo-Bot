// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

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

    frontRight = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[0]);
    frontLeft = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[1]);
    backRight = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[2]);
    backLeft = new WPI_VictorSPX(Constants.Ports.DRIVE_PORTS[3]);

    backRight.follow(frontRight);
    backLeft.follow(frontLeft);

    frontRight.configFactoryDefault();
    frontLeft.configFactoryDefault();
    backRight.configFactoryDefault();
    backLeft.configFactoryDefault();

    leftSide = new SpeedControllerGroup(frontLeft, backLeft);
    rightSide = new SpeedControllerGroup(frontRight, backRight);
    
    diffDrive = new DifferentialDrive(leftSide, rightSide);
  }

  public void arcadeDrive(double speed, double rotation){
    diffDrive.arcadeDrive(speed, rotation);
  }
  @Override
  public void periodic() {
    // This method will be called once per scheduler run
  }
}
