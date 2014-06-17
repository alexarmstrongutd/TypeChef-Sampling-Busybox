#!/bin/bash
timeout 200 make -j 4 &> buildout

RETVAL=$?
[ $RETVAL -eq 0 ] && echo "Success_Build"
[ $RETVAL -eq 124 ] && echo "Failure_Timeout"
[ $RETVAL -ne 0 ] && echo "Failure_Build"

exit
