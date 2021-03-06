#ifndef CMM_H
   #define CMM_H

   #define ATL_mmMULADD
   #define ATL_mmLAT 4
   #define ATL_mmMU  4
   #define ATL_mmNU  2
   #define ATL_mmKU  16
   #define MB 40
   #define NB 40
   #define KB 40
   #define NBNB 1600
   #define MBNB 1600
   #define MBKB 1600
   #define NBKB 1600
   #define NB2 80
   #define NBNB2 3200

   #define ATL_MulByNB(N_) ((N_) * 40)
   #define ATL_DivByNB(N_) ((N_) / 40)
   #define ATL_MulByNBNB(N_) ((N_) * 1600)

#endif
