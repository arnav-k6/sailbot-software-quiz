#include "stdbool.h"
#include "standard_calc.h"
#include <stdio.h>
/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle)
{
    if (angle >= -180 && angle < 180)
    {
        return angle;
    }
    /* if angle is already in the specified range, simply return the angle*/
    if (angle >= 0)
    {
        while (angle >= 180)
        {
            angle -= 360;
        }
    }
    else
    {
        while (angle < -180)
        {
            angle += 360;
        }
    }
    return angle;
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 *
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle)
{
    float first = bound_to_180(first_angle); // bound all angles to a value between -180 and 180 using helper function
    float middle = bound_to_180(middle_angle);
    float second = bound_to_180(second_angle);

    middle = bound_to_180(middle - first); // offset middle and second by first, making first angle = 0 for simplicity, and for clear second and first value comparision
    second = bound_to_180(second - first);

    if (second >= 0)
    { // if second is ahead (greater) than first which is implicitly 0
        return (second >= middle && middle >= 0);
        // angle is only between first and second if the distance from first to middle is less than or equal to first and second
        // AND the middle angle is at or ahead of first (0), if not then it's out of the acute range
    }
    else
    { // if second is less than first (0)
        return (second <= middle && middle <= 0);
        // angle is only between first and second if the distance from first to middle is less than or equal to first and second
        // AND the middle angle is at or behind first (0), if not then it's out of the acute range
    }
}

int main(){
    bool result = is_angle_between(45,90,270);
    printf("The result is: %d",result);
}