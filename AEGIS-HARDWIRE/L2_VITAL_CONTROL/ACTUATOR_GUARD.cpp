/* * --------------------------------------------------------------------------
 * PROJECT: IRONMIND PROTOCOL (AEGIS-HARDWIRE / HSG-Protocol)
 * AUTHOR: Akhil Shijo
 * CONTACT: +91 8137864105 | mrakhilshijo@gmail.com
 * LOCATION: Idukki, Kerala, India
 * GITHUB: https://github.com/14akhilshijo
 * WEBSITE: https://akhilshijoinnov.site
 * LINKEDIN: https://www.linkedin.com/in/akhil-shijo/
 * ORGANIZATION: BITVION TECHNOLOGIES
 * LICENSE: Apache License 2.0
 * * ANY MODIFICATION OR DISTRIBUTION OF THIS FILE MUST RETAIN THIS HEADER.
 * FOR COMMERCIAL USE, ATTRIBUTION TO THE AUTHOR AND PLATFORM IS MANDATORY.
 * --------------------------------------------------------------------------
 * Module: L2_VITAL_CONTROL - Actuator Guard
 * Author: Akhil Shijo (BITVION TECHNOLOGIES)
 */

#include "Vitals.h"

// Strict physical limits that cannot be exceeded programmatically
const float MAX_VELOCITY = 1.5; // meters per second
const float MAX_TORQUE = 50.0;  // Newton-meter

void execute_safe_movement(float requested_speed, float requested_torque) {
    
// Check alignment with L0 logic (physical fuse)
    if (!check_l0_integrity()) {
        hard_stop_all_motors();
        return;
    }

// Command filtering: If the AI ​​requests an insane speed, it is immediately restricted.
    float safe_speed = (requested_speed > MAX_VELOCITY) ? MAX_VELOCITY : requested_speed;
    float safe_torque = (requested_torque > MAX_TORQUE) ? MAX_TORQUE : requested_torque;

// Sending pulses to motors (PWM Control)
    apply_pwm_signal(safe_speed, safe_torque);
}
