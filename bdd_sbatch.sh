#!/bin/bash

path=$(cd "$(dirname "$0")"; pwd)

filesToProcess() {
  local listFile=casestudy/busybox_files
  cat $listFile
}

flags=" --bdd \
  --serializeAST \
  -A doublefree -A xfree -A uninitializedmemory -A casetermination -A danglingswitchcode -A checkstdlibfuncreturn -A deadstore -A interactiondegree \
  -x CONFIG_ \
  -c $path/casestudy/redhat.properties \
  --include $path/casestudy/config.h \
  -I $path/busybox-1.18.5/include \
  --featureModelDimacs $path/casestudy/BB_fm.dimacs --simplifyFM $path/casestudy/busybox.model \
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
         sbatch -p sphinx -A sphinx -n 1 -c 2 --cpu_bind=sockets  --mem_bind=local --mail-type=all --mail-user=janker@fim.uni-passau.de /home/janker/clusterScripts/setupAndRunBB.sh  $path/busybox-1.18.5/$i.c $flags
	 done

