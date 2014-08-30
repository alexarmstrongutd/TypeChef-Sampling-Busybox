find redhat/ -name "*.h" |while read i; do echo $i; gsed -i 's///g' $i; done 
