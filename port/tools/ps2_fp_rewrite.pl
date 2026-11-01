#!/usr/bin/perl
# EE float semantics for the host build (see port/host/ps2_float.c):
# rewrite the single-precision arithmetic of an LLVM IR module (emitted at -O0,
# before any optimisation could fold it with round-to-nearest) into calls of
# the ps2_* helpers.  Usage: ps2_fp_rewrite.pl IN.ll OUT.ll
use strict;
use warnings;

sub rewrite {
my ($in, $out) = @_;
open(my $fh, '<', $in) or die "ps2_fp_rewrite: $in: $!";
my @lines = <$fh>;
close $fh;

my %bin = (fadd => 'ps2_fadd', fsub => 'ps2_fsub', fmul => 'ps2_fmul', fdiv => 'ps2_fdiv');
my %used;
my %proto = (
    ps2_fadd => 'float @ps2_fadd(float, float)',
    ps2_fsub => 'float @ps2_fsub(float, float)',
    ps2_fmul => 'float @ps2_fmul(float, float)',
    ps2_fdiv => 'float @ps2_fdiv(float, float)',
    ps2_fsqrt => 'float @ps2_fsqrt(float)',
    ps2_i2f => 'float @ps2_i2f(i32)',
    ps2_u2f => 'float @ps2_u2f(i32)',
    ps2_l2f => 'float @ps2_l2f(i64)',
    ps2_ul2f => 'float @ps2_ul2f(i64)',
);
my $n = 0;
for (@lines) {
    # %x = fadd [flags] float A, B[, !dbg !N]
    if (/^(\s*%[-\w.]+ = )(fadd|fsub|fmul|fdiv)((?: [a-z]+)*) float ([^,]+), ([^,\n]+)(.*)$/) {
        my ($lhs, $op, $flags, $a, $b, $rest) = ($1, $2, $3, $4, $5, $6);
        my $f = $bin{$op};
        $used{$f} = 1;
        $_ = "${lhs}call float \@$f(float $a, float $b)$rest\n";
        $n++;
        next;
    }
    if (/^\s*%[-\w.]+ = (fadd|fsub|fmul|fdiv)\b.*<\d+ x float>/) {
        die "ps2_fp_rewrite: $in: vector float arithmetic is not handled: $_";
    }
    # %x = sitofp/uitofp i32|i64 V to float
    if (/^(\s*%[-\w.]+ = )(sitofp|uitofp) (i32|i64) ([^ ]+) to float(.*)$/) {
        my ($lhs, $op, $ty, $v, $rest) = ($1, $2, $3, $4, $5);
        my $f = $op eq 'sitofp' ? ($ty eq 'i32' ? 'ps2_i2f' : 'ps2_l2f') : ($ty eq 'i32' ? 'ps2_u2f' : 'ps2_ul2f');
        $used{$f} = 1;
        $_ = "${lhs}call float \@$f($ty $v)$rest\n";
        $n++;
        next;
    }
    # sqrt
    if (s/call (?:[a-z]+ )*float \@(?:llvm\.sqrt\.f32|sqrtf)\(/call float \@ps2_fsqrt(/) {
        $used{ps2_fsqrt} = 1;
        $n++;
        next;
    }
    if (/\@llvm\.fmuladd\.f32|\@llvm\.fma\.f32/) {
        die "ps2_fp_rewrite: $in: fused multiply-add (build with -ffp-contract=off): $_";
    }
}
my $text = join('', @lines);
for my $f (sort keys %used) {
    next if $text =~ /^declare [^\n]*\@\Q$f\E\(/m || $text =~ /^define [^\n]*\@\Q$f\E\(/m;
    $text .= "\ndeclare $proto{$f}\n";
}
open(my $oh, '>', $out) or die "ps2_fp_rewrite: $out: $!";
print $oh $text;
close $oh;
return $n;
}

rewrite(@ARGV) if !caller && @ARGV == 2;
1;
