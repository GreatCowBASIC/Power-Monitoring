# TTL to RS-485 with Modbus Protocol

## Part 1 - Hardware & Understanding Modbus (in brief):
[Watch on YouTube](https://www.youtube.com/watch?v=HPZrGuBtk_c)

## Part 2 - Arduino Code Using Arduino Modbus Library:
[Watch on YouTube](https://www.youtube.com/watch?v=tBw15SfmuwI)

The Arduino, Raspberry Pi & ESP32 maker community love saving money. This is why they all have got into solar projects in a relatively big way.

You need to set up the ADL200 via its internal display for the rs-485 parameters being used (page 7 of manual).
[ADL200 Manual](https://www.acrelenergy.com/uploads/file/adl200-manual.pdf)
When you set the ADL200 parameters, they are stored in a register that can be accessed via rs-485. Just letting you know this, but no real need to access these unless you were trying to fault find why the data link is not working.
We will use 9600 baud.

## Holding Registers in the Acrel Power Meter

The holding registers in the Acrel power meter from the Acrel datasheet (pages 8, 9 & 10) that we are most interested in are:

1. **Total energy in KWH that the house has imported from the grid:**

>| Register | Measure    |
>|----------|------------|
>| 0068h    | Current forward active total energy  |


2. **Total energy in KWH that the house has exported to the grid (from the house solar panels):**

>| Register | Measure    |
>|----------|------------|
>| 0072h    | Current reversing active total energy|

3. **Instantaneous energy in KW that the house is importing from the grid:**

>| Register | Measure    |
>|----------|------------|
>| 006Ch    | Current forward active peak energy|

4. **Instantaneous energy in KW that the house is exporting to the grid:**

>| Register | Measure    |
>|----------|------------|
>| 0068h    | Current reversing peak energy|

The project will use these last 2 parameters above to determine if an appliance should be turned on or off. The touch LCD will be used to store the setting (in KW) the user wants to turn on or off a relay, which in turn turns on or off an appliance. The idea is to turn on an appliance when exporting power to the grid & to turn off an appliance when importing from the grid. Generally we use a delay of 20 seconds of exporting power before turning on an appliance & 7 minutes of importing power before turning off an appliance. The longer delay time for turn off is calculated on a 15 to 20 year life of the relays being used.

If power is being imported, the export register `0076H` should return a zero value & if power is being exported, the import register `006CH` should return a zero value.

>| Register | Measure    |
>|----------|------------|
>| 5300h    | voltage  |
>| 5302h    | current  |


## Instantaneous AC Mains Voltage & Current

Below are the registers for the instantaneous AC mains voltage & current. These can be interrogated & the results printed on the LCD display.

1. **Instantaneous AC mains frequency (if you want to display it on the LCD - we don't use it)**

>| Register | Measure    |
>|----------|------------|
>| 530Ch    | frequency  |


 
