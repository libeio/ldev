#!/usr/bin/env perl -w

package Foo;

sub bar {
	print "Hello $_[0]\n";
}

sub blat {
	print "World $_[0]\n";
}
1;