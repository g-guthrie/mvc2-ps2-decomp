#!/usr/bin/env perl

use strict;
use warnings;

my ($input, $output) = @ARGV;
die "usage: $0 INPUT.s OUTPUT.s\n" unless defined $input && defined $output;

open my $in, '<', $input or die "open $input: $!\n";
open my $out, '>', $output or die "open $output: $!\n";

my $converted = 0;
while (my $line = <$in>) {
    if ($line =~ m{^(\s*)/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]{8}\s+([0-9A-Fa-f]{8})\s*\*/}) {
        my ($indent, $offset, $bytes) = ($1, uc($2), uc($3));
        my @octets = ($bytes =~ /../g);
        my $word = join '', reverse @octets;
        print {$out} qq{$indent.word 0x$word /* raw 0x$offset */\n};
        ++$converted;
    } else {
        print {$out} $line;
    }
}

close $out or die "close $output: $!\n";
close $in or die "close $input: $!\n";
die "no four-byte payload records found in $input\n" unless $converted;
print "converted $converted four-byte payload records\n";
