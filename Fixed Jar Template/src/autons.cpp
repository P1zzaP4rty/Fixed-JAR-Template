#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1, 0, 10, 0);
  chassis.set_heading_constants(8, .3, 0, 1, 0);
  chassis.set_turn_constants(10, .2,.001, 2, 15); //original consitants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(8, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(.5, 150, 3000);
  chassis.set_turn_exit_conditions(1, 150, 1000);
  chassis.set_swing_exit_conditions(2, 0, 1000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 8;
  chassis.drive_max_voltage = 10;
  chassis.drive_settle_error = 1;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
  chassis.boomerang_setback = 0;
}

// motor_group left_drive = motor_group ();
// motor_group right_drive = motor_group ();

// void push (int power, int time){
// left_drive.spin(forward, power, volt);
// right_drive.spin(forward, power, volt);
// task::sleep(time);
// left_drive.spin(forward, 0, volt);
// right_drive.spin(forward, 0, volt);
// }

/*
 * To initialize data recorder, set "record" to true
 * before the turn starts.
 * To terminate data recorder, set "record" to false
 * after the PID settles.
 * You must have your controller connected to your computer.
 * Data will be shown in the Terminal.
 * 
 * @param record initializes and terminates data recorder.
 */

bool record = false;
int turn_PID_data_recorder(){
  while (true){
  while (record){
    printf("%.1f\n",custom_print_helper(chassis.get_absolute_heading()));
    task::sleep(5);
  }
  task::sleep(100);
  }
  return 0;
}

int odom_pos_track(){
  while (!driver_started){
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(5,20, "Auto X: %.1f Y: %.1f Heading: %.1f", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
  task::sleep(100);
  }
  return 0;
}

void initialize(){
  odom_constants();
  task auton0(turn_PID_data_recorder);
  task auto1(odom_pos_track);
}

void collect_turn_PID_data(){
initialize();
chassis.set_coordinates(0, 0, 0);
record = true;
chassis.turn_to_angle(100);
record = false;
}

void general_test()
{

}

/**
 * The expected behavior is to return to the start position.
  */

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}



/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}