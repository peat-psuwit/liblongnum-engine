#!/bin/sh
cd "$(dirname $0)"
mkdir -p m4/
autoreconf --install || echo "Please install libtool, autoconf and automake before run this script again."
