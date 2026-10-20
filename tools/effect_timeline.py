#!/usr/bin/env python3
"""Parse the native 0x422150 effect/timeline bytecode grammar.

The parser mirrors only stream cursor movement from the retail disassembly:
the target-pointer adjustments for opcodes 5 and 13 do not consume bytes.
"""

from __future__ import annotations

from dataclasses import dataclass


class TimelineParseError(ValueError):
    pass


@dataclass(frozen=True)
class Command:
    offset: int
    opcode: int
    operand: bytes = b""


@dataclass(frozen=True)
class Record:
    start: int
    end: int
    base: int
    preamble: tuple[Command, ...]
    commands: tuple[Command, ...]


@dataclass(frozen=True)
class Program:
    start: int
    end: int
    count: int
    records: tuple[Record, ...]


@dataclass(frozen=True)
class ByteField:
    offset: int
    name: str
    value: int


@dataclass(frozen=True)
class Run:
    start: int
    end: int
    kind: str
    fields: tuple[ByteField, ...] = ()


def partition_program(data: bytes, program: Program) -> tuple[Run, ...]:
    """Split a parsed program into native-read fields and opaque cursor skips."""
    fields: dict[int, ByteField] = {}

    def typed(offset: int, name: str) -> None:
        fields[offset] = ByteField(offset, name, data[offset])

    typed(program.start, "record_count")
    for record in program.records:
        typed(record.start, "record_base_byte")
        for command in record.preamble:
            op = command.opcode
            prefix = f"preamble_{command.offset:03X}"
            typed(command.offset, f"{prefix}_opcode_{op:02X}")
            if op == 1:
                names = (
                    "be16_a_high", "be16_a_low", "be16_b_high", "be16_b_low",
                    "native_read_u8",
                )
                for index, name in enumerate(names):
                    typed(command.offset + 1 + index, f"{prefix}_{name}")
            elif op in {5, 6, 7, 8, 9, 11}:
                label = "saved_value" if op == 5 else "payload_u8"
                typed(command.offset + 1, f"{prefix}_{label}")
            # Preamble opcode 12 advances over two bytes without loading them.
        for command in record.commands:
            op = command.opcode
            prefix = f"body_{command.offset:03X}"
            if op == 0:
                typed(command.offset, f"{prefix}_terminator_opcode")
            elif op == 1:
                typed(command.offset, f"{prefix}_opcode_01")
                typed(command.offset + 1, f"{prefix}_be16_high")
                typed(command.offset + 2, f"{prefix}_be16_low")
                # The native cursor advances by three further bytes without loads.
            elif op == 4:
                typed(command.offset, f"{prefix}_opcode_04")
                typed(command.offset + 1, f"{prefix}_opcode_04_payload")
            elif op == 5:
                typed(command.offset, f"{prefix}_target_adjust_opcode_05")
            elif op == 10:
                typed(command.offset, f"{prefix}_opcode_0A")
                typed(command.offset + 1, f"{prefix}_opcode_0A_payload")
            elif op == 13:
                typed(command.offset, f"{prefix}_target_adjust_opcode_0D")
            else:
                typed(command.offset, f"{prefix}_native_opcode_{op:02X}")

    runs: list[Run] = []
    cursor = program.start
    while cursor < program.end:
        is_typed = cursor in fields
        end = cursor + 1
        while end < program.end and (end in fields) == is_typed:
            end += 1
        run_fields = tuple(fields[pos] for pos in range(cursor, end)) if is_typed else ()
        runs.append(Run(cursor, end, "native_read" if is_typed else "opaque", run_fields))
        cursor = end
    return tuple(runs)


def _take(data: bytes, cursor: int, count: int, limit: int, what: str) -> tuple[bytes, int]:
    end = cursor + count
    if end > limit:
        raise TimelineParseError(
            f"truncated {what} at offset 0x{cursor:X}: needs {count} byte(s), "
            f"boundary is 0x{limit:X}"
        )
    return data[cursor:end], end


def parse_program(data: bytes, start: int, limit: int) -> Program:
    """Parse one count-prefixed program from *start*, bounded by *limit*.

    A program is a count byte followed by that many records. Each record has
    one base byte, a preamble ending at opcode 1, and body commands ending at
    opcode 0. Offsets and limits are relative to ``data``.
    """
    if start < 0 or limit < start or limit > len(data):
        raise TimelineParseError("invalid program bounds")
    raw, cursor = _take(data, start, 1, limit, "record count")
    count = raw[0]
    records: list[Record] = []
    for _ in range(count):
        record_start = cursor
        raw, cursor = _take(data, cursor, 1, limit, "record base")
        base = raw[0]
        preamble: list[Command] = []
        while True:
            offset = cursor
            raw, cursor = _take(data, cursor, 1, limit, "preamble opcode")
            opcode = raw[0]
            operand = b""
            if opcode == 1:
                operand, cursor = _take(data, cursor, 5, limit, "preamble opcode 1 payload")
                preamble.append(Command(offset, opcode, operand))
                break
            if opcode == 12:
                operand, cursor = _take(data, cursor, 2, limit, "preamble opcode 12 opaque payload")
            elif opcode in {5, 6, 7, 8, 9, 11}:
                operand, cursor = _take(data, cursor, 1, limit, f"preamble opcode {opcode} payload")
            # Opcodes 0, 2, 3, 4, 10 and >=13 are one-byte preamble opcodes.
            preamble.append(Command(offset, opcode, operand))

        commands: list[Command] = []
        while True:
            offset = cursor
            raw, cursor = _take(data, cursor, 1, limit, "body opcode/terminator")
            opcode = raw[0]
            operand = b""
            if opcode == 0:
                commands.append(Command(offset, opcode))
                break
            if opcode == 1:
                operand, cursor = _take(data, cursor, 5, limit, "body opcode 1 payload")
            elif opcode in {4, 10}:
                operand, cursor = _take(data, cursor, 1, limit, f"body opcode {opcode} payload")
            # Opcode 5 adds the saved preamble byte to the target pointer;
            # opcode 13 adds eight. Neither operation advances this cursor.
            commands.append(Command(offset, opcode, operand))
        records.append(Record(record_start, cursor, base, tuple(preamble), tuple(commands)))
    return Program(start, cursor, count, tuple(records))
