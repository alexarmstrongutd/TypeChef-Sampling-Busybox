#!/bin/bash

#SBATCH -D /scratch/janker/busybox/Morpheus-BusyBoxEvaluation
#SBATCH --job-name=typechef
#SBATCH -p chimaira
#SBATCH -A spl
#SBATCH --get-user-env
#SBATCH -n 1
#SBATCH -c 2
#SBATCH --mail-type=FAIL
#SBATCH --mail-user=janker@fim.uni-passau.de
#SBATCH --mem_bind=local
#SBATCH --output=/dev/null
#SBATCH --error=/dev/null
#SBATCH --time=12:00:00
#SBATCH --array=0-570

path=$(pwd)
#path=$(echo $path | sed s/scratch/local/g)

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
configId=${SLURM_ARRAY_TASK_ID}

i=`cat casestudy/busybox_files | head -n $((configId + 1)) | tail -n1`

     echo "Analysing $path/busybox-1.18.5/$i.c"
     echo "With settings: $flags"
     ./sampling.sh $path/busybox-1.18.5/$i.c $flags 
     #sbatch -p chimaira  -A spl -n 1 -c 2 --time=06:00:00  --mem_bind=local --output=/dev/null --error=/dev/null  /home/janker/clusterScripts/bb_sampling.sh $path/busybox-1.18.5/$i.c $flags
     # timeout 3h ../TypeChef/typechef.sh $path/busybox-1.18.5/$i.c $flags

