
#include "MODBus.h"


Table ADL200_REGISTER_FORMATS
    //! Constant ( set to physical address ), length of bytes.  4 = Word, 2 = byte, 1 = byte
    ADL200_CURRENT_TOTAL_ACTIVE_ENERGY, 4
    ADL200_CURRENT_SPIKE_ACTIVE_ENERGY, 4
    ADL200_CURRENT_PEAK_ACTIVE_ENERGY, 4
    ADL200_CURRENT_FLAT_ACTIVE_ENERGY, 4
    ADL200_CURRENT_VALLEY_ACTIVE_ENERGY, 4
    ADL200_CODE, 2
    ADL200_VOLTAGE, 2
    ADL200_CURRENT, 2
    ADL200_ACTIVE_POWER, 2
    ADL200_REACTIVE_POWER, 2
    ADL200_APPARENT_POWER, 2
    ADL200_POWER_FACTOR, 2
    ADL200_FREQUENCY, 2
    ADL200_YEAR_MONTH, 2
    ADL200_DAY_HOUR, 2
    ADL200_MINUTE_SECOND, 2
    ADL200_DEVICE_ADDRESS, 1
    ADL200_LIGHT_TIME, 2
    ADL200_TOTAL_ACTIVE_LAST_MONTH, 2
    ADL200_CURRENT_FORWARD_TOTAL_ENERGY, 2
End Table


// ADL200 MODBUS Register Addresses
#DEFINE ADL200_CURRENT_TOTAL_ACTIVE_ENERGY      0x0000  // Current combined total active energy (Unit: 0.01kWh)
#DEFINE ADL200_CURRENT_SPIKE_ACTIVE_ENERGY      0x0002  // Current combined spike active energy
#DEFINE ADL200_CURRENT_PEAK_ACTIVE_ENERGY       0x0004  // Current combined peak active energy
#DEFINE ADL200_CURRENT_FLAT_ACTIVE_ENERGY       0x0006  // Current combined flat active energy
#DEFINE ADL200_CURRENT_VALLEY_ACTIVE_ENERGY     0x0008  // Current combined valley active energy
#DEFINE ADL200_CODE                             0x000A  // Code
#DEFINE ADL200_VOLTAGE                          0x000B  // Voltage (Unit: 0.1V)
#DEFINE ADL200_CURRENT                          0x000C  // Current (Unit: 0.01A)
#DEFINE ADL200_ACTIVE_POWER                     0x000D  // Active power (Unit: 0.001kW)
#DEFINE ADL200_REACTIVE_POWER                   0x000E  // Reactive power (Unit: 0.001kvar)
#DEFINE ADL200_APPARENT_POWER                   0x000F  // Apparent power (Unit: 0.001kVA)
#DEFINE ADL200_POWER_FACTOR                     0x0010  // Power factor (Unit: 0.001)
#DEFINE ADL200_FREQUENCY                        0x0011  // Frequency (Unit: 0.01Hz)

#DEFINE ADL200_YEAR_MONTH                       0x0012  // Year, Month (R/W)
#DEFINE ADL200_DAY_HOUR                         0x0013  // Day, Hour (R/W)
#DEFINE ADL200_MINUTE_SECOND                    0x0014  // Minute, Second (R/W)
#DEFINE ADL200_DEVICE_ADDRESS                   0x0015  // Device Address (0-254) (R/W)
#DEFINE ADL200_BAUD_RATE                        0x0015  // Communication Baud Rate
#DEFINE ADL200_LIGHT_TIME                       0x0016  // Light time (R/W)

#DEFINE ADL200_TOTAL_ACTIVE_LAST_MONTH          0x0022  // Total active energy of last month (Unit: 0.01kWh)
#DEFINE ADL200_SPIKE_ACTIVE_LAST_MONTH          0x0024  // Spike active energy of last month
#DEFINE ADL200_PEAK_ACTIVE_LAST_MONTH           0x0026  // Peak active energy of last month
#DEFINE ADL200_FLAT_ACTIVE_LAST_MONTH           0x0028  // Flat active energy of last month
#DEFINE ADL200_VALLEY_ACTIVE_LAST_MONTH         0x002A  // Valley active energy of last month
#DEFINE ADL200_TOTAL_ACTIVE_LAST_2_MONTH        0x002C  // Total active energy of last 2 months
#DEFINE ADL200_SPIKE_ACTIVE_LAST_2_MONTH        0x002E  // Spike active energy of last 2 months
#DEFINE ADL200_PEAK_ACTIVE_LAST_2_MONTH         0x0030  // Peak active energy of last 2 months
#DEFINE ADL200_FLAT_ACTIVE_LAST_2_MONTH         0x0032  // Flat active energy of last 2 months
#DEFINE ADL200_VALLEY_ACTIVE_LAST_2_MONTH       0x0034  // Valley active energy of last 2 months
#DEFINE ADL200_TOTAL_ACTIVE_LAST_3_MONTH        0x0036  // Total active energy of last 3 months
#DEFINE ADL200_SPIKE_ACTIVE_LAST_3_MONTH        0x0038  // Spike active energy of last 3 months
#DEFINE ADL200_PEAK_ACTIVE_LAST_3_MONTH         0x003A  // Peak active energy of last 3 months
#DEFINE ADL200_FLAT_ACTIVE_LAST_3_MONTH         0x003C  // Flat active energy of last 3 months
#DEFINE ADL200_VALLEY_ACTIVE_LAST_3_MONTH       0x003E  // Valley active energy of last 3 months

#DEFINE ADL200_STATUS                           0x0045  // Status (R/W)
#DEFINE ADL200_PARITY                           0x0048  // Parity (None: 0000, Even: 0002)

#DEFINE ADL200_CURRENT_FORWARD_TOTAL_ENERGY     0x0068  // Current forward active total energy (Unit: 0.01kWh)
#DEFINE ADL200_CURRENT_FORWARD_SPIKE_ENERGY     0x006A  // Current forward active spike energy
#DEFINE ADL200_CURRENT_FORWARD_PEAK_ENERGY      0x006C  // Current forward active peak energy
#DEFINE ADL200_CURRENT_FORWARD_FLAT_ENERGY      0x006E  // Current forward active flat energy
#DEFINE ADL200_CURRENT_FORWARD_VALLEY_ENERGY    0x0070  // Current forward active valley energy
#DEFINE ADL200_CURRENT_REVERSING_TOTAL_ENERGY   0x0072  // Current reversing active total energy
#DEFINE ADL200_CURRENT_REVERSING_SPIKE_ENERGY   0x0074  // Current reversing active spike energy
#DEFINE ADL200_CURRENT_REVERSING_PEAK_ENERGY    0x0076  // Current reversing active peak energy
#DEFINE ADL200_CURRENT_REVERSING_FLAT_ENERGY    0x0078  // Current reversing active flat energy
#DEFINE ADL200_CURRENT_REVERSING_VALLEY_ENERGY  0x007A  // Current reversing active valley energy

#DEFINE ADL200_CURRENT_TOTAL_REACTIVE_ENERGY    0x00B0  // Current total reactive energy (Unit: 0.01kVarh)
#DEFINE ADL200_CURRENT_SPIKE_REACTIVE_ENERGY    0x00B2  // Current spike reactive energy
#DEFINE ADL200_CURRENT_PEAK_REACTIVE_ENERGY     0x00B4  // Current peak reactive energy
#DEFINE ADL200_CURRENT_FLAT_REACTIVE_ENERGY     0x00B6  // Current flat reactive energy
#DEFINE ADL200_CURRENT_VALLEY_REACTIVE_ENERGY   0x00B8  // Current valley reactive energy
#DEFINE ADL200_CURRENT_FORWARD_REACTIVE_TOTAL   0x00BA  // Current forward reactive total energy
#DEFINE ADL200_CURRENT_FORWARD_REACTIVE_SPIKE   0x00BC  // Current forward reactive spike energy
#DEFINE ADL200_CURRENT_FORWARD_REACTIVE_PEAK    0x00BE  // Current forward reactive peak energy
#DEFINE ADL200_CURRENT_FORWARD_REACTIVE_FLAT    0x00C0  // Current forward reactive flat energy
#DEFINE ADL200_CURRENT_FORWARD_REACTIVE_VALLEY  0x00C2  // Current forward reactive valley energy
#DEFINE ADL200_CURRENT_REVERSING_REACTIVE_TOTAL 0x00C4  // Current reversing reactive total energy
#DEFINE ADL200_CURRENT_REVERSING_REACTIVE_SPIKE 0x00C6  // Current reversing reactive spike energy
#DEFINE ADL200_CURRENT_REVERSING_REACTIVE_PEAK  0x00C8  // Current reversing reactive peak energy
#DEFINE ADL200_CURRENT_REVERSING_REACTIVE_FLAT  0x00CA  // Current reversing reactive flat energy
#DEFINE ADL200_CURRENT_REVERSING_REACTIVE_VALLEY 0x00CC // Current reversing reactive valley energy

// Floating Point Measurements
#DEFINE ADL200_VOLTAGE_FLOAT                    0x5300  // Voltage (Float)
#DEFINE ADL200_CURRENT_FLOAT                    0x5302  // Current (Float)
#DEFINE ADL200_ACTIVE_POWER_FLOAT               0x5304  // Active power (Float)
#DEFINE ADL200_REACTIVE_POWER_FLOAT             0x5306  // Reactive power (Float)
#DEFINE ADL200_APPARENT_POWER_FLOAT             0x5308  // Apparent power (Float)
#DEFINE ADL200_POWER_FACTOR_FLOAT               0x530A  // Power factor (Float)
#DEFINE ADL200_FREQUENCY_FLOAT                  0x530C  // Frequency (Float)
