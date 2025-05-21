// MODBUS Function Code Constants
#DEFINE MODBUS_READ_COILS                       0x01    // Read Coils
#DEFINE MODBUS_READ_DISCRETE_INPUTS             0x02    // Read Discrete Inputs
#DEFINE MODBUS_READ_HOLDING_REGS                0x03    // Read Holding Registers
#DEFINE MODBUS_READ_INPUT_REGS                  0x04    // Read Input Registers
#DEFINE MODBUS_WRITE_SINGLE_COIL                0x05    // Write Single Coil
#DEFINE MODBUS_WRITE_SINGLE_REG                 0x06    // Write Single Holding Register
#DEFINE MODBUS_WRITE_MULTIPLE_COILS             0x0F    // Write Multiple Coils
#DEFINE MODBUS_WRITE_MULTIPLE_REGS              0x10    // Write Multiple Holding Registers
#DEFINE MODBUS_READ_WRITE_REGS                  0x17    // Read/Write Multiple Registers
#DEFINE MODBUS_MASK_WRITE_REG                   0x16    // Mask Write Register
#DEFINE MODBUS_READ_FIFO_QUEUE                  0x18    // Read FIFO Queue

// MODBUS Exception Codes
#DEFINE MODBUS_EXCEPTION_ILLEGAL_FUNCTION         0x01    // Error Code 01 - Illegal Function
#DEFINE MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS     0x02    // Error Code 02 - Illegal Data Address
#DEFINE MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE       0x03    // Error Code 03 - Illegal Data Value
#DEFINE MODBUS_EXCEPTION_SLAVE_DEVICE_FAILURE     0x04    // Error Code 04 - Slave Device Failure
#DEFINE MODBUS_EXCEPTION_ACKNOWLEDGE              0x05    // Error Code 05 - Acknowledge
#DEFINE MODBUS_EXCEPTION_SLAVE_DEVICE_BUSY        0x06    // Error Code 06 - Slave Device Busy
#DEFINE MODBUS_EXCEPTION_MEMORY_PARITY_ERROR      0x08    // Error Code 08 - Memory Parity Error
#DEFINE MODBUS_EXCEPTION_GATEWAY_PATH_UNAVAILABLE 0x0A    // Error Code 0A - Gateway Path Unavailable
#DEFINE MODBUS_EXCEPTION_GATEWAY_TARGET_FAILED    0x0B    // Error Code 0B - Gateway Target Device Failed to Respond




/*
    In MODBUS communication, 0x80 is often associated with error conditions when interpreting exception responses. 
    Specifically: When a slave device encounters an error while processing a function request, 
    it typically modifies the function code in the response. 
    The function code is OR-ed with 0x80, effectively setting the highest bit to indicate an error condition.

*/
#DEFINE MODBUS_EXCEPTION_MASK                     0x80    // Error mask


' Function to build MODBUS RTU request with CRC calculation
Sub ModBusRequest(_ModBusSlaveID As Byte, _ModBusFunctionCode As Byte, _ModBusRegisterAddress As Word, _ModBusNumRegisters As Word, out _ModBusRequestArray() ) As Byte
    
    Dim _ModBusRequestArray(7) As Byte   ' MODBUS RTU message structure
    Dim _ModBus_CRC As Word
    
    ' Construct the MODBUS RTU request
    _ModBusRequestArray(0) = _ModBusSlaveID
    _ModBusRequestArray(1) = _ModBusFunctionCode
    _ModBusRequestArray(2) = _ModBusRegisterAddress_H
    _ModBusRequestArray(3) = _ModBusRegisterAddress
    _ModBusRequestArray(4) = _ModBusNumRegisters_H
    _ModBusRequestArray(5) = _ModBusNumRegisters
    
    ' Calculate CRC-16
    _ModBus_CRC = _ModBusCRC(_ModBusRequestArray, 6)
    _ModBusRequestArray(6) = _ModBus_CRC
    _ModBusRequestArray(7) = _ModBus_CRC_H

End Sub

' Function to calculate CRC-16 (MODBUS RTU)
Function _ModBusCRC(_ModBusData() As Byte, _ModBusLength As Byte) As Word
    Dim _ModBus_CRC As Word 
    _ModBus_CRC = 0xFFFF
    Dim _ModBusI, _ModBusJ As Byte
    
    For _ModBusI = 0 To (_ModBusLength - 1)
        _ModBus_CRC = _ModBus_CRC Xor _ModBusData(_ModBusI)
        
        For _ModBusJ = 0 To 7
            If (_ModBus_CRC And 0x0001) <> 0 Then
                _ModBus_CRC = (_ModBus_CRC >> 1) Xor 0xA001
            Else
                _ModBus_CRC = _ModBus_CRC >> 1
            End If
        Next _ModBusJ
    Next _ModBusI
    
    Return _ModBus_CRC
End Function
