.. _mchp_qt7_sample:

Microchip QT7 Xplained Pro
##########################

Overview
********

The **Microchip® QT7 Xplained Pro** is an extension board designed to evaluate
**self-capacitance touch** applications with a strong focus on **water-tolerant
operation**.

The kit demonstrates water-tolerant touch functionality using either
**Driven Shield** or **Driven Shield+**, depending on the capabilities of the
target MCU. The board features:

* One self-capacitance slider
* Two self-capacitance buttons
* Eight LEDs providing visual feedback for button state and slider position

This sample provides a generic reference implementation and is intended to work
with **any Microchip development board and touch controller supported by Zephyr**,
provided the appropriate device tree configuration is present.

---

Requirements
************

* A Microchip MCU board supported by Zephyr with a capacitive touch controller
* **QT7 Xplained Pro** extension board
* Properly configured ``/chosen`` device tree nodes, for example:

  * ``zephyr,ptc``

---

Touch Configuration (Kconfig)
*****************************

The following Kconfig options must be enabled for touch operation:

Mandatory options:

* ``CONFIG_INPUT``
  Enables the Zephyr input subsystem.

* ``CONFIG_INPUT_MCHP_TOUCH``
  Enables the Microchip touch driver.

* ``CONFIG_INPUT_MCHP_TOUCH_EN_BTTN_MODULE``
  Enables the touch button module.

* ``CONFIG_INPUT_MCHP_TOUCH_EN_FREQ_HOP``
  Enables Frequency Hopping for noise avoidance.

* ``CONFIG_INPUT_MCHP_TOUCH_EN_SCROLLER``
   Enables the Scroller module.

Optional options:

* ``CONFIG_INPUT_MCHP_TOUCH_EN_FREQ_AUTO_TUNE``
  Enables Frequency Hopping with Autotune.

  Frequency Hopping with Autotune is the **recommended configuration** for
  robust touch operation. This feature operates autonomously and provides the
  flexibility required to counteract electrical noise in real-world
  environments.

  The Autotune module is a superset of Frequency Hopping. In addition to
  frequency variation, it continuously monitors noise and automatically tunes
  the touch acquisition frequency.

  The touch controller performs measurements on multiple frequencies (by
  default three, or as configured by the host). Noise levels are monitored for
  each frequency. If the noise on a given frequency exceeds the configured
  Noise Threshold for a defined number of integrations, that frequency is
  replaced by another frequency from the available frequency pool.

* ``CONFIG_INPUT_MCHP_TOUCH_DATASTREAMER_UNI_DIR``
  Enables unidirectional touch data streaming. This option is required only if
  touch data visualization using the Data Visualizer tool is needed.

---

Building and Running
********************

This is a generic sample and should work with any supported Microchip board and
touch controller, as long as the required device tree bindings are configured.

Before building the sample, make sure all required modules and binary blobs are
available.

Fetch Zephyr modules:

.. code-block:: console

   west update

Fetch Microchip HAL binary blobs:

.. code-block:: console

   west blobs fetch hal_microchip

Build the sample:

.. zephyr-app-commands::
   :zephyr-app: samples/shields/mchp_qt7
   :board: pic32cm_jh01_cpro
   :goals: build
   :compact:

.. code-block:: console

   west build -b pic32cm_jh01_cpro samples/shields/mchp_qt7 --shield qt7_pic32cm_jh01_cpro

---

Expected Output
***************

After flashing the application:

* Touching the **buttons** toggles the corresponding LEDs
* Sliding a finger across the **slider** updates the LED position feedback
* Touch functionality remains responsive even in the presence of moisture,
  depending on the selected driven shield mode and MCU capabilities

---

Data Streaming and Visualization
********************************

Touch diagnostic data can be streamed to a host PC and visualized using the
**Microchip Data Visualizer** tool, which displays touch parameters in a
graphical user interface (GUI).

To enable touch data streaming, the following configuration options must be
enabled:

* ``CONFIG_INPUT_MCHP_TOUCH_DATASTREAMER_UNI_DIR``
* ``CONFIG_SERIAL``

When enabled, touch data is transmitted over the serial interface and can be
monitored in real time using the Data Visualizer GUI. This is useful for
debugging, tuning, and validating touch performance.

Detailed instructions for installing and using the Data Visualizer tool are
available at the following link:

* https://developerhelp.microchip.com/xwiki/bin/view/applications/touch-gesture/mplab-data-visualizer-touch-plugin/visualize-touch-data-using-mplab-data-visualizer/

---

References
**********

* Microchip QT7 Xplained Pro Extension Board documentation
  [QT7 Xplained Pro User Guide](https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/UserGuides/QT7XplainedProUserGuide50002725A.pdf "QT7 Xplained Pro")
