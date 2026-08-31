#!/usr/bin/env python3

from pathlib import Path
import sys

from splat.util import conf, file_presets


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit(f"usage: {sys.argv[0]} CONFIG.yaml")
    conf.load([Path(sys.argv[1])], modes=["code"])
    file_presets.write_all_files()


if __name__ == "__main__":
    main()
