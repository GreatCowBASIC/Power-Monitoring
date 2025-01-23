# Development Introduction

## Basic Project Scope (for BC BASIC end-users):

1. **Connect the Acrel Power Meter**
   - Install the Acrel power meter into the mains power meter box.
   - A qualified electrician should handle this installation to ensure safety and compliance with local regulations.
   - Note: The supplied Acrel meter operates on 220V to 265V AC, but models for 110V to 120V AC are available.

2. **Program the PIC Microcontroller**
   - Program the PIC microcontroller with the "GCBASIC Import/Export Power" project code.
   - Including a Modbus-RTU library component in GCBASIC would be beneficial.

3. **Connect the PIC Micro to the Acrel Power Meter**
   - Use the PIC UART to TTL interface board to connect the PIC microcontroller to the Acrel power meter.
   - Connect two wires to the rs-485 terminals on the Acrel unit.
   - For longer runs, screened cables like 2 wire + screen microphone cable or CAT5/CAT6 cable should be used.
   - Typically, a 120R resistor is used at each end of the rs-485 communications cable, but for runs <25m, only one 120R resistor on the serial to TTL board is sufficient.

4. **Utilize Modbus-RTU Protocol**
   - The Acrel power meter uses Modbus-RTU protocol over the rs-485 data link.
   - Different holding registers store power information in the Acrel power meter.
   - Registers indicate instantaneous power import/export and update every few seconds.

5. **Touch LCD Screen Implementation**
   - Display the contents of the Acrel registers on the supplied touch LCD screen.
   - User can select power thresholds to control a relay for turning appliances on/off.
   - Example: Turn on a hot water system when exporting >2KW of power, or turn off an appliance when importing a certain amount of power.

   Example:
   - User selects >2KW of export power via the touch screen to turn on a hot water service.
   - When the Acrel power meter detects >2KW export, the PIC board turns on a relay to power the hot water service, using solar power instead of grid power.
   - Delays are required before turning off the relay, and the relay turns off if the household begins importing power again.

6. **Real World Application**
   - This project can help users save on energy bills by managing power import/export efficiently.
   - In Australia, for example, the system could be used to control a pool pump.

## Additional Information
- The ADL200 power meter is designed for installation in your mains power box.
- It measures imported/exported power and stores KWH data, which can be accessed anytime.

For more information or assistance, please feel free to ask.
