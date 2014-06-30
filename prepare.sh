#!/bin/bash

path=$(cd "$(dirname "$0")"; pwd)

filesToProcess() {
  local listFile=busybox_files
  cat $listFile
}

flags="-x CONFIG_ \
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

#tunitgen

tunitgen=" --bdd \
  --study busybox --serializeAST --writePI --interface --debugInterface"


filesToProcess|while read i; do
         echo "Analysing $path/busybox-1.18.5/$i.c"
         echo "With settings: $tunitgen $flags"
         ../Morpheus/morpheus.sh $path/busybox-1.18.5/$i.c $tunitgen $flags
	 done

interfacegen="--study busybox  --writeProjectInterface"

echo "Generate interfaces"

../Morpheus/morpheus.sh $path/busybox-1.18.5/archival/ar.c $interfacegen

refgen="--bdd \
  --study busybox --reuseAST --refPrep --refLink $path/CLinking.interface"

filesToProcess|while read i; do
         echo "Analysing $path/busybox-1.18.5/$i.c"
         echo "With settings: $refgen $flags"
         ../Morpheus/morpheus.sh $path/busybox-1.18.5/$i.c $refgen $flags
         done



