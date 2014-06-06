#!/bin/bash 

filesToProcess() {
  local listFile=configFlags
  cat $listFile
}

cd busybox-1.18.5
mkdir --p "$1"

#Ref first
i=0

filesToProcess|while read config; do
        echo "Verifiying $1"
        echo "With config: $config"
        rm -f .config
        cp $config/.config 
        ./build.sh | tee "$1"/"$i"_ref.build
        cd testsuite
        ./runtest | tee "$1"/"$i"_ref.test
        cd ..
        i=`expr $i + 1`
        done

#Clean
git checkout .

#Org Next
i=0

filesToProcess|while read config; do
        echo "Verifiying $1"
        echo "With config: $config"
        rm -f .config
        cp $config/.config 
        ./build.sh | tee "$1"/"$i"_org.build
        cd testsuite
        ./runtest | tee "$1"/"$i"_org.test
        cd ..        
        i=`expr $i + 1`
        done

#Clean
exit