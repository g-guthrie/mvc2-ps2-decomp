import unittest

from tools.objdiff_report import DATA_SIZE, TEXT_SIZE, build_report


class ProjectTest(unittest.TestCase):
    def test_wired_sources_accepts_preprocessed_sdk_assembly(self):
        from tools.check_build_coverage import wired_sources

        assembly_compile = (
            '"$WIBO" "$SNCPP" -P src/primitive.S "$BUILD/primitive.s"\n'
            '"$WIBO" "$SNAS" -G0 -o "$BUILD/primitive.o" "$BUILD/primitive.s"\n'
        )
        verification = (
            '"$PYTHON" tools/verify_object.py "$BUILD/primitive.o" '
            'private/SLUS_204.86.rom --source src/primitive.S\n'
        )
        legacy = (
            '"$PYTHON" tools/verify_object.py "$BUILD/legacy.o" '
            'private/SLUS_204.86.rom --source "src/legacy.c"\n'
        )
        self.assertEqual(wired_sources(assembly_compile), set())
        self.assertEqual(
            wired_sources(legacy + assembly_compile + verification),
            {"src/legacy.c", "src/primitive.S"},
        )
        for invalid in ("src/primitive.S.disabled", "src/legacy.c.disabled", "src/header.h"):
            with self.subTest(source=invalid):
                self.assertEqual(wired_sources(f'--source {invalid}\n'), set())

    def test_deci2_sdk_assembly_credit_has_production_recipe(self):
        import csv
        from pathlib import Path
        from tools.check_build_coverage import wired_sources

        root = Path(__file__).resolve().parent.parent
        script = (root / "tools/compile_matching.sh").read_text()
        with (root / "config/matches.csv").open(newline="") as handle:
            owners = [row for row in csv.DictReader(handle)
                      if row["name"] == "func_00104210"]
        self.assertEqual(len(owners), 1)
        self.assertEqual(owners[0]["source"], "src/sony_deci2_call.S")
        self.assertEqual(int(owners[0]["size"], 0), 16)
        self.assertIn(owners[0]["source"], wired_sources(script))
        cpp = script.index('"$SNCPP" -P src/sony_deci2_call.S ')
        assemble = script.index('"$SNAS" -G0 -o "$BUILD/sony_deci2_call.o" ')
        verify = script.index('tools/verify_object.py "$BUILD/sony_deci2_call.o" ')
        self.assertLess(cpp, assemble)
        self.assertLess(assemble, verify)
        self.assertNotIn(
            "void func_00104210(void)",
            (root / "src/grok_tiny_leaves.c").read_text(),
        )

    def test_semaphore_sdk_provider_keeps_existing_credit_and_integer_results(self):
        import csv
        from pathlib import Path
        from tools.check_build_coverage import wired_sources

        root = Path(__file__).resolve().parent.parent
        names = {"func_00103DE0", "func_00103DF0", "func_00103E00",
                 "func_00103E10", "func_00103E20"}
        source = "src/sony29_kernel_semaphore_calls.S"
        with (root / "config/matches.csv").open(newline="") as handle:
            rows = [row for row in csv.DictReader(handle) if row["name"] in names]
        self.assertEqual(len(rows), len(names))
        self.assertEqual({row["name"] for row in rows}, names)
        self.assertEqual({row["source"] for row in rows}, {source})
        self.assertEqual([int(row["size"], 0) for row in rows], [16] * 5)
        self.assertIn(source, wired_sources((root / "tools/compile_matching.sh").read_text()))
        legacy = (root / "src/grok_tiny_leaves.c").read_text()
        header = (root / "src/sony29_kernel_semaphore_calls.h").read_text()
        assembly = (root / source).read_text()
        for name in sorted(names):
            with self.subTest(name=name):
                self.assertNotRegex(legacy, rf"\b{name}\s*\([^;{{}}]*\)\s*\{{")
                self.assertRegex(header, rf"\bint\s+{name}\s*\(")
                self.assertIn(f"SYSCALL_SPECIAL({name},", assembly)

    def test_data_build_must_follow_all_code_compiles(self):
        from tools.check_build_coverage import premature_data_build_commands

        valid = (
            'MWCIncludes="$MWCCPS2" "$WIBO" "$MWCCPS2" \\\n'
            '    src/owner.c -c -lang c \\\n'
            '    -o "$BUILD/owner.o"\n'
            'for unit in other_owner; do\n'
            '    "$WIBO" "$MWCCPS2" "src/$unit.c" -c -lang c \\\n'
            '        -o "$BUILD/$unit.o"\n'
            'done\n'
            'PYTHON="$PYTHON" tools/compile_matching_data.sh\n'
        )
        self.assertEqual(premature_data_build_commands(valid), [])

        invalid = (
            'PYTHON="$PYTHON" tools/compile_matching_data.sh\n'
            'MWCIncludes="$MWCCPS2" "$WIBO" "$MWCCPS2" \\\n'
            '    src/late_owner.c -c -lang c \\\n'
            '    -o "$BUILD/late_owner.o"\n'
            'for unit in later_owner; do\n'
            '    "$WIBO" "$MWCCPS2" "src/$unit.c" -c -lang c \\\n'
            '        -o "$BUILD/$unit.o"\n'
            'done\n'
        )
        self.assertEqual(
            premature_data_build_commands(invalid),
            ['src/late_owner.c -c -lang c \\', 'for unit in later_owner; do'],
        )

    def test_compile_continuations_cannot_escape_spaces_before_flags(self):
        from tools.check_build_coverage import malformed_compile_continuations

        valid = (
            'MWCIncludes="$MWCCPS2" "$WIBO" "$MWCCPS2" \\\n'
            '    src/motion.c -c -lang c -i src \\\n'
            '    -o "$BUILD/motion.o"\n'
        )
        malformed = (
            'MWCIncludes="$MWCCPS2" "$WIBO" "$MWCCPS2" \\\n'
            '    src/motion.c -c -lang c -i src \\    -o "$BUILD/motion.o"\n'
        )
        self.assertEqual(
            malformed_compile_continuations(valid),
            [],
        )
        self.assertEqual(
            malformed_compile_continuations(
                '"$WIBO" "$MWCCPS2" src/motion\\ draft.c -c -o "$BUILD/motion.o"\n'
            ),
            [],
        )
        self.assertEqual(
            malformed_compile_continuations(malformed),
            [malformed.splitlines()[1].strip()],
        )

    def test_orphan_object_verification_heads_are_rejected(self):
        from tools.check_build_coverage import detached_object_verification_commands

        valid = (
            '"$PYTHON" tools/verify_object.py \\\n'
            '    "$BUILD/grok_good.o" private/SLUS_204.86.rom \\\n'
            '    --source src/grok_good.c\n'
        )
        for object_path in ('"$BUILD/grok_bad.o"', '$BUILD/grok_bad.o'):
            with self.subTest(object_path=object_path):
                script = (
                    valid
                    + f'    {object_path} private/SLUS_204.86.rom \\\n'
                    + '    --source src/grok_bad.c\n'
                )
                self.assertEqual(
                    detached_object_verification_commands(script),
                    [f'{object_path} private/SLUS_204.86.rom \\'],
                )

    def test_multiline_compile_and_verify_continuations_are_valid(self):
        from tools.check_build_coverage import (
            detached_object_verification_commands,
            detached_source_commands,
        )

        script = (
            'WIBO="$WIBO" "$MWCCPS2" \\\n'
            '    src/grok_good.c -c -lang c \\\n'
            '    -o "$BUILD/grok_good.o"\n'
            '"$PYTHON" tools/verify_object.py \\\n'
            '    "$BUILD/grok_good.o" private/SLUS_204.86.rom \\\n'
            '    --source src/grok_good.c\n'
        )
        self.assertEqual(detached_source_commands(script), [])
        self.assertEqual(detached_object_verification_commands(script), [])

    def test_duplicate_match_ownership_is_rejected(self):
        from pathlib import Path
        import tempfile
        from tools.objdiff_report import load_matches

        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "matches.csv"
            path.write_text(
                "name,address,size,source,status\n"
                "func_00100008,0x00100008,0x8,src/first.c,complete\n"
                "func_00100008,0x00100008,0x8,src/second.c,complete\n",
                encoding="utf-8",
            )
            with self.assertRaisesRegex(SystemExit, "duplicate code match"):
                load_matches(path)

    def test_duplicate_data_ownership_is_rejected(self):
        from pathlib import Path
        import tempfile
        from tools.objdiff_report import load_data_matches

        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            units = root / "units.csv"
            matches = root / "matches.csv"
            units.write_text(
                "name,address,size\na,0x00424200,0x8\n", encoding="utf-8"
            )
            matches.write_text(
                "name,address,size,source,status,progress\n"
                "a,0x00424200,0x8,src/a.c,complete,reconstructed\n"
                "a,0x00424200,0x8,src/b.c,complete,reconstructed\n",
                encoding="utf-8",
            )
            with self.assertRaisesRegex(SystemExit, "duplicate data match"):
                load_data_matches(units, matches)
            units.write_text(
                "name,address,size\na,0x00424200,0x8\na,0x00424200,0x8\n",
                encoding="utf-8",
            )
            with self.assertRaisesRegex(SystemExit, "duplicate data unit"):
                load_data_matches(units, matches)

    def test_source_tiles_preserve_totals_across_chunk_boundary(self):
        result = build_report(
            [{"name": "crossing", "address": 0x10FFFC, "size": 8}],
            {"crossing": {"address": 0x10FFFC, "size": 8,
                          "source": "src/crossing.c", "complete": True, "progress": "reconstructed"}},
        )
        units = result["units"]
        self.assertEqual(sum(int(u["measures"].get("total_code", 0)) for u in units), TEXT_SIZE)
        self.assertEqual(sum(u["measures"].get("total_functions", 0) for u in units), 1)
        tile = next(u for u in units if u["name"] == "src/crossing.c")
        self.assertEqual(tile["measures"]["fuzzy_match_percent"], 100)
        self.assertTrue(tile["metadata"]["complete"])
        self.assertNotIn("data_matches", units[-1]["metadata"])

    def test_report_is_objdiff_v2_and_conservative(self):
        result = build_report(
            [{"name": "func_00100008", "address": 0x00100008, "size": 8}],
            {"func_00100008": {
                "address": 0x00100008,
                "size": 8,
                "source": "src/main.c",
                "complete": True, "progress": "reconstructed",
            }},
        )
        self.assertEqual(result["version"], 2)
        self.assertEqual(result["measures"]["total_code"], str(TEXT_SIZE))
        self.assertEqual(result["measures"]["total_data"], str(DATA_SIZE))
        self.assertEqual(result["measures"]["matched_code"], "8")
        self.assertEqual(result["measures"]["matched_functions"], 1)
        self.assertEqual(result["measures"]["complete_code"], "8")
        self.assertEqual(result["units"][0]["metadata"]["progress_categories"], ["main"])

    def test_overlapping_data_units_are_rejected(self):
        from pathlib import Path
        import tempfile
        from tools.objdiff_report import load_data_matches

        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "units.csv").write_text(
                "name,address,size\n"
                "a,0x00424200,0x20\n"
                "b,0x00424210,0x20\n",
                encoding="utf-8",
            )
            (root / "matches.csv").write_text(
                "name,address,size,source,status,progress\n"
                "a,0x00424200,0x20,src/a.c,complete,placeholder\n"
                "b,0x00424210,0x20,src/b.c,complete,reconstructed\n",
                encoding="utf-8",
            )
            with self.assertRaisesRegex(SystemExit, "overlapping data units"):
                load_data_matches(root / "units.csv", root / "matches.csv")
            for classification in ("", "typo"):
                (root / "matches.csv").write_text(
                    "name,address,size,source,status,progress\n"
                    f"a,0x00424200,0x20,src/a.c,complete,{classification}\n"
                )
                with self.assertRaisesRegex(SystemExit, "classification missing or invalid"):
                    load_data_matches(root / "units.csv", root / "matches.csv")

    def test_placeholder_data_is_uncredited_but_keeps_denominator(self):
        result = build_report([], {}, {
            "raw": {"address": 0x424200, "size": 8192, "source": "raw.c",
                    "complete": True, "progress": "placeholder"},
            "table": {"address": 0x426200, "size": 52, "source": "table.c",
                      "complete": True, "progress": "reconstructed"},
            "unlinked": {"address": 0x426234, "size": 16, "source": "next.c",
                         "complete": False, "progress": "reconstructed"},
        })
        measures = result["measures"]
        self.assertEqual(int(measures["total_data"]), DATA_SIZE)
        self.assertEqual(int(measures["matched_data"]), 68)
        self.assertEqual(int(measures["complete_data"]), 52)
        self.assertEqual(sum(int(u["measures"].get("total_data", 0))
                             for u in result["units"]), DATA_SIZE)
        by_name = {u["name"]: u for u in result["units"]}
        self.assertFalse(by_name["main/raw"]["metadata"]["complete"])
        self.assertTrue(by_name["main/table"]["metadata"]["complete"])
        self.assertFalse(by_name["main/next"]["metadata"]["complete"])


    def test_linked_data_percent_never_exceeds_span(self):
        from tools.objdiff_report import DATA_SIZE, BASE_ADDRESS, TEXT_SIZE
        from tools.progress_catalog import unique_covered_bytes

        data_lo = BASE_ADDRESS + TEXT_SIZE
        covered = unique_covered_bytes(
            [(data_lo, DATA_SIZE), (data_lo + 16, 32)],
            data_lo,
            data_lo + DATA_SIZE,
        )
        self.assertEqual(covered, DATA_SIZE)
        result = build_report([], {}, {
            "a": {"address": data_lo, "size": DATA_SIZE, "source": "src/a.c", "complete": True, "progress": "reconstructed"},
        })
        self.assertLessEqual(float(result["measures"]["complete_data_percent"]), 100.0)
        self.assertEqual(result["measures"]["complete_data"], str(DATA_SIZE))


    def test_data_owner_symbols_preserve_suffixed_legacy_labels(self):
        from pathlib import Path
        import tempfile
        from tools.generate_data_symbol_addrs import extract_symbols

        with tempfile.TemporaryDirectory() as tmp:
            source = Path(tmp) / "pointer.c"
            source.write_text(
                "extern unsigned int data_u32_004C2424[];\n"
                "void *data_ptr_004C2430 = &data_u32_004C2424[1];\n"
                "extern char gMvc2Scratchpad_70000000[];\n"
                "extern char jtblTyped_00464100[];\n"
                "extern void func_00163F40(void);\n"
                "extern void residual_003AFA90(unsigned char *);\n"
                "void (*jtbl_004C1F78)(unsigned char *) = residual_003AFA90;\n"
                "int ordinary;\n",
                encoding="utf-8",
            )
            self.assertEqual(dict(extract_symbols(source)), {
                "data_u32_004C2424": 0x004C2424,
                "data_ptr_004C2430": 0x004C2430,
                "gMvc2Scratchpad_70000000": 0x70000000,
                "jtblTyped_00464100": 0x00464100,
                "func_00163F40": 0x00163F40,
                "residual_003AFA90": 0x003AFA90,
                "jtbl_004C1F78": 0x004C1F78,
            })


if __name__ == "__main__":
    unittest.main()
