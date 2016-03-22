#!/bin/bash

path=$(pwd)

filesToProcess() {
  local listFile=casestudy/busybox_files
  cat $listFile
}

filesToProcess|while read i; do


     currFile=$path/busybox-1.18.5/$i.c
     result=$currFile-features_srcml.csv
     echo "$result"
     touch result
     echo "Function;Features;Names" > $result

     currXML=$(./srcml $currFile) # Parse *.c File as xml
     allFunctions=$(echo $currXML | \
     ./srcml --xpath "//src:function/src:name" | \
     ./srcml --xpath "string(//src:name)") # Find all functions

     for f in $allFunctions; do
            echo fun: $f
            features=$(echo $currXML | \
            ./srcml --xpath "//src:function[src:name = '$f']//cpp:*//src:name" | \
            ./srcml --xpath "string(//src:name)" | \
            grep [A-Za-z0-9_] | grep -v -w "defined"  | sort | uniq ) # get unique features from cpp directives
            
            total=$(echo -e "$features" | grep '[^ ]' | wc -l | xargs)

            echo -n $f";" | tee -a $result
            echo -n "$total;" | tee -a $result
            echo -n $features | tee -a $result
            echo ";" | tee -a $result

        done
    done
