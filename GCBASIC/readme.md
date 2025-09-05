<xaiArtifact artifact_id="b9dff4eb-9fe1-469a-b6fa-3cbc9a21ff2a" artifact_version_id="3769e886-7142-44b2-a3da-a10c7a323697" title="README.md" contentType="text/markdown">

# Power Monitoring Project

## Overview
This project provides a set of GCBASIC scripts and documentation for implementing a power monitoring system using the ATmega328PB microcontroller and the ADL200 energy meter. The system supports hardware serial communication, graphical LCD (GLCD) interfacing, and Modbus protocol communication to monitor and display power-related metrics.

## Table of Contents
- [Project Description](#project-description)
- [Getting Started](#getting-started)
- [Files Overview](#files-overview)
- [Adding New Values](#adding-new-values)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Project Description
The Power Monitoring project enables the collection, processing, and display of energy data using the ADL200 energy meter interfaced with an ATmega328PB microcontroller. The system leverages GCBASIC for programming, utilizing hardware serial communication, GLCD for visualization, and Modbus protocol for data exchange.

## Getting Started
To begin using this project, follow the instructions in [2. Getting_started.md](2. Getting_started.md). This document outlines the initial setup steps, including:
- Setting up the GCBASIC compiler.
- Configuring the ATmega328PB microcontroller.
- Connecting the ADL200 energy meter.
- Loading and running the provided scripts.

Ensure you have the necessary hardware and software installed before proceeding.

## Files Overview
The project includes the following key files:
- **010_mega328pb_hardwareserial.gcb**: Implements hardware serial communication for the ATmega328PB to interface with external devices.
- **020_mega328pb_hardwareGLCD.gcb**: Configures a graphical LCD to display power monitoring data.
- **030_mega328p_ModBusProtocol.gcb**: Provides Modbus protocol support for communication with the ADL200 energy meter.
- **030_mega328pb_ADL200.gcb**: Core script for interfacing with the ADL200 energy meter, handling data retrieval.
- **040_mega328pb_ADL200.gcb**: Advanced script for integrating serial communication, GLCD output, and Modbus protocol to monitor and display ADL200 data.
- **ADL200.h**: Header file containing definitions and configurations specific to the ADL200 energy meter.
- **MODBus.h**: Header file with Modbus protocol definitions and functions.
- **methods.gcb**: Utility functions and methods used across the project scripts.

### Documentation
- **1. readme.adoc**: Initial project overview (replaced by this README.md).
- **2. Getting_started.md**: Step-by-step guide to set up the project.
- **3. Howto_add_new_value_040_mega328pb_ADL200.adoc**: Instructions for adding new values to the `040_mega328pb_ADL200.gcb` script, such as additional power metrics or custom data processing.

## Adding New Values
To extend the functionality of the `040_mega328pb_ADL200.gcb` script by adding new values (e.g., new energy metrics or custom calculations), refer to [3. Howto_add_new_value_040_mega328pb_ADL200.adoc](3. Howto_add_new_value_040_mega328pb_ADL200.adoc). This guide provides detailed steps for:
- Modifying the script to include new data points.
- Updating Modbus register mappings.
- Adjusting GLCD output for new values.

## Usage
1. **Compile and Upload**: Use the GCBASIC compiler to compile the scripts (e.g., `040_mega328pb_ADL200.gcb`) and upload them to the ATmega328PB microcontroller.
2. **Hardware Setup**: Connect the ADL200 energy meter and GLCD to the microcontroller as described in [2. Getting_started.md](2. Getting_started.md).
3. **Run the System**: Power on the system to start monitoring and displaying energy data via the GLCD.

For a fully integrated setup, use `040_mega328pb_ADL200.gcb`, which combines serial communication, GLCD output, and Modbus protocol for comprehensive power monitoring.

## Dependencies
- **GCBASIC Compiler**: Required to compile the `.gcb` scripts.
- **ATmega328PB Microcontroller**: Target hardware for the project.
- **ADL200 Energy Meter**: For power data collection.
- **Graphical LCD**: For displaying energy metrics.
- **Modbus Library**: Included via `MODBus.h` for protocol support.

Ensure all dependencies are properly installed and configured as per [2. Getting_started.md](2. Getting_started.md).

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Submit a pull request with a clear description of your changes.

Please ensure your changes are compatible with the ATmega328PB and ADL200 hardware.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

</xaiArtifact>