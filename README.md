# Automotive Button Driver

## Overview

The project uses DIO abstraction to read from input channels and provide button debounced states to application layer.The driver do not have direct register access and do not know about application logic.

---

## Module Responsibilities

- Uses the DIO driver to read digital input channels
- Applies debounce logic to button inputs
- Provides debounced button states to the application layer
- Does not access hardware registers directly
- Does not contain application-specific logic


---

## Architecture Position


```
│
├── 
│
├──
│
└──
```
---

## Configuration Concept


---

## API Overview


---

## Error Handling and Assumptions


---

## Target Hardware

- **MCU:** PIC18F4550
- **CLOCK:** 20 MHZ
- **Toolchain** XC8
- **Programmer** PICKit (pk2cmd)
- **OS:** Linux

---


