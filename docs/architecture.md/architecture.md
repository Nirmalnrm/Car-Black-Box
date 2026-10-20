# System Architecture

## Data flow

1. Input drivers receive configured sensor, digital, analog, or vehicle-bus values.
2. Validation converts raw values into documented units and rejects invalid samples.
3. The event detector evaluates thresholds and state transitions.
4. The recorder adds time and integrity information.
5. Storage persists periodic samples and important events.
6. An export interface transfers records to a host-side analysis tool.

## Module boundaries

- `input`: sensor and communication drivers.
- `processing`: unit conversion, filtering, validation, and thresholds.
- `events`: event state machine and event classification.
- `storage`: append, read, integrity check, and full-storage handling.
- `clock`: timestamp source and time validity.
- `diagnostics`: health, fault codes, and counters.
- `export`: UART, USB, SD, or another verified retrieval interface.

## Configuration

Keep the following in one configuration layer: sampling interval, signal ranges, event thresholds, storage capacity, and interface selection. Do not hard-code values before the target hardware is confirmed.

## Failure behavior

- Invalid samples are rejected and counted.
- Communication timeouts produce a diagnostic event.
- Storage errors are reported and must not be mistaken for valid records.
- A restart must not silently overwrite valid records.
- Automotive power faults require hardware protection and a controlled test setup.
