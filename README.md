# bitman.c

This is a CLI that helps you convert values between decimal, hexadecimal and binary.
Written in C, because I wanted to revise how to do the conversions and C is the best. Sorry Rust (Kidding of course).

> This is not thoroughly tested and could break.

## How to use
First of all you can download a pre-built binary from the releases page. This will be a static binary.
You could build the binary from source if you want to and especially if there is no build for the platform you are on.

To build from source, first clone the repository, then change directory into bitman and run `make` in your terminal (if you have make installed). If you do not have make installed, run `clang bitman.c -o bitman -lm -static`.

## Commands
- `b` for binary
- `d` for decimal and
- `h` for hexadecimal

To convert from one to another, just combine them like
```shell
$ bitman dh 404
```
This will convert a decimal value to a hexadecimal value. `db` for decimal to binary, `hb` for hex to binary and so on.

