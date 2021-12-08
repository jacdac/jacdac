// Autogenerated C header file for Light level
#ifndef _JACDAC_SPEC_LIGHT_LEVEL_H
#define _JACDAC_SPEC_LIGHT_LEVEL_H 1

#define JD_SERVICE_CLASS_LIGHT_LEVEL  0x17dc9a1c

// enum Variant (uint8_t)
#define JD_LIGHT_LEVEL_VARIANT_PHOTO_RESISTOR 0x1
#define JD_LIGHT_LEVEL_VARIANT_LEDMATRIX 0x2
#define JD_LIGHT_LEVEL_VARIANT_AMBIENT 0x3

/**
 * Read-only ratio u0.16 (uint16_t). Detect light level
 */
#define JD_LIGHT_LEVEL_REG_LIGHT_LEVEL JD_REG_READING

/**
 * Read-only ratio u0.16 (uint16_t). Absolute estimated error of the reading value
 */
#define JD_LIGHT_LEVEL_REG_LIGHT_LEVEL_ERROR JD_REG_READING_ERROR

/**
 * Constant Variant (uint8_t). The type of physical sensor.
 */
#define JD_LIGHT_LEVEL_REG_VARIANT JD_REG_VARIANT

#endif
