#!/bin/bash

path=$(cd "$(dirname "$0")"; pwd)

filesToProcess() {
  local listFile=busybox_files
  cat $listFile
}

flags=" --bdd \
  --study busybox --reuseAST --refEval extract --refLink $path/CLinking.interface \
  -x CONFIG_ \
  -c $path/redhat.properties \
  --include $path/config.h \
  -I $path/busybox-1.18.5/include \
  --featureModelDimacs $path/BB_fm.dimacs \
  --recordTiming --parserstatistics --lexNoStdout \
  -U HAVE_LIBDMALLOC \
  -DCONFIG_FIND \
  -U CONFIG_FEATURE_WGET_LONG_OPTIONS \
  -U ENABLE_NC_110_COMPAT \
  -U CONFIG_EXTRA_COMPAT \
  -D_GNU_SOURCE"


filesToProcess|while read i; do
         echo "Analysing $path/busybox-1.18.5/$i.c"
         echo "With settings: $flags"
         ../Morpheus/morpheus.sh $path/busybox-1.18.5/$i.c $flags
         echo "Verifiying  $path/result/$i"
         busybox-1.18.5/verify.sh $path/result/$i.c
	 done

