# Car Black Box
A documentation-first embedded systems project exploring a compact vehicle black-box device for recording and reviewing vehicle information in a fleet or taxi-service context.
> This repository is based on the project explanation video supplied from the Emertxe LMS. Hardware part numbers, sensor specifications, communication protocols, and measured results are intentionally left as placeholders until the implementation details are added.
## Project motivation
A small in-vehicle recorder can help a taxi or fleet operator collect information from several vehicles and review it later. The project explanation describes a use case involving a taxi service with multiple vehicles and a device that records information for later viewing.
## System concept
```
Vehicle signals / sensors
          │
          ▼
   Car black-box device
          │
          ▼
 Recorded data → later review and analysis
```
## Intended capabilities
- Compact in-vehicle monitoring device
- Recording of relevant vehicle information
- Support for fleet or taxi-service monitoring
- Retrieval or viewing of recorded information
- A foundation for later event and driving analysis
## Project status
This repository currently contains the project documentation and planned structure. The implementation should be added in a follow-up commit after the original source files, circuit details, and test evidence are collected.
## Planned repository structure
```
Car-Black-Box/
├── README.md
├── firmware/       # Embedded firmware
├── hardware/       # Schematics, PCB, and wiring documentation
├── data-format/    # Recorded-data format and message definitions
├── tools/          # Host-side viewing or analysis tools
├── tests/          # Test cases and recorded test evidence
└── docs/           # Design notes and project documentation
```
## Information still to document
- Microcontroller and development environment
- Sensors and vehicle signals monitored
- Storage medium and data format
- Communication interface or protocol
- Recording trigger and sampling strategy
- Data-viewing or analysis workflow
- Power supply and automotive protection
- Test setup, test cases, and measured results
## Safety and privacy
This project is for educational and engineering documentation. Any real-vehicle deployment must consider automotive electrical protection, safe installation, data privacy, and local regulations. Do not connect unverified hardware to a vehicle network.
## Source video
Project explanation: [3 MC Car black box](https://www.youtube.com/watch?v=9j2ciOnrLXY)
## Author
**Nirmal Mohan**  
[GitHub profile](https://github.com/Nirmalnrm) · [LinkedIn](https://www.linkedin.com/in/nirmal-mohan-5426b431a)
