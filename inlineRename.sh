#!/bin/bash


time ./eval_inline.sh 2>&1 | tee inlineLog
mv result result_inline
time ./eval_rename.sh 2>&1 | tee renameLog
mv result result_rename


