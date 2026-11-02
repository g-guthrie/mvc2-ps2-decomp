#!/usr/bin/perl
# C_COMPILER_LAUNCHER: compile one C file with the EE's float semantics
# (port/host/ps2_float.c, port/tools/ps2_fp_rewrite.pl).
#   ps2fp-cc.pl COMPILER [ARGS...] -o OBJ -c SRC
# 1. the same command, but emitting LLVM IR at -O0 (nothing folded with
#    round-to-nearest yet, no fused multiply-add; it also writes the -MD
#    dependency file),
# 2. the single-precision arithmetic is rewritten into ps2_* helper calls,
# 3. the rewritten IR is optimised and compiled with the original flags.
# MVC2_NO_PS2FP=1 in the build environment compiles as usual (A/B checks).
use strict;
use warnings;
use FindBin;
require "$FindBin::Bin/../tools/ps2_fp_rewrite.pl";

my @cmd = @ARGV;
my ($obj, $src);
for my $i (0 .. $#cmd) {
    $obj = $cmd[$i + 1] if $cmd[$i] eq '-o' && $i < $#cmd;
    $src = $cmd[$i] if $cmd[$i] =~ /\.c$/;
}
if ($ENV{MVC2_NO_PS2FP} || !$obj || !$src || $src =~ /(ps2_float|arcade_code)\.c$/) {  # arcade_code.c models the NAOMI SH-4 (round to nearest, fused FMAC)
    exec @cmd or die "ps2fp-cc: exec $cmd[0]: $!";
}
my ($ir1, $ir2) = ("$obj.ps2fp.ll", "$obj.ps2fp.r.ll");
my @c1;
for (my $i = 0; $i <= $#cmd; $i++) {
    my $a = $cmd[$i];
    if ($a eq '-o') { push @c1, '-o', $ir1; $i++; next; }
    if ($a =~ /^-O[0-3sz]$/) { push @c1, '-O0'; next; }
    push @c1, $a;
}
push @c1, '-S', '-emit-llvm', '-Xclang', '-disable-O0-optnone', '-ffp-contract=off';
system(@c1) == 0 or exit 1;
rewrite($ir1, $ir2);
unlink $ir1;
my @c2;
# emcc itself does not take IR input with -x ir: use its clang (as emcc-direct.sh)
if ($cmd[0] =~ m{(^|/)emcc$}) {
    (my $dir = $cmd[0]) =~ s{/?emcc$}{};
    @cmd = ("$dir/../bin/clang", '--target=wasm32-unknown-emscripten', @cmd[1 .. $#cmd]);
}
for (my $i = 0; $i <= $#cmd; $i++) {
    my $a = $cmd[$i];
    if ($a eq $src) { next; }
    if ($a eq '-c') { next; }
    if ($a eq '-MD' || $a eq '-MMD') { next; }
    if ($a eq '-MT' || $a eq '-MF' || $a eq '-include' || $a eq '-I' || $a eq '-D') { $i++; next; }
    if ($a =~ /^-(I|D|std=|include)/) { next; }
    push @c2, $a;
}
push @c2, '-Wno-unused-command-line-argument', '-c', '-x', 'ir', $ir2;
my $rc = system(@c2);
unlink $ir2;
exit($rc == 0 ? 0 : 1);
