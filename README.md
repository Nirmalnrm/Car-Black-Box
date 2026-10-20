# Car Black Box

An educational embedded-systems project for recording and reviewing vehicle information in taxi and fleet-monitoring scenarios.

> The high-level project concept comes from the Emertxe LMS explanation video. The video establishes the use case—an in-vehicle device records information so it can be reviewed later—but it does not confirm a specific MCU, sensor set, protocol, storage device, or measured result. Those values remain configurable until the original hardware and source files are available.

## Objectives

- Monitor selected vehicle signals or sensors.
- Timestamp and validate incoming data.
- Detect important driving or vehicle events.
- Store records safely for later retrieval.
- Export data for viewing and analysis.
- Provide a modular foundation for fleet or taxi-service monitoring.

## System architecture

```text
vehicle signals/sensors -> input drivers -> controller -> event detection -> storage
                                         |                 |
                                         +-> diagnostics    +-> UART/USB/SD export -> analysis tools
```

The final interfaces are intentionally configurable. A real deployment must use automotive-rated power protection and verified vehicle interfaces.

## Proposed data record

```text
timestamp,speed,rpm,voltage,temperature,event
2026-10-21T14:32:18,52,2200,13.8,84,NORMAL
2026-10-21T14:32:26,18,1600,13.7,85,HARSH_BRAKING
```

The project can use CSV for simple inspection or a packed binary record for embedded storage. See [data-format/record-format.md](data-format/record-format.md).

## Repository structure

```text
Car-Black-Box/
├── README.md
├── docs/
│   ├── requirements.md
│   ├── architecture.md
│   └── test-plan.md
├── data-format/
│   └── record-format.md
├── firmware/
│   └── README.md
├── hardware/
│   └── README.md
├── tools/
│   └── README.md
└── tests/
    └── README.md
```

## Functional requirements

1. Initialize the controller, clock, input drivers, storage, and diagnostics.
2. Sample configured vehicle signals at a defined interval.
3. Reject invalid or out-of-range input values.
4. Detect configurable events such as harsh braking, overspeed, low voltage, or sensor failure.
5. Store a timestamped event or periodic record.
6. Preserve valid records across restart and handle storage-full conditions.
7. Provide a documented method to retrieve logs.
8. Make the implementation testable without connecting unverified hardware to a vehicle.

## Project status

This is the first complete project specification and repository scaffold. Firmware, schematics, measured thresholds, and test evidence must be added after the actual project hardware and original source files are confirmed.

## Safety and privacy

This repository is for education and engineering documentation. Do not connect unverified hardware to a vehicle network or safety-critical system. Real installation requires automotive electrical protection, safe isolation, data minimization, and compliance with applicable regulations.

## Source and author

- Project explanation: [3 MC Car black box](https://www.youtube.com/watch?v=9j2ciOnrLXY)
- Author: [Nirmal Mohan](https://github.com/Nirmalnrm)
- LinkedIn: [Nirmal Mohan](https://www.linkedin.com/in/nirmal-mohan-5426b431a)
