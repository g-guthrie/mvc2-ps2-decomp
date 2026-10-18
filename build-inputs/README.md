# Build inputs (not distributed)

The build needs a retail copy of the game executable and the period
compilers. **None of that is redistributable, so none of it is in this
repository.** You have to supply it yourself from material you already own
or have licensed.

The bundle `mvc2-ps2-build-inputs.tar.gz` is expected to contain:

    private/SLUS_204.86.rom            retail NTSC-U executable (SLUS-204.86)
    private/extracted/SLUS_204.86      the same image, extracted
    private/toolchain/compilers/mwcps2-3.0-011126/    Metrowerks CodeWarrior
    private/toolchain/compilers/mwcps2-3.0.3-020716/  Metrowerks CodeWarrior
    private/toolchain/compilers/sn-gcc-2.95.2/        SN Systems GCC
    private/toolchain/compilers/ee-gcc2.96/           EE GCC
    private/toolchain/wibo-x86_64, wibo-macos         wibo (MIT)

`private/SHA256SUMS` pins every file, so `tools/bootstrap_private_inputs.py`
will tell you if what you supplied differs from what this tree was matched
against.

Point the bootstrapper at your own copy:

    .venv/bin/python tools/bootstrap_private_inputs.py \
        --archive /path/to/mvc2-ps2-build-inputs.tar.gz

The Sony 2.9-ee-991111 compiler is fetched separately and automatically by
`tools/setup_sony29.py`, which downloads it from the public decompme
compilers release and verifies its SHA-256.
