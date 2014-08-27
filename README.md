Morpheus-BusyBoxEvaluation
===========================

This project contains all evaluation-related material for the case study BusyBox 1.18.5 for the variability-aware refactoring engine for C, [Morpheus](https://github.com/joliebig/Morpheus).


Installation and Usage
----------------------

To run this case study a version of [Morpheus](https://github.com/joliebig/Morpheus) is required. See the project page for installation notes.

Run the Evaluation
-----------------

If you want to run the evaluation of the refactoring engine [Morpheus](https://github.com/joliebig/Morpheus) run `prepare.sh` first to create the required .tunit, .interface and .pr files. Now you can edit `eval.sh` to choose your desired refactoring method: rename, extract- or inline function and subsequently run `./eval.sh` to execute the evalution.

Run the experimental GUI
-----------------

In order to show a GUI and refactor a single file of this case study "ide-like" just execute `./run.sh <file/to/refactor>`.


Good luck. In case of problems contact [me](mailto:janker@fim.uni-passau.de).
