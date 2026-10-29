/*
 * mvc2_stubs.h - runtime for the host link's faked symbols (Port G).
 *
 * Everything the host link fakes is named: generated stubs (gen_link_glue.py,
 * build/<tree>/glue/mvc2_glue_stubs.c) and the hand-written ones in
 * port/stubs/ (*.c) both enter through MVC2_STUB_ENTER, and gen_link_glue.py
 * lists every one of them (scanning this directory for MVC2_STUB_ENTER) in
 * the generated table mvc2_fakes[] (glue/mvc2_glue_table.c) and in
 * glue/stubs.csv.  Host code only: never included by game TUs.
 */
#ifndef MVC2_STUBS_H
#define MVC2_STUBS_H

#ifdef __cplusplus
extern "C" {
#endif

/* One row per faked symbol (generated). */
struct mvc2_fake {
    const char *name;     /* symbol */
    unsigned ee_addr;     /* EE address (0 if none) */
    const char *kind;     /* stub class, see gen_link_glue.py */
    const char *how;      /* what the host does instead */
};
extern const struct mvc2_fake mvc2_fakes[];
extern const unsigned mvc2_fake_count;

/* Logs the first MVC2_STUB_LOG_LIMIT hits of each stub (stderr), counts all.
 * MVC2_STUB_QUIET=1 silences it, MVC2_STUB_TRAP=name aborts on that stub. */
void mvc2_stub_hit(const char *name, unsigned ee_addr, const char *kind);
void mvc2_stub_hit_slot(int *slot, const char *name, unsigned ee_addr, const char *kind);
void mvc2_stub_report(void);
unsigned mvc2_stub_hits(const char *name);

#define MVC2_STUB_ENTER(name, addr, kind) \
    do { static int mvc2_slot_ = -1; mvc2_stub_hit_slot(&mvc2_slot_, name, addr, kind); } while (0)

#ifdef __cplusplus
}
#endif
#endif
