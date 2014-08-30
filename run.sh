#!/bin/bash

path=$(cd "$(dirname "$0")"; pwd)


flags=" --bdd \
  --study busybox --showGui \
  -x CONFIG_ \
  -c $path/casestudy/redhat.properties \
  --include $path/casestudy/config.h \
  -I $path/busybox-1.18.5/include \
  --featureModelDimacs $path/casestudy/BB_fm.dimacs \
  --recordTiming --parserstatistics --lexNoStdout \
  -U HAVE_LIBDMALLOC \
  -DCONFIG_FIND \
  -U CONFIG_FEATURE_WGET_LONG_OPTIONS \
  -U ENABLE_NC_110_COMPAT \
  -U CONFIG_EXTRA_COMPAT \
  -D_GNU_SOURCE"

echo "Analysing $path/busybox-1.18.5/$1"
echo "With settings: $flags"
../Morpheus/morpheus.sh $path/busybox-1.18.5/$1 $flags

