# OLED Display System Description

The system uses a board under the OLED board, which contains an ST32 microcontroller. The main board, visible in the video clip, is the power control board equipped with a PIC16F716. This power control board uses 3oz copper, making it unsuitable for the fine-pitch components used beneath the OLED.

## Scrolling OLED Display Information

The scrolling OLED displays the following screens:

### 1. First Screen: Total Energy Stored
- **Display**: ENERGY STORED TOTAL kWh
- **Details**: 
  - Displays total energy in kWh, switching to MWh after reaching 999,999 kWh, with the possibility of rolling over to zero.
  - kWh reading is obtained from a register in the ADL200, representing the total energy consumed by the appliance (e.g., an electric hot water system).
  - The appliance is powered when solar energy is exported to the grid. It could alternatively be an air conditioner.

### 2. Second Screen: Instantaneous Power
- **Display**: Shows instantaneous power being imported from or exported to the grid (e.g., solar export from the solar inverter).
- **Details**:
  - In the video, an LED on the import side consumes 2W to ensure the current sense transformer's zero setting is accurate.
  - When importing power, exported power reads zero. When exporting, the OLED displays the exported power by interrogating the ADL200.

### 3. Third Screen: Current Consumption
- **Display**: Shows the current consumed by the heating element.
- **Details**:
  - The hot water service has a dual-element arrangement (800W and 1600W), allowing three heating levels: 800W, 1600W, or 2400W (both).
  - The PIC16F716 evaluates exported power and decides which element(s) to activate.
  - Delays are implemented to accommodate fridge/air-conditioner startups and to minimize relay switching, extending relay lifespan (large relays are in parallel).
  - Watts are calculated by multiplying the element's current (read from the current sense transformer) by the grid voltage (read from an ADL200 register).

### 4. Fourth Screen: Grid Voltage
- **Display**: Shows the grid voltage.
- **Details**: Obtained from an ADL200 register.

### 5. Fifth Screen: Water Temperature
- **Display**: Shows the temperature of the water in the hot water service.
- **Details**: Calculated using an NTC thermistor, independent of the ADL200.

## Additional Notes
- The video shows a second loop of the above screens.
- This setup is an example, and the system's possibilities are nearly limitless.