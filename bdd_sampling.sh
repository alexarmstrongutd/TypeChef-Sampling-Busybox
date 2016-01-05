#!/bin/bash

path=$(cd "$(dirname "$0")"; pwd)
path=$(echo $path | sed s/scratch/local/g)

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
         sbatch -p chimaira  -A spl -n 1 -c 2 --time=06:00:00  --mem_bind=local --output=/dev/null --error=/dev/null  /home/janker/clusterScripts/bb_sampling.sh $path/busybox-1.18.5/$i.c $flags
	 # timeout 3h ../TypeChef/typechef.sh $path/busybox-1.18.5/$i.c $flags
	 done

