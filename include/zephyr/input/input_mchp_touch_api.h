/*
 * Copyright (c) 2026 Microchip Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Header file for touch events API.
 * @ingroup touch_events
 */

#ifndef ZEPHYR_INCLUDE_INPUT_MCHP_TOUCH_H_
#define ZEPHYR_INCLUDE_INPUT_MCHP_TOUCH_H_

#include <zephyr/input/input.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Key sensor status byte
 *
 * Note: Bit 7 indicates logical 'In Detect' (States 'Detect' and 'Filter Out')
 */
#define QTM_KEY_STATE_DISABLE  0x00u
#define QTM_KEY_STATE_INIT     0x01u
#define QTM_KEY_STATE_CAL      0x02u
#define QTM_KEY_STATE_NO_DET   0x03u
#define QTM_KEY_STATE_FILT_IN  0x04u
#define QTM_KEY_STATE_DETECT   0x85u
#define QTM_KEY_STATE_FILT_OUT 0x86u
#define QTM_KEY_STATE_ANTI_TCH 0x07u
#define QTM_KEY_STATE_SUSPEND  0x08u
#define QTM_KEY_STATE_CAL_ERR  0x09u
#define KEY_TOUCHED_MASK       0x80u

/**
 * @brief uint16_t get_sensor_node_signal(const struct device *dev, uint16_t sensor_node)
 *
 * This function returns the sensor signal value
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 *
 * @retval uint16_t
 */
uint16_t get_sensor_node_signal(const struct device *dev, uint16_t sensor_node);

/**
 * @brief void update_sensor_node_signal(const struct device *dev, uint16_t sensor_node,
 *                                                                 uint16_t new_signal);
 *
 * This function updates the sensor signal value
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 * @param new_signal @ref new value
 *
 */
void update_sensor_node_signal(const struct device *dev, uint16_t sensor_node,
				uint16_t new_signal);

/**
 * @brief uint16_t get_sensor_node_reference(const struct device *dev, uint16_t sensor_node)
 *
 * This function returns the sensor reference value
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 *
 * @retval uint16_t
 */
uint16_t get_sensor_node_reference(const struct device *dev, uint16_t sensor_node);

/**
 * @brief void update_sensor_node_reference(const struct device *dev, uint16_t sensor_node,
 *                                                                    uint16_t new_reference)
 *
 * This function updates the sensor reference value
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 * @param new_reference @ref new value
 *
 */
void update_sensor_node_reference(const struct device *dev, uint16_t sensor_node,
				uint16_t new_reference);

/**
 * @brief uint16_t get_sensor_cc_val(const struct device *dev, uint16_t sensor_node)
 *
 * This function returns the sensor Compensation Capacitance value
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 *
 * @retval uint16_t
 */
uint16_t get_sensor_cc_val(const struct device *dev, uint16_t sensor_node);

/**
 * @brief void update_sensor_cc_val(const struct device *dev, uint16_t sensor_node,
 *                                                            uint16_t new_cc_value)
 *
 * This function updates the sensor Compensation Capacitance value
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 * @param new_cc_value @ref new value
 *
 */
void update_sensor_cc_val(const struct device *dev, uint16_t sensor_node, uint16_t new_cc_value);

/**
 * @brief uint8_t get_sensor_state(const struct device *dev, uint16_t sensor_node)
 *
 * This function returns the sensor state
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 *
 * @retval uint8_t
 *
 * Note: refer to the "Key sensor status byte"
 */
uint8_t get_sensor_state(const struct device *dev, uint16_t sensor_node);

/**
 * @brief void update_sensor_state(const struct device *dev, uint16_t sensor_node,
 *                                                           uint8_t new_state)
 *
 * This function updates the sensor state
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 * @param new_state @ref new value
 *
 * Note: refer to the "Key sensor status byte"
 *
 */
void update_sensor_state(const struct device *dev, uint16_t sensor_node, uint8_t new_state);

/**
 * @brief void calibrate_node(const struct device *dev, uint16_t sensor_node)
 *
 * This function calibrate the sensor node
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 *
 */
void calibrate_node(const struct device *dev, uint16_t sensor_node);

/**
 * @brief void suspend_sensor(const struct device *dev, uint16_t sensor_node)
 *
 * This function suspend the sensor node
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 *
 */
void suspend_sensor(const struct device *dev, uint16_t sensor_node);

/**
 * @brief void resume_sensor(const struct device *dev, uint16_t sensor_node)
 *
 * This function resume the suspended sensor node
 *
 * @param _dev @ref device pointer.
 * @param sensor_node @ref sensor number
 *
 */
void resume_sensor(const struct device *dev, uint16_t sensor_node);

/**
 * @brief uint8_t get_def_no_of_sensors(const struct device *dev)
 *
 * This function returns total number of sensor node
 *
 * @retval uint8_t @ref total number of buttons
 */
uint8_t get_def_no_of_sensors(const struct device *dev);

/**
 * @brief uint8_t get_scroller_state(const struct device *dev, uint16_t sensor_node)
 *
 * This function returns scroller state
 *
 * @retval uint8_t @ref scroller state
 */
uint8_t get_scroller_state(const struct device *dev, uint16_t sensor_node);

/**
 * @brief uint16_t get_scroller_position(const struct device *dev, uint16_t sensor_node)
 *
 * This function returns scroller position
 *
 * @retval uint16_t @ref scroller position
 */
uint16_t get_scroller_position(const struct device *dev, uint16_t sensor_node);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_INPUT_MCHP_TOUCH_H_ */
