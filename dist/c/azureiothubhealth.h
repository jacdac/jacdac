// Autogenerated C header file for Azure IoT Hub Health
#ifndef _JACDAC_SPEC_AZURE_IOT_HUB_HEALTH_H
#define _JACDAC_SPEC_AZURE_IOT_HUB_HEALTH_H 1

#define JD_SERVICE_CLASS_AZURE_IOT_HUB_HEALTH  0x1462eefc

// enum ConnectionStatus (uint16_t)
#define JD_AZURE_IOT_HUB_HEALTH_CONNECTION_STATUS_CONNECTED 0x0
#define JD_AZURE_IOT_HUB_HEALTH_CONNECTION_STATUS_DISCONNECTED 0x1
#define JD_AZURE_IOT_HUB_HEALTH_CONNECTION_STATUS_CONNECTING 0x2
#define JD_AZURE_IOT_HUB_HEALTH_CONNECTION_STATUS_DISCONNECTING 0x3

/**
 * Read-only string (bytes). Something like `my-iot-hub.azure-devices.net`; empty string when not properly configured
 */
#define JD_AZURE_IOT_HUB_HEALTH_REG_HUB_NAME 0x180

/**
 * Read-only ConnectionStatus (uint16_t). Indicates the status of connection. A message beyond the [0..3] range represents an HTTP error code.
 */
#define JD_AZURE_IOT_HUB_HEALTH_REG_CONNECTION_STATUS 0x181

/**
 * Reads internal statistics about messages sent to the hub.
 */
#define JD_AZURE_IOT_HUB_HEALTH_REG_STATISTICS 0x182
typedef struct jd_azure_iot_hub_health_statistics {
    uint32_t reading;
    uint32_t event;
    uint32_t twin_reported;
    uint32_t twin_desired;
} jd_azure_iot_hub_health_statistics_t;


/**
 * Argument: twin_report pipe (bytes). Returns the twin json payload
 */
#define JD_AZURE_IOT_HUB_HEALTH_CMD_TWIN 0x80

/**
 * Argument: content string (bytes). Returns the twin json payload
 */

/**
 * No args. Starts a connection to the IoT hub service
 */
#define JD_AZURE_IOT_HUB_HEALTH_CMD_CONNECT 0x81

/**
 * No args. Starts disconnecting from the IoT hub service
 */
#define JD_AZURE_IOT_HUB_HEALTH_CMD_DISCONNECT 0x82

/**
 * Argument: payload uint32_t. Commands the device to send a `ping` message to the hub with the given payload.
 */
#define JD_AZURE_IOT_HUB_HEALTH_CMD_PING 0x85

/**
 * No args. Restricted command to override the existing connection string to the Azure IoT Hub.
 */
#define JD_AZURE_IOT_HUB_HEALTH_CMD_SET_CONNECTION_STRING 0x86

/**
 * Report: Argument: connection_string_port pipe_port (uint16_t)
 */

/**
 * Argument: connection_status ConnectionStatus (uint16_t). Raised when the connection status changes
 */
#define JD_AZURE_IOT_HUB_HEALTH_EV_CONNECTION_STATUS_CHANGE JD_EV_CHANGE

/**
 * Raised when the twin model is modified.
 */
#define JD_AZURE_IOT_HUB_HEALTH_EV_TWIN_CHANGE 0x80

#endif
