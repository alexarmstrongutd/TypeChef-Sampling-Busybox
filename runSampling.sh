#!/bin/bash


path=$(pwd)

filesToProcess() {
  local listFile=casestudy/busybox_files
  cat $listFile
}

flags=" --bdd --reuseAST \
  -x CONFIG_ \
  -c $path/casestudy/redhat.properties \
  --include $path/casestudy/config.h \
  -I $path/busybox-1.18.5/include \
  --featureModelDimacs $path/casestudy/BB_fm.dimacs  \
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
     ./sampling.sh $path/busybox-1.18.5/$i.c $flags 
done
