#ifndef UTILS_H
#define UTILS_H

#include <xdc/std.h>
#include <xdc/runtime/System.h>

/**
 * @brief Prints a float value with two decimal precision.
 *
 * @param value The float value to print.
 */
void printFloat(float value);

/**
 * @brief Displays sensor averages for arrays of x, y, z data.
 *
 * @param arx Pointer to array of x-axis sensor data.
 * @param ary Pointer to array of y-axis sensor data.
 * @param arz Pointer to array of z-axis sensor data.
 * @param arrSize Size of the arrays.
 */
void displaySensorAvg(float *arx, float *ary, float *arz, const unsigned int arrSize);

/**
 * @brief Converts a Morse code string to its corresponding ASCII character.
 *
 * @param morse The Morse code string.
 * @return The corresponding ASCII character or '?' for unknown codes.
 */
char morseToAscii(const char *morse);

/**
 * @brief Calculates a filtered ay value based on the previous ay value.
 *
 * @param ay The current ay value.
 * @return The filtered ay value.
 */
float calculateFilteredAy(const float ay);

/**
 * @brief Calculates the average of an array of floats.
 *
 * @param array Pointer to the float array.
 * @param arrSize Size of the array.
 * @return The average of the array.
 */
float calculateAvg(const float *array, const unsigned int arrSize);

#endif // UTILS_H
