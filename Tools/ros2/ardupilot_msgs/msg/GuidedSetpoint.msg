# This topic publishes Plane guided setpoints in a single command.
# Use set_heading, set_airspeed, and set_altitude to control which
# fields are applied on the vehicle.
std_msgs/Header header

# Heading control.
# heading_type:
#   0 = clear heading tracking
#   1 = course over ground
#   2 = maintain vehicle heading

bool set_heading
uint8 heading_type
float32 heading_deg
float32 heading_accel_limit_mss

# Airspeed control.
bool set_airspeed
float32 airspeed_mps
float32 airspeed_accel_mps2

# Altitude control.
bool set_altitude
uint8 altitude_frame
float32 altitude_m
float32 climb_rate_mps
